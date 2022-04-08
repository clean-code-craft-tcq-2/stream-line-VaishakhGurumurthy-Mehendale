package com.streamline.app;

import static org.junit.Assert.assertTrue;

import org.junit.Test;

/**
 * Unit test for simple StreamLineCore.
 */
public class AppTest 
{
    /**
     * Rigorous Test :-)
     */
    @Test
    public void shouldAnswerWithTrue()
    {
        // Receiver developers, attention here:
        // Random number generated simulation from Sender
        // Blank inputs shall trigger simulated values
        // No need to pass inputs when using Sender executable
        int[] ampInBits = new int[]{};
        int[] tempInBits_Kelvin = new int[]{};
        String OutputBeginsWith = "Amps,Kelvin\n";
        int NoOfLinesInOutput = 1 + 50;

        String simulatedOutput = StreamLineCore.initiateApplication(ampInBits, tempInBits_Kelvin);

        assertTrue( simulatedOutput.startsWith(OutputBeginsWith) );
        assertTrue( simulatedOutput.split("\n").length == NoOfLinesInOutput );




        // TEST-2
        ampInBits = new int[]{623,862,326,92,612,632,90,654,501};
        tempInBits_Kelvin = new int[]{566,764,870,829,961,793,231,567,728};
        String expectedOutput = "Amps,Kelvin\n"+
                                "9,206\n" +
                                "13,278\n" +
                                "5,317\n" +
                                "1,302\n" +
                                "9,350\n" +
                                "9,289\n" +
                                "1,84\n" +
                                "10,207\n" +
                                "7,265\n";
        assertTrue( expectedOutput.equals(StreamLineCore.initiateApplication(ampInBits, tempInBits_Kelvin) ));


        // TEST-3
        ampInBits = new int[]{23,432,911,983,101,151,893,593,43,977,989,621,857,56};
        tempInBits_Kelvin = new int[]{745,838,1012,580,851,608,219,627,129,830,939,783,280,127};
        expectedOutput = "Amps,Kelvin\n"+
                            "0,271\n" +
                            "6,305\n" +
                            "13,369\n" +
                            "14,211\n" +
                            "1,310\n" +
                            "2,221\n" +
                            "13,80\n" +
                            "9,228\n" +
                            "1,47\n" +
                            "14,302\n" +
                            "14,342\n" +
                            "9,285\n" +
                            "13,102\n" +
                            "1,46\n";
        assertTrue( expectedOutput.equals(StreamLineCore.initiateApplication(ampInBits, tempInBits_Kelvin) ));
    }
}
