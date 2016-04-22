CC=gcc
CCFLAGS= -c -Wall
SOURCES=rle.c
HEADERS=rle.h
TEST_SOURCES=test_rle.c


a2z: $(HEADERS) $(SOURCES)
	$(CC) $(CFLAGS) -o a2z main.c $(SOURCES) $(HEADERS)
	
clean:
	rm -f *.o a2z AllTests AllTests.c
	
test: $(SOURCES) $(TEST_SOURCES) $(HEADERS)
	
	chmod a+x make-tests.sh
	
	./make-tests.sh > AllTests.c

	$(CC) $(CFLAGS) -o AllTests  AllTests.c CuTest.c $(SOURCES) $(TEST_SOURCES)

	./AllTests
