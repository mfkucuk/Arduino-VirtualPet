#include "pong_state.h"

#include "Arduino.h"
#include "global.h"
#include "state_manager.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <CuteBuzzerSounds.h>

void PongState::setup() {
  playerScore = 0;
  computerScore = 0;
}

void PongState::update() {

  if (playerScore == 7) {
    delay(1500);
    global.stateManager->changeState(GAME_STATE);
  }

  if (computerScore == 7) {
    delay(1500);
    global.stateManager->changeState(GAME_STATE);
  }

  if (!roundStarted) return;

  ball.x += ball.vx;
  ball.y += ball.vy;

  // Ball collision with top and bottom walls
  if (ball.y - ball.radius <= 0 || ball.y + ball.radius >= 64) {
    ball.vy = -ball.vy;
  }

  // Ball collision with paddle1
  if (ball.x - ball.radius <= paddle1.x + paddle1.w &&
      ball.y + ball.radius >= paddle1.y &&
      ball.y - ball.radius <= paddle1.y + paddle1.h) {
    ball.vx = -ball.vx;
    ball.x = paddle1.x + paddle1.w + ball.radius;  // Prevent sticking
  }

  // Ball collision with paddle2
  if (ball.x + ball.radius >= paddle2.x &&
      ball.y + ball.radius >= paddle2.y &&
      ball.y - ball.radius <= paddle2.y + paddle2.h) {
    ball.vx = -ball.vx;
    ball.x = paddle2.x - ball.radius;  // Prevent sticking
  }

  if (ball.vy > 0) {
    if (paddle2.y + paddle2.h < 64) {
      paddle2.y++;
    }
  } else if (ball.vy < 0) {
    if (paddle2.y > 0) {
      paddle2.y--;
    }
  }

  if (ball.x + ball.radius < 0) {
    computerScore++;
    roundStarted = false;
    ball.x = 64;
    ball.y = 32;
    cute.play(S_SAD);
  }

  if (ball.x - ball.radius > 128) {
    playerScore++;
    roundStarted = false;
    ball.x = 64;
    ball.y = 32;
    cute.play(S_HAPPY);
  }
}

void PongState::render() {
  global.display->fillCircle(ball.x, ball.y, ball.radius, SSD1306_WHITE);
  global.display->fillRect(paddle1.x, paddle1.y, paddle1.w, paddle1.h, SSD1306_WHITE);
  global.display->fillRect(paddle2.x, paddle2.y, paddle2.w, paddle2.h, SSD1306_WHITE);

  global.display->setTextSize(1);
  global.display->setTextColor(SSD1306_WHITE);
  global.display->setCursor(64 - 12, 2);
  global.display->println(playerScore);

  global.display->setCursor(64 + 10, 2);
  global.display->println(computerScore);
}

void PongState::input(int pin, bool pressed, bool longPressed) {
  if (pin == LEFT_BUTTON_PIN) {
    if (paddle1.y + paddle1.h < 64) {
      paddle1.y++;
    }
  } else if (pin == RIGHT_BUTTON_PIN) {
    if (paddle1.y > 0) {
      paddle1.y--;
    }
  } else if (pin == MIDDLE_BUTTON_PIN && pressed) {
    roundStarted = true;
  } else if (pin == MIDDLE_BUTTON_PIN && longPressed) {
    global.stateManager->changeState(GAME_STATE);
  }
}