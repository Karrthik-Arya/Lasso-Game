#ifndef __COIN_H__
#define __COIN_H__
#include<ctime>
#include "MovingObject.h"

class Coin : public MovingObject {
  double coin_start_x;
  double coin_start_y;
  double release_speed;
  double release_angle_deg;
  double coin_ax;
  double coin_ay;

  // Moving parts
  Circle coin_circle;

 public:
 Coin(double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta) : MovingObject(speed, angle_deg, argax, argay, argpaused, rtheta) {
    release_speed = speed;
    release_angle_deg = angle_deg;
    coin_ax = argax;
    coin_ay = argay;
  }
  void initCoin();
  void initCoinsp();
  void resetCoinsp();
  void destroyCoinsp();
  void resetCoin();
  void level1();
  void level2();
  void level3();
  void initlevel4(int a);
  void initBomb();
  void destroyBomb();
  void destroyBoost();
  void resetBomb();
  void initBoost();
  void resetBoost();
  void initBall();
  void resetBall();
  void destroyBall();

}; // End class Coin

#endif
