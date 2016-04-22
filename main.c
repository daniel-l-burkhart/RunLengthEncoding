#include <stdio.h>
#include <stdlib.h>

#include "rle.h"

int main(int argc, char* argv[]) {

	FILE* in = NULL;
	FILE* out = NULL;
	int num_lines = 0;
	int num_cols = 0;
	char* infilename;
	char* outfilename;
	char* operation;

	if (argc != 4) {
		printf("Usage: a2z [--encode image.ascii image.enc] [--decode image.enc image.ascii]");
		return EXIT_FAILURE;
	}

	
	operation = argv[1];
	infilename = argv[2];
	outfilename = argv[3];

	printf("Input file: %s\n", infilename);
	printf("Output file: %s\n", outfilename);

	in = fopen(infilename, "r");
	out = fopen(outfilename, "w");

	if (0 == strncmp("--encode", operation, 8)) {
		num_lines = count_lines(in);
		fprintf(stdout, "#lines: %d\n", num_lines);
		if (num_lines <= 0) {
			printf("Empty input file\n");
			return EXIT_FAILURE;
		}

		num_cols = count_columns(in);
		fprintf(stdout, "#columns: %d\n", num_cols);
		if (num_cols <= 0) {
			printf("Invalid number of columns\n");
			return EXIT_FAILURE;
		}

		encode_file(out, in, num_lines, num_cols);
	}

	if (0 == strncmp("--decode", operation, 8)) {
		decode_file(out, in);
	}

	fclose(in);
	fclose(out);
	
	return EXIT_SUCCESS;
}
