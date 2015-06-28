#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: white;");

    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            b[i][j]= new Blank(i,j,this);
            connect(b[i][j], SIGNAL(Click(int,int)), this, SLOT(button_clicked(int, int)));
            connect(b[i][j], SIGNAL(finishMove()), this, SLOT(zeroVanish()));
        }
    }

    gameStart();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::gameStart()
{
  //  ui->WIN->hide();
  //  ui->LOSE->hide();
    score=0;
    str= QString::number(score,10);
    ui->scoreText->setText(str);
    steps=20;
    stp= QString::number(steps,10);
    ui->stepsText->setText(stp);

    for(int i=0; i<10; i++)//row
    {
        for (int j=0; j<10; j++)//column
        {
            b[i][j]->setNumber();
            b[i][j]->setButtonPic();

            if (j>=2 && (b[i][j]->number == b[i][j-2]->number) && (b[i][j]->number == b[i][j-1]->number))
            {
                j--;
            }

            if (i>=2 && (b[i][j]->number == b[i-2][j]->number) && (b[i][j]->number == b[i-1][j]->number))
            {
                j--;
            }
        }
    }
}

void MainWindow::setClickPicture(Blank *b)
{
    if(!isClicked)
    {
        switch(b->number){
        case 1:b->button->setIcon(QIcon(QPixmap(":/pic/PIC/1c.png")));
               b->button->setIconSize(b->button->size());break;
        case 2:b->button->setIcon(QIcon(QPixmap(":/pic/PIC/2c.png")));
               b->button->setIconSize(b->button->size());break;
        case 3:b->button->setIcon(QIcon(QPixmap(":/pic/PIC/3c.png")));
               b->button->setIconSize(b->button->size());break;
        case 4:b->button->setIcon(QIcon(QPixmap(":/pic/PIC/4c.png")));
               b->button->setIconSize(b->button->size());break;
        case 5:b->button->setIcon(QIcon(QPixmap(":/pic/PIC/5c.bmp")));
               b->button->setIconSize(b->button->size());break;
        case 11:b->button->setIcon(QIcon(QPixmap(":/pic/PIC/11c.png")));
               b->button->setIconSize(b->button->size());break;
        case 12:b->button->setIcon(QIcon(QPixmap(":/pic/PIC/12c.png")));
               b->button->setIconSize(b->button->size());break;
        case 13:b->button->setIcon(QIcon(QPixmap(":/pic/PIC/13c.png")));
               b->button->setIconSize(b->button->size());break;
        case 21:b->button->setIcon(QIcon(QPixmap(":/pic/PIC/21c.png")));
               b->button->setIconSize(b->button->size());break;
        case 22:b->button->setIcon(QIcon(QPixmap(":/pic/PIC/22c.png")));
               b->button->setIconSize(b->button->size());break;
        case 23:b->button->setIcon(QIcon(QPixmap(":/pic/PIC/23c.png")));
               b->button->setIconSize(b->button->size());break;
        case 31:b->button->setIcon(QIcon(QPixmap(":/pic/PIC/31c.png")));
               b->button->setIconSize(b->button->size());break;
        case 32:b->button->setIcon(QIcon(QPixmap(":/pic/PIC/32c.png")));
               b->button->setIconSize(b->button->size());break;
        case 33:b->button->setIcon(QIcon(QPixmap(":/pic/PIC/33c.png")));
               b->button->setIconSize(b->button->size());break;
        case 41:b->button->setIcon(QIcon(QPixmap(":/pic/PIC/41c.png")));
               b->button->setIconSize(b->button->size());break;
        case 42:b->button->setIcon(QIcon(QPixmap(":/pic/PIC/42c.png")));
               b->button->setIconSize(b->button->size());break;
        case 43:b->button->setIcon(QIcon(QPixmap(":/pic/PIC/43c.png")));
               b->button->setIconSize(b->button->size());break;
        }
    }
    else
    {
        b->setButtonPic();
    }
}

bool MainWindow::judge(int row1, int col1, int row2, int col2)
{
 //   if (steps==0)
 //           ui->LOSE->show();
    bool hasEliminated[13];
    hasEliminated[0]= judgeDoubleStar(row1, col1, row2, col2);
    hasEliminated[1]= judgeBombStar(row1, col1, row2, col2);
    hasEliminated[2]= judgeOneStar(row1, col1, row2, col2);
    hasEliminated[3]= judgeStar(row1, col1);
    hasEliminated[4]= judgeStar(row2, col2);
    hasEliminated[5]= judgeBox(row1, col1);
    hasEliminated[6]= judgeBox(row2, col2);
    hasEliminated[7]= judgeLine(row1, col1);
    hasEliminated[8]= judgeLine(row2, col2);
    hasEliminated[9]= judgeHorThree(row1, col1);
    hasEliminated[10]= judgeHorThree(row2, col2);
    hasEliminated[11]= judgeVerThree(row1, col1);
    hasEliminated[12]= judgeVerThree(row2, col2);

    //算分
    if (hasEliminated[0]) {score=score+2000;str= QString::number(score,10);ui->scoreText->setText(str);}
    if (hasEliminated[1]) {score=score+1500;str= QString::number(score,10);ui->scoreText->setText(str);}
    if (hasEliminated[2]) {score=score+1000;str= QString::number(score,10);ui->scoreText->setText(str);}
    if (hasEliminated[3]) {score=score+800;str= QString::number(score,10);ui->scoreText->setText(str);}
    if (hasEliminated[4]) {score=score+800;str= QString::number(score,10);ui->scoreText->setText(str);}
    if (hasEliminated[5]) {score=score+500;str= QString::number(score,10);ui->scoreText->setText(str);}
    if (hasEliminated[6]) {score=score+500;str= QString::number(score,10);ui->scoreText->setText(str);}
    if (hasEliminated[7]) {score=score+250;str= QString::number(score,10);ui->scoreText->setText(str);}
    if (hasEliminated[8]) {score=score+250;str= QString::number(score,10);ui->scoreText->setText(str);}
    if (hasEliminated[9]) {score=score+100;str= QString::number(score,10);ui->scoreText->setText(str);}
    if (hasEliminated[10]) {score=score+100;str= QString::number(score,10);ui->scoreText->setText(str);}
    if (hasEliminated[11]) {score=score+100;str= QString::number(score,10);ui->scoreText->setText(str);}
    if (hasEliminated[12]) {score=score+100;str= QString::number(score,10);ui->scoreText->setText(str);}

 //   if (score>4000)
 //               ui->WIN->show();

    qDebug()<< "score" << score;
    for (int i=0; i<13; i++)
    {
        if (hasEliminated[i]==true)
        {
            steps=steps-1;
            stp= QString::number(steps,10);
            ui->stepsText->setText(stp);
            qDebug() << steps;
            return true;
        }
    }
    return false;
}

bool MainWindow::judgeDoubleStar(int row1, int col1, int row2, int col2)
{
    bool anySpawn=false;
    if (b[row1][col1]->number==5 && b[row2][col2]->number==5)
    {
        qDebug() << "Double Star";
        for (int i=0; i<10; i++)
        {
            for (int j=0; j<10; j++)
                b[i][j]->number=0;
        }
        resetMap();
        anySpawn=true;
    }
    return anySpawn;
}

bool MainWindow::judgeBombStar(int row1, int col1, int row2, int col2)
{
    bool anySpawn=false;
    if (b[row1][col1]->number==5 && b[row2][col2]->number>10 && b[row2][col2]->number%10!=0)
    {
        qDebug() << "Bomb Star-1";
        int color= b[row2][col2]->number/10;
        int bomb= b[row2][col2]->number%10;
        b[row1][col1]->number=b[row2][col2]->number;
        b[row2][col2]->number=0;
        for (int i=0; i<10; i++)
        {
            for (int j=0; j<10; j++)
            {
                if (b[i][j]->number==color)
                {
                    b[i][j]->number=color*10+bomb;
                    switch(bomb){
                    eliminate *e;
                    case 1://爆
                        e= new vertical;
                        e->elimination(b, b[i][j]);
                        delete e;break;
                    case 2://爆
                        e= new horizontal;
                        e->elimination(b,b[i][j]);
                        delete e;break;
                    case 3://爆
                        e= new box;
                        e->elimination(b,b[i][j]);
                        delete e;break;
                    }
                }
            }
        }anySpawn=true;
    }

    if (b[row2][col2]->number==5 && b[row1][col1]->number>10 && b[row1][col1]->number%10!=0)
    {
        qDebug() << "Bomb Star-2";
        int color= b[row1][col1]->number/10;
        int bomb= b[row1][col1]->number%10;
        b[row2][col2]->number=b[row1][col1]->number;
        b[row1][col1]->number=0;
        for (int i=0; i<10; i++)
        {
            for (int j=0; j<10; j++)
            {
                if (b[i][j]->number==color)
                {
                    b[i][j]->number=color*10+bomb;
                    switch(bomb){
                    eliminate *e;
                    case 1://爆
                        e= new vertical;
                        e->elimination(b, b[i][j]);
                        delete e;break;
                    case 2://爆
                        e= new horizontal;
                        e->elimination(b,b[i][j]);
                        delete e;break;
                    case 3://爆
                        e= new box;
                        e->elimination(b,b[i][j]);
                        delete e;break;
                    }
                }
            }
        }anySpawn=true;
    }return anySpawn;
}

bool MainWindow::judgeOneStar(int row1, int col1, int row2, int col2)
{
    bool anySpawn=false;
    if (b[row1][col1]->number==5 && b[row2][col2]->number<5 )
    {
        qDebug() << "One Star-1";
        int color= b[row2][col2]->number;
        b[row1][col1]->number=b[row2][col2]->number;
        b[row2][col2]->number=0;
        for (int i=0; i<10; i++)
        {
            for (int j=0; j<10; j++)
            {
                if (b[i][j]->number/10==color || b[i][j]->number==color)
                    b[i][j]->number=0;
            }
        }anySpawn=true;
    }
    if (b[row2][col2]->number==5 && b[row1][col1]->number<=5 )
    {
        qDebug() << "One Star-2";
        int color= b[row1][col1]->number;
        b[row2][col2]->number=b[row1][col1]->number;
        b[row1][col1]->number=0;
        for (int i=0; i<10; i++)
        {
            for (int j=0; j<10; j++)
            {
                if (b[i][j]->number/10==color || b[i][j]->number==color)
                    b[i][j]->number=0;
            }
        }anySpawn=true;
    }
    return anySpawn;
}

bool MainWindow::judgeStar(int row, int col)
{
    int returnValue;
    bool anySpawn=false;

    eliminate *e= new clean5;
    returnValue= e->condition(b, b[row][col]);

    if (returnValue)
    {
        switch(returnValue){
        case 1:
            e->spawn(b,b[row][col],1);
            anySpawn=true;break;
        case 2:
            e->spawn(b,b[row][col],2);
            anySpawn=true;break;
        case 3:
            e->spawn(b,b[row][col],3);
            anySpawn=true;break;
        case 4:
            e->spawn(b,b[row][col],4);
            anySpawn=true;break;

        }
    }
    delete e;
    return anySpawn;
}

bool MainWindow::judgeBox(int row, int col)
{
    int returnValue;
    bool anySpawn=false;

    eliminate *e= new box;
    returnValue= e->condition(b, b[row][col]);

    if (returnValue)
    {
        switch(returnValue){
        case 1:
            e->spawn(b,b[row][col],1);
            anySpawn=true;break;
        case 2:
            e->spawn(b,b[row][col],2);
            anySpawn=true;break;
        case 3:
            e->spawn(b,b[row][col],3);
            anySpawn=true;break;
        case 4:
            e->spawn(b,b[row][col],4);
            anySpawn=true;break;
        case 5:
            e->spawn(b,b[row][col],5);
            anySpawn=true;break;
        case 6:
            e->spawn(b,b[row][col],6);
            anySpawn=true;break;
        case 7:
            e->spawn(b,b[row][col],7);
            anySpawn=true;break;
        case 8:
            e->spawn(b,b[row][col],8);
            anySpawn=true;break;
        case 9:
            e->spawn(b,b[row][col],9);
            anySpawn=true;break;
        case 10:
            e->spawn(b,b[row][col],10);
            anySpawn=true;break;
        case 11:
            e->spawn(b,b[row][col],11);
            anySpawn=true;break;
        case 12:
            e->spawn(b,b[row][col],12);
            anySpawn=true;break;
        case 13:
            e->spawn(b,b[row][col],13);
            anySpawn=true;break;
        case 14:
            e->spawn(b,b[row][col],14);
            anySpawn=true;break;
        case 15:
            e->spawn(b,b[row][col],15);
            anySpawn=true;break;
        case 16:
            e->spawn(b,b[row][col],16);
            anySpawn=true;break;
        }
    }
    delete e;
    return anySpawn;
}

bool MainWindow::judgeLine(int row, int col)
{
    int returnValue;
    bool anySpawn=false;

    eliminate *e= new clean4;
    returnValue= e->condition(b, b[row][col]);

    if (returnValue)
    {
        switch(returnValue){
        case 1:
            e->spawn(b,b[row][col],1);
            anySpawn=true;break;
        case 2:
            e->spawn(b,b[row][col],2);
            anySpawn=true;break;
        case 3:
            e->spawn(b,b[row][col],3);
            anySpawn=true;break;
        case 4:
            e->spawn(b,b[row][col],4);
            anySpawn=true;break;
        case 5:
            e->spawn(b,b[row][col],5);
            anySpawn=true;break;
        case 6:
            e->spawn(b,b[row][col],6);
            anySpawn=true;break;
        case 7:
            e->spawn(b,b[row][col],7);
            anySpawn=true;break;
        case 8:
            e->spawn(b,b[row][col],8);
            anySpawn=true;break;
        }
    }
    delete e;
    return anySpawn;
}

bool MainWindow::judgeHorThree(int row, int col)
{
    int returnValue;
    bool anySpawn=false;

    eliminate *e= new clean3h;
    returnValue= e->condition(b, b[row][col]);

    if (returnValue)
    {
        switch(returnValue){
        case 1:
            e->spawn(b,b[row][col],1);
            anySpawn=true;break;
        case 2:
            e->spawn(b,b[row][col],2);
            anySpawn=true;break;
        case 3:
            e->spawn(b,b[row][col],3);
            anySpawn=true;break;
        case 4:
            e->spawn(b,b[row][col],4);
            anySpawn=true;break;
        case 5:
            e->spawn(b,b[row][col],5);
            anySpawn=true;break;
        case 6:
            e->spawn(b,b[row][col],6);
            anySpawn=true;break;
        }
    }
    delete e;
    return anySpawn;
}

bool MainWindow::judgeVerThree(int row, int col)
{
    int returnValue;
    bool anySpawn=false;

    eliminate *e= new clean3v;
    returnValue= e->condition(b, b[row][col]);

    if (returnValue)
    {
        switch(returnValue){
        case 1:
            e->spawn(b,b[row][col],1);
            anySpawn=true;break;
        case 2:
            e->spawn(b,b[row][col],2);
            anySpawn=true;break;
        case 3:
            e->spawn(b,b[row][col],3);
            anySpawn=true;break;
        case 4:
            e->spawn(b,b[row][col],4);
            anySpawn=true;break;
        case 5:
            e->spawn(b,b[row][col],5);
            anySpawn=true;break;
        case 6:
            e->spawn(b,b[row][col],6);
            anySpawn=true;break;
        }
    }
    delete e;
    return anySpawn;
}

bool MainWindow::moveZero()
{
    for (int i=9; i>=0; i--)
    {
        for (int j=9; j>=0; j--)
        {
            if (b[i][j]->number==0)
            {
                for (int k=i; k>=0; k--)
                {
                    if (b[k][j]->number!=0)
                    {
                        b[i][j]->number=b[k][j]->number;
                        b[k][j]->number=0;
                        break;
                    }
                }
            }
        }
    }
}

bool MainWindow::canEliminate()//找在一次的移動中還有沒有可能被消除的可能性
{
    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            if (judgeStar(i, j)==true)
                return true;
        }
    }
    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            if (judgeBox(i, j)==true)
                return true;
        }
    }
    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            if (judgeLine(i, j)==true)
                return true;
        }
    }
    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            if (judgeHorThree(i, j)==true)
                return true;
        }
    }
    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            if (judgeVerThree(i, j)==true)
                return true;
        }
    }
    return false;
}

bool MainWindow::cannotPlay()
{
    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            if (b[i][j]->number==5) return false;
        }
    }//check for existing stars

    for (int i=0; i<10; i++)
    {
        for (int j=0; j<9; j++)
        {
            qDebug() << "In check horizontally";
            qDebug() << b[i][j]->number;
            int temp=0;
            temp=b[i][j]->number;
            b[i][j]->number=b[i][j+1]->number;
            b[i][j+1]->number=temp;
            if (judgeVerThree(i,j) || judgeHorThree(i,j+1))
            {
                temp=b[i][j]->number;
                b[i][j]->number=b[i][j+1]->number;
                b[i][j+1]->number=temp;
            }

            temp=b[i][j]->number;
            b[i][j]->number=b[i][j+1]->number;
            b[i][j+1]->number=temp;
            qDebug() << b[i][j]->number << "Out check horizontally" ;
        }
    }

    for (int i=0; i<9; i++)
    {
        for (int j=0; j<10; j++)
        {
            qDebug() << "In check vertically";
            qDebug() << b[i][j]->number;
            int temp=0;
            temp=b[i][j]->number;
            b[i][j]->number=b[i+1][j]->number;
            b[i+1][j]->number=temp;
            if (judgeVerThree(i,j)==true)
            {
                b[i+1][j]->number=b[i][j]->number;
                b[i][j]->number=temp;
                qDebug() << "ver" << b[i][j]->number;
                return false;
            }
            if (judgeHorThree(i,j)==true)
            {
                b[i+1][j]->number=b[i][j]->number;
                b[i][j]->number=temp;
                qDebug() << "hor" << b[i][j]->number;
                return false;
            }
            b[i+1][j]->number=b[i][j]->number;
            b[i][j]->number=temp;
            qDebug() <<b[i][j]->number << "Out check vertically" ;
        }
    }
    qDebug() << "Cannot play==true";
    return true;
}

void MainWindow::fillInZero()
{
    for (int i=9; i>=0; i--)
    {
        for (int j=9; j>=0; j--)
        {
            if (b[i][j]->number==0)
            {
                b[i][j]->setNumber();
                if (j<=7 && (b[i][j]->number==b[i][j+1]->number || b[i][j]->number==b[i][j+1]->number/10) && (b[i][j]->number==b[i][j+2]->number || b[i][j]->number==b[i][j+2]->number/10))
                {
                    b[i][j]->number=0;
                    j++;
                }//檢查右邊
                if (j>=2 && (b[i][j]->number==b[i][j-1]->number || b[i][j]->number==b[i][j-1]->number/10) && (b[i][j]->number==b[i][j-2]->number || b[i][j]->number==b[i][j-2]->number/10))
                {
                    b[i][j]->number=0;
                    j++;
                }//檢查左邊
                if (i<=7 && (b[i][j]->number==b[i+1][j]->number || b[i][j]->number==b[i+1][j]->number/10) && (b[i][j]->number==b[i+2][j]->number || b[i][j]->number==b[i+2][j]->number/10))
                {
                    b[i][j]->number=0;
                    j++;
                }//檢查下面
                if (j>=1 && j<=8 && (b[i][j]->number==b[i][j-1]->number || b[i][j]->number==b[i][j-1]->number/10) && (b[i][j]->number==b[i][j+1]->number || b[i][j]->number==b[i][j+1]->number/10))
                {
                    b[i][j]->number=0;
                    j++;
                }
            }
        }
    }
}

void MainWindow::renewPic()
{
    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            b[i][j]->setButtonPic();
        }
    }
}

void MainWindow::resetMap()
{
    qDebug() << "In reset map";

    //Initialize all the blocks
    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            b[i][j]->number=0;
        }
    }

    for(int i=0; i<10; i++)//row
    {
        for (int j=0; j<10; j++)//column
        {
            b[i][j]->setNumber();
            b[i][j]->setButtonPic();

            if (j>=2 && (b[i][j]->number == b[i][j-2]->number) && (b[i][j]->number == b[i][j-1]->number))
            {j--;}

            if (i>=2 && (b[i][j]->number == b[i-2][j]->number) && (b[i][j]->number == b[i-1][j]->number))
            {j--;}
        }
    }

    if (cannotPlay()==true){resetMap();}
}


void MainWindow::button_clicked(int R, int C)
{
    qDebug() << b[R][C]->number;

    if (!isClicked)
    {
        setClickPicture(b[R][C]);
        isClicked=true;
        record_R= R;
        record_C= C;
    }
    else
    {
        if (record_R==R && record_C==C-1)//left
        {
            *b[record_R][record_C]-b[R][C];
            if (!judge(record_R,record_C,R,C))
            {
                *b[R][C]-b[record_R][record_C];
            }
        }
        else if (record_R==R && record_C==C+1)//right
        {
            *b[R][C]-b[record_R][record_C];
            if (!judge(record_R,record_C,R,C))
            {
                *b[record_R][record_C]-b[R][C];
            }
        }
        else if (record_R==R-1 && record_C==C)//up
        {
            *b[record_R][record_C]|b[R][C];
            if (!judge(record_R,record_C,R,C))
            {
                *b[R][C]|b[record_R][record_C];
            }
        }
        else if (record_R==R+1 && record_C==C)//down
        {
            *b[R][C]|b[record_R][record_C];
            if (!judge(record_R,record_C,R,C))
            {
                *b[record_R][record_C]|b[R][C];
            }
        }
        else
        {
            setClickPicture(b[record_R][record_C]);
        }
        isClicked=false;
    }
}

void MainWindow::zeroVanish()
{
    while(1)
    {
        qDebug() << "In while (1)";
        moveZero();
        qDebug() << "end moveZero";
        if (canEliminate()==false) break;
    }
    qDebug() << "start fillInZero";
    fillInZero();
    qDebug() << "start cannotPlayJudge";
  /*  if (cannotPlay()==true){
        qDebug() << "Start Reset Map";
        resetMap();}*/

    renewPic();
}

void MainWindow::on_pushButton_clicked()
{
    this->close();
}

void MainWindow::on_reset_clicked()
{
    gameStart();
}
