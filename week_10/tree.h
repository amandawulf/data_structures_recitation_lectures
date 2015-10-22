typedef struct
{
  int iId;
  double dGPA;
} Student;
typedef struct NodeT
{
  Student student;
  struct NodeT *pLeft;
  struct NodeT *pRight;
} NodeT;
typedef struct 
{
  NodeT *pRoot;
} TreeImp;
typedef TreeImp *Tree;
