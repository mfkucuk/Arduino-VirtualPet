#include "WString.h"
#include "pong_state.h"

#include "Arduino.h"
#include "global.h"
#include "state_manager.h"
#include "stats.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <CuteBuzzerSounds.h>

void PongState::setup() {
  playerScore = 0;
  computerScore = 0;
  ball.x = 64;
  ball.y = 32;
  roundStarted = false;
  paddle1.y = 24;
  paddle2.y = 24;
}

void PongState::update() {

  if (playerScore == 7 || computerScore == 7) {
    delay(2000);
    global.stats->updateHappiness(10);
    global.stateManager->changeState(GAME_STATE);
  }

  if (!roundStarted) return;

  ball.x += ball.vx;
  ball.y += ball.vy;

  // Ball collision with top and bottom walls
  if (ball.y - 2 <= 0 || ball.y + 2 >= 64) {
    ball.vy = -ball.vy;
  }

  // Ball collision with paddle1 (left paddle)
if (ball.x - 2 <= 10 &&
    ball.y + 2 >= paddle1.y &&
    ball.y - 2 <= paddle1.y + 16) {

    // Check if the ball hits the top or bottom corners of the paddle
    if (ball.y - 2 <= paddle1.y || ball.y + 2 >= paddle1.y + 16) {
        ball.vy = -ball.vy;  // Reverse vertical velocity if corner hit
    } else {
      ball.vx = -ball.vx;  // Reverse horizontal velocity
      ball.x = 10 + 2;  // Prevent sticking
    }
}

// Ball collision with paddle2 (right paddle)
if (ball.x + 2 >= 118 &&
    ball.y + 2 >= paddle2.y &&
    ball.y - 2 <= paddle2.y + 16) {

    

    // Check if the ball hits the top or bottom corners of the paddle
    if (ball.y - 2 <= paddle2.y || ball.y + 2 >= paddle2.y + 16) {
        ball.vy = -ball.vy;  // Reverse vertical velocity if corner hit
    } else {
      ball.vx = -ball.vx;  // Reverse horizontal velocity
      ball.x = 118 - 2;  // Prevent sticking
    }
    
}


  if (ball.y > paddle2.y + 8) {
    if (paddle2.y + 16 < 64) {
      paddle2.y += 2;
    }
  } else if (ball.y < paddle2.y + 8) {
    if (paddle2.y > 0) {
      paddle2.y -= 2;
    }
  }

  if (ball.x + 2 < 0) {
    computerScore++;
    roundStarted = false;
    ball.x = 64;
    ball.y = 32;
    cute.play(S_FART1);
  }

  if (ball.x - 2 > 128) {
    playerScore++;
    roundStarted = false;
    ball.x = 64;
    ball.y = 32;
    cute.play(S_HAPPY);
  }
}

void PongState::render() {
  global.display->fillCircle(ball.x, ball.y, 2, SSD1306_WHITE);
  global.display->fillRect(5, paddle1.y, 5, 16, SSD1306_WHITE);
  global.display->fillRect(118, paddle2.y, 5, 16, SSD1306_WHITE);

  global.display->setTextColor(SSD1306_WHITE);
  global.display->setCursor(64 - 12, 2);
  global.display->println(playerScore);

  global.display->setCursor(64 + 10, 2);
  global.display->println(computerScore);

  if (playerScore == 7) {
    global.display->setCursor(36, 50);
    global.display->print(F("You Win :)"));
  }

  if (computerScore == 7) {
    global.display->setCursor(22, 50);
    global.display->print(F("Computer Wins :("));
  }
}

void PongState::input(int pin, bool pressed, bool longPressed) {
  if (pin == LEFT_BUTTON_PIN) {
    if (paddle1.y + 16 < 64) {
      paddle1.y += 2;
    }
  } else if (pin == RIGHT_BUTTON_PIN) {
    if (paddle1.y > 0) {
      paddle1.y -= 2;
    }
  } else if (pin == MIDDLE_BUTTON_PIN && pressed) {
    roundStarted = true;
  } else if (pin == MIDDLE_BUTTON_PIN && longPressed) {
    global.stateManager->changeState(GAME_STATE);
  }
}