#include "game.h"
#include "MyRect.h"
#include "Score.h"
#include <QGraphicsView>
#include <QTimer>
#include <QHBoxLayout>
#include<QMediaPlayer>

Game::Game()
  : score_(0)
  , health_(10)
{
  QGraphicsScene *scene = new QGraphicsScene;
  MyRect *player = new MyRect;
  player->setFlag(QGraphicsItem::ItemIsFocusable);
  player->setFocus();
  scene->addItem(player);
  QGraphicsView *view = new QGraphicsView;
  view->setScene(scene);
  view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setFixedSize(800, 600);
  scene->setSceneRect(0, 0, 800, 600);
  scene->setBackgroundBrush(QBrush(QImage(":/image/bg.png")));
  player->setPos(view->width() / 2, view->height() - player->pixmap().height());

  QTimer *time = new QTimer;
  QObject::connect(time, SIGNAL(timeout()), player, SLOT(spawn()));
  time->start(2000);
  
  Score *score = new Score();
  connect(player,&MyRect::ScoreChange,this,[=]()
  {
    score_ +=1;
    score->GetScore(score_);
  });
  scene->addItem(score);

  Health *health = new Health();
  connect(player,&MyRect::HealthChange,this,[=]()
  {
    health_--;
    health->GetHealth(health_);
  });
  scene->addItem(health);
  health->setPos(pos().x(), pos().y() + 25);

  QMediaPlayer *music = new QMediaPlayer();
  music->setMedia(QUrl("E:/project/game/src/sound/background.mp3"));
  music->play();
  QHBoxLayout *main_layout = new QHBoxLayout;
  main_layout->addWidget(view);
  this->setLayout(main_layout);

}
Game::~Game()
{
  
}