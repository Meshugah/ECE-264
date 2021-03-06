#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 512

void displayInput();

int main(int argc, char * argv[])
{
//LOCAL DECLARTAIONS
int i;  //Control variable for for loops 
FILE *fp;  //For file operations
int a;

//EXECUTABLE STATEMENTS
//PART 1
if(argc == 1)
{
	displayInput();
	return EXIT_SUCCESS;
}	
 


if((argc - 1) && (strcmp(argv[1], "--help")) == 0)
   {
     printf("Usage: cat-lite [--help] [FILE]...\nWith no FILE, or when FILE is -, read standard input.\n\nExamples:\n  cat-lite README   Print the file README to standard output.\n  cat-lite f - g    Print f's contents, then standard input,\n                    then g's contents.\n  cat-lite          Copy standard input to standard output.\n");
   }
 

 
 //PART 2
 else
   {
     for(i = 1; i < argc; i++)
       {
	 fp = fopen(argv[i], "r");
	 
	 if(fp != NULL)
	   {
	     while ((a = getc(fp)) != EOF)
	       {
		 putchar(a);
	       }
	     fclose(fp);
	   }
	 
	 else if(strcmp(argv[i], "-") == 0)
	   {
	     displayInput();
	   }
	 

	 else
	   {
	     fprintf(stderr,"cat cannot open %s\n", argv[i]);
	     return EXIT_FAILURE;
	   }
	 
       }
     
     
   }
 
 return EXIT_SUCCESS;
}


void displayInput()
{
  //LOCAL DECLARATIONS
  char buffer[SIZE];
  
  do
{
  size_t bytes = fread(buffer, sizeof(char), SIZE, stdin);
  fwrite(buffer, sizeof(char), bytes, stdout);
  fflush(stdout);
  if (bytes < SIZE)
    if (feof(stdin))
      break;
 }while(1);
  
}
