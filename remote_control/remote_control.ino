#include <SoftwareSerial.h>

SoftwareSerial bluetooth(2, 3);

// MENENTUKAN BATAS IDLE SUMBU X
int BATAS_ATAS_X = 522 + 50;
int BATAS_BAWAH_X = 522 - 50;

// MENENTUKAN BATAS IDLE SUMBU Y
int BATAS_ATAS_Y = 508 + 50;
int BATAS_BAWAH_Y = 508 - 50;

// UNTUK MENAMPUNG PERINTAH
char data;

void setup() {
  bluetooth.begin(9600);
  Serial.begin(9600);
}

void loop() {

  char data = command();

  // JIKA DATA SELAIN 'S'
  if (data != 'S') {

    // MAKA KIRIMKAN DATA KE BLUETOOTH
    bluetooth.write(data);
    Serial.println(data);
  }

  delay(50);
}