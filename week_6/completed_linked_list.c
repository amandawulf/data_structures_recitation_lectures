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
  printf("%s\t%s\n", "ABC123", "GPA");

  // Loop to traverse the linked list and print the ABC123 and GPA of each student.
  // Alternate method (that we went over in recitation) would be to use a while loop
  // NodeLL *pCurrentNode = list->pHead;
  // while(pCurrentNode != NULL) {
  //   // ...
  //   pCurrentNode = pCurrentNode->pNext;
  // }
  NodeLL *pCurrentNode;
  for(pCurrentNode = list->pHead; pCurrentNode != NULL; pCurrentNode = pCurrentNode->pNext) {
    printf(
      "%s\t%.2lf\n",
      pCurrentNode->student.szAbc123Id,
      pCurrentNode->student.dGPA
    );
  }
}

double highGPA(LinkedList list)
{
  double dHighestGPA = 0.0;

  // Loop to traverse the linked list and compare the GPA to the highest GPA
  // we've seen so far.
  //
  // Alternate method (that we went over in recitation) would be to use a while loop
  // NodeLL *pCurrentNode = list->pHead;
  // while(pCurrentNode != NULL) {
  //   // ...
  //   pCurrentNode = pCurrentNode->pNext;
  // }
  NodeLL *pCurrentNode;
  for(pCurrentNode = list->pHead; pCurrentNode != NULL; pCurrentNode = pCurrentNode->pNext) {
    double dCurrentGPA = pCurrentNode->student.dGPA;

    // Compare the current student's GPA to the highest GPA we've seen so far.
    // If the current GPA is higher than the highest GPA we've seen so far, set
    // the highest GPA so far to the current GPA.
    if(dCurrentGPA > dHighestGPA) {
      dHighestGPA = dCurrentGPA;
    }
  }
  return dHighestGPA;
}

NodeLL* last(LinkedList list)
{
  NodeLL *pCurrentNode;

  // Loop to traverse the linked list until we reach the last node
  // Do nothing within the loop body.
  //
  // Alternate method (that we went over in recitation) would be to use a while loop
  // NodeLL *pCurrentNode = list->pHead;
  // while(pCurrentNode->pNext != NULL) {
  //   pCurrentNode = pCurrentNode->pNext;
  // }
  // return pCurrentNode;
  for(pCurrentNode = list->pHead; pCurrentNode->pNext != NULL; pCurrentNode = pCurrentNode->pNext) {
    ;
  }
  return pCurrentNode;
}

NodeLL* findStudent(LinkedList list, char *szNeedle)
{
  NodeLL *pCurrentNode;

  // Loop to traverse the linked list until we find the student whose ABC123
  // matches szNeedle, then return the node that that student belongs to.
  //
  // Alternate method (that we went over in recitation) would be to use a while loop
  // NodeLL *pCurrentNode = list->pHead;
  // while(pCurrentNode != NULL) {
  //   // ...
  //   pCurrentNode = pCurrentNode->pNext;
  // }
  for(pCurrentNode = list->pHead; pCurrentNode != NULL; pCurrentNode = pCurrentNode->pNext) {

    // Compare the student's ID to szNeedle. If they're equal, return the current node.
    //
    // If strcmp returns 0, then the student's ID is the same string as szNeedle.
    // In C, the expression iVariable == 0 is equivalent to the expression !iVariable because
    // C treats 0 as false, so I used a ! before strcmp as shorthand for strcmp(...) == 0.
    if(!strcmp(pCurrentNode->student.szAbc123Id, szNeedle)) {
      return pCurrentNode;
    }
  }
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

  double dHighestGPA = highGPA(list);
  printf("%.2lf\n\n", dHighestGPA);

  NodeLL *pLastNode = last(list);
  printf("%s\n\n", pLastNode->student.szAbc123Id);

  NodeLL *pFoundStudent = findStudent(list, "ccc111");
  printf("%.2lf\n\n", pFoundStudent->student.dGPA);
}
