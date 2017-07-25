#ifndef _BULLET_H_
#define _BULLET_H_
#include "Score.h"
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>
class Bullet:public QObject,public QGraphicsPixmapItem
{
  Q_OBJECT;
public:
  Bullet();
public slots:
  void move();
signals:
  void ScoreChanged();
  void HealthChanged();
private:
  Score* score_;
  int score_num_;
};


#endif
