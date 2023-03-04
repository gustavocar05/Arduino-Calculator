//Alunos: Gustavo Carmo Melo e Silva e Vinicius Brenner


double soma(double num1, double num2) {
    return num1 + num2;
}


double subtracao(double num1, double num2) {
    return num1 - num2;
}


double multiplicacao(double num1, double num2) {
    return num1 * num2;
}


double divisao(double num1, double num2) {
    return num1 / num2;
}
void setup() {
  Serial.begin(9600); 
  Serial.println("Calculadora Inteligente!");
  Serial.println("Entre com dois numeros utilizando um dos caracteres (+, -, *, /) entre os numeros para realizar a operação");
  Serial.println("Exemplo: 1+2, 300-5, 4000*6, 8/2");
}

void loop() {
  if (Serial.available() > 0) { 
    String input = Serial.readString(); 
    String num1 = "", num2 = "", operador = "";
    int i;
    for (i = 0; i < input.length(); i++) { //Verifica a quantidade de Caracteres escrito
      if (input[i] >= '0' && input[i] <= '9') {
        num1 += input[i]; 
      }
      else {
        operador += input[i]; 
        break;
      }
    }
    for (i = i + 1; i < input.length(); i++) {
      num2 += input[i];
    }
    double n1 = num1.toDouble(); 
    double n2 = num2.toDouble();
    if (operador == "+") {
      Serial.println(soma(n1, n2));
    }
    else if (operador == "-") {
      Serial.println(subtracao(n1, n2)); 
    }
    else if (operador == "*") {
      Serial.println(multiplicacao(n1, n2)); 
    }
    else if (operador == "/") {
      Serial.println(divisao(n1, n2)); 
    }
    else {
      Serial.println("Operação Invalida");
    }
  }
}
