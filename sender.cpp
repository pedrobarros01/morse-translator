int botao = 3;

void setup() {
  Serial.begin(9600);
  pinMode(botao, INPUT);
}

void loop() {
  int value = digitalRead(botao);
  //itoa(value, my_str_s, 10);
  if(value == HIGH){
    Serial.write('1');
  }else{
  	Serial.write('0');
  }
  delay(1000);
  
}
