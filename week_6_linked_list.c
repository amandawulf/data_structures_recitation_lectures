#include <stdio.h>
#include <stdlib.h>

#define LL_NULL -1

typedef struct
{
  char szAbc123Id[7];
  double dGPA;
} Student;

typedef struct NodeLL
{
  Student student;
  struct NodeLL *pNext;
} NodeLL;

typedef struct
{
  NodeLL *pHead;
} LinkedListImp;
typedef LinkedListImp *LinkedList;

LinkedList newLinkedList ()
{
  LinkedList list = (LinkedList) malloc(sizeof(LinkedListImp));
  // Mark the list as empty
  list->pHead = NULL;   // empty list
  return list;
}

// 1. Show code for the function printGPA which is passed a LinkedList and prints the abc123Id and GPA for each student in the linked list.   Also, include column headings.
//
// 2. Show code for the function highGPA which returns the highest GPA in the linked list.
//
// 3. Show code for the function last(LinkedList list) which returns a pointer to the last node in the list.
//
// 4. Show code for the function findStudent which is passed a linked list and a student ABC 123 ID.  It returns a pointer to the node containing the specified student.  If not found, return NULL.

void printGPA(LinkedList list)
{
  NodeLL* currentNode = list->pHead;
  while((currentNode = currentNode->pNext) != NULL) {
    printf("%s\t%s\n", currentNode->student.abc123Id, currentNode->student.GPA);
  }
}

int main()
{
  LinkedList list = newLinkedList(); 
  printGPA(list);
}
