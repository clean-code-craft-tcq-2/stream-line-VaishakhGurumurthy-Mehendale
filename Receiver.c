#include <stdio.h>

#include "Receiver.h"

void ReadConsoleData()
{
  char data;
  //int data;
  for(int i=0;i<1000;i++)
  {
     scanf("%c",&data);
     printf("%c",data);
    if(data == '\n')
    {
      printf("\n");
    }
    
  }
}
