// Name: SANJANA MAHESH
#include "heap.h"
#include <stdlib.h>
#include<stdio.h>

/*
 ** Do not use global variables->
 ** Mark any functions that you declare in this file that are not in the header
 *as static
 ** Do not use static variables
 ** All occurences of count_ptr indicate that the number of comparison
 ** operations need to be stored in the location pointed by it
 ** The implementation can assume it is initialized to 0->
 */

// Initialise heap
// Set heap size to 0
// Set heap max_size to paramter max_size
// Allocate memory of max_size to the array
void init_heap(heap_t *heap, int max_size) {
  heap->max_size=max_size;
  heap->size=0;
  heap->arr=(int*)malloc((sizeof(int))*max_size);

}

// Insert element "key" to heap "heap"
// and store the number of key comparisons made in the
// location pointed to by count_ptr->

void insert(heap_t *heap, int key, int *count_ptr) {
  if(heap->size==heap->max_size)
  {
    return;
  }
  else
  {
    heap->size++;
    heap->arr[heap->size-1]=key;
    heapify(heap,count_ptr);
  }

}

static void heapify(heap_t *heap,int *count_ptr)
{
  int i,j,k,key;
  for(i=1;i<heap->size;i++)
  {
    key=heap->arr[i];
    j=i;
    k=(j-1)/2;
    while (j>0 && heap->arr[k]<key) {
      *count_ptr++;
      heap->arr[j]=heap->arr[k];
      j=k;
      k=(j-1)/2;
    }
    heap->arr[j]=key;
  }
}

// *Removes and Returns* the maximum element in the heap
// and store the number of key comparisons made in the
// location pointed to by count_ptr->
int extract_max(heap_t *heap, int *count_ptr) {
  int key=heap->arr[0];
  heap->arr[0]=heap->arr[heap->size];
  heap->size--;
  heapify(heap,count_ptr);
  return key;
}

// Searches for the element key in the heap
// Returns the element if found, else -1
int search(const heap_t *heap, int key, int *count_ptr) {
  for(int i=0;i<heap->max_size;i++)
  {
    if(heap->arr[i]==key)
    {
      return key;
    }
    *count_ptr++;
  }
  return -1;
}

// Returns the maximum value of the element in the heap
// and store the number of key comparisons made in the
// location pointed to by count_ptr->
int find_max(const heap_t *heap, int *count_ptr) {
  int res=heap->arr[0];
  for(int i=1;i<heap->size;i++)
  {
    if(heap->arr[i]>res)
    {
      res=heap->arr[i];
      *count_ptr++;
    }
  }
  return res;
}

// Returns the minimum value in the heap
int find_min(const heap_t *heap, int *count_ptr) {
  int res1;
  res1=heap->arr[0];
  for(int i=1;i<heap->size;i++)
  {
    if(heap->arr[i] < res1)
    {

      res1=heap->arr[i];
    }
    *count_ptr++;
  }
  return res1;
}

// Clears the heap for reuse
void clear_heap(heap_t *heap) {
  for(int i=0;i<heap->size;i++)
  {
    heap->arr[i]=0;
  }
  heap->size=0;
  heap->max_size=0;
}

// Frees all resources acquired to initialize heap
void free_heap(heap_t *heap) {
  free(heap);
}
