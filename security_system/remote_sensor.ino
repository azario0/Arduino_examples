int irPin     = 9;
int pinData   = 9;
int key=0;
void setup() {
  Serial.begin(9600);
  pinMode(irPin, INPUT);
}
void loop() {
  key = getIRKey();
  Serial.println(key);
}
int getIRKey() {
  uint32_t pulseBitValue=0; // Value used for reading the PulseIn()
  uint32_t bitValue=0; // Value used for converting the pulseBitValue to 1 or 0
  uint32_t pulseOne=1200; // Threshold for Binary Value=1
  uint32_t startPulse=2600; // Threshold for StartBit
  uint32_t thePulse = pulseIn(pinData, LOW); // Initialze pulse sent
  uint32_t resultValue=0; // Initalize resultValue Returned = 0
  uint32_t bitShiftValue=0; // Initialize the Binary Shift Value
  if(thePulse > startPulse) { // Ready To Receive value when thePulse >StartBit Threshold
    // digitalWrite(statLED,HIGH); // Status LED = ON
    for(uint8_t i = 1; i <= 32; i++) { // Loop to Get 32 Pulses
      pulseBitValue=pulseIn(pinData,HIGH,10000); // Get the pulseBit Value
      bitValue=(pulseBitValue>=pulseOne)?1:0; // If pulseBitValue > Binary 1 Threshold Value then bitValue=1 else bitValue=0
      if(i>16 && i<=24) { // If the bitPosition of the PulseIn Values are between 17 and 24 ...
        resultValue=resultValue+(bitValue <<(bitShiftValue++)); // then add bitValue*2^bitShiftValue to returnValue
      }
    }
  }
  return resultValue;
}