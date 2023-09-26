#include <iostream>
#include <bitset>
#include <thread>
#include <chrono>

#define SER 4
#define SRCLK 6
#define RCLK 5
/*
void mostrarPatron(uint8_t patron);

int main()
 2)
  // Configura los pines como salidas
  pinMode(SER, OUTPUT);
  pinMode(SRCLK, OUTPUT);
  pinMode(RCLK, OUTPUT);

  while (1) {
    // Enciende todos los LEDs simultáneamente
    uint8_t patronEncendido = 0xFF; // Enciende todos los LEDs en una fila
    mostrarPatron(patronEncendido);
    delay(2000); // Tiempo de encendido de todos los LEDs

    // Apaga todos los LEDs simultáneamente
    uint8_t patronApagado = 0x00; // Apaga todos los LEDs en una fila
    mostrarPatron(patronApagado);
    delay(2000); // Tiempo de apagado de todos los LEDs
  }

  return 0;
}

void mostrarPatron(uint8_t patron) {
  for (int i = 0; i < 8; i++) {
    // Simula la función shiftOut
    for (int j = 7; j >= 0; j--) {
      uint8_t bit = (patron >> j) & 0x01;
      digitalWrite(SER, bit);
      digitalWrite(SRCLK, HIGH);
      digitalWrite(SRCLK, LOW);
    }
  }
  digitalWrite(RCLK, HIGH);
  digitalWrite(RCLK, LOW);
}
}*/

/*
3)
  bool patron[8][8]; // Matriz para almacenar el patrón personalizado

void mostrarPatronPersonalizado();

int main() {
  // Configurar los pines como salidas
  pinMode(SER, OUTPUT);
  pinMode(SRCLK, OUTPUT);
  pinMode(RCLK, OUTPUT);
  std::cout << "Iniciando..." << std::endl;

  while (1) {
    // Preguntar al usuario por cada fila del patrón
    for (int fila = 0; fila < 8; fila++) {
      std::cout << "Ingrese el patrón para la fila " << fila + 1 << ":" << std::endl;

      for (int columna = 0; columna < 8; columna++) {
        while (!(std::cin >> patron[fila][columna])) {
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout << "Entrada no válida. Ingrese 0 o 1." << std::endl;
        }
      }
    }

    // Mostrar el patrón personalizado junto con la fila correspondiente
    for (int fila = 0; fila < 8; fila++) {
      std::cout << "Fila " << fila + 1 << ": ";
      for (int columna = 0; columna < 8; columna++) {
        std::cout << patron[fila][columna] << " ";
      }
      std::cout << std::endl;
    }

    mostrarPatronPersonalizado();
    std::this_thread::sleep_for(std::chrono::milliseconds(2000)); // Tiempo de visualización del patrón
  }

  return 0;
}

void mostrarPatronPersonalizado() {
  for (int fila = 7; fila >= 0; fila--) { // Mostrar las filas en orden inverso
    uint8_t filaLEDs = 0;
    for (int columna = 7; columna >= 0; columna--) { // Mostrar las columnas en orden inverso
      filaLEDs |= (patron[fila][columna] << (7 - columna)); // Crear la fila de LEDs
    }
    // Simular la función shiftOut
    for (int j = 7; j >= 0; j--) {
      uint8_t bit = (filaLEDs >> j) & 0x01;
      digitalWrite(SER, bit);
      digitalWrite(SRCLK, HIGH);
      digitalWrite(SRCLK, LOW);
    }
    digitalWrite(RCLK, HIGH);
    digitalWrite(RCLK, LOW);
    std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Retardo para mostrar cada fila
  }
}*/


   /*
    4)
// Declarar un arreglo bidimensional para representar los patrones
std::bitset<8> patrones[] = {
    std::bitset<8>("00011000"), // Rombo
    std::bitset<8>("10000001"), // X
    std::bitset<8>("01101101"), // S
    std::bitset<8>("11110000")  // Flecha
};

int numPatrones = sizeof(patrones) / sizeof(patrones[0]);

void mostrarPatron(const std::bitset<8>& patron);

int main() {
    // Configurar los pines como salidas
    pinMode(SER, OUTPUT);
    pinMode(SRCLK, OUTPUT);
    pinMode(RCLK, OUTPUT);

    std::cout << "Iniciando..." << std::endl;

    while (1) {
        for (int i = 0; i < numPatrones; i++) {
            mostrarPatron(patrones[i]);
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        }
    }

    return 0;
}

void mostrarPatron(const std::bitset<8>& patron) {
    // Mostrar el patrón
    for (int i = 7; i >= 0; i--) {
        for (int j = 7; j >= 0; j--) {
            digitalWrite(SER, patron[i]);
            digitalWrite(SRCLK, HIGH);
            digitalWrite(SRCLK, LOW);
        }
    }
    digitalWrite(RCLK, HIGH);
    digitalWrite(RCLK, LOW);
}*/

/*5)
int parametros[3] = {1, 1, 1}; // Arreglo para almacenar tiempoEncendido, tiempoApagado y numSecuencias

void mostrarMenu();
void verificarFuncionamientoLEDs();
void configurarParametros();

int main() {
    // Configurar los pines como salidas
    pinMode(SER, OUTPUT);
    pinMode(SRCLK, OUTPUT);
    pinMode(RCLK, OUTPUT);
    std::cout << "Iniciando..." << std::endl;

    while (1) {
        mostrarMenu();
        while (!std::cin) {
            // Esperar a que el usuario ingrese la opción
        }
        char opcion;
        std::cin >> opcion;

        switch (opcion) {
            case 'a':
                configurarParametros();
                verificarFuncionamientoLEDs();
                break;
            // Agregar más casos para otras funciones aquí
        }
    }

    return 0;
}

void mostrarMenu() {
    std::cout << "Seleccione una opcion:" << std::endl;
    std::cout << "a: Verificar funcionamiento de LEDs." << std::endl;
    std::cout << "b: Mostrar imagen de prueba." << std::endl;
    std::cout << "c: Mostrar patrones alternados." << std::endl;
}

void verificarFuncionamientoLEDs() {
    int tiempoEncendido = parametros[0];
    int tiempoApagado = parametros[1];
    int numSecuencias = parametros[2];

    std::cout << "Tiempo de encendido (segundos): " << tiempoEncendido << std::endl;
    std::cout << "Tiempo de apagado (segundos): " << tiempoApagado << std::endl;
    std::cout << "Numero de secuencias: " << numSecuencias << std::endl;

    for (int secuencia = 0; secuencia < numSecuencias; secuencia++) {
        std::cout << "Secuencia #" << secuencia + 1 << std::endl;

        // Encender LEDs
        mostrarPatron(0xFF);
        std::this_thread::sleep_for(std::chrono::seconds(tiempoEncendido));

        // Apagar LEDs
        mostrarPatron(0x00);
        std::this_thread::sleep_for(std::chrono::seconds(tiempoApagado));
    }
}

void configurarParametros() {
    std::cout << "Ingrese el tiempo de encendido (segundos): ";
    while (!(std::cin >> parametros[0])) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Entrada no válida. Ingrese un número." << std::endl;
    }

    std::cout << "Ingrese el tiempo de apagado (segundos): ";
    while (!(std::cin >> parametros[1])) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Entrada no válida. Ingrese un número." << std::endl;
    }

    std::cout << "Ingrese el numero de secuencias: ";
    while (!(std::cin >> parametros[2])) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Entrada no válida. Ingrese un número." << std::endl;
    }

    std::cout << "Parametros configurados." << std::endl;

    // Mostrar el patrón con los nuevos valores
    mostrarPatron(0xFF); // Mostrar todos los LEDs encendidos
    std::this_thread::sleep_for(std::chrono::seconds(1));
    mostrarPatron(0x00); // Apagar todos los LEDs
}

void mostrarPatron(uint8_t patron) {
    for (int fila = 7; fila >= 0; fila--) { // Mostrar las filas en orden inverso
        uint8_t filaLEDs = 0;
        for (int columna = 0; columna < 8; columna++) {
            filaLEDs |= (patron & (1 << columna)) ? (1 << (7 - columna)) : 0; // Reordenar los bits
        }
        // Simular la función shiftOut
        for (int j = 7; j >= 0; j--) {
            uint8_t bit = (filaLEDs >> j) & 0x01;
            digitalWrite(SER, bit);
            digitalWrite(SRCLK, HIGH);
            digitalWrite(SRCLK, LOW);
        }
        digitalWrite(RCLK, HIGH);
        digitalWrite(RCLK, LOW);
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Retardo para mostrar cada fila
    }
}*/



/*5b)



byte** imagen; // Matriz dinámica para almacenar la imagen de prueba
const int numRows = 8;
const int numCols = 8;

void mostrarMenu();
void mostrarImagenDePrueba();
void mostrarPatronDePrueba();

int main() {
    // Configurar los pines como salidas
    pinMode(SER, OUTPUT);
    pinMode(SRCLK, OUTPUT);
    pinMode(RCLK, OUTPUT);
    std::cout << "Iniciando..." << std::endl;

    while (1) {
        mostrarMenu();
        while (!std::cin) {
            // Esperar a que el usuario ingrese la opción
        }
        char opcion;
        std::cin >> opcion;

        switch (opcion) {
            case 'b':
                mostrarImagenDePrueba();
                break;
            // Agregar más casos para otras funciones aquí
        }
    }

    return 0;
}

void mostrarMenu() {
    std::cout << "Seleccione una opción:" << std::endl;
    std::cout << "b: Mostrar imagen de prueba." << std::endl;
}

void mostrarImagenDePrueba() {
    std::cout << "Ingrese la imagen de prueba (fila por fila, 8 filas, 64 dígitos 0 o 1):" << std::endl;

    // Crear la matriz dinámica para la imagen de prueba
    imagen = new byte*[numRows];
    for (int fila = 0; fila < numRows; fila++) {
        imagen[fila] = new byte[numCols];
    }

    for (int fila = 0; fila < numRows; fila++) {
        std::cout << "Fila " << fila + 1 << ": ";
        for (int columna = 0; columna < numCols; columna++) {
            while (!(std::cin >> imagen[fila][columna])) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Entrada no válida. Ingrese 0 o 1." << std::endl;
            }
        }
    }

    std::cout << "Imagen de prueba recibida:" << std::endl;

    for (int fila = 0; fila < numRows; fila++) { // Impresión en orden correspondiente a la fila
        std::cout << "Fila " << fila + 1 << ": ";
        for (int columna = 0; columna < numCols; columna++) {
            std::cout << static_cast<int>(imagen[fila][columna]);
        }
        std::cout << std::endl;
    }

    mostrarPatronDePrueba();
}

void mostrarPatronDePrueba() {
    for (int fila = numRows - 1; fila >= 0; fila--) { // Impresión en orden correspondiente a la fila, de derecha a izquierda
        std::cout << "Mostrando fila " << fila + 1 << ":" << std::endl;
        byte filaLEDs = 0;
        for (int columna = numCols - 1; columna >= 0; columna--) { // De derecha a izquierda
            filaLEDs |= (imagen[fila][columna] << (numCols - 1 - columna));
        }
        // Simular la función shiftOut
        for (int j = 7; j >= 0; j--) {
            uint8_t bit = (filaLEDs >> j) & 0x01;
            digitalWrite(SER, bit);
            digitalWrite(SRCLK, HIGH);
            digitalWrite(SRCLK, LOW);
        }
        digitalWrite(RCLK, HIGH);
        digitalWrite(RCLK, LOW);
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Retardo para mostrar cada fila
    }

    // Liberar la memoria de la matriz dinámica
    for (int fila = 0; fila < numRows; fila++) {
        delete[] imagen[fila];
    }
    delete[] imagen;
}*/



/* 5c)

// Declarar un arreglo bidimensional para representar los patrones
uint8_t patrones[][8] = {
    { // Rombo
        0b00011000,
        0b00111100,
        0b01111110,
        0b11111111,
        0b11111111,
        0b01111110,
        0b00111100,
        0b00011000
    },
    { // X
        0b10000001,
        0b01000010,
        0b00100100,
        0b00011000,
        0b00011000,
        0b00100100,
        0b01000010,
        0b10000001
    },
    { // S
        0b01101101,
        0b01101101,
        0b11011011,
        0b11011011,
        0b01101101,
        0b01101101,
        0b11011011,
        0b11011011
    },
    { // Flecha
        0b11110000,
        0b01111000,
        0b00111100,
        0b00011110,
        0b00011110,
        0b00111100,
        0b01111000,
        0b11110000
    }
};

int numPatrones = sizeof(patrones) / sizeof(patrones[0]);
int retardoEntrePatrones = 2; // Retardo predeterminado en segundos

void mostrarMenu();
void configurarRetardo();
void mostrarPatronesAlternados();
void mostrarPatron(const uint8_t patron[]);

int main() {
    // Configurar los pines como salidas
    pinMode(SER, OUTPUT);
    pinMode(SRCLK, OUTPUT);
    pinMode(RCLK, OUTPUT);
    std::cout << "Iniciando..." << std::endl;

    while (1) {
        mostrarMenu();
        while (!std::cin) {
            // Esperar a que el usuario ingrese la opción
        }
        char opcion;
        std::cin >> opcion;

        switch (opcion) {
            case 'c':
                configurarRetardo();
                mostrarPatronesAlternados();
                break;
            // Agregar más casos para otras funciones aquí
        }
    }

    return 0;
}

void mostrarMenu() {
    std::cout << "Seleccione una opción:" << std::endl;
    std::cout << "c: Mostrar patrones alternados." << std::endl;
}

void configurarRetardo() {
    std::cout << "Ingrese el retardo entre patrones (en segundos): ";
    while (!(std::cin >> retardoEntrePatrones)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Entrada no válida. Ingrese un número." << std::endl;
    }
    std::cout << "Retardo configurado a " << retardoEntrePatrones << " segundos." << std::endl;
}

void mostrarPatronesAlternados() {
    while (true) {
        for (int i = 0; i < numPatrones; i++) {
            mostrarPatron(patrones[i]);
            std::this_thread::sleep_for(std::chrono::seconds(retardoEntrePatrones));
        }
    }
}

void mostrarPatron(const uint8_t patron[]) {
    for (int i = 0; i < 8; i++) {
        shiftOut(SER, SRCLK, LSBFIRST, patron[i]);
    }
    digitalWrite(RCLK, HIGH);
    digitalWrite(RCLK, LOW);
}*/
