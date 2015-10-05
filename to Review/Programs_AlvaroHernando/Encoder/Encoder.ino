#define BUTTON_PIN         3
#define ENCODER_A_PIN      4
#define ENCODER_B_PIN      5 

#define LED_PIN            13


unsigned char push = 0;
int encoderPos = 1;
int encoderPinALast = LOW;
int n = LOW;

void setup() { 
  pinMode(ENCODER_A_PIN,INPUT);
  pinMode(ENCODER_B_PIN,INPUT);
  pinMode(BUTTON_PIN, INPUT);
  Serial.begin(19200);
} 

void loop() { 
  if((digitalRead(BUTTON_PIN) == 0) && (push == 0)) {
    push = 1;
    Serial.println("--------> Button KEY");
    digitalWrite(LED_PIN, HIGH);
  } else if (digitalRead(BUTTON_PIN) != 0) {
    push = 0;
    digitalWrite(LED_PIN, LOW);
  }
  
  n = digitalRead(ENCODER_A_PIN);
  if ((encoderPinALast == LOW) && (n == HIGH)) {
    if (digitalRead(ENCODER_B_PIN) == LOW) {
      encoderPos++;
    } else {
      encoderPos--;
    }
    Serial.println(encoderPos);
  } 
  encoderPinALast = n;
} 
