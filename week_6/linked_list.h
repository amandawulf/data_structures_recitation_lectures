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
