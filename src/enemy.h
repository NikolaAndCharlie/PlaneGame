#ifndef _ENEMY_H_
#define _ENEMY_H_
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>
class Enemy :public QObject, public QGraphicsPixmapItem
{
  Q_OBJECT;
public:
  Enemy();
public slots:
  void move();
signals:
  void HealthChanged();
};


#endif
