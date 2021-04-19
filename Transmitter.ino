//transmitter
int pin=3;
int del=100;
String msg="\nWrite anything!!\n";
void setup() {
  // put your setup code here, to run once:
pinMode(pin, OUTPUT);
Serial.begin(9600);
Serial.println(msg);
}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(pin,255);
delay(1000);
while(Serial.available()>0)
{
  send_data(Serial.read());
}
}

void send_data(char data)
{
  byte val;
  analogWrite(pin, 0);
  delay(del);
for(int j=0;j<4;j++)
{
  val=(data&(0x03 << (2*j)))>>(2*j);
  Serial.println(val, BIN);
  if(val==0)
  {
    analogWrite(pin, 63);
  }
  if(val==1)
  {
    analogWrite(pin,127);
  }
  if(val==2)
  {
    analogWrite(pin, 170);
  }
  if(val==3)
  {
    analogWrite(pin, 255);
  }
delay(del);
}
}
