// Name: SANJANA MAHESH
#include "bst.h"
#include <stdlib.h>
#include <stdio.h>
/*
 ** Do not use global variables.
 ** Mark any functions that you declare in this file that are not in the header as static
 ** Do not use static variables
 ** All occurences of count_ptr indicate that the number of comparison
 ** operations need to be stored in the location pointed by it
 ** The implementation can assume it is initialized to 0.
*/

// Initializes the root of the bst
void init_bst(bst_t *bst)
{
  bst->root=NULL;
}

// Inserts element key into the Binary search tree
// Stores the number of comparisons at the location
// pointed by count_ptr
void insert(bst_t *tree, int key, int *count_ptr)
{
  tree->root=ins(tree->root,key,count_ptr);
}
static node_t* ins(node_t *tree,int key,int *count_ptr)
{
  if(tree==NULL)
  {
    tree=(node_t*)malloc(sizeof(node_t));
    tree->key=key;
    tree->left=NULL;
    tree->right=NULL;
    return tree;
  }
  else
  {
    if(key>(tree->key))
    {
      tree->right=ins(tree->right,key,count_ptr);
      (*count_ptr)++;
    }
    else
    {
      tree->left=ins(tree->left,key,count_ptr);

      (*count_ptr)++;
    }
  }
  return tree;
}

// Delete key from the BST
// Replaces node with in-order successor
void delete_element(bst_t *tree, int key, int *count_ptr)
{
  tree->root=del(tree->root,key,count_ptr);
}
static node_t* del(node_t *tree,int key,int *count_ptr)
{
  if(tree==NULL)
  {
    return tree;
  }
  if(key<tree->key)
  {
    tree->left=del(tree->left,key,count_ptr);
    (*count_ptr)++;
  }
  else if(key>tree->key)
  {
    tree->right=del(tree->right,key,count_ptr);
    (*count_ptr)++;
  }
  else{
    if(tree->left==NULL)
    {
      node_t *temp=tree->right;
      free(tree);
      return temp;
    }
    else if(tree->right==NULL)
    {
      node_t *temp=tree->left;
      free(tree);
      return temp;
    }
    node_t *temp=min(tree->right);
    tree->key=temp->key;
    tree->right=del(tree->right,temp->key,count_ptr);
  }
  return tree;
}

static node_t* min(node_t *tree)
{
  node_t *curr=tree;
  while(curr && curr->left!=NULL)
  {
    curr=curr->left;
  }
  return curr;
}
// Searches for the element key in the bst
// Returns the element if found, else -1
int search(const bst_t *tree, int key, int *count_ptr)
{
  int found=ser(tree->root,key,count_ptr);
  return found;
}
static int ser(node_t *tree,int key,int *count_ptr)
{
  if(tree==NULL)
  {
    return -1;
  }
  else
  {
    if(tree->key == key)
    {
      (*count_ptr)++;
      return key;
    }
    else if(tree->key < key)
    {
      (*count_ptr)++;
      return ser(tree->right,key,count_ptr);
    }
    else
    {
      (*count_ptr)++;
      return ser(tree->left,key,count_ptr);
    }
  }
}
// Returns the maximum element in the BST
int find_max(const bst_t *tree, int *count_ptr)
{
  int found=find(tree->root,count_ptr);
  return found;
}
static int find(node_t *tree,int *count_ptr)
{
  if(tree==NULL)
  {
    return -1;
  }
  else
  {
    if(tree->right==NULL)
    {
      (*count_ptr)++;
      return tree->key;
    }
    else
    {
      return find(tree->right,count_ptr);
    }
  }
}

// Deletes all the elements of the bst
void free_bst(bst_t *bst)
{
  free1(bst->root);
  free(bst);
}
static void free1(node_t *tree)
{
  if(tree==NULL)
  {
    return;
  }
  free1(tree->left);
  free1(tree->right);
}
// Deletes all the elements if the bst and ensures it can be used again
void clear_bst(bst_t *bst)
{
  free1(bst->root);
  bst->root=NULL;
}
