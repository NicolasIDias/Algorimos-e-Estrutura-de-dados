#include <stdio.h>

int main()
{

  int a,b;

  scanf("%d %d", &a, &b);

  for(int i=0;i<a;i++)
  {
    for(int j=b;j>0;j--){
      printf("*");
    }
    printf("\n");
  }

  return 0;
}