#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char * argv[])
{
	//LOCAL DECLARATIONS
	int i;

	//EXECUTABLE STATEMENTS 
	if(argc > 1)
	{
		printf("%s", argv[1]);
	
		for(i = 2; i < argc; i++)
		{	
			printf(" %s", argv[i]);
		}
	}
	printf("\n");
return EXIT_SUCCESS;
}
