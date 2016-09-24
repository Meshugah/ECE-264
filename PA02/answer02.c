
#include "answer02.h"
#include<string.h>


char * strcat_ex(char * * dest, int * n, const char * src)
{ 
	//LOCAL DECLARATIONS
	

	//EXECUTABLE STATEMENTS
	if(*n  < 1 + 2 *(strlen(*dest) + strlen(src)))
	{
		char * buffer = malloc(1 + 2 * (strlen(*dest) + strlen(src)));
		*n = (int*)buffer;
		strcpy(buffer,*dest);
		*dest = buffer;
			
		if(*dest != NULL)
		{			
		free(*dest);
		}


		strcat(*dest,src);
		return(*dest);
	}
	
	else
	{
	
	strcat(*dest, src);
 	return (*dest);
	
	}
}	

char * * explode(const char *str, const char *delims, int *arrlen)
	
{
	//LOCAL DECLARATIONS
	int i = 0;
	int j = 0;
	int numD = 0;
	int count = 0;
	int previous = 0;
	char * * strArr = malloc((*arrlen)*sizeof(char*));
	
	//EXECUTABLE STATEMENTS
	while(str[i] != '\0')
	{
		i++;
		if(strchr(delims, str[i]) != NULL)	
		{
			numD++;
		}
	}

	*arrlen = numD + 1;
	//check here
	i = 0;

	while(i <= strlen(str))
	{
		if((strchr(delims,str[i]) != NULL)||(str[i] == '\0'))
		{
			strArr[j] = (char*)malloc((count + 1) * sizeof(char));
			memcpy(strArr[j], &str[previous], i - (previous - 1));
			strArr[j][i - previous] = '\0';
			


			previous = i+1;
			count = 0;
			j++;
		}
	
	else	
	{
		count++;
	}
	i++;
	}
	return(strArr);

}


char * implode(char * * strArr, int len, const char * glue)
{
  int i = 0;
  int sum = 0;
   int j = 1;
  
  for(i = 0; i < len ; i++)
    {
      //printf("here")
      sum = sum + strlen(strArr[i]);
   
    }
  sum = sum + (((len -1) * strlen(glue)) + 1);


  char * i_string = malloc(sizeof(char) * sum); // creating string for implode
  
  strcpy(i_string, strArr[0]);
  //printf("the string is %s", i_string);
  
  while(j < len)
    {
      strcat(i_string, glue);
    
      strcat(i_string, strArr[j]);
      j++;
    }
  
  return(i_string);
  

}

int cmpfunc1(const void * one, const void * two)
{
  char const * *one_1 = (char const * *)one;

  char const * *two_2 = (char const * *)two;



  return strcmp(*one_1, *two_2);
}

void sortStringArray(char * * arrString, int len)
{
  // printf("here\n");
  // printf("the string is : %s", arrString);
  qsort(arrString, len, sizeof(char*), cmpfunc1);

  
}

int cmpfunc2(void* a, void* b)
{
  return(strcmp((char const *)a, (char const *)b));
}

void sortStringCharacters(char * str)
{
  //printf("%s\n", str);
  //printf("blah\n");
  //int length = strlen(str);

  //SEG FUALT HERE?????
  
  qsort((void *)str, strlen(str), sizeof(char), cmpfunc2);
  
}

void destroyStringArray(char * * strArr, int len)
{
	//LOCAL DECLARATIONS
	int i; 
	

	//EXECUTABLE STATEMENTS
	for(i = 0; i < len; i++)
	{
		free(strArr[i]);
	}
	free(strArr);
}
