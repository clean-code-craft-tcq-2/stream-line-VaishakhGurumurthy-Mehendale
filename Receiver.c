#include <stdio.h>
#include <iostream.h>
#include "Receiver.h"

void ReadConsoleData()
{
  char data;
 
  for(int i=0;i<35000;i++)
  {
     scanf("%d",&data);
     printf("%d ",data);
    if(data == '\n')
    {
      printf("\n");
    }
    
  }
}
