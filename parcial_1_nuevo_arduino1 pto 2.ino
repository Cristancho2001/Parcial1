#define SER 4
#define SRCLK 6
#define RCLK 5

byte *patron[8]; // Arreglo de punteros para almacenar el patrón personalizado

void setup() {
  pinMode(SER, OUTPUT);
  pinMode(SRCLK, OUTPUT);
  pinMode(RCLK, OUTPUT);
  Serial.begin(9600); // Inicializar el Monitor Serial
}

void loop() {
  // Liberar la memoria del patrón anterior, si existe
  for (int fila = 0; fila < 8; fila++) {
    if (patron[fila] != NULL) {
      delete[] patron[fila];
    }
  }

  // Preguntar al usuario por cada fila del patrón
  for (int fila = 0; fila < 8; fila++) {
    Serial.print("Ingrese el patron para la fila ");
    Serial.print(fila + 1);
    Serial.println(":");
    while (Serial.available() < 8) {
      // Esperar a que el usuario ingrese los 8 valores
    }

    // Asignar memoria para almacenar el patrón de la fila actual
    patron[fila] = new byte[8];

    for (int columna = 0; columna < 8; columna++) {
      patron[fila][columna] = (Serial.read() == '1'); // Leer el valor y almacenarlo en el arreglo dinámico
    }
  }

  // Mostrar el patrón personalizado junto con la fila correspondiente
  for (int fila = 0; fila < 8; fila++) {
    Serial.print("Fila ");
    Serial.print(fila + 1);
    Serial.print(": ");
    for (int columna = 0; columna < 8; columna++) {
      Serial.print(patron[fila][columna]);
      Serial.print(" ");
    }
    Serial.println();
  }

  mostrarPatronPersonalizado(patron);
  delay(2000); // Tiempo de visualización del patrón
}

void mostrarPatronPersonalizado(byte *patron[]) {
  for (int fila = 7; fila >= 0; fila--) { // Mostrar las filas en orden inverso
    byte filaLEDs = 0;
    for (int columna = 7; columna >= 0; columna--) { // Mostrar las columnas en orden inverso
      filaLEDs |= (patron[fila][columna] << (7 - columna)); // Crear la fila de LEDs
    }
    shiftOut(SER, SRCLK, LSBFIRST, filaLEDs);
    digitalWrite(RCLK, HIGH);
    digitalWrite(RCLK, LOW);
    delay(500); // Retardo para mostrar cada fila
  }
}