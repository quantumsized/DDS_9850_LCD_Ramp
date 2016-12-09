// include the DDS Library:
#include <DDS.h>
//======================================
// AD9850 Module....
// set pin numbers:

const int W_CLK = 8;    // Pin 8 - connect to AD9850 module word load clock pin (CLK)
const int FQ_UD = 9;    // Pin 9 - connect to freq update pin (FQ)
const int DATA = 10;    // Pin 10 - connect to reset pin (RST)
const int RESET = 11;   // Pin 11 - connect to serial data load pin (DATA)

double lowFreq = 1000;
double highFreq = 2500;

const int stepVal = 10;
const int pauseVal = 5;

// Instantiate the DDS...
DDS dds(W_CLK, FQ_UD, DATA, RESET);

void setup() {
  // start up the DDS...
  dds.init();
  // (Optional) trim if your xtal is not at 125MHz...
  dds.trim(125000000); // enter actual osc freq
}

void loop() {
  for (double freq = lowFreq; freq <= highFreq; freq += stepVal) {
    dds.setFrequency(freq);
    delay(pauseVal);
  }
}
