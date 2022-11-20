#include <SoftwareSerial.h>

// MENENTUKAN INSTANCE UNTUK BLUETOOTH
SoftwareSerial bluetooth(2, 3);

// INISIALISASI PIN UNTUK MOTOR DC
int ENA = 10;
int IN1 = 9;
int IN2 = 8;
int IN3 = 7;
int IN4 = 6;
int ENB = 5;

// VARIABLE UNTUK MENAMPUNG DATA DARI REMOTE CONTROL
char data;

void setup() {
  bluetooth.begin(9600);
  Serial.begin(9600);

  // INISIALISASI PIN-PIN MOTOR DC
  init_motor(ENA, IN1, IN2, IN3, IN4, ENB);
}

void loop() {

  // CEK APAKAH ADA SIGNAL YANG DIKIRIM OLEH TRANSMITTER/REMOTE
  if (bluetooth.available() > 0) {

    // JIKA ADA SIGNAL DARI TRANSMITTER/REMOTE BACA DATA YANG DIKIRIM
    data = bluetooth.read();

    // CETAK DATA YANG DITERIMA KE SERIAL MONITOR
    Serial.println(data);

    // KONTROL SETIAP DATA
    if (data == 'F') {
      go_forward(100, 100);
    } else if (data == 'B') {
      go_backward(100, 100);
    } else if (data == 'R') {
      turn_right(100);
    } else if (data == 'L') {
      turn_left(100);
    } else {
      stop();
    }
  }

  // MEMBERI JEDA 50 milisekon UNTUK ARDUINO
  delay(50);

  // JIKA TIDAK ADA SIGNAL DARI TRANSMITTER/REMOTE MAKA ROBOT BERHENTI
  stop();
}