#define CATCH_CONFIG_MAIN

#include "test/catch.hpp"
#include "Receiver.h"


TEST_CASE("READ SAMPLE CONSOLE DATA")
{ 
  ReadConsoleData();
  //REQUIRE(TransmitBatteryStatus(TotalCounts,TotalBatteries) == TRUE);
}
