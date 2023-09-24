#define SER 2
#define SRCLK 3
#define RCLK 4

int pic[8] = {0, 36, 36, 36, 0, 66, 60, 0};
int verificacion[8] = {255, 255, 255, 255, 255, 255, 255, 255};

void setup() {
  pinMode(SER, OUTPUT);
  pinMode(SRCLK, OUTPUT);
  pinMode(RCLK, OUTPUT);
}

void loop() {
  // Enciende todos los LEDs
  for (int i = 0; i < 8; i++) {
    shiftOut(SER, SRCLK, LSBFIRST, ~verificacion[i]);
    shiftOut(SER, SRCLK, LSBFIRST, 128 >> i);
    rclk();
  }
  delay(1000); // Pausa de 1 segundo (ajusta el tiempo según lo que desees)
  
  // Apaga todos los LEDs
  for (int i = 0; i < 8; i++) {
    shiftOut(SER, SRCLK, LSBFIRST, 0);
  }
  rclk();
  delay(1000); // Pausa de 1 segundo
}

void rclk() {
  digitalWrite(RCLK, HIGH);
  delayMicroseconds(10);
  digitalWrite(RCLK, LOW);
  delayMicroseconds(10);
}