#include "particle.h"

#include "global.h"
#include <avr/pgmspace.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

void ParticleSystem::play(const int& minDx, const int& maxDx, const int& minDy, const int& maxDy, const int& gravity, const float& lifetime) {
  running = true;

  for (int i = 0; i < particleCount; i++) {
    particles[i].x = x;
    particles[i].y = y;

    particles[i].dx = (int)random(minDx, maxDx + 1);
    particles[i].dy = (int)random(minDy, maxDy + 1);
    particles[i].lifetime = lifetime;
    particles[i].age = 0;
  }
}

void ParticleSystem::stop() {
  running = false;
}

void ParticleSystem::update() {

  for (int i = 0; i < particleCount; i++) {
    if (!particles[i].alive) {
      if (random(1, 100) == 50) {
        particles[i].alive = true;
      }
    } else {
      particles[i].x += particles[i].dx;
      particles[i].y += particles[i].dy + particles[i].gravity;

      if (particles[i].age > particles[i].lifetime) {
        particles[i].x = x;
        particles[i].y = y;

        if (!running) {
          particles[i].alive = false;
        }
      }

      particles[i].age += 1.0f / 60.0f;
    }
  }
}

void ParticleSystem::render() {
  for (int i = 0; i < particleCount; i++) {
    if (particles[i].alive) {
      global.display->drawPixel(particles[i].x, particles[i].y, SSD1306_WHITE);
    }
  }
}