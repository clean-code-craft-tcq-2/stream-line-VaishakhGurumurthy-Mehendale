#include <stdio.h>
#include <string.h>

#include "Receiver.h"

int Amps[50];
int kelvin[50];
char data[1000];
char Amps_c[5];
char Kelvin_c[5];
int AmpsFlag_Count=0;
int KelvinFlag_Count=0;
int AmpsFlag=0;
int KelvingFlag=0;
int AIndex_I=0;
int KIndex_I=0;
int MaxReadCharCounts=0;

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
  return ConvetedIntData;
}

void FetchAmpsandKelvindata()
{
  for(int Index=0; MaxReadCharCounts > Index ; Index++)
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
        kelvin[KIndex_I++]=ConvertCharToInt(KelvinFlag_Count,Kelvin_c);   
        KelvinFlag_Count=0;
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
  do
  {
    scanf("%c",&data[i]);
    MaxReadCharCounts++;
  }while(data[i-1] != '\0');
  
  FetchAmpsandKelvindata();
  
  for(int Index_I=0;Index_I<50;Index_I++)
  {
     printf("Amps[%d]=%d Kelvin[%d]=%d\n ",Index_I,Amps[Index_I],Index_I,kelvin[Index_I]);
  }
     
}
