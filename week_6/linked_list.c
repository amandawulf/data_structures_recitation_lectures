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

void printGPA(LinkedList list)
{
  NodeLL* pCurrentNode = list->pHead;
  printf("%s\t%s\n", "ABC123", "GPA");
  while((pCurrentNode = pCurrentNode->pNext) != NULL) {
    printf(
      "%s\t%.2lf\n", 
      pCurrentNode->student.szAbc123Id,
      pCurrentNode->student.dGPA
    );
  }
}

double highGPA(LinkedList list)
{
  NodeLL* pCurrentNode = list->pHead;
  double dHighGPA = 0.0;
  while((pCurrentNode = pCurrentNode->pNext) != NULL) {
    double dCurrentGPA = pCurrentNode->student.dGPA;
    if(dCurrentGPA > dHighGPA) {
      dHighGPA = dCurrentGPA;
    }
  }
  return dHighGPA;
}

NodeLL* last(LinkedList list)
{
  NodeLL *pCurrentNode = list->pHead;
  while(pCurrentNode->pNext != NULL) {
    pCurrentNode = pCurrentNode->pNext;
  }
  return pCurrentNode;
}

NodeLL* findStudent(LinkedList list, char *szNeedle)
{
  NodeLL *pCurrentNode = list->pHead;
  while((pCurrentNode = pCurrentNode->pNext) != NULL) {
    if(!strcmp(pCurrentNode->student.szAbc123Id, szNeedle)) {
      return pCurrentNode;
    }
  }
  return NULL;
}

// 1. Show code for the function printGPA which is passed a LinkedList and prints the abc123Id and GPA for each student in the linked list.   Also, include column headings.
//
// 2. Show code for the function highGPA which returns the highest GPA in the linked list.
//
// 3. Show code for the function last(LinkedList list) which returns a pointer to the last node in the list.
//
// 4. Show code for the function findStudent which is passed a linked list and a student ABC 123 ID.  It returns a pointer to the node containing the specified student.  If not found, return NULL.
int main()
{
  LinkedList list = newLinkedList(); 

  Student student1 = { "aaa111", 4.0};
  Student student2 = { "bbb111", 3.5};
  Student student3 = { "ccc111", 2.0};
  Student student4 = { "ddd111", 4.0};
  Student student5 = { "eee111", 2.5};

  insertOrderedLL(list, student1);
  insertOrderedLL(list, student2);
  insertOrderedLL(list, student3);
  insertOrderedLL(list, student4);
  insertOrderedLL(list, student5);

  printGPA(list);
  printf("\n");
  printf("%.2lf\n", highGPA(list));
  printf("\n");

  NodeLL *pLast = last(list);
  printf("%s\n", pLast->student.szAbc123Id);
  printf("\n");

  NodeLL *pFoundStudent = findStudent(list, "ccc111");
  printf("%.2lf\n", pFoundStudent->student.dGPA);
}
