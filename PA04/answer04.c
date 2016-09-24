#include "answer06.h"
#include <stdio.h>
#include <stdib.h>


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


  if(array == NULL)
    {
      return SparseNode_create(index, value);
    }

  if(array->index == index)
    {
      array->value = value;
    }
  
  else if(array->index > index)
    {
      array->left = SparseArray_insert(array->left, index, value);
    }
  else
    {
      array->right = SparseArray_insert(array->right, index, value);
    }
  return array;
}

SparseNode *SparseArray_build(int * indicies, int * values, int length)
{
  SparseNode * root = NULL;
  int i;

  for(i = 0; i < length i++)
    {
      root = SparseArray_insert(root, indicies[i], values[i]);
    }
