#include "bullet.h"
#include "enemy.h"
#include "Score.h"
#include "game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>


Bullet::Bullet()
  : score_num_(0)
{
  setPixmap(QPixmap(":/image/bullet.png"));
  QTimer *time = new QTimer();
  QObject::connect(time, &QTimer::timeout, this, &Bullet::move);
  time->start(50);
}

void Bullet::move()
{
  QList<QGraphicsItem* > colliding_items = collidingItems();
  for(int i = 0,n = colliding_items.size();i<n;i++)
  {
    if(typeid(*(colliding_items[i])) == typeid(Enemy))
    {
      emit ScoreChanged();
      scene()->removeItem(colliding_items[i]);
      scene()->removeItem(this);
      delete colliding_items[i];
      delete this;
      return;
    }
  }


  setPos(x(), y() - 10);
  if(pos().y()+pixmap().height()<0)
  {
    scene()->removeItem(this);
    delete this;
  }
}

