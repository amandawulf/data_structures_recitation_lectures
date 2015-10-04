#include <stdio.h>

int main()
{
  char szInput[6];
  while(fgets(szInput, 6, stdin) != NULL) {
    printf("%s", szInput);
  }
}
