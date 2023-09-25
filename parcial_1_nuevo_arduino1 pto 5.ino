#define SER 4
#define SRCLK 6
#define RCLK 5

byte** imagen; 
const int numRows = 8;
const int numCols = 8;

byte patrones[][8] = {
  { // Rombo
    B00011000,
    B00111100,
    B01111110,
    B11111111,
    B11111111,
    B01111110,
    B00111100,
    B00011000
  },
  { // X
    B10000001,
    B01000010,
    B00100100,
    B00011000,
    B00011000,
    B00100100,
    B01000010,
    B10000001
  },
  { // S
    B01101101,
    B01101101,  
    B11011011,
    B11011011,
    B01101101,
    B01101101,
    B11011011,
    B11011011
  },
  { // Flecha
    B11110000,
    B01111000,
    B00111100,
    B00011110,
    B00011110,
    B00111100,
    B01111000,
    B11110000
  }
};

int numPatrones = sizeof(patrones) / sizeof(patrones[0]);
int retardoEntrePatrones = 2; // Retardo predeterminado en segundos

void setup() {
  pinMode(SER, OUTPUT);
  pinMode(SRCLK, OUTPUT);
  pinMode(RCLK, OUTPUT);
  Serial.begin(9600); // Inicializar el Monitor Serial
}

void loop() {
  Serial.println("Seleccione una opcion:");
  Serial.println("a: Verificar funcionamiento de LEDs.");
  Serial.println("b: Mostrar imagen de prueba.");
  Serial.println("c: Mostrar patrones alternados.");
  
  while (!Serial.available()) {
    // Esperar a que el usuario ingrese la opción
  }
  
  char opcion = Serial.read();
  switch (opcion) {
    case 'a':
      verificarFuncionamientoLEDs();
      break;
    case 'b':
      mostrarImagenDePrueba();
      break;
    case 'c':
      configurarRetardo();
      mostrarPatronesAlternados();
      break;
  }
}

void verificarFuncionamientoLEDs() {
  int tiempoEncendido = 1; // Valor predeterminado para el tiempo de encendido en segundos
  int tiempoApagado = 1;  // Valor predeterminado para el tiempo de apagado en segundos
  int numSecuencias = 1;  // Valor predeterminado para la cantidad de secuencias

  Serial.println("Configuración actual:");
  Serial.print("Tiempo de encendido (segundos): ");
  Serial.println(tiempoEncendido);
  Serial.print("Tiempo de apagado (segundos): ");
  Serial.println(tiempoApagado);
  Serial.print("Numero de secuencias: ");
  Serial.println(numSecuencias);

  Serial.println("Ingrese el tiempo de encendido (segundos): ");
  while (!Serial.available()) {
    // Esperar a que el usuario ingrese el valor
  }
  tiempoEncendido = Serial.parseInt();

  Serial.println("Ingrese el tiempo de apagado (segundos): ");
  while (!Serial.available()) {
    // Esperar a que el usuario ingrese el valor
  }
  tiempoApagado = Serial.parseInt();

  Serial.println("Ingrese el numero de secuencias: ");
  while (!Serial.available()) {
    // Esperar a que el usuario ingrese el valor
  }
  numSecuencias = Serial.parseInt();

  Serial.println("Nuevos parametros configurados:");
  Serial.print("Tiempo de encendido (segundos): ");
  Serial.println(tiempoEncendido);
  Serial.print("Tiempo de apagado (segundos): ");
  Serial.println(tiempoApagado);
  Serial.print("Numero de secuencias: ");
  Serial.println(numSecuencias);

  for (int secuencia = 0; secuencia < numSecuencias; secuencia++) {
    Serial.println("Secuencia #" + String(secuencia + 1));

    // Encender LEDs
    mostrarPatron((byte)0xFF);
    delay(tiempoEncendido * 1000); // Convertir segundos a milisegundos

    // Apagar LEDs
    mostrarPatron((byte)0x00);
    delay(tiempoApagado * 1000); // Convertir segundos a milisegundos
  }
}

void mostrarImagenDePrueba() {
  Serial.println("Ingrese la imagen de prueba (fila por fila, 8 filas, 64 dígitos 0 o 1):");

  // Crear la matriz dinámica para la imagen de prueba
  imagen = new byte*[numRows];
  for (int fila = 0; fila < numRows; fila++) {
    imagen[fila] = new byte[numCols];
  }

  for (int fila = 0; fila < numRows; fila++) {
    Serial.print("Fila " + String(fila + 1) + ": ");
    while (Serial.available() < numCols) {
      // Esperar a que el usuario ingrese los 8 valores de la fila
    }

    for (int columna = 0; columna < numCols; columna++) {
      imagen[fila][columna] = (Serial.read() == '1') ? 1 : 0;
    }
  }

  Serial.println("Imagen de prueba recibida:");

  for (int fila = 0; fila < numRows; fila++) { // Impresión en orden correspondiente a la fila
    Serial.print("Fila " + String(fila + 1) + ": ");
    for (int columna = 0; columna < numCols; columna++) {
      Serial.print(imagen[fila][columna]);
    }
    Serial.println();
  }

  mostrarPatronImagen();
}

void mostrarPatron(byte patron) {
  for (int fila = 7; fila >= 0; fila--) { // Mostrar las filas en orden inverso
    byte filaLEDs = 0;
    for (int columna = 0; columna < 8; columna++) {
      filaLEDs |= (patron & (1 << columna)) ? (1 << (7 - columna)) : 0; // Reordenar los bits
    }
    shiftOut(SER, SRCLK, LSBFIRST, filaLEDs);
    digitalWrite(RCLK, HIGH);
    digitalWrite(RCLK, LOW);
    delay(500); // Retardo para mostrar cada fila
  }
}

void mostrarPatronImagen() {
  for (int fila = numRows - 1; fila >= 0; fila--) { // Impresión en orden correspondiente a la fila, de derecha a izquierda
    Serial.println("Mostrando fila " + String(fila + 1) + ":");
    byte filaLEDs = 0;
    for (int columna = numCols - 1; columna >= 0; columna--) { // De derecha a izquierda
      filaLEDs |= (imagen[fila][columna] << (numCols - 1 - columna));
    }
    shiftOut(SER, SRCLK, LSBFIRST, filaLEDs);
    digitalWrite(RCLK, HIGH);
    digitalWrite(RCLK, LOW);
    delay(500);
  }
}

void configurarRetardo() {
  Serial.println("Ingrese el retardo entre patrones (en segundos): ");
  while (!Serial.available()) {
    // Esperar a que el usuario ingrese el valor
  }
  retardoEntrePatrones = Serial.parseInt();
  Serial.println("Retardo configurado a " + String(retardoEntrePatrones) + " segundos.");
}

void mostrarPatronesAlternados() {
  while (true) {
    for (int i = 0; i < numPatrones; i++) {
      mostrarPatron(patrones[i]);
      delay(retardoEntrePatrones * 1000); // Convertir segundos a milisegundos
    }
  }
}

void mostrarPatron(byte patron[]) {
  for (int i = 0; i < 8; i++) {
    shiftOut(SER, SRCLK, LSBFIRST, patron[i]);
  }
  digitalWrite(RCLK, HIGH);
  digitalWrite(RCLK, LOW);
}