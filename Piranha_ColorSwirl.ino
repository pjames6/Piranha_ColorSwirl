int redPin   = 9;
int greenPin = 10;
int bluePin  = 11;
int redVal   = 255;
int greenVal = 1;
int blueVal  = 1;
int i = 0;  
int wait = 10;
int DEBUG = 0;

void setup()
{
  pinMode(redPin,   INPUT);
  pinMode(greenPin, INPUT);
  pinMode(bluePin,  INPUT);
  if (DEBUG) {
    Serial.begin(9600);
  }
}

void loop()
{
  i += 1;
  if (i < 255)
  {
    redVal   -= 1;
    greenVal += 1;
    blueVal   = 1;
  }
  else if (i < 509)
  {
    redVal    = 1;
    greenVal -= 1;
    blueVal  += 1;
  } 
  else if (i < 763)
  {
    redVal  += 1;
    greenVal = 1;
    blueVal -= 1;
  }
  else
  {
    i = 1;
  }  

  analogWrite(redPin,   redVal);
  analogWrite(greenPin, greenVal); 
  analogWrite(bluePin,  blueVal);  

  if (DEBUG) {
    DEBUG += 1;
    if (DEBUG > 10)
    {
      DEBUG = 1;

      Serial.print(i);
      Serial.print("\t");
      Serial.print("R:");
      Serial.print(redVal);
      Serial.print("\t");
      Serial.print("G:");
      Serial.print(greenVal);
      Serial.print("\t");    
      Serial.print("B:");    
      Serial.println(blueVal);
    }
  }
  delay(wait);
}

