#ifndef RLE_H
#define RLE_H

#define LINE_LENGTH_ERROR (-1)

#include <stdio.h>

/**
 * Counts the number of lines in an ascii file.
 *
 * @param ascii_file the file to examine
 * @return the number of lines in the file
 */
int count_lines(FILE* ascii_file);

/**
 * Counts the number of columns in an ascii file. It assumes all lines have the same
 * number of columns.  It will return LINE_LENGTH_ERROR if not.
 *
 * @param ascii_file the file to examine
 * @return the number of columns in the file
 */
int count_columns(FILE* ascii_file);

/**
 * Encodes a single line of the file using a simple run-length encoding.  
 * Each encoded line will be a string of character-number pairs, 
 * for example c2h4M9 would be the encoded form
 * of cchhhhMMMMMMMMM
 *
 * @param plaintext the line to be encoded
 * @param line_length the length of the plaintext line
 * @return the encoded string.  The user is responsible for free()-ing this
 */
char* encode_line(char plaintext[], int line_length);

/**
 * Decodes a single line of encoded text.  See encode_line() for the encoded format.
 *
 * @param encoded the encoded line of text
 * @return the plaintext line.  Will be empty string if encoded is empty and NULL if encoded is NULL.  The user is responsible for free()-ing this.
 */
char* decode_line(char* encoded);

/**
 * Encodes an entire file.  There will be one line of encoded text in the outfile for
 * every line of plaintext in the input file.
 *
 * @param out the output (encoded) file
 * @param in the input (plaintext) file
 * @param rows the number of lines in the input file
 * @param cols the number of columns in the input file
 */
void encode_file(FILE* out, FILE* in, int rows, int cols);

/**
 * Decodes an entire file.  There will be one line of decoded text in the outfile for
 * every line of encoded text in the input file.
 *
 * @param out the output (plaintext) file
 * @param in the input (encoded) file
 */
void decode_file(FILE* out, FILE* in);

/**
 * Given an encoded line, calculates how long the decoded line would be. Empty strings and
 * NULL strings will return zero.
 *
 * @param encoded an encoded line of text
 * @returns the length of the decoded line, in char's
 */
int find_decoded_line_length(char* encoded_line);

#endif
