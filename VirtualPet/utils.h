#pragma once

#include "global.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

inline void drawInvertBitmapColor(int16_t x, int16_t y,
            const uint8_t *bitmap, int16_t w, int16_t h,
            uint16_t color) {

  int16_t i, j, byteWidth = (w + 7) / 8;

  for(j=0; j<h; j++) {
    for(i=0; i<w; i++ ) {
      if((pgm_read_byte(bitmap + j * byteWidth + i / 8) & (128 >> (i & 7)))==0) {
        global.display->drawPixel(x+i, y+j, color);
      }
    }
  }
}