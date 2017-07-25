#include "MyRect.h"
#include "bullet.h"
#include "enemy.h"
#include <QKeyEvent>
#include <stdlib.h>
#include <QGraphicsScene>

MyRect::MyRect()
{
  bulletsound_ = new QMediaPlayer;
  bulletsound_->setMedia(QUrl("bulletsound.mav"));
  setPixmap(QPixmap(":/image/player.png"));
}


void MyRect::keyPressEvent(QKeyEvent*event)
{
  if(event->key() == Qt::Key_Left)
  {
    setPos(x() - 10, y());
    if(pos().x()<0)
    {
      setPos(0, y());
    }
  }
  else if(event->key() == Qt::Key_Right)
  {
    setPos(x() + 10, y());
    if(pos().x()+pixmap().width()>scene()->width())
    {
      setPos(scene()->width() - pixmap().width(), y());
    }
  }
  else if (event->key() == Qt::Key_Up)
  {
    setPos(x(), y() - 10);
  }
  else if(event->key() == Qt::Key_Down)
  {
    setPos(x(), y() + 10);
    if(pos().y()>scene()->height()-pixmap().height())
    {
      setPos(x(), scene()->height()-pixmap().height());
    }
  }
  else if(event->key() == Qt::Key_Space)
  {

    Bullet *bullet = new Bullet();
    connect(bullet, &Bullet::ScoreChanged, this, &MyRect::Scorechnaged);
    bullet->setPos(x()+20, y());
    scene()->addItem(bullet);
    if(bulletsound_->state() == QMediaPlayer::PlayingState)
    {
      bulletsound_->stop();
    }
    else if(bulletsound_->state() == QMediaPlayer::StoppedState)
    {
     bulletsound_->play();
    }
  }
}

void MyRect::spawn()
{
  Enemy *enemy = new Enemy;
  connect(enemy, &Enemy::HealthChanged, this, &MyRect::HealthChanged);
  scene()->addItem(enemy);
}

void MyRect::Scorechnaged()
{
  emit ScoreChange();
}

void MyRect::HealthChanged()
{
  emit HealthChange();
}