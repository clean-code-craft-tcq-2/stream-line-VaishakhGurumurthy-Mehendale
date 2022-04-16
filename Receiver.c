#include <stdio.h>
#include <string.h>

#include "Receiver.h"

char data[1000];
char Amps_c[5];
char Kelvin_c[5];
int Amps[100];
int kelvin[100];
int AmpsFlag_Count=0;
int KelvinFlag_Count=0;
int AmpsFlag=0;
int KelvingFlag=0;
int AIndex_I=0;
int KIndex_I=0;
int ConvertCharToInt(int AmpsFlag_Count,char *AAmps_c)
{
  int counter=0;
  int data=0;
  while(counter != AmpsFlag_Count)
  {
    data=data*10;
    data+= (int) (AAmps_c[counter]- '0');
    counter++;
  }
  printf("data=%d\n",data);
  return data;
}

void FetchAmpsandKelvindata()
{
  for(int Index=0; 1000 > Index ; Index++)
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
        Amps[AIndex_I]=ConvertCharToInt(AmpsFlag_Count,Amps_c);
        AIndex_I++;
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
        printf("K=%s ",Kelvin_c);
        kelvin[KIndex_I++]=ConvertCharToInt(KelvinFlag_Count,Kelvin_c);        
        printf("\n");
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
  
   for(int i=0;i<1000;i++)
  {
     printf("Converted A= %d K=%d\n",Amps[i], kelvin[i]);
  }
  
}
