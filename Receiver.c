#include <stdio.h>
#include "Receiver.h"

void ReadConsoleData()
{
  char data;
 
  for(int i=0;i<35000;i++)
  {
     scanf("%c",&data);
     printf("%d ",data);
    if(data == '\n')
    {
      printf("\n");
    }
    
  }
}
