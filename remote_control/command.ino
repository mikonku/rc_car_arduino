char command() {
  int Y = analogRead(A0);
  int X = analogRead(A1);

  if (Y < BATAS_BAWAH_Y) {
     return 'F';
  } else if (Y > BATAS_ATAS_Y) {
     return 'B';
  } else if (X < BATAS_BAWAH_X) {
     return 'L';
  } else if (X > BATAS_ATAS_X) {
     return 'R';
  } else {
    return 'S';
  }
}