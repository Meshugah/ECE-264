#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "answer08.h"

void Node_destruct(List * n);

List * List_createNode(const char * str)
{
  List *list = malloc(sizeof(List));
  assert(list != NULL);
  
  list->str = strdup(str);
  list->next = NULL;
  
  return list;
}

void List_destroy(List * list)
{
  List* prev = list;
  List* nex;
  
  while(prev != NULL)
    {
      nex = prev-> next;
      Node_destruct(prev);
      prev = nex;
    }
  
  
  
}

void Node_destruct(List * list)
{
  free (list->str);
  free(list);
}




int List_length(List *list) 
{
  //    assert(list != NULL);

  //List *list = list->first;
  int length = 1;
      
      while (list->next != NULL) 
	{
	  length++;
	  list = list->next;
	}
    
  return length;
}


List * List_merge(List * lhs, 
		  List * rhs, 
		  int (*compar)(const char *, const char*))
{
  struct ListNode_st* comp = 0;

  //NULL checks
  if(lhs == 0 || rhs == 0)
    {
      if(rhs == NULL)
	return(lhs);
      else 
	return(rhs);
    }
  
  
  

   int stor = 0;
  
  if(lhs->str <= rhs->str)
    {
      stor = strcmp(lhs,rhs);

       printf("\n1) lhs : %d rhs : %d stor = %d", lhs , rhs, stor);
      if(stor = -1)
	goto latter;
      
    former:
      lhs->next = List_merge(lhs->next, rhs, strcmp(lhs,rhs));
     
     return lhs;

    }
  

  else
    {
      stor = strcmp(lhs,rhs);
        printf("\n2) lhs  : %d rhs %d stor = %d", lhs , rhs, stor);


      if(stor = 1)
	goto former;

    latter:
      rhs->next = List_merge(rhs->next, lhs, strcmp(rhs,lhs));
       
      return rhs;
    } 
      


  return(comp);
 
}



List * List_sort(List * list, int (*compar)(const char *, const char*))
{

  return;
}


