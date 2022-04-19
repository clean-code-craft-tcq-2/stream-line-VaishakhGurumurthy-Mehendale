#include <stdio.h>
#include <string.h>

#include "Receiver.h"

int Amps_i[50];
int kelvin_i[50];
char data_c[1000];
char Amps_c[5];
char Kelvin_c[5];
int AmpsFlagCount_i=0;
int KelvinFlagCount_i=0;
int AmpsFlag_i=0;
int KelvingFlag_i=0;
int AIndex_i=0;
int KIndex_i=0;
int MaxReadCharCounts_i=0;

/*brief - convert string in to integer value*/
int ConvertCharToInt(int Flag_Count,char *CharReadData)
{
  int counter_i=0;
  int ConvetedIntData_i=0;
  while(counter_i != Flag_Count)
  {
    ConvetedIntData_i=ConvetedIntData_i*10;
    ConvetedIntData_i += (int) (CharReadData[counter]- '0');
    counter_i++;
  }
  return ConvetedIntData_i;
}

void FetchAmpsandKelvindata()
{
  for(int Index=0; MaxReadCharCounts > Index ; Index++)
  {
    if(RecivedData_c[Index]=='\n' && KelvingFlag != 1)
    {
      AmpsFlag_i=1;
      AmpsFlagCount_i=0;
    }
    else if(AmpsFlag_i == 1)
    {
      if(RecivedData_c[Index] == ',')
      {
        KelvingFlag_i=1;
        AmpsFlag_i=0;
        Amps_c[AIndex_I++]=ConvertCharToInt(AmpsFlag_Count,Amps_c);        
        memset(Amps_c, 0, 5);
        AmpsFlagCount_i=0;
      }
      else
      {
        Amps_c[AmpsFlag_Count++]=RecivedData_c[Index];
      }
    }
    else if(KelvingFlag_i == 1)
    {
      if(RecivedData_c[Index] == '\n')
      {
        KelvingFlag_i=0;
        AmpsFlag_i=1;        
        kelvin[KIndex_I++]=ConvertCharToInt(KelvinFlag_Count,Kelvin_c);   
        KelvinFlagCount_i=0;
        memset(Kelvin_c, 0, 5);      
      }
      else
      {
        Kelvin_c[KelvinFlag_Count++]=RecivedData_c[Index];
      }
    }
  }
}

void ReadandPrintSenderData()
{
  do
  {
    scanf("%c",&RecivedData_c[MaxReadCharCounts]);
    MaxReadCharCounts++;
  }while(RecivedData_c[MaxReadCharCounts-1] != '\0');
  
  FetchAmpsandKelvindata();
  
  for(int Index_i=0;Index_i<50;Index_i++)
  {
     printf("Amps[%d]=%d Kelvin[%d]=%d\n ",Index_I,Amps[Index_I],Index_I,kelvin[Index_I]);
  }
     SenderDataAverageValue(Amps_i,Kelvin_i)
}

void SenderDataAverageValue(int *AAmps_i,int* AKelvin_i)
{
  for(Index=45;Index <50 ; Index++)
  {
    KelvinAvg+=AKelvin_i[Index];
    AMPSAvg+=AAmps_i[Index];
  }
  KelvinAvg /=5;
  AMPSAvg/=5;
  printf("Average value of Amps=%d and Kelvin=%d",AMPSAvg,KelvinAvg);
}
                      
