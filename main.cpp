/* Author:Karrthik Arya
   The Lasso Game */

#include <simplecpp>
#include <string>
#include "MovingObject.h"
#include "lasso.h"
#include "coin.h"
using namespace simplecpp;
void start(){
  Text t(400,150,"The Lasso game");
  t.setColor(COLOR("blue"));
  Text t2 (400, 200, " 1. Aim of the game is to adjust and throw the lasso to catch as many coins as possible!");
  Text t3(400,220, " 2. Press ] and [ to increase and decrease the angle at which the lasso is thrown ");
  Text t4(400, 240, "3. Press t to finally throw the lasso!");
  Text t5(400, 260, "4. Press y to yank the lasso back ");
  Text t6(400, 280, "5. Press l to open the lasso and catch the coins");
  Text t7(400, 300, "6. Beware of the               !! Catching any bombs would result in a penalty of one coin from your score!");
  Text t7r(210, 300, "red bombs");
  t7r.setColor(COLOR("red"));
  Circle c7(250, 300, 5);
  c7.setColor(COLOR("red"));
  c7.setFill(true);
  Text t8(400, 320, "7. The                 would increase the speed of the lasso and help you catch more coins");
  Text t8r(200,320, " blue boosts");
  t8r.setColor(COLOR("blue"));
  Circle c8(250,320,5);
  c8.setFill(true);
  c8.setColor(COLOR("blue"));
  Text t9(400, 340, "8. Catching the                  however would cause your lasso to slow down");
  Text t9p(310, 340, "purple balls");
  t9p.setColor(COLOR("purple"));
  Circle c9(355, 340, 5);
  c9.setColor(COLOR("purple"));
  c9.setFill(true);
  Text t10(400,360, "9. Make sure to catch the special                 too! Missing them can cost you coins!");
  Text t10r(380, 360, "brown coins");
  t10r.setColor(COLOR("brown"));
  Circle c10(420, 360, 5);
  c10.setColor(COLOR("brown"));
  c10.setFill(true);
  Text t11(400, 380, "There are 4 levels in the game: ");
  Text t12(400,400, "You will get 40s for level1, 80s for all other levels");
  Text t13(400, 430, "Good Luck Catching Coins !!!!!");
  t13.setColor(COLOR("green"));
  Text t1(400,450,"Press any key on your keyboard to start playing!");

  XEvent e;
  while(true){
    t1.setColor(COLOR("red"));
    wait(0.5);
    t1.setColor(COLOR("blue"));
    wait(1);
    bool pendingEv = checkEvent(e);
    if(pendingEv) {
      break;
    }
  }
}
main_program {

  initCanvas("Lasso", WINDOW_X, WINDOW_Y);
  start();
  int stepCount = 0;
  float stepTime = STEP_TIME;
  float runTime = -1; // sec; -ve means infinite
  float currTime = 0;

  // Draw lasso at start position
  double release_speed = INIT_RELEASE_SPEED + RELEASE_SPEED_STEP/2; // m/s
  double release_angle_deg = INIT_RELEASE_ANGLE_DEG; // degrees
  double lasso_ax = 0;
  double lasso_ay = LASSO_G;
  bool paused = true;
  bool rtheta = true;
  Lasso lasso(release_speed, release_angle_deg, lasso_ax, lasso_ay, paused, rtheta);
  bool level2init = false;
  bool level3init = false;
  bool level4init = false;
  Line b1(0, PLAY_Y_HEIGHT, WINDOW_X, PLAY_Y_HEIGHT);
  b1.setColor(COLOR("blue"));
  Line b2(PLAY_X_START, 0, PLAY_X_START, WINDOW_Y);
  b2.setColor(COLOR("blue"));

  string msg("Cmd: _");
  Text charPressed(PLAY_X_START+50, PLAY_Y_HEIGHT+20, msg);
  char coinScoreStr[256];
  char levelStr[256];
  char timeStr[256];
  float levelTime=0;
  sprintf(coinScoreStr, "Coins: %d", lasso.getNumCoins());
  sprintf(levelStr, "Level: %d", lasso.level());
  sprintf(timeStr, "Time: %d", (int)levelTime );
  Text coinScore(PLAY_X_START+50, PLAY_Y_HEIGHT+50, coinScoreStr);
  Text levels(PLAY_X_START+50, PLAY_Y_HEIGHT+75, levelStr);
  Text time1(PLAY_X_START+450, PLAY_Y_HEIGHT+50, timeStr);
  paused = true; rtheta = true;
  double coin_speed = COIN_SPEED;
  double coin_angle_deg = COIN_ANGLE_DEG;
  double coin_ax = 0;
  double coin_ay = COIN_G;
  Coin coin(coin_speed, coin_angle_deg, coin_ax, coin_ay, paused, rtheta);
  coin.initCoin();

  double coin_speed1 = 0;
  double coin_angle_deg1 = 0;
  double coin_ax1 = 0;
  double coin_ay1  = 0;
  Coin coin1(coin_speed1, coin_angle_deg1, coin_ax1, coin_ay1, paused, rtheta);
  Coin coin2(coin_speed1, coin_angle_deg1, coin_ax1, coin_ay1, paused, rtheta);

  double coin_speedsp = 100;
  double coin_angle_degsp = 75;
  double coin_axsp = -10;
  double coin_aysp = 17;
  bool spcoin1 = false, spcoin2 = false;
  Coin spcoin(coin_speedsp, coin_angle_degsp, coin_axsp, coin_aysp, paused, rtheta);

  srand((unsigned) time(0));
  int randomNumber = rand()%50;
  double bomb_speed = 100;
  double bomb_angle_deg = 40+randomNumber;
  double bomb_ax = -20;
  double bomb_ay  = 15;
  bool bombinit = false;
  int bombtime;
  Coin bomb(bomb_speed, bomb_angle_deg,bomb_ax, bomb_ay, paused, rtheta);

  srand((unsigned) time(0)*5);
  int randomNumberboost = rand()%30;
  double boost_speed = 100;
  double boost_angle_deg = 40+randomNumberboost;
  double boost_ax = -20;
  double boost_ay  = 15;
  bool boostinit = false;
  int boosttime=0;
  bool boostCaught=false;
  Coin boost(boost_speed, boost_angle_deg,boost_ax, boost_ay, paused, rtheta);

  srand((unsigned) time(0)*7);
  int randomNumberball = rand()%30;
  double ball_speed = 100;
  double ball_angle_deg = -(40+randomNumberball);
  double ball_ax = -20;
  double ball_ay  = 15;
  bool ballinit = false;
  int balltime=0;
  bool ballCaught=false;
  Coin ball(ball_speed, ball_angle_deg,ball_ax, ball_ay, paused, rtheta);
  // After every COIN_GAP sec, make the coin jump
  double last_coin_jump_end = 0;

  // When t is pressed, throw lasso
  // If lasso within range, make coin stick
  // When y is pressed, yank lasso
  // When l is pressed, loop lasso
  // When q is pressed, quit

  for(;;) {
    if((runTime > 0) && (currTime > runTime)) { break; }
    // Setting the time interval for levels to be over
    if(lasso.getNumCoins()<2){
          if(levelTime>40){
            Text t(450,300,"Time Up!! Game Over!!!");
            t.setColor(COLOR("red"));
            wait(3);
            exit(0);
          }
      }
    else if(lasso.getNumCoins()<=5){
      if(levelTime>80){
        Text t(450,300,"Time Up!! Game Over!!!");
        t.setColor(COLOR("red"));
        wait(3);
        exit(0);
      }
    }
    else if(lasso.getNumCoins()<=9){
        if(levelTime>80){
          Text t(450,300,"Time Up!! Game Over!!!");
          t.setColor(COLOR("red"));
          wait(3);
          exit(0);
        }
    }
    else if(lasso.getNumCoins()<=11){
        if(levelTime>80){
          Text t(450,300,"Time Up!! Game Over!!!");
          t.setColor(COLOR("red"));
          wait(3);
          exit(0);
        }
    }
    else if(lasso.getNumCoins()==12){
        Text t(450, 300, " Congratulations! You won the game!!!!");
        t.setColor(COLOR("green"));
        wait(3);
        exit(0);
    }
    // initializing coins for Level4 
    if(lasso.getNumCoins()>=10){
      coin1.initlevel4(1);
      coin2.initlevel4(-2);
    }
    // initializng bombs, boosts and balls
    if(lasso.getNumCoins()==3 && !bombinit){
      bomb.initBomb();
      bombinit = true;
      bombtime = currTime;
    }
    if(lasso.getNumCoins()==2 && !boostinit){
      boost.initBoost();
      boostinit = true;
      boosttime = currTime;
    }
    if(lasso.getNumCoins()==2 && !ballinit){
      ball.initBall();
      ballinit = true;
      balltime = currTime;
    }
    //Resetting the boost in 40 seconds
    if(lasso.getNumCoins() > 2){
      if(!boostinit){
        boost.resetBoost();
        boostinit = true;
        boosttime = currTime;
      }
      else if(currTime-boosttime >= 40)
        boostinit = false;
    }
    //Setting the duration of the boost
    if(currTime-boosttime>=20 && boostCaught){
        lasso.addSpeed(-RELEASE_SPEED_STEP);
        boostCaught=false;
        Text t2(450, 300, "Boost deactivated");
        t2.setColor(COLOR("blue"));
        wait(1);
      }
      //resetting ball in 42 seconds
      if(lasso.getNumCoins() > 2){
        if(!ballinit){
          ball.resetBall();
          ballinit = true;
          balltime = currTime;
        }
        else if(currTime-balltime >= 42)
        ballinit = false;
    }
    //For duration of slowdown
    if(currTime-balltime>=20 && ballCaught){
        lasso.addSpeed(+RELEASE_SPEED_STEP);
        ballCaught=false;
        Text t2(450, 300, "Slowdown over!!");
        t2.setColor(COLOR("blue"));
        wait(1);
      }
    // resetting bombs
    if(lasso.getNumCoins() > 3){
      if(!bombinit){
        bomb.resetBomb();
        bombinit = true;
        bombtime = currTime;
      }
      else if(currTime-bombtime >= 30)
        bombinit = false;
    }
    // initializing special coins
    if(lasso.getNumCoins() == 3 && !spcoin1){
      spcoin.initCoinsp();
      spcoin1 =true;
    }
    if(lasso.getNumCoins() == 7 && !spcoin2){
      spcoin.resetCoinsp();
      spcoin2 = true;
    }
    XEvent e;
    bool pendingEv = checkEvent(e);
    if(pendingEv) { 
      char c = charFromEvent(e);
      msg[msg.length()-1] = c;
      charPressed.setMessage(msg);
      switch(c) {
      case 't':
	lasso.unpause();
	break;
      case 'y':
	lasso.yank();
    if(lasso.getNumCoins()<=5  && !level2init && lasso.getNumCoins()>1){
          Text t(450, 350, " You have advanced to level 2!!!!");
          t.setColor(COLOR("green"));
          wait(1.5);
          level2init=true;
          levelTime=0;
      }
    else if(lasso.getNumCoins()<=9 && !level3init && lasso.getNumCoins()>5){
          Text t(450, 300, " You have advanced to level 3!!!!");
          t.setColor(COLOR("green"));
          wait(1.5);
          level3init=true;
          levelTime =0;
        }
    else if(lasso.getNumCoins()<=11 && !level4init && lasso.getNumCoins()>9){
          Text t(450, 300, " You have advanced to level 4!!!!");
          t.setColor(COLOR("green"));
          wait(1.5);
          level4init=true;
          levelTime=0;
      }
	break;
      case 'l':
	lasso.loopit();
  if(lasso.getNumCoins() >=3){
    lasso.check_for_bomb(&bomb); //check for bombs being caught
    }
  if(lasso.getNumCoins() >=2){
    lasso.check_for_ball(&ball, &ballCaught); // check for balls being caught
  }
  if(lasso.getNumCoins() >=2){
    lasso.check_for_boost(&boost, &boostCaught); // check for boost being caught
  }
  lasso.check_for_coinsp(&spcoin); // checking for  special coins being caught
	lasso.check_for_coin(&coin);  // checking for coin to be caught in most part of the game
  if(lasso.getNumCoins()>9 && lasso.getNumCoins()<=11){
    lasso.check_for_coin(&coin1); //checking for coins being caught in level4
    lasso.check_for_coin(&coin2);
      }
	wait(STEP_TIME*5);
	break;
      case '[':
	if(lasso.isPaused()) { lasso.addAngle(-RELEASE_ANGLE_STEP_DEG);	}
	break;
      case ']':
	if(lasso.isPaused()) { lasso.addAngle(+RELEASE_ANGLE_STEP_DEG); }
	break;
      case 'q':
	exit(0);
      default:
	break;
      }
    }

    lasso.nextStep(stepTime);

    coin.nextStep(stepTime);
    if(coin.isPaused()) {
      if((currTime-last_coin_jump_end) >= COIN_GAP) {
	     coin.unpause();
      }
    }
    if(spcoin1 || spcoin2){
      spcoin.nextStep(stepTime);
      if(spcoin.isPaused()) {
          spcoin.unpause();
      }
    }
    if(lasso.getNumCoins()>=3&&bombinit){
      bomb.nextStep(stepTime);
    if(bomb.isPaused()) {
          bomb.unpause();
      }
    }
    if(lasso.getNumCoins()>=2 && boostinit){
      boost.nextStep(stepTime);
    if(boost.isPaused()) {
          boost.unpause();
      }
    }
    if(lasso.getNumCoins()>=2 && ballinit){
      ball.nextStep(stepTime);
    if(ball.isPaused()) {
          ball.unpause();
      }
    }
    // What to do after a coin crosses the y-axis
    if(coin.getYPos() > PLAY_Y_HEIGHT) { 
      if(lasso.getNumCoins()<=1)
        coin.level1();
      else if(lasso.getNumCoins()<=5){
        coin.level2();
        if(!level2init){
          Text t(450, 350, " You have advanced to level 2!!!!");
          levelTime=0;
          t.setColor(COLOR("green"));
          wait(1.5);
          level2init=true;
        }
      }
      else if(lasso.getNumCoins()<=9){
        coin.level3();
        if(!level3init){
          levelTime=0;
          Text t(450, 300, " You have advanced to level 3!!!!");
          t.setColor(COLOR("green"));
          wait(1.5);
          level3init=true;
        }
        }
        else if(lasso.getNumCoins()<=11 && !level4init){
          Text t(450, 300, " You have advanced to level 4!!!!");
          levelTime =0;
          t.setColor(COLOR("green"));
          wait(1.5);
          level4init=true;
      }
      last_coin_jump_end = currTime;
    }
    if(spcoin.getYPos() > PLAY_Y_HEIGHT){
      lasso.reduceNumCoins();
      spcoin.destroyCoinsp();
    }

    sprintf(coinScoreStr, "Coins: %d", lasso.getNumCoins());
    coinScore.setMessage(coinScoreStr);
    sprintf(levelStr, "Level: %d", lasso.level());
    levels.setMessage(levelStr);
    stepCount++;
    currTime += stepTime;
    levelTime+=stepTime;
    sprintf(timeStr, "Time: %d", (int)levelTime);
    time1.setMessage(timeStr);
    wait(stepTime);
  } // End for(;;)

  wait(3);
} // End main_program
