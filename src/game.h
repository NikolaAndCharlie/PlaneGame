#ifndef _GAME_H_
#define _GAME_H_
#include <QGraphicsScene>
#include <QWidget>
#include "Score.h"
#include "Health.h"


class Game:public QWidget
{
public:
  Game();
  ~Game();
  int score_;
  int health_;
};



#endif //_GAME_H_