#include<stdio.h>
int main()
{
  int i,j;
 
  for(i=1;i<=10;i++)
  {
    printf("\n");
    for(j=1;j<=i;j++)
    {
      printf(" ");
    }
    for(j=1;j<=(10-i+1);j++)
    {
      printf("*");
    }
  }
  return 0;
}
