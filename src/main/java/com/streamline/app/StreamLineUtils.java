package com.streamline.app;
;

public class StreamLineUtils {

    public static float maxAmpBit = 1024;
    public static float maxTempBit = 1024;

    public static float minAmpBit = 0;
    public static float minTempBit = 0;

    public static  boolean isTempBitInRange(int tempInBits) {
           if( tempInBits > maxTempBit || tempInBits < minTempBit )
               return false;

            return true;
    }

    public static boolean isAmpBitInRange(int ampInBits){
            if( ampInBits> maxAmpBit || ampInBits < minAmpBit )
                return false;
            return true;
    }

    public static int[] convertBitsToAmps(int[] ampInBits){

        int[] trueAmps = new int[ampInBits.length];
        int maxAmp = 15;
        for (int i = 0; i < ampInBits.length; i++) {
            if(isAmpBitInRange(ampInBits[i]))
                trueAmps[i] = Math.round(maxAmp * ampInBits[i] / maxAmpBit);
        }
        return trueAmps;
    }

    public static int[] convertBitsToTempKelvin(int[] tempInBits){
        int[] trueTemp = new int[tempInBits.length];
        int maxKelvin = 373;
        for (int i=0; i<tempInBits.length; i++){
            if(isTempBitInRange(tempInBits[i]))
                trueTemp[i] = Math.round( maxKelvin * tempInBits[i] / maxTempBit );
        }
        return trueTemp;
    }


    public static String sendToOutput(int[] ampereValues, int[] kelvinValues){
        String output = "";



        int index = ampereValues.length > kelvinValues.length ? ampereValues.length : kelvinValues.length;

        System.out.print("Amps,Kelvin\n");
        output = "Amps,Kelvin\n";
        for(int i=0; i<index; i++){
            try {
                output += ampereValues[i] + "," + kelvinValues[i]+"\n";
                System.out.print(ampereValues[i] + "," + kelvinValues[i]+"\n");
            }catch (IndexOutOfBoundsException ioe){

            }
        }
        return output;
    }

}
