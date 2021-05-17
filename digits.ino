void digitZero(int offset, uint32_t colour){
    stripClock.fill(colour, (0 + offset), 27);
    stripClock.fill(colour, (36 + offset), 27);
}

void digitOne(int offset, uint32_t colour){
    stripClock.fill(colour, (0 + offset), 9);
    stripClock.fill(colour, (36 + offset), 9);
}

void digitTwo(int offset, uint32_t colour){
    stripClock.fill(colour, (0 + offset), 18);
    stripClock.fill(colour, (27 + offset), 9);
    stripClock.fill(colour, (45 + offset), 18);
}

void digitThree(int offset, uint32_t colour){
    stripClock.fill(colour, (9 + offset), 27);
    stripClock.fill(colour, (45 + offset), 18);
}

void digitFour(int offset, uint32_t colour){
    stripClock.fill(colour, (18 + offset), 27);
    stripClock.fill(colour, (54 + offset), 9);
}

void digitFive(int offset, uint32_t colour){
    stripClock.fill(colour, (9 + offset), 45);
}

void digitSix(int offset, uint32_t colour){
    stripClock.fill(colour, (0 + offset), 54);
}

void digitSeven(int offset, uint32_t colour){
    stripClock.fill(colour, (18 + offset), 9);
    stripClock.fill(colour, (45 + offset), 18);
}

void digitEight(int offset, uint32_t colour){
    stripClock.fill(colour, (0 + offset), 63);
}

void digitNine(int offset, uint32_t colour){
    stripClock.fill(colour, (9 + offset), 54);
}

void digitTen(int offset, uint32_t colour){
    stripClock.fill(0x888888, (0 + offset), 9);
    stripClock.fill(colour, (9 + offset), 18);
    stripClock.fill(0x888888, (36 + offset), 9);
    stripClock.fill(colour, (45 + offset), 18);
}

void digitEleven(int offset, uint32_t colour){
    stripClock.fill(colour, (0 + offset), 9);
    stripClock.fill(colour, (18 + offset), 9);
    stripClock.fill(colour, (36 + offset), 9);
    stripClock.fill(colour, (54 + offset), 9);
}


void blazeIt(int seconds) {
  int redNum = 0;
  int yellowNum = 1;
  int greenNum = 2;
  for (int x = 0; x < 7; x++) {
    int rando = random(0, 3);
    if (rando == 0) {
      stripClock.fill(red, x*9, 9);
    } else if (rando == 1) {
      stripClock.fill(yellow, x*9, 9);
    } else if (rando == 2) {
      stripClock.fill(green, x*9, 9);
    }
//    if ((redNum + seconds + x) % 3 == 0) {
//      stripClock.fill(red, x*9, 9);
//    } else if ((yellowNum + seconds + x) % 3 == 0) {
//      stripClock.fill(yellow, x*9, 9);
//    } else if ((greenNum + seconds + x) % 3 == 0) {
//      stripClock.fill(green, x*9, 9);
//    }
  }
  delay(1000);
}

void rainbow(int wait) {
  for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
    for(int i=0; i<stripClock.numPixels(); i++) { 
      int pixelHue = firstPixelHue + (i * 65536L / stripClock.numPixels());
      stripClock.setPixelColor(i, stripClock.gamma32(stripClock.ColorHSV(pixelHue)));
    }
    stripClock.show();
    delay(wait);
  }
}
