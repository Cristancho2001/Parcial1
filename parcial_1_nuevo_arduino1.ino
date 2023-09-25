#define SER 4
#define SRCLK 6
#define RCLK 5

void setup() {
  pinMode(SER, OUTPUT);
  pinMode(SRCLK, OUTPUT);
  pinMode(RCLK, OUTPUT);
}

void loop() {
  // Enciende todos los LEDs simultáneamente
  byte patronEncendido = B11111111; // Enciende todos los LEDs en una fila
  mostrarPatron(patronEncendido);
  delay(2000); // Tiempo de encendido de todos los LEDs

  // Apaga todos los LEDs simultáneamente
  byte patronApagado = B00000000; // Apaga todos los LEDs en una fila
  mostrarPatron(patronApagado);
  delay(2000); // Tiempo de apagado de todos los LEDs
}

void mostrarPatron(byte patron) {
  for (int i = 0; i < 8; i++) {
    shiftOut(SER, SRCLK, LSBFIRST, patron);
  }
  digitalWrite(RCLK, HIGH);
  digitalWrite(RCLK, LOW);
}