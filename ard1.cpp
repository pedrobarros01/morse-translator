int botao = 3;
int modoTransmissao = 2;  
char letras[] = {'A', 'B', 'C', 'D', 
                 'E', 'F', 'G', 'H', 
                 'I', 'J', 'K', 'L', 
                 'M', 'N', 'O', 'P', 
                 'Q', 'R', 'S', 'T', 
                 'U', 'V', 'W', 'X', 
                 'Y', 'Z'};

String morse[1] = {
"1"
};
String valorMorse = "";
int contarZeros = 0;
void setup() {
  pinMode(botao, INPUT);
  Serial.begin(9600);
  modoTransmissao = 2;
}

void loop() {
  int leituraBotao = digitalRead(botao);
 
  if (Serial.available() > 0 && modoTransmissao == 2) {
    char c = Serial.read();
    if(c == '2'){
     modoTransmissao = 0 ;
    }
  }
  
  if(leituraBotao == HIGH && modoTransmissao == 2){
   modoTransmissao = 1;
   Serial.write('3');
  }
  if (modoTransmissao == 1){
    if(leituraBotao == HIGH && contarZeros < 12){
      Serial.write('1');
      contarZeros = 0;
    }else if(leituraBotao == LOW && contarZeros < 12 ){
      Serial.write('0');
      contarZeros++;  
    }
    
    if(contarZeros == 12){
      modoTransmissao = 2;
      contarZeros = 0;
    }
  }else if(modoTransmissao == 0 && Serial.available() > 0){
    char c = Serial.read();
    Serial.print(c);
  }
  delay(200);
 
}
void clearSerial() {
  while (Serial.available() > 0) {
    Serial.read();  
  }
}
char tradutorMorse(String valor) {
  int tamanho = 1;
  String aux = "";
  for (int i = 0; i < valor.length() - 3; i++) {
    aux += valor[i];
  }
  for (int i = 0; i < tamanho; i++) {
    if (aux == morse[i]) {
      return letras[i];
    }
  }
  return '0';  
}
