#include <stdio.h>

#include "Receiver.h"

void ReadConsoleData()
{
  char data[1000];
  int i=0;
  do
  {
    scanf("%c",&data[i]);
    i++;
  }while(data[i-1] != '\0');
  printf("finished =%d \n",i);
  for(int i=0;i<1000;i++)
  {
     printf("%c",data[i]);
  }
}
