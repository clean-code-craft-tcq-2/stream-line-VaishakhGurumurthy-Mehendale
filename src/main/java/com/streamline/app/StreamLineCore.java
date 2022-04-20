package com.streamline.app;

/**
 * Hello world!
 *
 */
public class StreamLineCore
{
    public static int[] ampInBits;
    public static int[] tempInBits;

    public static String initiateApplication(int[] inputAmpBits, int[] inputTempBits){

        if(inputAmpBits.length == 0)
            ampInBits = getAmpInBits(); //This is just for simulation in Part-2 of Project
        else
            ampInBits = inputAmpBits;

        if(inputTempBits.length == 0)
            tempInBits = getTempInBits(); //This is just for simulation in Part-2 of Project
        else
            tempInBits = inputTempBits;

//        for(int i=0; i<50; i++){
//            System.out.print(ampInBits[i]+",");
//        }
//        System.out.println("-------------------------------");
//        for(int i=0; i<50; i++){
//            System.out.print(tempInBits[i]+",");
//        }
//        System.out.println("-------------------------------");
        int[] ampereValues = StreamLineUtils.convertBitsToAmps(ampInBits);
        int[] kelvinValues = StreamLineUtils.convertBitsToTempKelvin(tempInBits);

        String processedOutput = StreamLineUtils.sendToOutput(ampereValues, kelvinValues);
        return processedOutput;
    }

    public static int[] getAmpInBits(){
        return SensorSimulatorUtil.getAmpSensorValuesInBits();
    }

    public static int[] getTempInBits(){
        return SensorSimulatorUtil.getTempSensorValuesInBits();
    }


    public static void main(String[] args){
        initiateApplication(new int[]{},new int[]{});
    }

}
