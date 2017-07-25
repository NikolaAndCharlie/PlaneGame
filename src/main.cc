#include "game.h"
#include <QApplication>


Game *g;
int main(int argc,char* argv[])
{
  QApplication a(argc, argv);
  g = new Game;
  g->show();
  a.exec();
}