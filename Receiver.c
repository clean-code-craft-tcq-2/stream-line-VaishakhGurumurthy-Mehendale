#include <stdio.h>
#include "Receiver.h"

void ReadConsoleData()
{
  int data;
  for(int i=0;i<1000;i++)
  {
    scanf("%d",data);
     printf("%d",data);
  }
}
