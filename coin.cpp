#include "coin.h"
#include "lasso.h"
#include<cstdlib>
#include<ctime>
void Coin::initCoin() {
  coin_start_x = (PLAY_X_START+WINDOW_X)/2;
  coin_start_y = PLAY_Y_HEIGHT;
  coin_circle.reset(coin_start_x, coin_start_y, COIN_SIZE);
  coin_circle.setColor(COLOR("gold"));
  coin_circle.setFill(true);
  addPart(&coin_circle);
}

void Coin::initCoinsp() {
  coin_start_x = 90+(PLAY_X_START+WINDOW_X)/2;
  coin_start_y = PLAY_Y_HEIGHT-50;
  coin_circle.reset(coin_start_x, coin_start_y, COIN_SIZE);
  coin_circle.setColor(COLOR("brown"));
  coin_circle.setFill(true);
  addPart(&coin_circle);
}
void Coin::resetCoinsp() {
  coin_start_x = 90+(PLAY_X_START+WINDOW_X)/2;
  coin_start_y = PLAY_Y_HEIGHT-50;
  double coin_speed = 100;
  double coin_angle_deg = 75;
  coin_ax = -10;
  coin_ay = 17;
  bool paused = true, rtheta = true;
  reset_all(coin_start_x, coin_start_y, coin_speed, coin_angle_deg, coin_ax, coin_ay, paused, rtheta);
}
void Coin::destroyCoinsp(){
  double coin_speed = 0;
  double coin_angle_deg = 0;
  coin_ax = 0;
  coin_ay = 0;
  bool paused = true, rtheta = true;
  reset_all(0, 0, coin_speed, coin_angle_deg, coin_ax, coin_ay, paused, rtheta);
}
void Coin::resetCoin() {
  double coin_speed = COIN_SPEED;
  double coin_angle_deg = COIN_ANGLE_DEG;
  coin_ax = 0;
  coin_ay = COIN_G;
  bool paused = true, rtheta = true;
  reset_all(coin_start_x, coin_start_y, coin_speed, coin_angle_deg, coin_ax, coin_ay, paused, rtheta);
}

void Coin::level1(){
  double coin_speed = COIN_SPEED;
  double coin_angle_deg = COIN_ANGLE_DEG;
  coin_ax = 0;
  coin_ay = COIN_G;
  bool paused = true, rtheta = true;
  reset_all(coin_start_x, coin_start_y, coin_speed, coin_angle_deg, coin_ax, coin_ay, paused, rtheta);

}
void Coin::level2(){
  double coin_speed = COIN_SPEED;
  double coin_angle_deg = 60;
  coin_ax = 0;
  coin_ay = 30;
  bool paused = true, rtheta = true;
  reset_all(coin_start_x, coin_start_y, coin_speed, coin_angle_deg, coin_ax, coin_ay, paused, rtheta);

}

void Coin::level3(){
  srand((unsigned) time(0));
  int randomNumber = rand()%50;
  double coin_speed = 100;
  double coin_angle_deg = 20+randomNumber;
  coin_ax = -20;
  coin_ay = 15;
  bool paused = true, rtheta = true;
  reset_all(coin_start_x, coin_start_y, coin_speed, coin_angle_deg, coin_ax, coin_ay, paused, rtheta);
}
void Coin::initlevel4(int a) {
  srand((unsigned) time(0)*a);
  int randomNumber = 500+rand()%200 + 20*a;
  coin_start_x = randomNumber-100;
  coin_start_y = randomNumber-300;
  coin_circle.reset(coin_start_x, coin_start_y, COIN_SIZE);
  coin_circle.setColor(COLOR("gold"));
  coin_circle.setFill(true);
  addPart(&coin_circle);
}
void Coin::initBomb() {
  coin_start_x = 30+(PLAY_X_START+WINDOW_X)/2;
  coin_start_y = PLAY_Y_HEIGHT;
  coin_circle.reset(coin_start_x, coin_start_y, COIN_SIZE);
  coin_circle.setColor(COLOR("red"));
  coin_circle.setFill(true);
  addPart(&coin_circle);
}
void Coin::resetBomb() {
  srand((unsigned) time(0));
  int randomNumber = rand()%50;
  double bomb_speed = 100;
  double bomb_angle_deg = 40+randomNumber;
  double bomb_ax = -20;
  double bomb_ay  = 15;
  bool paused = true, rtheta = true;
  reset_all(coin_start_x, coin_start_y, bomb_speed, bomb_angle_deg, bomb_ax, bomb_ay, paused, rtheta);
}

void Coin::destroyBomb() {
  double bomb_speed = 0;
  double bomb_angle_deg = 0;
  double bomb_ax = 0;
  double bomb_ay  = 0;
  bool paused = true, rtheta = true;
  reset_all(0, 0, bomb_speed, bomb_angle_deg, bomb_ax, bomb_ay, paused, rtheta);
}

void Coin::initBoost() {
  coin_start_x = 20+(PLAY_X_START+WINDOW_X)/2;
  coin_start_y = PLAY_Y_HEIGHT-20;
  coin_circle.reset(coin_start_x, coin_start_y, COIN_SIZE);
  coin_circle.setColor(COLOR("blue"));
  coin_circle.setFill(true);
  addPart(&coin_circle);
}

void Coin::resetBoost() {
  srand((unsigned) time(0)*2);
  int randomNumber = rand()%50;
  double bomb_speed = 100;
  double bomb_angle_deg = 40+randomNumber;
  double bomb_ax = -20;
  double bomb_ay  = 15;
  bool paused = true, rtheta = true;
  reset_all(coin_start_x, coin_start_y, bomb_speed, bomb_angle_deg, bomb_ax, bomb_ay, paused, rtheta);
}
void Coin::destroyBoost() {
  double boost_speed = 0;
  double boost_angle_deg = 0;
  double boost_ax = 0;
  double boost_ay  = 0;
  bool paused = true, rtheta = true;
  reset_all(0, 0, boost_speed, boost_angle_deg, boost_ax, boost_ay, paused, rtheta);
}

void Coin::initBall() {
  coin_start_x = 40+(PLAY_X_START+WINDOW_X)/2;
  coin_start_y = PLAY_Y_HEIGHT-400;
  coin_circle.reset(coin_start_x, coin_start_y, COIN_SIZE);
  coin_circle.setColor(COLOR("purple"));
  coin_circle.setFill(true);
  addPart(&coin_circle);
}
void Coin::resetBall() {
  srand((unsigned) time(0)*2);
  int randomNumber = rand()%50;
  double bomb_speed = 100;
  double bomb_angle_deg = -(40+randomNumber);
  double bomb_ax = -20;
  double bomb_ay  = 15;
  bool paused = true, rtheta = true;
  reset_all(coin_start_x, coin_start_y, bomb_speed, bomb_angle_deg, bomb_ax, bomb_ay, paused, rtheta);
}

void Coin::destroyBall() {
  double bomb_speed = 0;
  double bomb_angle_deg = 0;
  double bomb_ax = 0;
  double bomb_ay  = 0;
  bool paused = true, rtheta = true;
  reset_all(0, 0, bomb_speed, bomb_angle_deg, bomb_ax, bomb_ay, paused, rtheta);
}