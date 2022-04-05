package com.streamline.app;

import java.util.ArrayList;

public class SensorSimulatorUtil {


    public static int[] getAmpSensorValuesInBits(){

        int[] ampInBits = new int[50];
        int maxPossible = 1024;
        int minPossible = 0;

        for(int i=0; i<50; i++){
            ampInBits[i] = (int) (Math.random()*(maxPossible-minPossible+1)+minPossible);
        }

        return ampInBits;
    }

    public static int[] getTempSensorValuesInBits(){

        int[] tempInBits = new int[50];
        int maxPossible = 1024;
        int minPossible = 0;

        for(int i=0; i<50; i++){
            tempInBits[i] = (int) (Math.random()*(maxPossible-minPossible+1)+minPossible);
        }

        return tempInBits;
    }

}
