//Traffic Lights


//Declaring the LED and button pins and initial state
int redPin = 2;
int yellowPin = 3;
int greenPin = 4;
int buttonPin = 5;
int state = 0;

void setup()
{
  //Declaring the functioning of LED and Button
pinMode(redPin, OUTPUT);  
pinMode(yellowPin, OUTPUT);
pinMode(greenPin, OUTPUT);

}

void loop()
{
if (state == 0)
{
digitalWrite(redPin,HIGH);
digitalWrite(yellowPin,LOW);
digitalWrite(greenPin,LOW);
state = 1;
}
else if (state == 1)
{
digitalWrite(redPin,HIGH);
digitalWrite(yellowPin,HIGH);
digitalWrite(greenPin,LOW);
state = 2;
}
else if (state == 2)
{
digitalWrite(redPin,LOW);
digitalWrite(yellowPin,LOW);
digitalWrite(greenPin,HIGH);
state = 3;
}
else if (state == 3)
{
digitalWrite(redPin,LOW);
digitalWrite(yellowPin,HIGH);
digitalWrite(greenPin,LOW);
state = 0;
}
delay(1000); //the delay can be changed to 2 seconds,3 seconds,etc.

}
void setLights(int red, int yellow,
int green)
{
digitalWrite(redPin, red);
digitalWrite(yellowPin, yellow);
digitalWrite(greenPin, green);
}
