#define SER 2
#define SRCLK 3
#define RCLK 4

// Función para cargar un byte de datos en el 74HC595
void cargarDatos(byte datos) {
  shiftOut(SER, SRCLK, LSBFIRST, datos);
  digitalWrite(RCLK, HIGH);
  digitalWrite(RCLK, LOW);
}

// Arreglo para almacenar patrones predefinidos
byte patronesPredefinidos[][8] = {
  {B11111111, B10000001, B10000001, B10000001, B10000001, B10000001, B10000001, B11111111},
  {B00000000, B11111111, B10000001, B10000001, B10000001, B10000001, B11111111, B11111111},
  // Agrega más patrones predefinidos aquí
};

void setup() {
  // Configurar los pines como salidas
  pinMode(SER, OUTPUT);
  pinMode(SRCLK, OUTPUT);
  pinMode(RCLK, OUTPUT);
  Serial.begin(9600); // Inicializar el Monitor Serial
}

void loop() {
  // Mostrar patrones predefinidos en bucle
  for (int i = 0; i < sizeof(patronesPredefinidos) / sizeof(patronesPredefinidos[0]); i++) {
    cargarDatos(patronesPredefinidos[i][0]);
    delay(1000);
    cargarDatos(B00000000);
    delay(1000);
  }

  // Verificar si hay datos disponibles en el Monitor Serial
  if (Serial.available() > 0) {
    byte patronPersonalizado = Serial.parseInt(); // Leer el patrón ingresado por el usuario desde el Monitor Serial
    cargarDatos(patronPersonalizado); // Mostrar el patrón personalizado
    delay(1000); // Mostrar el patrón durante un segundo
    cargarDatos(B00000000); // Apagar todos los LEDs
  }
}