#include "particle.h"

#include "Arduino.h"
#include "global.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

void ParticleSystem::play() {
  running = true;

  randomSeed(analogRead(0));

  for (int i = 0; i < particleCount; i++) {
    particles[i].x = x;
    particles[i].y = y;

    particles[i].dx = random(-1, 2);
    particles[i].dy = random(0, 2);
    particles[i].age = 0;
  }
}

void ParticleSystem::stop() {
  running = false;
  for (int i = 0; i < particleCount; i++) {
    particles[i].alive = false;
  }
}

void ParticleSystem::update() {

  if (!running) return;

  for (int i = 0; i < particleCount; i++) {
    if (!particles[i].alive) {
      if (random(1, 20) == 10) {
        particles[i].alive = true;
      }
    } else {
      particles[i].x += particles[i].dx;
      particles[i].y += particles[i].dy + gravity;

      if (particles[i].age > lifetime) {
        particles[i].x = x;
        particles[i].y = y;
        particles[i].age = 0;
        particles[i].dx = random(-1, 2);
        particles[i].dy = random(0, 2);

        if (!running) {
          particles[i].alive = false;
        }
      }

      particles[i].age += 1.0f / 60.0f;
    }
  }
}

void ParticleSystem::render() {

  if (!running) return;

  for (int i = 0; i < particleCount; i++) {
    if (particles[i].alive) {
      global.display->fillCircle(particles[i].x, particles[i].y, 1, color);
    }
  }
}