/* first_address.c */
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

void swapString(const char **, const char **);

int main(int argc, char * argv[])
{
 printf("\nTesting swapString(...)\n");
    char * str1 = "one";
    char * str2 = "two";
    printf("Before swap, str1 == %p (i.e., '%s'), "
	   "str2 == %p (i.e., '%s')\n", str1, str1, str2, str2);
    swapString(&str1, &str2);
    printf("After swap, str1 == %p (i.e., '%s'), "
	   "str2 == %p (i.e., '%s')\n", str1, str1, str2, str2);


return(0);
}

 
void swapString(const char **a, const char **b)
{

const char *temp = *a;
*a = *b;
*b = temp;


}

