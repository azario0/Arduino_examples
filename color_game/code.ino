const int buttonPin1 = 2;  // Button connected to pin 2
const int buttonPin2 = 3;  // Button connected to pin 3
const int buttonPin3 = 4;  // Button connected to pin 4
const int buttonPin4 = 5;  // Button connected to pin 5

const int ledPin1 = 6;     // LED connected to pin 6
const int ledPin2 = 7;     // LED connected to pin 7
const int ledPin3 = 8;     // LED connected to pin 8
const int ledPin4 = 9;     // LED connected to pin 9

int buttonState1 = 0;      // Variable to store the button state
int buttonState2 = 0;      // Variable to store the button state
int buttonState3 = 0;      // Variable to store the button state
int buttonState4 = 0;      // Variable to store the button state

int list[20];
int position = 0;

bool btn1_off=false;
bool btn2_off=false;
bool btn3_off=false;
bool btn4_off=false;

int indexer=0;


bool hello=false;

void setup() {
  pinMode(buttonPin1, INPUT);  // Set button pin as input
  pinMode(buttonPin2, INPUT);  // Set button pin as input
  pinMode(buttonPin3, INPUT);  // Set button pin as input
  pinMode(buttonPin4, INPUT);  // Set button pin as input

  pinMode(ledPin1, OUTPUT);    // Set LED pin as output
  pinMode(ledPin2, OUTPUT);    // Set LED pin as output
  pinMode(ledPin3, OUTPUT);    // Set LED pin as output
  pinMode(ledPin4, OUTPUT);    // Set LED pin as output
  Serial.begin(9600); 
  
}

void initializer(){
  
  digitalWrite(ledPin1, HIGH); // Turn on LED 1
   delay(500); 
  digitalWrite(ledPin2, HIGH); // Turn on LED 2
   delay(500); 
  digitalWrite(ledPin3, HIGH); // Turn on LED 3
   delay(500); 
  digitalWrite(ledPin4, HIGH); // Turn on LED 4
   delay(500); 
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, LOW);
  
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
  digitalWrite(ledPin4, HIGH);
  delay(1000); 
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, LOW);
  delay(1000); 
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
  digitalWrite(ledPin4, HIGH);
  delay(1000); 
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, LOW);
  delay(1000);
  
  
}

void lighter(){
  for (int i = 0;i<position;i++){
    delay(1500);
  digitalWrite(list[i]+6, HIGH);
    delay(1000);
    digitalWrite(list[i]+6, LOW);
  }
}

void winner(){
  indexer=0;
int randomLed = random(4);
  
    list[position]=randomLed;
  position+=1;
    lighter();
      Serial.print("Random LED: ");   
  Serial.println(randomLed);  
}
void loser(){
position=0;
  indexer=0;
}

void loop() {
  
  if (position == 0){
    initializer();
  	int randomLed = random(4);
    list[0]=randomLed;
    digitalWrite(6+randomLed, HIGH);
    position=1;
      Serial.print("Random LED: ");   
  Serial.println(randomLed);  
  }  
 
  
  buttonState1 = digitalRead(buttonPin1);  // Read the button state
  buttonState2 = digitalRead(buttonPin2);  // Read the button state
  buttonState3 = digitalRead(buttonPin3);  // Read the button state
  buttonState4 = digitalRead(buttonPin4);  // Read the button state
  
  if (buttonState1 == LOW ){
  btn1_off=false;
  }
  if (buttonState2 == LOW ){
  btn2_off=false;
  }
  if (buttonState3 == LOW ){
  btn3_off=false;
  }
  if (buttonState4 == LOW ){
  btn4_off=false;
  }

  if (indexer==position){
  winner();
  }
  
  if (buttonState1 == HIGH && btn1_off==false) {    // If button is pressed
	digitalWrite(ledPin1, HIGH);
    delay(500);
    digitalWrite(ledPin1, LOW);
    btn1_off=true;
    if (list[indexer]==0){
      indexer+=1;
    }
    else {
    loser();
    }
  } else {                       // If button is not pressed
    digitalWrite(ledPin1, LOW);  // Turn off LED
  }

  if (buttonState2 == HIGH && btn2_off==false) {    // If button is pressed
    btn2_off=true;
    digitalWrite(ledPin2, HIGH);
    delay(500);
    digitalWrite(ledPin2, LOW);
    if (list[indexer]==1){
      indexer+=1;
    }
    else {
    loser();
    }
  } else {                       // If button is not pressed
    digitalWrite(ledPin2, LOW);  // Turn off LED
  }

  if (buttonState3 == HIGH && btn3_off==false) {    // If button is pressed
    btn3_off=true;
    digitalWrite(ledPin3, HIGH);
    delay(500);
    digitalWrite(ledPin3, LOW);
    if (list[indexer]==2){
      indexer+=1;
    }
    else {
    loser();
    }
  } else {                       // If button is not pressed
    digitalWrite(ledPin3, LOW);  // Turn off LED
  }

  if (buttonState4 == HIGH && btn4_off==false) {    // If button is pressed
    btn4_off=true;
    digitalWrite(ledPin4, HIGH);
    delay(500);
    digitalWrite(ledPin4, LOW);
    if (list[indexer]==3){
      indexer+=1;
    }
    else {
    loser();
    }
  } else {                       // If button is not pressed
    digitalWrite(ledPin4, LOW);  // Turn off LED
  }
}
