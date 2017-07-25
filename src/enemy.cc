#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>


Enemy::Enemy()
{
  int random_number = rand() % 700;
  setPos(random_number, 0);
  setPixmap(QPixmap(":/image/enemy.jpg"));
  setTransformOriginPoint(50, 50);
  setRotation(180);
  QTimer *time = new QTimer();
  QObject::connect(time, &QTimer::timeout, this, &Enemy::move);
  time->start(50);
}

void Enemy::move()
{
  setPos(x(), y() + 5);
  if(pos().y()>scene()->height())
  {
    scene()->removeItem(this);
    emit HealthChanged();
    delete this;
  }
}

