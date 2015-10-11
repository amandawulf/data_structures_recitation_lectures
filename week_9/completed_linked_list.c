#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

LinkedList newLinkedList ()
{
  LinkedList list = (LinkedList) malloc(sizeof(LinkedListImp));
  // Mark the list as empty
  list->pHead = NULL;   // empty list
  return list;
}

NodeLL *searchLL(LinkedList list, char* match, NodeLL **ppPrecedes)
{
  NodeLL *p;
  // used when the list is empty or we need to insert at the beginning
  *ppPrecedes = NULL;
                  
  // Traverse through the list looking for where the key belongs or
  // the end of the list.
  for (p = list->pHead; p != NULL; p = p->pNext) {
    if (match == p->student.szAbc123Id)
      return p;
    if (match < p-> student.szAbc123Id)
      return NULL;
    *ppPrecedes = p;
  }
                
  // Not found return NULL
  return NULL;
}

NodeLL *allocateNode(LinkedList list, Student value)
{
  NodeLL *pNew;
  pNew = (NodeLL *)malloc(sizeof(NodeLL));
  //if (pNew == NULL)
  //  ErrExit(ERR_ALGORITHM, "No available memory for linked list");
  strcpy(pNew->student.szAbc123Id, value.szAbc123Id);
  pNew->student.dGPA = value.dGPA;
  pNew->pNext = NULL;
  return pNew;
}

NodeLL *insertOrderedLL(LinkedList list, Student value)
{
  NodeLL *pNew, *pFind, *pPrecedes;
  // see if it already exists
  pFind = searchLL(list, value.szAbc123Id, &pPrecedes);
  if (pFind != NULL)
    return pFind;
  
  // doesn't already exist.  Allocate a node and insert.
  pNew = allocateNode(list, value);
  
  // Check for inserting at the beginning of the list
  // this will also handle when the list is empty
  if (pPrecedes == NULL) {
    pNew->pNext = list->pHead;
    list->pHead = pNew;
  } else {
    pNew->pNext = pPrecedes->pNext;
    pPrecedes->pNext = pNew;
  }
  return pNew;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

double getHighGPA(NodeLL *p)
{
  if(p == NULL) {
    return 0.0;
  }
  NodeLL *pNext = p->pNext;
  double dHigh = getHighGPA(pNext);
  if(dHigh > p->student.dGPA) {
    return dHigh;
  } else {
    return p->student.dGPA;
  }
}

NodeLL* last(NodeLL *p)
{
  if(p == NULL) {
    return NULL;
  }
  if(p->pNext == NULL) {
    return p;
  }
  return last(p->pNext);
}

// 1. Show recursive code for the function getHighGPA(NodeLL *p) which returns the highest GPA in the list.  Initially, it is passed list->pHead.  If the list is empty, it should return 0.0.  Note:  you will probably need a local variable, double dHigh.
//
// 2. Show recursive code for the function last(NodeLL *p) which is initially passed list->pHead and returns a pointer to the last node in the list.  If empty, it returns NULL.

int main()
{
  LinkedList list = newLinkedList(); 
  LinkedList emptyList = newLinkedList();

  Student student1 = { "aaa111", 0.0};
  Student student2 = { "bbb111", 3.5};
  Student student3 = { "ccc111", 2.0};
  Student student4 = { "ddd111", 4.0};
  Student student5 = { "eee111", 2.5};

  insertOrderedLL(list, student1);
  insertOrderedLL(list, student2);
  insertOrderedLL(list, student3);
  insertOrderedLL(list, student4);
  insertOrderedLL(list, student5);

  double dHighestGPA = getHighGPA(list->pHead);
  printf("%.2lf\n\n", dHighestGPA);

  dHighestGPA = getHighGPA(emptyList->pHead);
  printf("%.2lf\n\n", dHighestGPA);

  NodeLL *pLastNode = last(list->pHead);
  printf("%s\n\n", pLastNode->student.szAbc123Id);
  
  pLastNode = last(emptyList->pHead);
  if(pLastNode == NULL) {
    printf("Success!\n");
  }
}
