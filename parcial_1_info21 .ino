#define SER 2
#define SRCLK 3
#define RCLK 4


// Función para cargar un byte de datos en el 74HC595
void cargarDatos(byte datos) {
  shiftOut(SER, SRCLK, LSBFIRST, datos);
  digitalWrite(RCLK, HIGH);
  digitalWrite(RCLK, LOW);
}

// Arreglo para almacenar un patrón de LEDs
byte pic[8] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000
};

// Bucle principal
void setup() {
  // Configurar los pines como salidas
  pinMode(SER, OUTPUT);
  pinMode(SRCLK, OUTPUT);
  pinMode(RCLK, OUTPUT);
}

void loop() {
  // Enciende todos los LEDs
  cargarDatos(B11111111);
  delay(1000);

  // Apaga todos los LEDs
  cargarDatos(B00000000);
  delay(1000);

  // Cargar el patrón deseado (en este caso, pic[0])
  cargarDatos(pic[0]);
  delay(1000);
}