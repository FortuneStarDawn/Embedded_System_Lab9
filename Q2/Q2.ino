#include <Arduino_FreeRTOS.h>
#include <Stepper.h>
#define STEPS 2048

int door, value;
int photo = A0;
const int trigPin = 4;  const int echoPin = 3;
long duration, distance;
Stepper stepper(STEPS, 8, 10, 9, 11);

void Photo( void *pvParameters );
void UltraSonic( void *pvParameters );

void setup()
{
  xTaskCreate(Photo, (const portCHAR *)"Photo", 128, NULL, 2, NULL);
  xTaskCreate(UltraSonic, (const portCHAR *)"Ultra", 128, NULL, 2, NULL);
  door = 1; //open
  pinMode(photo, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  stepper.setSpeed(10);
}

void loop()
{

}


void Photo( void *pvParameters )
{
  (void) pvParameters;
  for (;;)
  {
    if(door==1)
    {
      value = analogRead(photo);
      if(value<600)
      {
        stepper.step(512);
        door = 0;
      }
      delay(500);
    }
    else
    {
      delay(100);
    }
  }
}

void UltraSonic( void *pvParameters )
{
  (void) pvParameters;
  for (;;)
  {
    if(door==0)
    {
      digitalWrite(trigPin, LOW); // Clears the trigPin
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH);
      distance = duration*0.034/2;
      if(distance>50)
      {
        stepper.step(-512);
        door = 1;
      }
      delay(300);
    }
    else
    {
      delay(100);
    }
  }
}

