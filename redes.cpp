// C++ code
//
int button = 3;
int led = 7;
void setup()
{
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
}

void loop()
{
  int readButton = digitalRead(button);
  if(readButton == HIGH){
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
  }
}