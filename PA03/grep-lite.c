

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define BUFFER 2000

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
  FILE* fb = stdin;
  //EXECUTABLE STATEMENTS
  int ind = 1; 
  for( ; ind < argc; ++ind) 
    {
      len = strlen(argv[ind]);
      
      first = argv[ind][0];
	  sec = argv[ind][1];
      
      if(len == 2 || first == sec)
	{
	 
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
  //ACTUAL CODE STARTS HERE
  char buffer[BUFFER]; // here you can use char *line=malloc(100);i
  int control = 0;
  int line_num = 0;
  int ctrl =0;
  
  if(invertMatch)
    goto THERE;
    //here
  if(!invertMatch)
    {
  while (fgets(buffer  , BUFFER, stdin) != NULL) //&& strlen(buffer) > 1)
    {
      control++;
      
      //ONLY LINENUM	
      //	if(lineNumber == TRUE)
      //	{
      //	printf("%d)%s", control ,buffer);
      //	}
      

      if(strstr(buffer, argv[argc-1]) != NULL)
    	{
	   if(quiet == TRUE)
	    {
	      return 0;
	      break;
	    }

	  if(lineNumber == TRUE)
	    {
	      printf("%d:%s", control ,buffer);
	      return 0;
	      break;
	    }
	  
	  
	  
	  else
	    {
	      printf("%s",buffer);
	      return 0;
	      break;
	    }	
	  
	}  
    }


    THERE:
    
      
      while (fgets(buffer  , BUFFER, stdin) != NULL && strlen(buffer) > 1)
	{
	  ctrl++;
	  if(strstr(buffer, argv[argc-1]) != NULL)
	    {
	      continue;
	    }
	  else
	    {
	      if(quiet ==TRUE)
		return 1;
	      else
		{
		  if(lineNumber == TRUE)
		    printf("%d:%s",ctrl,buffer);
		  else
		    printf("%s",buffer);
		}
	      
	    }
	}
      return 0;
    
  

  
  
     
  //I was over here
  // else
  //	{
  //	  return 1;
  //	}
     
    }
  



     

return EXIT_SUCCESS;
}


