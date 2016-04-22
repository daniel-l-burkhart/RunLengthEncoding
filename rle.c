#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "rle.h"

int count_lines(FILE* ascii_file) {
	int count = 0;
	int next_char;
	rewind(ascii_file);
	while (1) {
		next_char = fgetc(ascii_file);
		if (next_char == '\n') {
			count++;
		} else if (next_char == EOF) {
			break;
		}
	}

	return count;
}

int count_columns(FILE* ascii_file) {
	int first_line_length = 0;
	int curr_line_length = 0;
	int next_char;

	rewind(ascii_file);

	// read the size of the 1st line
	while(1) {
		next_char = fgetc(ascii_file);
		if (next_char == '\n') {
			break;
		} else if (next_char == EOF) {
			return first_line_length;
		} else {
			first_line_length++;
		}
	}

	// read the size of subsequent lines
	while(1) {
		next_char = fgetc(ascii_file);
		if (next_char == '\n') {
			if (curr_line_length == first_line_length) {
				curr_line_length = 0;
				continue;
			} else {
				return LINE_LENGTH_ERROR;
			}
		} else if (next_char == EOF) {
			if (curr_line_length == first_line_length || curr_line_length == 0) {
				return first_line_length;
			} else {
				return LINE_LENGTH_ERROR;
			}
		} else {
			curr_line_length++;
		}
	}

	return first_line_length;
}

char* encode_line(char plaintext[], int line_length) {
	
	char *encodedLine = (char *)malloc(sizeof(char)*(line_length*2 + 1));
	
	char numberOfOccurrences[line_length*2];
	
	int i;
	int j = 0;
	int k;
	int occurrenceCount;
	
	for(i=0; i<line_length; i++){
		encodedLine[j++] = plaintext[i];
		
		occurrenceCount = 1;
		while(((i + 1) < line_length) && (plaintext[i] == plaintext[i+1])) {
			occurrenceCount++;
			i++;
		}
		
		sprintf(numberOfOccurrences, "%d", occurrenceCount);
		
		for(k=0; *(numberOfOccurrences+k); k++){
			encodedLine[j] = numberOfOccurrences[k];
			j++;
		}
	}
	
	
	encodedLine[j] = '\0';
	return encodedLine;
}

int find_decoded_line_length(char* encoded) {
	
	int decoded_line_count=0;
    int decode_char_count = 0;
    char decodedLtr;
    
    int decoded_count;
    for (decoded_count = 0; decoded_count<strlen(encoded); decoded_count++) {
        
		if((encoded + decoded_count) != '\0'){
            
			sscanf(encoded + decoded_count, "%c%u", &decodedLtr, &decode_char_count);
            decoded_line_count+=decode_char_count;
			
			int number = floor(log10(abs(decode_char_count))) +1;
			decoded_count += number;
        }
    }
	
	return decoded_line_count;
}

char* decode_line(char* encoded) {
    
    char* decoded_line; 
	int decoded_length = find_decoded_line_length(encoded);
    decoded_line = (char*)malloc(decoded_length*sizeof(char*) +1);
    
    char ltr;
    int count;
    int i;
    int j;
	int currentDecodedIndex = 0;
    
    for (i=0; i < strlen(encoded)-1; i++) {
        
        if((encoded + i) != '\0'){
            
            sscanf(encoded+i, "%c%u", &ltr, &count);
            
            for (j=0; j<count; j++) {
                *(decoded_line+currentDecodedIndex+j) = ltr;
            }
        }
		
		currentDecodedIndex+=j;
		i += floor(log10(abs(count))) +1;
    }
	
    *(decoded_line + decoded_length + 1) = '\0';
	
	return decoded_line;
}

void encode_file(FILE* out, FILE* in, int rows, int cols) {
	char* line;
	char* encoded;
	int i;

	if (in == NULL) {
		fprintf(stderr, "Error: encode(): NULL input file");
		return;
	}

	if (out == NULL) {
		fprintf(stderr, "Error: encode(): NULL output file");
		return;
	}

	rewind(in);

	line = (char*)malloc((cols + 1) * sizeof(char));

	for (i = 0; i < rows; i++) {
		fscanf(in, "%s", line);
		line[cols] = '\n';
		encoded = encode_line(line, cols);
		fprintf(out, "%s\n", encoded);
		free(encoded);
	}

	free(line);
}

void decode_file(FILE* out, FILE* in) {
	int num_cols = 0;
	int num_rows = 0;
	char* encoded_line;
	char* decoded_line;
	int encoded_line_length = 0;
	char next_char;
	int bytes_read = 0;
	int i;

	if (in == NULL) {
		fprintf(stderr, "Error: decode(): NULL input file");
		return;
	}

	if (out == NULL) {
		fprintf(stderr, "Error: decode(): NULL output file");
		return;
	}

	rewind(in);

	// find the length of the first encoded line
	while(1) {
		next_char = fgetc(in);
		if (next_char == '\n' || next_char == EOF) {
			break;
		}
		encoded_line_length++;
	}

	// find the decoded line length (number of columns)
	rewind(in);
	encoded_line = (char*)malloc( (encoded_line_length + 1) * sizeof(char));
	fscanf(in, "%s", encoded_line);
	num_cols = find_decoded_line_length(encoded_line);
	free(encoded_line);
	
	// get the number of rows
	num_rows = count_lines(in);

	// set up a general read-in buffer.  This will, at worst, be (2*num_cols)+1
	// (i.e., all characters happen exactly once, +1 for the nulchar)
	encoded_line_length = 2 * num_cols + 1;
	encoded_line = (char*)malloc( encoded_line_length * sizeof(char));
	memset(encoded_line, '\0', encoded_line_length);
	// start decoding
	rewind(in);
	for (i = 0; i < num_rows; i++) {
		fscanf(in, "%s%n", encoded_line, &bytes_read);
		encoded_line[bytes_read] = '\0';
		decoded_line = decode_line(encoded_line);
		fprintf(out, "%s\n", decoded_line);
		if (decoded_line != NULL) {
			free(decoded_line);
		}
	}

	free(encoded_line);	
	return;
}
