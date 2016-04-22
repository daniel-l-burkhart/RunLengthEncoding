

/* This is auto-generated code. Edit at your own peril. */
#include <stdio.h>
#include <stdlib.h>

#include "CuTest.h"


extern void Test_find_decoded_line_length_b4_should_be_four(CuTest*);
extern void Test_find_decoded_line_length_b1000_should_be_one_thousand(CuTest*);
extern void Test_find_decoded_line_length_b502_should_be_502(CuTest*);
extern void Test_string_of_encode(CuTest*);
extern void Test_string_of_encode_with_all_the_same_character(CuTest*);
extern void Test_string_of_encode_with_a_large_number_of_characters(CuTest*);
extern void Test_string_of_encode_with_single_occurrence_characters(CuTest*);
extern void Test_same_character_string_of_decode(CuTest*);
extern void Test_multicharacter_string_of_decode(CuTest*);
extern void Test_140character_string_of_decode(CuTest*);
extern void Test_1character_occurrences_string_of_decode(CuTest*);


void RunAllTests(void) 
{
    CuString *output = CuStringNew();
    CuSuite* suite = CuSuiteNew();


    SUITE_ADD_TEST(suite, Test_find_decoded_line_length_b4_should_be_four);
    SUITE_ADD_TEST(suite, Test_find_decoded_line_length_b1000_should_be_one_thousand);
    SUITE_ADD_TEST(suite, Test_find_decoded_line_length_b502_should_be_502);
    SUITE_ADD_TEST(suite, Test_string_of_encode);
    SUITE_ADD_TEST(suite, Test_string_of_encode_with_all_the_same_character);
    SUITE_ADD_TEST(suite, Test_string_of_encode_with_a_large_number_of_characters);
    SUITE_ADD_TEST(suite, Test_string_of_encode_with_single_occurrence_characters);
    SUITE_ADD_TEST(suite, Test_same_character_string_of_decode);
    SUITE_ADD_TEST(suite, Test_multicharacter_string_of_decode);
    SUITE_ADD_TEST(suite, Test_140character_string_of_decode);
    SUITE_ADD_TEST(suite, Test_1character_occurrences_string_of_decode);

    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
    CuStringDelete(output);
    CuSuiteDelete(suite);
}

int main(void)
{
    RunAllTests();
	return EXIT_SUCCESS;
}

