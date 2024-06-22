#define RED_LED 12
#define YELLOW_LED 11
#define GREEN_LED 10
#define PUSH_PIN 2
boolean yellowStart = true;//should yellow be the next one that blinks

int LEDPins[3] = {RED_LED, YELLOW_LED, GREEN_LED};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  //set up all pins
  setPinModeOutput();
  
  //turn off all pins
  turnOffLEDs();

  //set up push pin
  pinMode(PUSH_PIN, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  //if pushed stop blinking lights
  //if not pushed 
    //red and green  power on, yellow off for 300ms
    //red and green  power off, yellow on for 300ms
  if(digitalRead(PUSH_PIN) == LOW){ //check if led is not pushed 
     togleLEDState();
  }

}

void setPinModeOutput(){
  int size = (sizeof(LEDPins) / sizeof(LEDPins[0]));
  for(int x = 0; x< size; x++){
      pinMode(LEDPins[x], OUTPUT);
  }
}

void turnOffLEDs(){
  int size = (sizeof(LEDPins) / sizeof(LEDPins[0]));
  for(int x = 0; x< size; x++){
    digitalWrite(LEDPins[x], LOW);
  }
}

void togleLEDState(){
  if(yellowStart==true){
        //Red and green on
        digitalWrite(RED_LED, HIGH);
        digitalWrite(YELLOW_LED, LOW);
        digitalWrite(GREEN_LED, HIGH);
        delay(300);
        yellowStart = false;
      }else{
           //yellow on
        digitalWrite(RED_LED, LOW);
        digitalWrite(YELLOW_LED, HIGH);
        digitalWrite(GREEN_LED, LOW);
        delay(300);
        yellowStart = true;
      }
}