int count1, count2, count3;
int redPin = 11, greenPin = 10, bluePin = 9;
int red, blue, green, value;
int photo = A0, sound = A1;
const int trigPin = 4;  const int echoPin = 3;
long duration, distance;

void setup()
{
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
  if(count2==10)
  {
    value = analogRead(photo);
    if(value>600) red = 150;
    else red = 0;
    digitalWrite(redPin, red);
    count2=0;
  }
  if(count3==25)
  {
    value = analogRead(sound);
    if(value>30) green = 150;
    else green = 0;
    digitalWrite(greenPin, green);
    count3=0;
  }

  count1++;
  count2++;
  count3++;
  delay(100);
}
