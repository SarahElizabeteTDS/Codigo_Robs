int ENA = 3;
int ENB = 6;  //define velocidade aqui
int IN1 = 2;
int IN2 = 4;
int IN3 = 7;
int IN4 = 5;

int sensorD = 11;
int sensorE = 13;

void setup() {
  Serial.begin(9600);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(sensorD, INPUT);
  pinMode(sensorE, INPUT);
}

void loop() {
  int valorSensorE = digitalRead(sensorE);
  int valorSensorD = digitalRead(sensorD);

  Serial.print("Sensor E: ");
  Serial.print(valorSensorE);
  Serial.print(" Sensor D: ");
  Serial.println(valorSensorD);

if(valorSensorE == 1 && valorSensorD == 1)
{
  praFrente(); //esta indo para a esquerda
}
else if(valorSensorE == 1 && valorSensorD == 0)
{
  praDireita(); //esta esta indp para frente
}
else if(valorSensorE == 0 && valorSensorD == 1)
{
  praEsquerda(); // esta funcao esta indo para tras
}
else
{
  praFrente(); //esta funcao esta indo para esquerda
}
}
void praEsquerda() {
  // Aciona os motores
  analogWrite(ENA, 180);
  analogWrite(ENB, 180);
  digitalWrite(IN1, LOW);   // A
  digitalWrite(IN2, HIGH);  // A
  digitalWrite(IN3, LOW);   // B
  digitalWrite(IN4, HIGH);  // B
}

void praDireita() {
  // Aciona os motores
  analogWrite(ENA, 180);
  analogWrite(ENB, 180);
  digitalWrite(IN1, HIGH);   // A
  digitalWrite(IN2, LOW);  // A
  digitalWrite(IN3, HIGH);   // B
  digitalWrite(IN4, LOW);  // B
}

void praFrente() {
  analogWrite(ENA, 240);
  analogWrite(ENB, 240);
  // Aciona os motores no sentido inverso
  digitalWrite(IN1, HIGH);  // A
  digitalWrite(IN2, LOW);   // A
  digitalWrite(IN3, LOW);   // B
  digitalWrite(IN4, HIGH);  // B
}
