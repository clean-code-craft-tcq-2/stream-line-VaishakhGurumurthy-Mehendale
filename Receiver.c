#include <stdio.h>
#include <string.h>

#include "Receiver.h"

int Amps_i[50];
int kelvin_i[50];
char RecivedData_c[1000];
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
int AmpsConvertCharToInt(int AFlag_Count)
{
  int Acounter_i=0;
  int AConvetedIntData_i=0;
  if(AFlag_Count < 5)
  {
    while(Acounter_i != AFlag_Count)
    {
      AConvetedIntData_i=AConvetedIntData_i*10;
      AConvetedIntData_i += (int) (Amps_c[Acounter_i]- '0');
      Acounter_i++;
    }
  }
  else
  {
   /* do nothing */
  }
  return AConvetedIntData_i;
}

int KelvinConvertCharToInt(int AFlag_Count)
{
  int Kcounter_i=0;
  int KConvetedIntData_i=0;
  while(Kcounter_i != AFlag_Count)
  {
    KConvetedIntData_i=KConvetedIntData_i*10;
    KConvetedIntData_i += (int) (Kelvin_c[Kcounter_i]- '0');
    Kcounter_i++;
  }
  return KConvetedIntData_i;
}

void FetchAmpsandKelvindata()
{
  for(int Index=0; MaxReadCharCounts_i > Index ; Index++)
  {
    if(RecivedData_c[Index]=='\n' && KelvingFlag_i != 1)
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
        //Amps_c[AIndex_i++]=ConvertCharToInt(AmpsFlagCount_i,Amps_c);        
        Amps_c[AIndex_i++]=AmpsConvertCharToInt(AmpsFlagCount_i);    
        memset(Amps_c, 0, 5);
        AmpsFlagCount_i=0;
      }
      else
      {
        Amps_c[AmpsFlagCount_i++]=RecivedData_c[Index];
      }
    }
    else if(KelvingFlag_i == 1)
    {
      if(RecivedData_c[Index] == '\n')
      {
        KelvingFlag_i=0;
        AmpsFlag_i=1;        
        //kelvin_i[KIndex_i++]=ConvertCharToInt(KelvinFlagCount_i,Kelvin_c);   
        KelvinFlagCount_i=0;
        memset(Kelvin_c, 0, 5);      
      }
      else
      {
        Kelvin_c[KelvinFlagCount_i++]=RecivedData_c[Index];
      }
    }
  }
}

#if 0
void SenderDataAverageValue(int *AAmps_i,int* AKelvin_i)
{
  int KelvinAvg=0;
  int AMPSAvg=0;
  for(int Index=45;Index <50 ; Index++)
  {
    KelvinAvg+=AKelvin_i[Index];
    AMPSAvg+=AAmps_i[Index];
  }
  KelvinAvg /=5;
  AMPSAvg/=5;
  printf("\nAverage value of Amps=%d and Kelvin=%d",AMPSAvg,KelvinAvg);
}
#endif


void ReadandPrintSenderData()
{
  do
  {
    scanf("%c",&RecivedData_c[MaxReadCharCounts_i]);
    MaxReadCharCounts_i++;
  }while(RecivedData_c[MaxReadCharCounts_i-1] != '\0');
  
  FetchAmpsandKelvindata();
  
  for(int Index_i=0;Index_i<50;Index_i++)
  {
     printf("Amps[%d]=%d Kelvin[%d]=%d\n ",Index_i,Amps_i[Index_i],Index_i,kelvin_i[Index_i]);
  }
     //SenderDataAverageValue(Amps_i,kelvin_i);
}


                      
