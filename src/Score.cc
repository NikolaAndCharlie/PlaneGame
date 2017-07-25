#include "Score.h"
#include <QFont>

Score::Score()
  : score_(0)
{
  setPlainText(QString("Score: %1").arg(score_));
  setDefaultTextColor(Qt::green);
  setFont(QFont("times",16));
}

int Score::GetScore(int a)
{
  setPlainText(QString("Score: %1").arg(a));
  return a;
}

void Score::IncreaseScore()
{

}


