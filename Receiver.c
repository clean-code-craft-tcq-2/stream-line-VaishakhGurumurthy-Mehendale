#include <stdio.h>

#include "Receiver.h"

void ReadConsoleData()
{
  char data[1000];
  while(data[i] != '\0')
  {
     scanf("%c",&data[i]);
  }
  
  for(int i=0;i<1000;i++)
  {
     printf("%c",data[i]);
  }
}
