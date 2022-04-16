#include <stdio.h>

#include "Receiver.h"

char data[1000];
int Amps[100];
int kelvin[100];
int AmpsFlag_Count=0;
char Amps_c[5];
char Kelvin_c[5];

void FetchAmpsandKelvindata()
{
  for(int index=0; 100 > Index ; Index++)
  {
    if(data[i]=='\n')
    {
      AmpsFlag=1;
      AmpsFlag_Count=0;
    }
    if(AmpsFlag == 1)
    {
      if(data[i] == ',')
      {
        KelvingFlag=1;
        AmpsFlag=0;
      }
      else
      {
        Amps_c[AmpsFlag_Count++]=data[i];
        printf("A=%s  ",Amps_c);
      }
    }
    if(KelvingFlag == 1)
    {
      if(data[i] == '\n')
      {
        KelvingFlag=0;
        AmpsFlag=1;
        KelvinFlag_Count=0;
      }
      else
      {
        Kelvin_c[KelvinFlag_Count++]=data[i];
        printf("K=%s \n",Kelvin_c);
      }
    }
  }
}

void ReadConsoleData()
{
  int i=0;
  
  do
  {
    scanf("%c",&data[i]);
    i++;
  }while(data[i-1] != '\0');
  
  printf("finished =%d \n",i);
  
  FetchAmpsandKelvindata();
  
  for(int i=0;i<1000;i++)
  {
     printf("%c",data[i]);
  }
}
