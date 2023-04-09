int irPin = 9;
int pinData = 9;
int key = 0;

// Indice for password
int indice_pass = 0;
int entered_pass[3];

// Buzzer
const int buzzer = 7; // buzzer to arduino pin 9

// LED pin
int ledPin1 = 2;

// Somme password
int spass = 0;

// Indica activation alarm
int activate = 0;

// To read the light brightness
int analogValue;

void setup()
{
    Serial.begin(9600);
    pinMode(irPin, INPUT);
    pinMode(ledPin1, OUTPUT);
    pinMode(buzzer, OUTPUT);
    blink();
}
void loop()
{
    key = getIRKey();
  if (key!=0) {
    entered_pass[indice_pass] = key;
    indice_pass++;
    Serial.println(key);
  }

    if (indice_pass == 3)
    {
        spass = 0;
        indice_pass = 0;
        for (int i = 0; i < 3; i++)
        {
            spass += entered_pass[i];
        }
        if (spass == 51)
        {
            // Activate alaram
            blink();
            three_bip();
            digitalWrite(ledPin1, HIGH);
            activate = 1;
        }
        else if (spass == 63)
        {
            // Desactivate alarm
            blink();
            three_bip();
            activate = 0;
            noTone(buzzer);
        }
    }
    if (activate == 1)
    {
        analogValue = analogRead(A0);
      	Serial.println(analogValue);
        if (analogValue < 100)
        {
            delay(500);
            analogValue = analogRead(A0);
            if (analogValue > 100)
            {
                tone(buzzer, 1000);
            }
        }
    }
}

void blink()
{
    for (int i = 0; i < 3; i++)
    {
        digitalWrite(ledPin1, HIGH); // Allumage de la LED : état haut = HIGH
        delay(500);
        digitalWrite(ledPin1, LOW); // Extinction de la LED : état bas = LOW
        delay(500);
    }
}
void three_bip()
{
    for (int i = 0; i < 3; i++)
    {
        tone(buzzer, 1000);
        delay(500);
        noTone(buzzer);
      delay(500);

    }
}
int getIRKey()
{
    uint32_t pulseBitValue = 0;                // Value used for reading the PulseIn()
    uint32_t bitValue = 0;                     // Value used for converting the pulseBitValue to 1 or 0
    uint32_t pulseOne = 1200;                  // Threshold for Binary Value=1
    uint32_t startPulse = 2600;                // Threshold for StartBit
    uint32_t thePulse = pulseIn(pinData, LOW); // Initialze pulse sent
    uint32_t resultValue = 0;                  // Initalize resultValue Returned = 0
    uint32_t bitShiftValue = 0;                // Initialize the Binary Shift Value
    if (thePulse > startPulse)
    { // Ready To Receive value when thePulse >StartBit Threshold
        // digitalWrite(statLED,HIGH); // Status LED = ON
        for (uint8_t i = 1; i <= 32; i++)
        {                                                   // Loop to Get 32 Pulses
            pulseBitValue = pulseIn(pinData, HIGH, 10000);  // Get the pulseBit Value
            bitValue = (pulseBitValue >= pulseOne) ? 1 : 0; // If pulseBitValue > Binary 1 Threshold Value then bitValue=1 else bitValue=0
            if (i > 16 && i <= 24)
            {                                                                // If the bitPosition of the PulseIn Values are between 17 and 24 ...
                resultValue = resultValue + (bitValue << (bitShiftValue++)); // then add bitValue*2^bitShiftValue to returnValue
            }
        }
    }
    return resultValue;
}