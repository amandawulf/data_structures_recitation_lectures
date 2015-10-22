#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

NodeT *allocateNodeT(Student student)
{
  NodeT *pNew = (NodeT *) malloc(sizeof(NodeT));
  pNew->student = student;
  pNew->pLeft = NULL;
  pNew->pRight = NULL;
  return pNew;
}

NodeT *insertT(NodeT **pp, Student student)
{
  // If *pp is null, this is where we want to insert.
  if (*pp == NULL) {
    NodeT *newNode = allocateNodeT(student);
    return newNode;
  }
  // does it match 
  if (student.iId == (*pp)->student.iId)
    return *pp;
  // which side should we follow
  if (student.iId < (*pp)->student.iId) {
    NodeT *newNode = insertT(&((*pp)->pLeft), student);
    if((*pp)->pLeft == NULL) {
      (*pp)->pLeft = newNode;
    }
    return newNode;
  } else {
    NodeT *newNode = insertT(&((*pp)->pRight), student);
    if((*pp)->pRight == NULL) {
      (*pp)->pRight = newNode;
    }
    return newNode;
  }
}

TreeImp *newTree()
{
  Tree tree = malloc(sizeof(TreeImp));
  tree->pRoot = NULL;
  return tree;
}

// 1. Show a recursive function printDescending which prints the iId and dGPA for each node in the tree in descending order.
// 2. Trace the below function
// 3. Describe what goofy did.
int goofy(NodeT *p)
{
  if (p == NULL)
  return 0;
  if (p->pLeft == NULL && p->pRight == NULL)
    return 1;
  else
    return goofy(p->pLeft) + goofy(p->pRight);
}

int main()
{
  Tree tree = newTree();
        
  Student *students = malloc(6*sizeof(Student));
  students[0].iId = 333;
  students[0].dGPA = 2.5;
  students[1].iId = 500;
  students[1].dGPA = 2.2;
  students[2].iId = 400;
  students[2].dGPA = 3.3;
  students[3].iId = 600;
  students[3].dGPA = 3.9;
  students[4].iId = 200;
  students[4].dGPA = 3.8;
  students[5].iId = 100;
  students[5].dGPA = 2.8;

  tree->pRoot = insertT(&(tree->pRoot), students[0]);
  int i;
  for(i = 1; i < 6; i++) {
    insertT(&(tree->pRoot), students[i]);
  }
}
