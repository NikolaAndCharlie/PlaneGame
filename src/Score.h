#ifndef SCORE_H_
#define SCORE_H_
#include <QGraphicsTextItem>

class Score:public QGraphicsTextItem
{
 public:
   Score();
   void IncreaseScore();
   int GetScore(int a);
private:
  int score_;
};




#endif
