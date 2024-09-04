// C++ code
//
int botao = 3;
int led = 7;
int modoTransmissao = 0;
char letras[] = {'A', 'B', 'C', 'D', 
                 'E', 'F', 'G', 'H', 
                 'I', 'J', 'K', 'L', 
                 'M', 'N', 'O', 'P', 
                 'Q', 'R', 'S', 'T', 
                 'U', 'V', 'W', 'X', 
                 'Y', 'Z'};

String morse[1] = {
"10111"
};
String valorMorse = "";
int contarZeros = 0;
void setup()
{
  pinMode(botao, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  
  int leituraBotao = digitalRead(botao);
  if(leituraBotao == HIGH && !modoTransmissao){
    modoTransmissao = 1;
  }
  if(modoTransmissao){
    //int terminouCaractere = verificarSeCaractereTerminou(valorMorse);
    String aoba = "LeituraBotao: " + leituraBotao;
    Serial.print(aoba + "\n");
    
    
    
    if(leituraBotao == LOW && contarZeros < 3){
      valorMorse += "0";
      contarZeros++;
    }else if(leituraBotao == HIGH && contarZeros < 3){
      valorMorse += "1";
      contarZeros = 0;
    }
    
    String aoba2 = "valorMorse: " + valorMorse;
    Serial.print(aoba2 +  "\n");
    //int terminouCaractere = verificarSeCaractereTerminou(valorMorse);
    if(contarZeros == 3){
      char letraTraduzida = tradutorMorse(valorMorse);
      valorMorse = "";
      //modoTransmissao = 0;
      Serial.print(letraTraduzida);
    }
  }
  delay(1000);
  Serial.print("Aperte o botao)\n");
}

int verificarSeCaractereTerminou(String valor){
  int tamanho = valor.length();
  int cont = 0;
  int terminou = 0;
  for(int i = 0; i < tamanho; i++){
  	char logico = valor[i];
    if(cont == 3){
      terminou = 1;
      break;
    }
    if(logico == '0'){
      cont++; 
    }else{
      cont = 0;
    }
  }
  return terminou;
}
char tradutorMorse(String valor){
  int tamanho = 1;
  String aux = "";
  for(int i = 0; i < valor.length() - 3; i++){
    aux += valor[i];
  }
  String aoba3 = "aux: " + aux;
  Serial.print(aoba3 +  "\n");
  String aoba4 = "valor: " + valor;
  Serial.print(aoba4 +  "\n");
  for(int i = 0; i < tamanho; i++){
    if(aux == morse[i]){
    	return letras[i];
    }
  }
  return 'Z';

}