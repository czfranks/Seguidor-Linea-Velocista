#include "altavoz.h"

Altavoz::Altavoz() {
}
Altavoz::~Altavoz() {
}

void Altavoz::silencio() {
  noTone(mPin);
}

void Altavoz::configuraPin(uint8_t pin) {
  mPin = pin;
}

void Altavoz::beep() {
  tone(mPin, 2000, 50);
  delay(50);
  silencio();
}

void Altavoz::mejora() {
  tone(mPin, 1000, 50);
  delay(50);
  silencio();
}
void Altavoz::turbo() {

  tone(mPin, 97, 50);
  delay(50);
  /*delay(2.32099826389);
  tone(mPin, 97, 98.1782265625);
  delay(109.086918403);
  delay(2.32099826389);
  tone(mPin, 195, 98.1782265625);
  /*delay(109.086918403);
  delay(2.32099826389);
  tone(mPin, 97, 98.1782265625);
  delay(109.086918403);
  delay(2.32099826389);
  tone(mPin, 174, 98.1782265625);
  delay(109.086918403);
  delay(2.32099826389);
  tone(mPin, 97, 98.1782265625);
  delay(109.086918403);
  delay(2.32099826389);
  tone(mPin, 130, 98.1782265625);
  delay(109.086918403);
  delay(2.32099826389);
  tone(mPin, 146, 98.1782265625);
  delay(109.086918403);
  delay(2.32099826389);
  tone(mPin, 97, 98.1782265625);
  delay(109.086918403);
  delay(2.32099826389);
  tone(mPin, 97, 98.1782265625);
  delay(109.086918403);
  delay(2.32099826389);
  tone(mPin, 195, 98.1782265625); */

  silencio();
}

void Altavoz::calibra() {
  tone(mPin, 987, 82.1428229167);
  delay(82.1428229167);
  delay(3.57142708333);
  tone(mPin, 987, 82.1428229167);
  delay(82.1428229167);
  delay(3.57142708333);
  tone(mPin, 987, 82.1428229167);
  delay(82.1428229167);
  delay(3.57142708333);
  tone(mPin, 987, 82.1428229167);
  delay(82.1428229167);
  delay(3.57142708333);

  silencio();
}

void Altavoz::gameover() {
  int melody[] = { NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4 };  // note durations: 4 = quarter note, 8 = eighth note, etc.:
  int noteDurations[] = { 4, 8, 8, 4, 4, 4, 4, 4 };
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    // one second divided by the note type.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(mPin, melody[thisNote], noteDuration);
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(mPin);
  }
  silencio();
}

void Altavoz::finDeTono() {
  tone(mPin, 783, 82.1428229167);
  delay(82.1428229167);
  delay(3.57142708333);
  tone(mPin, 783, 82.1428229167);
  delay(82.1428229167);
  delay(3.57142708333);
  tone(mPin, 783, 82.1428229167);
  delay(82.1428229167);
  delay(3.57142708333);
  tone(mPin, 783, 82.1428229167);

  silencio();
}

void Altavoz::sad() {
  tone(mPin, 880, 600.0);
  delay(600.0);
  tone(mPin, 830, 900.0);
  delay(900.0);
  tone(mPin, 739, 300.0);
  delay(300.0);
  tone(mPin, 830, 600.0);
  delay(600.0);
  tone(mPin, 739, 900.0);
  delay(900.0);
  tone(mPin, 659, 300.0);
  delay(300.0);
  tone(mPin, 739, 600.0);
  delay(600.0);
  tone(mPin, 659, 600.0);
  delay(600.0);
  tone(mPin, 220, 450.0);
  delay(450.0);
  tone(mPin, 146, 150.0);
  delay(150.0);
  tone(mPin, 554, 600.0);
  delay(600.0);
  tone(mPin, 622, 600.0);
  delay(600.0);
  tone(mPin, 207, 450.0);
  delay(450.0);
  tone(mPin, 138, 150.0);
  delay(150.0);
  tone(mPin, 123, 300.0);
  delay(300.0);
  tone(mPin, 184, 300.0);
  delay(300.0);
  tone(mPin, 246, 300.0);
  delay(300.0);
  tone(mPin, 184, 300.0);
  delay(300.0);
  tone(mPin, 493, 300.0);
  delay(300.0);
  tone(mPin, 123, 300.0);
  delay(300.0);
  tone(mPin, 138, 300.0);
  delay(300.0);
  tone(mPin, 207, 300.0);
  delay(300.0);
  tone(mPin, 277, 300.0);
  delay(300.0);
  tone(mPin, 329, 300.0);
  delay(300.0);
  tone(mPin, 277, 300.0);
  delay(300.0);
  tone(mPin, 207, 300.0);
  delay(300.0);
  tone(mPin, 123, 300.0);
  delay(300.0);
  tone(mPin, 184, 300.0);
  delay(300.0);
  tone(mPin, 246, 300.0);
  delay(300.0);
  tone(mPin, 184, 300.0);
  delay(300.0);
  tone(mPin, 493, 300.0);
  delay(300.0);
  tone(mPin, 123, 300.0);
  delay(300.0);
  tone(mPin, 138, 300.0);
  delay(300.0);
  tone(mPin, 207, 300.0);
  delay(300.0);
  tone(mPin, 659, 300.0);
  delay(300.0);
  tone(mPin, 554, 300.0);
  delay(300.0);
  tone(mPin, 659, 300.0);
  delay(300.0);
  tone(mPin, 830, 300.0);
  delay(300.0);
  tone(mPin, 1108, 2400.0);
  delay(2400.0);

  silencio();
}