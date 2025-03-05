#pragma once


struct ParticleSystem {
  struct Particle {
    int x, y;
    int dx, dy;
    int gravity;
    float lifetime;
    float age;
    bool alive;
  };

  int particleCount = 2;
  Particle particles[2];
  int x, y;
  bool running = false;

  void play(const int& minDx, const int& maxDx, const int& minDy, const int& maxDy, const int& gravity, const float& lifetime);
  void stop();
  void update();
  void render();
};