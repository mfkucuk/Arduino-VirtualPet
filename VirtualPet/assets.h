#include <avr/pgmspace.h>
#pragma once

const unsigned char PROGMEM rabbitBitmap[] = {
  0x0e, 0x70, 0x16, 0x48, 0x16, 0x48, 0x16, 0x48, 0x1f, 0xf8, 0x3f, 0xf8, 0x3f,
  0xf8, 0x37, 0xb8, 0x74, 0xbc, 0x7f, 0xfc, 0x7f, 0xfc, 0x7f, 0xfc, 0x3f, 0xf8, 
  0x00, 0x00, 0x2f, 0xe4, 0x6f, 0xf6, 0xef, 0xf7, 0xef, 0xf7, 0x6f, 0xf6, 0x0f, 
  0xf0, 0x0f, 0xf0, 0x07, 0xe0, 0x00, 0x00, 0x0e, 0x70, 0x0e, 0x70, 0x36, 0x77
};

const unsigned char PROGMEM kitchenShelfBitmap[] = {
  0x3e, 0x3e, 0x7c, 0x1c, 0x1c, 0x38, 0x08, 0x08, 0x10, 0xeb, 0xeb, 0x97, 0xeb, 
  0xeb, 0xb7, 0x08, 0x08, 0x30, 0x08, 0x3e, 0x30, 0x1c, 0x41, 0x30, 0x14, 0x5d, 
  0x10, 0x14, 0x5d, 0x00, 0x14, 0x5d, 0x00, 0x14, 0x41, 0x00, 0x00, 0x3e, 0x00, 
  0x00, 0x00, 0x00
};

const unsigned char PROGMEM kitchenTableBitmap[] = {
  0x00, 0x00, 0x00, 0x00, 0x3f, 0xf8, 0x37, 0xf8, 0x2f, 0x78, 0x3e, 0xf8, 0x3d, 
  0xe8, 0x3b, 0xd8, 0x1f, 0xb0, 0x0f, 0xe0, 0x00, 0x00, 0xff, 0xff, 0x81, 0x01, 
  0xbd, 0x7d, 0x81, 0x01, 0xff, 0xff, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 
  0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01
};

const unsigned char PROGMEM kitchenFurnaceBitmap[] = {
  0xff, 0xfc, 0x80, 0x04, 0x80, 0x24, 0x91, 0x54, 0xbb, 0x74, 0xbb, 0x74, 0x80, 
  0x04, 0xff, 0xfc, 0x00, 0x00, 0xff, 0xfc, 0xd8, 0xec, 0xff, 0xfc, 0x80, 0x04, 
  0xbf, 0xf4, 0xa0, 0x14, 0xbf, 0xf4, 0xbf, 0xf4, 0xbf, 0xf4, 0xbf, 0xf4, 0xbf, 
  0xf4, 0x80, 0x04, 0xff, 0xfc, 0x00, 0x00, 0xff, 0xfc, 0xff, 0xfc, 0x00, 0x00, 
  0xff, 0xfc, 0x80, 0x04, 0xbf, 0xf4, 0xb8, 0x74, 0xbf, 0xf4, 0x80, 0x04, 0xff, 
  0xfc
};

const unsigned char PROGMEM gamepadBitmap[] = {
  0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x01, 0x00, 0xff, 0xff, 0x80, 0x01, 0x93, 
  0x95, 0xb8, 0x01, 0x92, 0x95, 0x80, 0x01, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00
};

const unsigned char PROGMEM zzzBitmap[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x04, 0x01, 0xc8, 0x00, 
  0x50, 0x1c, 0x9c, 0x05, 0x00, 0x09, 0xc0, 0x10, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char PROGMEM hatBitmap[] = {
  0x00, 0x00, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f, 
  0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x3f, 0xfc, 0x3f, 0xfc, 0x00, 0x00, 0x00, 0x00
};

const unsigned char PROGMEM cookieBitmap[] = {
  0x00, 0x00, 0x03, 0xc0, 0x0c, 0x30, 0x10, 0x88, 0x16, 0x28, 0x26, 0x04, 0x20, 
  0x34, 0x20, 0xb4, 0x20, 0x04, 0x11, 0xa8, 0x11, 0x88, 0x0c, 0x30, 0x03, 0xc0, 0x00, 0x00
};

const unsigned char PROGMEM pongLogoBitmap[] = {
  0x00, 0x00, 0x60, 0x06, 0x60, 0x06, 0x61, 0xc6, 0x63, 0xe6, 0x67, 0xf6, 0x67,
  0xf6, 0x67, 0xf6, 0x63, 0xe6, 0x61, 0xc6, 0x60, 0x06, 0x60, 0x06, 0x60, 0x06, 0x00, 0x00
};

const unsigned char PROGMEM bedBitmap[] = {
  0xc0, 0x00, 0x00, 0xc0, 0x00, 0x00, 0xc0, 0x1f, 0xf0, 0xc0, 0x7f, 0xf8, 0xde,
  0xff, 0xfc, 0xde, 0xff, 0xfc, 0xde, 0xff, 0xfc, 0xc0, 0x00, 0x00, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x07, 0xc0, 0x00, 0x03, 
  0xc0, 0x00, 0x03
};

const unsigned char PROGMEM clockBitmap[] = {
  0x1f, 0xf8, 0x20, 0x04, 0x5e, 0xfa, 0xbf, 0xfd, 0xbf, 0xfd, 0xbe, 0xfd, 0xbe, 
  0xfd, 0xbe, 0xfd, 0x9e, 0x09, 0xbf, 0xfd, 0xbf, 0xfd, 0xbf, 0xfd, 0xbf, 0xfd, 
  0x9f, 0x79, 0x40, 0x02, 0x3f, 0xfc
};

const unsigned char PROGMEM wardrobeBitmap[] = {
  0xff, 0xfe, 0x81, 0x02, 0xbd, 0x7a, 0xbd, 0x7a, 0xbd, 0x7a, 0xbd, 0x7a, 0xbd, 
  0x7a, 0xbd, 0x7a, 0xb5, 0x5a, 0xb5, 0x5a, 0xbd, 0x7a, 0xbd, 0x7a, 0xbd, 0x7a, 
  0xbd, 0x7a, 0xbd, 0x7a, 0xbd, 0x7a, 0x81, 0x02, 0xff, 0xfe, 0x81, 0x02, 0xbd, 
  0x7a, 0xa5, 0x4a, 0xbd, 0x7a, 0x81, 0x02, 0xff, 0xfe
};

const unsigned char PROGMEM doorBitmap[] = {
  0xff, 0xff, 0xff, 0xff, 0xc0, 0x07, 0xde, 0xf7, 0xd2, 0x97, 0xd2, 0x97, 0xd2, 
  0x97, 0xd2, 0x97, 0xd2, 0x97, 0xd2, 0x95, 0xd2, 0x97, 0xde, 0xf5, 0xc0, 0x05, 
  0xc0, 0x07, 0xde, 0xf7, 0xd2, 0x97, 0xd2, 0x97, 0xd2, 0x97, 0xde, 0xf7, 0xc0, 
  0x07, 0xff, 0xff, 0xff, 0xff
};

const unsigned char PROGMEM televisionBitmap[] = {
  0xff, 0xff, 0xff, 0x80, 0x00, 0x01, 0x80, 0x00, 0x01, 0x80, 0x00, 0x01, 0x80, 
  0x00, 0x01, 0x80, 0x00, 0x01, 0x80, 0x00, 0x01, 0x80, 0x00, 0x01, 0x80, 0x00, 
  0x01, 0x80, 0x00, 0x01, 0x80, 0x00, 0x01, 0x80, 0x00, 0x01, 0x80, 0x00, 0x01, 
  0x80, 0x00, 0x01, 0x80, 0x00, 0x01, 0xff, 0xff, 0xff, 0xf6, 0x42, 0x6f, 0xff, 0xff, 0xff
};

const unsigned char PROGMEM couchBitmap[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x7f, 0x00, 0x01, 0x01, 0x80, 0x80, 0x01, 
  0x7d, 0xbe, 0x80, 0x01, 0x7d, 0xbe, 0x80, 0x01, 0x01, 0x80, 0x80, 0x01, 0xff, 
  0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x7b, 0xff, 0xff, 0xde, 0x8a, 0x00, 0x00, 
  0x51, 0xaa, 0xff, 0xff, 0x55, 0xaa, 0xff, 0xff, 0x55, 0xaa, 0xff, 0xff, 0x55, 
  0xaa, 0xff, 0xff, 0x55, 0x8a, 0x00, 0x00, 0x51, 0xfb, 0xff, 0xff, 0xdf
};

const unsigned char PROGMEM windowBitmap[] = {
  0x00, 0x00, 0x00, 0xff, 0xff, 0xfe, 0x80, 0x10, 0x02, 0xbf, 0xd7, 0xfa, 0xbf, 
  0xd7, 0xfa, 0xbd, 0xd7, 0xba, 0xbb, 0xd7, 0x7a, 0xbf, 0xd7, 0xfa, 0xbf, 0xd7, 
  0xfa, 0xbf, 0xd7, 0xfa, 0xbd, 0xd7, 0xba, 0xbb, 0xd7, 0x7a, 0xbf, 0xd7, 0xfa, 
  0xbf, 0xd7, 0xfa, 0x80, 0x10, 0x02, 0xff, 0xff, 0xfe
};

const unsigned char PROGMEM nightstandBitmap[] = {
  0x03, 0xe0, 0x04, 0x20, 0x05, 0xa0, 0x05, 0xa0, 0x0b, 0xd0, 0x08, 0x10, 0x1f, 
  0xf8, 0x10, 0x08, 0x0f, 0xf0, 0x01, 0x80, 0x03, 0xc0, 0x07, 0xe0, 0xff, 0xff, 
  0x81, 0x81, 0xbd, 0xbd, 0x81, 0x81, 0xff, 0xff, 0x80, 0x01, 0x80, 0x01, 0x80, 
  0x01, 0x80, 0x01, 0x80, 0x01
};