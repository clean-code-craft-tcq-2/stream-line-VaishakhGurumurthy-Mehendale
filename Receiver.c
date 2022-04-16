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

int ConvertCharToInt(int Flag_Count,char *CharReadData)
{
  int counter=0;
  int ConvetedIntData=0;
  while(counter != Flag_Count)
  {
    ConvetedIntData=ConvetedIntData*10;
    ConvetedIntData += (int) (CharReadData[counter]- '0');
    counter++;
  }
  //printf("data=%d\n",ConvetedIntData);
  return ConvetedIntData;
}

void FetchAmpsandKelvindata()
{
  for(int Index=0; 1000 > Index ; Index++)
  {
    printf("Index=Amps[0]=%d %d\n ",Amps[0],Index);
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
        //printf("A=%s ",Amps_c);
        Amps[AIndex_I++]=ConvertCharToInt(AmpsFlag_Count,Amps_c);
        //printf("Index=Amps[%d]=%d\n ",AIndex_I-1,Amps[AIndex_I-1]);
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
        //printf("K=%s ",Kelvin_c);
        kelvin[KIndex_I++]=ConvertCharToInt(KelvinFlag_Count,Kelvin_c);   
        KelvinFlag_Count=0;
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
  
  FetchAmpsandKelvindata();
  
  for(int AIndex_I=0;AIndex_I<1000;AIndex_I++)
  {
     printf("Amps[%d]=%d\n ",AIndex_I,Amps[AIndex_I]);
  }
  
  for(int i=0;i<1000;i++)
  {
     //printf("%c",data[i]);
  }
  
   
  
}
