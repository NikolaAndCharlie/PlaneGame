#ifndef HEALTH_H_
#define HEALTH_H_
#include <QGraphicsTextItem>

class Health :public QGraphicsTextItem
{
public:
  Health();
  void DreaseHealth();
  int GetHealth(int a);
private:
  int health_;
};




#endif
