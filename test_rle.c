#include <stdlib.h>
#include "CuTest.h"
#include "rle.h"

/**
* Test the decode line length method.
**/
void Test_find_decoded_line_length_b4_should_be_four(CuTest* ct) {
	
	CuAssertIntEquals(ct, 4, find_decoded_line_length("b4"));
}

/**
* Tests a large number with find_decoded_line_length method.
**/
void Test_find_decoded_line_length_b1000_should_be_one_thousand(CuTest* ct) {
	
	CuAssertIntEquals(ct, 1000, find_decoded_line_length("b1000"));
}

/**
* Tests the in-between of the find_decoded_line_length line method.
**/
void Test_find_decoded_line_length_b502_should_be_502(CuTest* ct) {
	
	CuAssertIntEquals(ct, 502, find_decoded_line_length("b502"));
}

/**
 * A char array is passed to the encode method 
 * and checked against what should be the correct 
 * output of the encode method.
 */
void Test_string_of_encode(CuTest* ct) {
	
	char a2b1c3[6];
	a2b1c3[0] = 'a';
	a2b1c3[1] = 'a';
	a2b1c3[2] = 'b';
	a2b1c3[3] = 'c';
	a2b1c3[4] = 'c';
	a2b1c3[5] = 'c';
	
	
	CuAssertStrEquals(ct, "a2b1c3", encode_line(a2b1c3, 6));
}

/**
* Tests encode method with the same character
**/
void Test_string_of_encode_with_all_the_same_character(CuTest* ct) {
	
	char a6[6];
	a6[0] = 'a';
	a6[1] = 'a';
	a6[2] = 'a';
	a6[3] = 'a';
	a6[4] = 'a';
	a6[5] = 'a';
	
	char* encoded_line = encode_line(a6, 6);
	
	CuAssertStrEquals(ct, "a6", encoded_line);
}

/**
* Tests a high array value with the encode method.
**/
void Test_string_of_encode_with_a_large_number_of_characters(CuTest* ct) {
	
	char a7b8c9d8e2p9n8[51];
	a7b8c9d8e2p9n8[0] = 'a';
	a7b8c9d8e2p9n8[1] = 'a';
	a7b8c9d8e2p9n8[2] = 'a';
	a7b8c9d8e2p9n8[3] = 'a';
	a7b8c9d8e2p9n8[4] = 'a';
	a7b8c9d8e2p9n8[5] = 'a';
	a7b8c9d8e2p9n8[6] = 'a';
	a7b8c9d8e2p9n8[7] = 'b';
	a7b8c9d8e2p9n8[8] = 'b';
	a7b8c9d8e2p9n8[9] = 'b';
	a7b8c9d8e2p9n8[10] = 'b';
	a7b8c9d8e2p9n8[11] = 'b';
	a7b8c9d8e2p9n8[12] = 'b';
	a7b8c9d8e2p9n8[13] = 'b';
	a7b8c9d8e2p9n8[14] = 'b';
	a7b8c9d8e2p9n8[15] = 'c';
	a7b8c9d8e2p9n8[16] = 'c';
	a7b8c9d8e2p9n8[17] = 'c';
	a7b8c9d8e2p9n8[18] = 'c';
	a7b8c9d8e2p9n8[19] = 'c';
	a7b8c9d8e2p9n8[20] = 'c';
	a7b8c9d8e2p9n8[21] = 'c';
	a7b8c9d8e2p9n8[22] = 'c';
	a7b8c9d8e2p9n8[23] = 'c';
	a7b8c9d8e2p9n8[24] = 'd';
	a7b8c9d8e2p9n8[25] = 'd';
	a7b8c9d8e2p9n8[26] = 'd';
	a7b8c9d8e2p9n8[27] = 'd';
	a7b8c9d8e2p9n8[28] = 'd';
	a7b8c9d8e2p9n8[29] = 'd';
	a7b8c9d8e2p9n8[30] = 'd';
	a7b8c9d8e2p9n8[31] = 'd';
	a7b8c9d8e2p9n8[32] = 'e';
	a7b8c9d8e2p9n8[33] = 'e';
	a7b8c9d8e2p9n8[34] = 'p';
	a7b8c9d8e2p9n8[35] = 'p';
	a7b8c9d8e2p9n8[36] = 'p';
	a7b8c9d8e2p9n8[37] = 'p';
	a7b8c9d8e2p9n8[38] = 'p';
	a7b8c9d8e2p9n8[39] = 'p';
	a7b8c9d8e2p9n8[40] = 'p';
	a7b8c9d8e2p9n8[41] = 'p';
	a7b8c9d8e2p9n8[42] = 'p';
	a7b8c9d8e2p9n8[43] = 'n';
	a7b8c9d8e2p9n8[44] = 'n';
	a7b8c9d8e2p9n8[45] = 'n';
	a7b8c9d8e2p9n8[46] = 'n';
	a7b8c9d8e2p9n8[47] = 'n';
	a7b8c9d8e2p9n8[48] = 'n';
	a7b8c9d8e2p9n8[49] = 'n';
	a7b8c9d8e2p9n8[50] = 'n';

	
	char* encoded_line = encode_line(a7b8c9d8e2p9n8, 51);
	
	CuAssertStrEquals(ct, "a7b8c9d8e2p9n8", encoded_line);
}

/**
* Tests a high array value with the encode method.
**/
void Test_string_of_encode_with_single_occurrence_characters(CuTest* ct) {
	
	char alphabet[26];
	alphabet[0] = 'a';
	alphabet[1] = 'b';
	alphabet[2] = 'c';
	alphabet[3] = 'd';
	alphabet[4] = 'e';
	alphabet[5] = 'f';
	alphabet[6] = 'g';
	alphabet[7] = 'h';
	alphabet[8] = 'i';
	alphabet[9] = 'j';
	alphabet[10] = 'k';
	alphabet[11] = 'l';
	alphabet[12] = 'm';
	alphabet[13] = 'n';
	alphabet[14] = 'o';
	alphabet[15] = 'p';
	alphabet[16] = 'q';
	alphabet[17] = 'r';
	alphabet[18] = 's';
	alphabet[19] = 't';
	alphabet[20] = 'u';
	alphabet[21] = 'v';
	alphabet[22] = 'w';
	alphabet[23] = 'x';
	alphabet[24] = 'y';
	alphabet[25] = 'z';
	
	char* encoded_line = encode_line(alphabet, 26);
	
	CuAssertStrEquals(ct, "a1b1c1d1e1f1g1h1i1j1k1l1m1n1o1p1q1r1s1t1u1v1w1x1y1z1", encoded_line);
}

/**
* Tests the decode method with the same character.
**/
void Test_same_character_string_of_decode(CuTest* ct) {
    
    char* decoded_line = decode_line("a10");
    CuAssertStrEquals(ct, "aaaaaaaaaa", decoded_line);
}

/**
* Tests multiple characters with decode.
**/
void Test_multicharacter_string_of_decode(CuTest* ct) {
    
    char* decoded_line = decode_line("a10b4");
    CuAssertStrEquals(ct, "aaaaaaaaaabbbb", decoded_line);
}

/**
* Tests a large number with the decode method.
**/
void Test_140character_string_of_decode(CuTest* ct) {
    
    char* decoded_line = decode_line("a100b40");
    CuAssertStrEquals(ct, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb", decoded_line);
}

/**
* Tests a decode where each letter only occurs once.
**/
void Test_1character_occurrences_string_of_decode(CuTest* ct) {
    
    char* decoded_line;
	decoded_line = decode_line("a1b1c1d1e1f1g1h1i1j1k1l1m1n1o1p1q1r1s1t1u1v1w1x1y1z1");
    CuAssertStrEquals(ct, "abcdefghijklmnopqrstuvwxyz", decoded_line);
}