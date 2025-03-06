#pragma once

struct ParticleSystem {
  struct Particle {
    int x, y;
    int dx, dy;
    float age;
    bool alive;
  };

  int particleCount = 4;
  Particle particles[4];
  int x, y;
  int gravity = 1;
  int color;
  float lifetime = 0.1f;
  bool running = false;

  void play();
  void stop();
  void update();
  void render();
};