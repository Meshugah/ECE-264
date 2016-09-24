#include "answer06.h"
#include <stdio.h>
#include <stlib.h>


SparseNode *SparseNode_create(int index, int value)
{
  if(value == 0)//check
    return NULL;

  SparseNode * fp = malloc(sizeof(SparseNode));

  if(fp != NULL)
    {
      fp->left = NULL;
      fp->right = NULL;
      fp->value = value;
      fp->index = index;
      
      return fp;
    }
  
  else
    {
      return NULL;
    }
}


SparseNode * SparseArray_insert (SparseNode * array, int index, int value)
{
  if(value == 0)
    {
      return array;
    }

