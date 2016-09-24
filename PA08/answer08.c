#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#include<math.h>

#include"answer08.h"


char * u128ToString(uint128 value)
{
  //LOCAL VARIABLES
  uint128 stor = value;
  unsigned int count = 0;
  


  //EXECUTABLE STATEMENTS
  do
    {
    count++;
    stor /= 10;
    }while(stor != 0);

  char * str = malloc(sizeof(char) * (count + 1));
  if(str == NULL)
  return NULL;

  //run through the count
  int i;
  for(i = 0; i < count ; ++i)
    {
      str[count - i - 1] = value % 10 + '0';
      value /= 10;
    }
  str[count] = '\0';
  return str;
}





uint128 alphaTou128(const char * str)
{
	if(str==NULL)	// if str is NULL, return 0
		return 0;
	uint128 ans = 0;
	int i = 0;
	while(str[i]!='\0')	// run until end of string
	{
	  		if(str[i]=='-')
	  		return 0;
		if(str[i] >= '0' && str[i] <= '9')
			ans = ans*10 + (str[i] - '0');
		++i;
	}
	return ans;
}


typedef struct 
{
  uint128 low;
  uint128 high;
  uint128 stor;
  int *flag;
}Data;

void * thread_fn(void *arg)
{
  Data *data = (Data *)arg;
  uint128 index = data->low;


  while(index <= data->high)
    {
if ((data->stor) % index == 0)
	{
	  *(data->flag) = FALSE;
	}
      index += 2;
    }
  return;
}





int primalityTestParallel(uint128 value, int n_threads)
{
	uint128 stor = value;
	
	if(stor <= 1)
		return FALSE;
	else if(stor == 2)
		return TRUE;
	else if( (stor % 10) % 2 == 0 )
		return FALSE;
	else if(stor == 3)
		return TRUE;
		
	int answer = TRUE;
	pthread_t *thread = malloc(sizeof(pthread_t)*n_threads);

	Data *data = malloc(sizeof(Data)*n_threads);
	
	int i;
	uint128 range = sqrt(value)/n_threads;
	if(range%2==1)
		range++;
	for(i = 0; i < n_threads; ++i)	// loop to set ThreadData
	{
		data[i].flag  = &answer;
		data[i].stor = stor;
		data[i].low   = 3 + i*(range);
		data[i].high  = data[i].low + (range);
	}
	
	for(i = 0; i < n_threads; ++i)	// loop to call threads
		pthread_create( &thread[i], NULL, &thread_fn, &data[i] );
	
	for(i = 0; i < n_threads; ++i)	// loop to join the thread
		pthread_join(thread[i], NULL);
	
	free(data);		// free thread data
	free(thread);	// free the threads
	
	return answer;
}
