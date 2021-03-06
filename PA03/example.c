
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int main(int argc, char * * argv)
{
   //LOCAL DECLARTAIONS
   int showHelp = FALSE;
   int invertMatch = FALSE;
  // int badSwitch = FALSE;
   int quiet = FALSE;
   int lineNumber = FALSE;
	char first;
	char sec;
	int len;
	char buffer	

   //EXECUTABLE STATEMENTS
   int ind = 1; 
   for( ; ind < argc; ++ind) 
     {
       len = strlen(argv[ind]);
	
	
	if(len == 2)
	{
	first = argv[ind][0];
	sec = argv[ind][1];
	printf("\ngiven argument: %c%c \n", first, sec);

	if(argc - 1 && strcmp(argv[ind], "--help") == 0)
         showHelp = TRUE;
      
     if((strcmp(argv[ind], "-v") == 0)||(strcmp(argv[ind], "--invert-match") == 0))
         invertMatch = TRUE;
     if((strcmp(argv[ind], "-n") == 0)||(strcmp(argv[ind], "--line-number") == 0))
         lineNumber = TRUE;
     if((strcmp(argv[ind], "-q") == 0)||(strcmp(argv[ind], "--quiet") == 0))
	 quiet = TRUE;
 	
	
	if(argv[ind][0] == '-')
	{
		if(lineNumber + invertMatch + quiet == 0)
		{
		fprintf(stderr, "Aborting...\n");
		     return 2;
		}
	} 
	
	if(ind + 1 == argc)
	{
	fprintf(stderr, "Aborting...\n");
                     return 2;
	}
	



	}
	
     }	  
	    
		
     
	


  
	      //START OF IF CONDITIONS	      

   if(showHelp) 
      {
	printf("Usage: grep-lite [OPTION]... PATTERN\n");
	printf("Search for PATTERN in standard input. PATTERN is a\n");
	printf("string. grep-lite will search standard input line by\n");
	printf("line, and (by default) print out those lines which\ncontain pattern as a substring.\n\n");

	printf("  -v, --invert-match     print non-matching lines\n  -n, --line-number      print line numbers with output\n  -q, --quiet            suppress all output\n\nExit status is 0 if any line is selected, 1 otherwise;\nif any error occurs, then the exit status is 2.\n");
	      
    return EXIT_SUCCESS;
      }
     	
//HERE IS THE ACTUAL PROGRAM
//char name[2000];

//fgets(name, 2000, stdin);
//printf("This is what i got: \n\n%s", name);








     

return EXIT_SUCCESS;
}


