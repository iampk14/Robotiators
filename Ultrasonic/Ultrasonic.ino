const int forwardRight=12;
const int forwardLeft=9;
const int backwardRight=10;
const int backwardLeft=8;
float duration1 , duration2 , distance1 , distance2;
const int trig1=2;
const int echo1=3;
const int trig2=4;
const int echo2=5;

void setup()
{
  Serial.begin(9600);
  pinMode(forwardRight,OUTPUT);
  pinMode(forwardLeft,OUTPUT);
  pinMode(backwardRight,OUTPUT);
  pinMode(backwardLeft,OUTPUT);
  pinMode(trig1,OUTPUT);
  pinMode(trig2,OUTPUT);
  pinMode(echo1,INPUT);
  pinMode(echo2,INPUT);
}

void forward()
{
  digitalWrite(forwardRight,HIGH);
  digitalWrite(forwardLeft,HIGH);
}

void right()
{
  digitalWrite(forwardLeft,HIGH);
  digitalWrite(forwardRight,LOW);
}

void left()
{
  digitalWrite(forwardLeft,LOW);
  digitalWrite(forwardRight,HIGH);
}

void allstop()
{
  digitalWrite(forwardRight,LOW);
  digitalWrite(forwardLeft,LOW);
  digitalWrite(backwardRight,LOW);
  digitalWrite(backwardLeft,LOW);
}

void loop()
{
  digitalWrite(trig1,LOW);
  delayMicroseconds(2);
  digitalWrite(trig1,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1,LOW);
  duration1=pulseIn(echo1,HIGH);
  distance1= 0.034*(duration1/2);
  
  digitalWrite(trig2,LOW);
  delayMicroseconds(2);
  digitalWrite(trig2,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2,LOW);
  duration2=pulseIn(echo2,HIGH);
  distance2=0.034*(duration2/2);

  if((distance1 >= 7) && (distance1<=30) && (distance2 >=7) && (distance2 <=30))
  {
    forward();
  }

  else if((distance2 <= 30) && (distance2 >=7))
  {
    right();
  }

  else if((distance1 <= 30) && (distance1 >=7))
  {
    left();
  }
  else
  {
    allstop();
  }
}
