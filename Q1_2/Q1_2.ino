#include <Arduino_FreeRTOS.h>

int count1, count2, count3;
int redPin = 11, greenPin = 10, bluePin = 9;
int red, blue, green, value;
int photo = A0, sound = A1;
const int trigPin = 4;  const int echoPin = 3;
long duration, distance;

void UltraSonic( void *pvParameters );
void Photo( void *pvParameters );
void Sound( void *pvParameters );

void setup()
{
  xTaskCreate(UltraSonic, (const portCHAR *)"Ultra", 128, NULL, 2, NULL);
  xTaskCreate(Photo, (const portCHAR *)"Photo", 128, NULL, 2, NULL);
  xTaskCreate(Sound, (const portCHAR *)"Sound", 128, NULL, 2, NULL);

  count1=0;
  count2=0;
  count3=0;
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(photo, INPUT);
  pinMode(sound, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop()
{
  
}

void UltraSonic( void *pvParameters )
{
  (void) pvParameters;
  for (;;)
  {
    if(count1==4)
    {
      digitalWrite(trigPin, LOW); // Clears the trigPin
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH);
      distance = duration*0.034/2;
      if(distance>200) blue = 150;
      else blue = 0;
      digitalWrite(bluePin, blue);
      count1=0;
    }
     count1++;
     delay(100);
  }
}

void Photo( void *pvParameters )
{
  (void) pvParameters;
  for (;;)
  {
    if(count2==10)
    {
      value = analogRead(photo);
      if(value>600) red = 150;
      else red = 0;
      digitalWrite(redPin, red);
      count2=0;
    }
    count2++;
    delay(100);
  }
}

void Sound( void *pvParameters )
{
  (void) pvParameters;
  for (;;)
  {
    if(count3==25)
    {
      value = analogRead(sound);
      if(value>30) green = 150;
      else green = 0;
      digitalWrite(greenPin, green);
      count3=0;
    }
    count3++;
    delay(100);
  }
}

