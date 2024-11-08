int ENA = 3; //motor esquerda
int ENB = 6; //motor direita

int IN1 = 2; //é ENA
int IN2 = 4; //é ENA

int IN3 = 7; //é ENB
int IN4 = 5; //é ENB

//saida dos sensores no arduino
int sensorD = 11;
int sensorE = 13;

int contagem = 8;
bool maisvezes = false;

bool jaParou = false;

void setup() 
{
  Serial.begin(9600);
  //saida dos pinos
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(sensorD, INPUT);
  pinMode(sensorE, INPUT);
}

void loop() 
{
  unsigned long startTime = millis();  // tempo que ele comeca a andar

  if(!jaParou)
  {
    while (millis() - startTime < 62000) // 1000 ms é 1 seg
    { 
    seguirLinha();
    }
    Parar();
    jaParou = true;
  }
} 
void praEsquerda() 
{
  analogWrite(ENA, 0);
  analogWrite(ENB, 216);
  digitalWrite(IN1, HIGH);   // A f
  digitalWrite(IN2, LOW);  // A t
  digitalWrite(IN3, LOW);   // B t
  digitalWrite(IN4, HIGH);  // B f
}

void praDireita() 
{
  analogWrite(ENA, 216);
  analogWrite(ENB, 0);
  digitalWrite(IN1, HIGH);   // A f
  digitalWrite(IN2, LOW);  // A t
  digitalWrite(IN3, LOW);   // B t
  digitalWrite(IN4, HIGH);  // B f

}

void praFrente() 
{
  analogWrite(ENA, 216);
  analogWrite(ENB, 216);
  // Aciona os motores no sentido inverso
  digitalWrite(IN1, HIGH);  // A frente
  digitalWrite(IN2, LOW);   // A t
  digitalWrite(IN3, LOW);   // B t
  digitalWrite(IN4, HIGH);  // B frente
}

void Parar() 
{
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  // Aciona os motores no sentido inverso
  digitalWrite(IN1, LOW);  // A frente
  digitalWrite(IN2, LOW);   // A t
  digitalWrite(IN3, LOW);   // B t
  digitalWrite(IN4, LOW);  // B frente
}

void seguirLinha()
{
  //le o valor dos sensores
  int valorSensorE = digitalRead(sensorE);
  int valorSensorD = digitalRead(sensorD);

  if(valorSensorE == 1 && valorSensorD == 1)
  {
    praFrente(); 
  }
  else if(valorSensorE == 1 && valorSensorD == 0)
  {
    praDireita(); 
  }
  else if(valorSensorE == 0 && valorSensorD == 1)
  {
    praEsquerda();
  }
  else
  {
    praFrente(); 
  }
}

/*
void testaSensores()
{
  int valorSensorE = digitalRead(sensorE);
  int valorSensorD = digitalRead(sensorD);
  //mostra no terminal o valor lido pelos sensores
  Serial.print("Sensor E: ");
  Serial.print(valorSensorE);
  Serial.print(" Sensor D: ");
  Serial.println(valorSensorD);
}
*/
