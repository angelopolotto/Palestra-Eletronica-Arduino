#define FadePin 5

void setup(){
  pinMode(FadePin, OUTPUT);  
}

void loop(){
  for(int i = 0; i<360; i++){
    //convert 0-360 angle to radian (needed for sin function)
    float rad = DEG_TO_RAD * i;
    
    //calculate sin of angle as number between 0 and 255
    //this produce a natural fade in and fade out effect.
    //128 was added to eliminate negative number of the sin
    //function.
    int sinOut = constrain((sin(rad) * 128) + 128, 0, 255); 
    
    analogWrite(FadePin, sinOut);
    delay(15);
  }
}


