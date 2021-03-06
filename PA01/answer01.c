
#include "answer01.h"

// NOTE: You are NOT to use the strings library on this assignment,
// as stated in the README.

// DO NOT BEGIN WORKING ON THIS FILE UNTIL YOU HAVE COMPLETELY AND
// THOROUGHLY READ THE README FILE!!!

int arraySum(int * array, int len)
{
 //LOCAL DECLARATIONS
        int i;
        int sum = 0;
             


//EXECUTABLE STATEMENTS
        for(i = 0; i < len; i++)
                {
                        sum += array[i];
                }

    return sum;
}

int arrayCountNegative(int * array, int len)
{
 //LOCAL DECLARATIONS

int negCount = 0;
int i;

//EXECUTABLE STATEMENTS
        for(i = 0; i < len; i++)
                {
                        if(array[i] < 0)
			{
			  negCount += 1;
			}
                }

    return negCount;
 
}

int arrayIsIncreasing(int * array, int len)
{    
//LOCAL DECLARATIONS
int check = 1;    
int i;

//EXECUTABLE STATEMENTS
for(i = 0; i < len - 1; i++)
	{
		if(array[i] > array[i + 1])
		{
			check = 0;	
		}
	}		


return(check);
}

int arrayIndexRFind(int needle, const int * haystack, int len)
{
//LOCAL DECLARATIONS
int index  = -1;
int i;

//EXECUTABLE STATEMENTS
for(i = 0; i < len; i++)
{
	if(needle == haystack[i])
	{
		index = i;
	//	printf("\n index: %d current i: %d  current haystack: %d", index, i, haystack[i]);
	}
}

return(index);
}



int arrayFindSmallest(int * array, int len)
{
//LOCAL DECLARATIONS
int i;
int small = 0;
int stored;

//EXECUTABLE STATEMENTS
if(len != 0)
{
stored = array[0];

for(i = 1; i < len ; i++)
{
	if(stored > array[i])
	{
		stored = array[i];
		small = i;
	}
}}
return(small);
}


size_t my_strlen(const char * str)
{
//LOCAL DECLRATIONS
size_t i = 0;

//EXECUTABLE STATEMENTS
while(str[i]!='\0')
{
	i++;
}

return i;
}

char * my_strchr(const char * str, int ch)
{
//LOCAL DECLARATIONS
char *pointr = NULL;
int i = 0;

//EXECUTABLE STATEMENTS
while(str[i]!='\0')
{     
	if(str[i]==ch)
	{
		pointr = &str[i];
		return pointr;
	}
	i++;
}
if(str[i]==ch)
{
	pointr = &str[i];
}
return pointr;
}		




char * my_strstr(const char * haystack, const char * needle)
{
//LOCAL DECLARATIONS
char *pointr = NULL;	
int i = 0;
int j = 0;
int checker = 1;
	

//EXECUTABLE STATEMENTS
if(needle[0]=='\0')
{
return haystack;
}		
		
while(haystack[i]!='\0')
{			
	j = 0; //reset
	checker = 1;
	while(needle[j]!='\0' && checker==1)
	{		
		if(haystack[i+j]!=needle[j])
		{	
			checker = 0;
		}
		j++;
	}
	if(checker==1)	
	{
		pointr = &haystack[i];
	}		
	i++;
}
return pointr;			

    
}

char * my_strcpy(char * dest, const char * src)
{
//LOCAL DECLARATIONS
int i = 0;

//EXECUTABLE STATEMENTS	
while(src[i]!='\0')	
{
	dest[i] = src[i];	
	i++;
}


dest[i] = '\0';			
return dest;			
}


char * my_strcat(char * dest, const char * src)
{
//LOCAL DECLARATIONS
int i = 0;
int j = 0;

//EXECUTABLE STATEMENTS
while(src[i]!=0)
{
	j=0;	
	while(dest[j]!='\0')
	j++;		
	dest[j+1] = dest[j];	
	dest[j] = src[i];	
	i++;
}					
return dest;   
 
}

int my_isspace(int ch)
{
//LOCAL DECLARATIONS
int out = 0;

//EXECUTABLE STATEMENTS
if(ch == (int)' '  || ch == (int)'\f' || ch == (int)'\n' || ch == (int)'\r' || ch == (int)'\t' || ch == (int)'\v')		{	
		out = 1;		
		}
	return out;
}

int my_atoi(const char * str)
{
//LOCAL DECLARATIONS
int i;
int len;
int current = 0;
int prev = 0;
int a;

//EXECUTABLE STATEMENTS
len = my_strlen(str);

while(my_isspace(str[a]))
{
	a++;
}



for(i = a; i < len; i++)
{
	if(str[i] == '-')
	{
		current = -1;
	}
	
	if(str[i] >= '0' && str[i] <= '9')
	{
		prev *= 10;
		prev += ((int)str[i] - '0');
	}

}
return current * prev;
}
