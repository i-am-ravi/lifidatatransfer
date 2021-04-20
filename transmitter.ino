//transmitter

#define LED 6
#define period 500
void setup()
{
  pinMode(6, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  char x;
  analogWrite(LED, 255);
  delay(period/2);
  while(Serial.available()>0)
  {
    x = Serial.read();
    Serial.print(x);
    send_info(x);
  }
}

void send_info(char info)
{
  byte val;
  analogWrite(LED, 0);
  delay(period);
  //transmission
  for(int i = 0; i < 4; i++)
  {
    val = (info & (0x03 << (2*i)))>>(2*i);
    if(val == 0)
    {
      analogWrite(LED, 0);
    }
    if(val == 1)
    {
      analogWrite(LED, 85);
    }
    if(val == 2)
    {
      analogWrite(LED, 170);
    }
    if(val == 3)
    {
      analogWrite(LED, 255);
    }
    delay(period);
  }
  analogWrite(LED, 255);
  delay(period);
}
