char my_str_r[2]; // Array de tamanho 2 para armazenar o byte lido e o terminador nulo
bool is_char = false;
int cont = 0;

String morseChars[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", 
                       "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 
                   'U', 'V', 'W', 'X', 'Y', 'Z'};

String morse_str = "";
String morse_tdr = "";
int contarZeros = 0;
void setup() {
  Serial.begin(9600);
}

// Função que traduz o código Morse para a letra correspondente
char translateMorse(String morse) {
  for (int i = 0; i < 26; i++) {
    if (morse == morseChars[i]) {
      return alphabet[i];
    }
  }
  return '?'; // Retorna '?' se o código não for encontrado
}

void loop() {
  if (Serial.available() > 0) {
    char c = Serial.read(); // Lê 1 byte
    my_str_r[1] = '\0'; // Adiciona o terminador nulo para imprimir corretamente
    if(c == '0'){
      contarZeros++;
    }
    if(is_char == false && c == '1'){
      is_char = true;
      contarZeros = 0;
    }
    else if(is_char == true && c == '0'){
      is_char = false;
      if(cont >= 8){
        morse_str += "-";
      }
      else{
        morse_str += ".";
      }
      cont = 0;
    }

    if(is_char == true){
      cont++;
    }
    if(contarZeros >= 8){
        char letra = translateMorse(morse_str);
        //Serial.println(letra);
        morse_tdr += String(letra);
        morse_str = "";
        contarZeros = 0;
      }
   
    Serial.println(morse_str);
    Serial.println(morse_tdr);
    Serial.println(c);
  }
  
  delay(1000);
}