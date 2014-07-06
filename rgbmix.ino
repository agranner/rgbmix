/*
Adafruit Arduino - Lesson 7. RGB Fader
*/

int redLEDPin = 11;
int greenLEDPin = 10;
int blueLEDPin = 9;

int redSwitchPin = 7;
int greenSwitchPin = 6;
int blueSwitchPin = 5;

int red = 255;
int blue = 255;
int green = 255;

#define COMMON_ANODE
#define DEBUG
void setup()
{
  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);  
  pinMode(redSwitchPin, INPUT_PULLUP);
  pinMode(greenSwitchPin, INPUT_PULLUP);
  pinMode(blueSwitchPin, INPUT_PULLUP);
  
  #ifdef DEBUG
    Serial.begin(9600);
  #endif
}

void loop()
{
  if (digitalRead(redSwitchPin) == LOW)
  {
    red --;
    if (red < 5) red = 255;
    #ifdef DEBUG
    // Serial Debug
    Serial.print("R, G, B -> ");
    Serial.print(red);
    Serial.print(green);
    Serial.println(blue);
    #endif
  }
  if (digitalRead(greenSwitchPin) == LOW)
  {
    green--;
    if (green < 5) green = 255;
    #ifdef DEBUG
    // Serial Debug
    Serial.print("R, G, B -> ");
    Serial.print(red);
    Serial.print(green);
    Serial.println(blue);
    #endif
  }
  if (digitalRead(blueSwitchPin) == LOW)
  {
    blue--;
    if (blue < 5) blue = 255;
    #ifdef DEBUG
    // Serial Debug
    Serial.print("R, G, B -> ");
    Serial.print(red);
    Serial.print(green);
    Serial.println(blue);
    #endif
  }
  /*#ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif */
  analogWrite(redLEDPin, red);
  analogWrite(greenLEDPin, green);
  analogWrite(blueLEDPin, blue);  
  delay(10);
}
