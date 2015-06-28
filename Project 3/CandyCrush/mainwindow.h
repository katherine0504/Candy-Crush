#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <ctime>
#include <cstdlib>
#include <QString>

#include "blank.h"
#include "eliminate.h"
#include "clean5.h"
#include "clean4.h"
#include "clean3v.h"
#include "clean3h.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool isClicked=false;
    int record_R;
    int record_C;
    int score=0;
    int steps=20;
    void gameStart();
    void setClickPicture(Blank*b);
    bool judge(int row1, int col1,int row2, int col2);//find the blocks to destroy
    bool judgeDoubleStar(int row1, int col1,int row2, int col2);
    bool judgeBombStar(int row1, int col1,int row2, int col2);
    bool judgeOneStar(int row1, int col1,int row2, int col2);
    bool judgeStar(int row, int col);
    bool judgeBox(int row, int col);
    bool judgeLine(int row, int col);
    bool judgeHorThree(int row, int col);
    bool judgeVerThree(int row, int col);
    bool moveZero();//把零移到最上面
    bool canEliminate();//找在一次的移動中還有沒有可能被消除的可能性
    bool cannotPlay();//如果移動完之後 找整個棋盤還有沒有可以移動的可能性
    void fillInZero();
    void renewPic();
    void resetMap();
    QString str;
    QString stp;

private:
    Ui::MainWindow *ui;
    Blank *b[10][10];

public slots:
    void button_clicked(int R, int C);
    void zeroVanish();
private slots:
    void on_pushButton_clicked();
    void on_reset_clicked();
};

#endif // MAINWINDOW_H
