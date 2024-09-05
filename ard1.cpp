int botao = 3;
int modoTransmissao = 2;  // Modo de transmissão inicial
bool botaoPressionado = false;  // Variável para garantir que o botão só seja considerado uma vez
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
String valorMorse = "1000";

void setup() {
  pinMode(botao, INPUT);
  Serial.begin(9600);
  modoTransmissao = 2;
}

void loop() {
  int leituraBotao = digitalRead(botao);

  // Se o botão for pressionado e ainda não foi considerado
  if (leituraBotao == HIGH && !botaoPressionado && modoTransmissao == 2) {
    Serial.write("ARD1");  // Envia mensagem ARD1
    botaoPressionado = true;  // Marca o botão como pressionado
    modoTransmissao = 1;  // Altera para o modo de envio de mensagem
  }

  // Verifica se recebeu uma mensagem e está no modo de espera (modo 2)
  if (Serial.available() > 0 && modoTransmissao == 2) {
    String c = Serial.readString();
    Serial.println(c);
    //Serial.end();
    if (c == "ARD2") {  // Se receber "ARD2" do Arduino 2
      modoTransmissao = 0;  // Vai para o modo de tradução de mensagem
    }
  }

  // Se estiver no modo de tradução (modo 0)
  if (modoTransmissao == 0 && Serial.available() > 0) {
    String c = Serial.readString();
    Serial.print(c);  // Mostra a mensagem recebida
    //delay(1000);
    modoTransmissao = 2;  // Retorna ao modo de espera
  }

  // Se estiver no modo de envio da mensagem traduzida (modo 1)
  if (modoTransmissao == 1) {
    char letraTraduzida = tradutorMorse(valorMorse);  // Traduz a mensagem Morse
    //Serial.write(letraTraduzida);  // Envia a letra traduzida
    valorMorse = "";  // Limpa o valor Morse
    modoTransmissao = 2;  // Volta ao modo original
    botaoPressionado = false;  // Libera para outra leitura do botão
  }

  delay(1000);  // Pequeno atraso para evitar leituras rápidas demais
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
  return '0';  // Retorna '0' se a tradução falhar
}
