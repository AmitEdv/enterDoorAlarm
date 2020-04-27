#include <PIR_HCSR501.h>

int ledPin = 13;                // choose the pin for the LED
int pirInputPin = 2;               // choose the input pin (for PIR sensor)
Pir sensorPir(pirInputPin);

void onMotionDetected(void)
{
  // turn LED ON
  digitalWrite(ledPin, HIGH);  
}

void onNoMotionDetected(void)
{
  // turn LED OFF
  digitalWrite(ledPin, LOW);  
}

void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  sensorPir.setMotionStartCB((onMotionDetection_f)onMotionDetected);
  sensorPir.setMotionEndCB((onMotionDetection_f)onNoMotionDetected);
}

void loop() {
  sensorPir.detectMotion();
}
