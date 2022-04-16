#include <stdio.h>
#include <string.h>

#include "Receiver.h"

char data[1000];
int Amps[100];
int kelvin[100];
int AmpsFlag_Count=0;
int KelvinFlag_Count=0;
char Amps_c[5];
char Kelvin_c[5];
int AmpsFlag=0;
int KelvingFlag=0;

void FetchAmpsandKelvindata()
{
  for(int Index=0; 100 > Index ; Index++)
  {
    if(data[Index]=='\n' && KelvingFlag != 1)
    {
      AmpsFlag=1;
      AmpsFlag_Count=0;
    }
    else if(AmpsFlag == 1)
    {
      if(data[Index] == ',')
      {
        KelvingFlag=1;
        AmpsFlag=0;
        printf("A=%s ",Amps_c);
        memset(Amps_c, 0, 5);
        AmpsFlag_Count=0;
      }
      else
      {
        Amps_c[AmpsFlag_Count++]=data[Index];
      }
    }
    else if(KelvingFlag == 1)
    {
      if(data[Index] == '\n')
      {
        KelvingFlag=0;
        AmpsFlag=1;
        KelvinFlag_Count=0;
        printf("K=%s \n",Kelvin_c);
        memset(Kelvin_c, 0, 5);      
      }
      else
      {
        Kelvin_c[KelvinFlag_Count++]=data[Index];
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
