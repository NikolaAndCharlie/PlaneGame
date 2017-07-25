#include "Health.h"
#include <QFont>

Health::Health()
  : health_(10)
{
  setPlainText(QString("Health: %1").arg(health_));
  setDefaultTextColor(Qt::green);
  setFont(QFont("times", 16));
}

int Health::GetHealth(int a)
{
  setPlainText(QString("Health: %1").arg(a));
  return a;
  
}

void Health::DreaseHealth()
{
  
}


