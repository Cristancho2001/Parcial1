#define SER 4
#define SRCLK 6
#define RCLK 5

// Declarar un arreglo bidimensional para representar los patrones
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

void setup() {
  pinMode(SER, OUTPUT);
  pinMode(SRCLK, OUTPUT);
  pinMode(RCLK, OUTPUT);
}

void loop() {
  for (int i = 0; i < numPatrones; i++) {
    mostrarPatron(patrones[i]);
    delay(2000);
  }
}

void mostrarPatron(byte patron[]) {
  for (int i = 0; i < 8; i++) {
    shiftOut(SER, SRCLK, LSBFIRST, patron[i]);
  }
  digitalWrite(RCLK, HIGH);
  digitalWrite(RCLK, LOW);
}