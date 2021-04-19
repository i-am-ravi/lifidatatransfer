//receiver

#define LDR A0
#define period 500
#define thresh1 265

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  if(analogRead(A0) < thresh1)
  {
      Serial.print(get_info());
  }
}

char get_info()
{
  char val = 0;
  int x;
  delay(3*period/2);
  for (int i = 0; i < 4; i++)
  {
    x= analogRead(A0);
    //Serial.println(x);
    if(x >= 10 && x <= 100)
    {
      val = (0x00 << (2*i)) | (val);
    }
    if(x > 100 && x <= 200)
    {
      val = (0x01 << (2*i)) | (val);
    }
    if(x > 200 && x <= thresh1)
    {
      val = (0x02 << (2*i)) | (val);
    }
    if(x > thresh1 && x <= 310)
    {
      val = (0x03 << (2*i)) | (val);
    }
    delay(period);
  }
  return val;
}
