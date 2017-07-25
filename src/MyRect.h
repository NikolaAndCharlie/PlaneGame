#ifndef _MyRect_H_
#define _MyRect_H_
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QObject>
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>
class MyRect:public QObject,public QGraphicsPixmapItem
{
  Q_OBJECT
public:
  MyRect();
  void keyPressEvent(QKeyEvent*);
public slots:
  void spawn();
  void Scorechnaged();
  void HealthChanged();
signals:
  void ScoreChange();
  void HealthChange();
private:
  QMediaPlayer *bulletsound_;
};


#endif
