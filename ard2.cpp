int botao = 3;
int modoTransmissao = 0;  
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
  modoTransmissao = 0;
}

void loop() {
  int leituraBotao = digitalRead(botao);

  if (Serial.available() > 0 ) {
    String c = Serial.readString();
    Serial.print(c);
    delay(2000);
    clearSerial();
  }
  if(leituraBotao == HIGH && !modoTransmissao){
      modoTransmissao = 1;
   }
   if(modoTransmissao){
    if(leituraBotao == LOW && contarZeros < 3){
      valorMorse += "0";
      contarZeros++;
    }else if(leituraBotao == HIGH && contarZeros < 3){
      valorMorse += "1";
      contarZeros = 0;
    }
  
  if(contarZeros == 3){
      char letraTraduzida = tradutorMorse(valorMorse);
      valorMorse = "";
      modoTransmissao = 0;
      String aoba5 = "Letra Traduzida ARD2: " + String(valorMorse);
      Serial.println(aoba5 + "\n");
      delay(2000);
      clearSerial();
    }
     
  }
  delay(1000);
   
 
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
