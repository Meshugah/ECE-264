 
#include <stdio.h>
#include <stdlib.h>

// This includes the /declaratinos/ of the functions that you write
// in this assignment. Including the declarations allows you to use
// the functions in this file.

#include "answer01.h"

#define BUFFER_LEN 1024

void printArray(int * array, int len)
{
    printf("{");
    int ind;
    for(ind = 0; ind < len; ++ind) {
	printf("%d", array[ind]);
	if(ind != len - 1) {
	    printf(", ");
	}
    }
    printf("}");
    // If we don't include a '\n' character, then we need to 
    // include this line to ensure that our output is printed immediately.
    fflush(stdout); 
}

void test_arraySum(int * array, int len, int expected)
{
    printArray(array, len);
    int sum = arraySum(array, len);
    printf(". sum = %d, expected = %d.", sum, expected);
    if(sum != expected)
	printf(" FAIL");
    printf("\n");
}

void test_00_arraySum()
{
    printf("Testing arraySum(...)\n");

    // Here we use "static initialization" to create an array
    int array1[] = { -4, -1, 0, 1, 5, 10, 20, 21 };
    int len1 = 8;
    int expected1 = 52;
    test_arraySum(array1, len1, expected1);

    // Our functions must always work... even on empty arrays
    int array2[] = {};
    int len2 = 0;
    int expected2 = 0;
    test_arraySum(array2, len2, expected2);

    // You can add more test-cases here
    // ...

    printf("\n"); // Tidy output is easier to use
}

void test_arrayCountNegative(int * array, int len, int expected)
{
    printArray(array, len);
    int count = arrayCountNegative(array,len); 
    printf(". count = %d, expected = %d.", count, expected);
    if(count != expected)
	printf(" FAIL");
    printf("\n");
}


void test_04_arrayFindSmallest()
{
  printf("Testing array smallest finder\n");
  int array[] = { 3, 4, 5, 2 };
  int array2[] = { 3, 2, 2 , 3 };
  int len = 4;
  int ind1 = arrayFindSmallest(array, len); // ind1 == 0
  printf("\nSmallest = %d\n", ind1);


  int ind2 = arrayFindSmallest(array2, len); // ind2 == 1
  printf("\nSmallest = %d\n", ind2);


  printf("\n");
}
void test_03_arrayIndexRFind()
{
  printf("Testing array RFinder\n");
  int haystack[] = { 1, 47, -45, 4 , 4 ,6 ,47 ,-45 };
   int len = 8;
   int x1 = arrayIndexRFind(-45, haystack, len); // x1 == 0
printf("\n x1 = %d   should be 7", x1);

   int x2 = arrayIndexRFind(47, haystack, len); // x2 == 3
printf("\n x2 = %d   should be 6", x2);

   int x3 = arrayIndexRFind(4, haystack, len); // x3 == -1
printf("\n x3 = %d should be 4\n", x3);
}

void test_02_arrayIsIncreasing()
{
  printf("Testing arrayIsIncreasing(...)\n");
  int array1[] = { 1, 1, 2, 3, 3 };
  int len1 = 5;
  int array2[] = { 1, 2, 0, 4 };
  int len2 = 4;
  int isInc1 = arrayIsIncreasing(array1, len1); // isInc1 == 1
  printf("Array1: %d\n", isInc1);
  int isInc2 = arrayIsIncreasing(array2, len2); // isInc2 == 0
  printf("Array2: %d\n", isInc2);
  int isInc3 = arrayIsIncreasing(NULL, 0);      // isInc3 == 1
  printf("Array3: %d\n", isInc3);
  
}
void test_01_arrayCountNegative()
{
    printf("Testing arrayCountNegative(...)\n");

    int array1[] = { 1, 4, -5, 4 };
    int len1 = 4;
    test_arrayCountNegative(array1, len1, 1);

    int array2[] = {};
    int len2 = 0;
    test_arrayCountNegative(array2, len2, 0);

    int array3[] = { 0, 1, 2, 3, 4 };
    int len3 = 5;
    test_arrayCountNegative(array3, len3, 0);

    int array4[] = { -1, -2, -3, -4 };
    int len4 = 4;
    test_arrayCountNegative(array4, len4, 4);

    // You can add more test-cases here
    // ...

    printf("\n");
}

int main(int argc, char * * argv)
{
  /*  printf("Welcome to ECE264, we are working on PA01.\n"
	   "\n"
	   "You are encouraged to edit this file in order to test\n"
	   "the behavior of the functions you write in answer02.c\n"
	   "\n"
	   "This file will not be marked, and should not be\n"
	   "submitted.\n"
	   "\n"
	   "Don't forget to post questions on blackboard, and ask\n"
	   "the TAs and your classmates for help.\n"
	   "\n"); */


    // Uncomment to run two example (incomplete) testcases.
    // test_00_arraySum();
    // test_01_arrayCountNegative();
    // test_02_arrayIsIncreasing(); 
    // test_03_arrayIndexRFind();
    // test_04_arrayFindSmallest();
  

// Below are some testcases for the latter part of the assignment.
    // These testcases are incomplete, and are guides to get you started.

    //const char * s1 = "Hello World!";
    //const char * s2 = "";
    //const char * s3 = "foo";

    // -- my_strlen, should be: 12, 0, and 3

    //printf("my_strlen(\"%s\") = %d\n", s1, (int) my_strlen(s1));
    //printf("my_strlen(\"%s\") = %d\n", s2, (int) my_strlen(s2));
    //printf("my_strlen(\"%s\") = %d\n", s3, (int) my_strlen(s3));

    //---------------------------------------------------------------

    // -- my_strchr, should be: "llo World!", "(null)", and ""

    //printf("my_strchr(\"%s\", 'l') = %s\n", s1, my_strchr(s1, 'l'));
    //printf("my_strchr(\"%s\", 'o') = %s\n", s2, my_strchr(s2, 'o'));
    //printf("my_strchr(\"%s\", '\\0') = %s\n", s3, my_strchr(s3, '\0'));

    //---------------------------------------------------------------

    // -- my_strstr, should be: "World!", "Hello World!", "(null)"

    //printf("my_strstr(\"%s\", \"World\") = %s\n", s1, my_strstr(s1, "World"));
    //printf("my_strstr(\"%s\", \"\") = %s\n", s1, my_strstr(s1, ""));
    //printf("my_strstr(\"%s\", \"hello\") = %s\n", s1, my_strstr(s1, "hello"));

    //---------------------------------------------------------------

    // -- my_strcpy. For this function you need a buffer where you
    // copy the string to. 

    //char buffer[BUFFER_LEN];
    //my_strcpy(buffer, s1);
    //printf("my_strcpy(buffer, \"%s\"), buffer = \"%s\"\n", s1, buffer);
    //my_strcpy(buffer, s2);
    //printf("my_strcpy(buffer, \"%s\"), buffer = \"%s\"\n", s2, buffer);
    //my_strcpy(buffer, s3);
    //printf("my_strcpy(buffer, \"%s\"), buffer = \"%s\"\n", s3, buffer);

    //---------------------------------------------------------------

    // -- my_strcat. You will have to do this yourself... just
    // look at my_strcpy for an example, and go from there.



    //---------------------------------------------------------------

    // -- my_isspace. You will have to do this for yourself.



    //---------------------------------------------------------------

    // -- my_atoi. You will have to do this for yourself.


    //---------------------------------------------------------------

    return EXIT_SUCCESS;
}


