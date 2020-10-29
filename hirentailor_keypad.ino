#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  char customKey = customKeypad.getKey();
  char pass = "1234";
  digitalWrite(13,LOW);
  
  if (customKey == pass){
      //Serial.print("Pressed Key is = ");
      //Serial.println(customKey);
      Serial.print("Password is correct"); 
      digitalWrite(13,HIGH);
      delay(1000);
  }
  
}
