#include <stdio.h>
#include "Receiver.h"

void ReadConsoleData()
{
  char data;
  while(data !=',')
  {
     scanf("%c",&data);
  }
  for(int i=0;i<1000;i++)
  {
     scanf("%c",&data);
     printf("%d ",data);
    if(data == '\n')
    {
      printf("\n");
    }
    
  }
}
