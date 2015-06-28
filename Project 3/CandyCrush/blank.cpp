#include "blank.h"

Blank::Blank(int R, int C, QWidget*parent):row(R),column(C),QObject(parent)
{
    button=new QPushButton(parent);
    button->setGeometry(column* 100, row* 100, 100, 100);
    connect(button,SIGNAL(clicked()),this, SLOT(click()));

    shift=1;
    time= new QTimer();

}

Blank::~Blank()
{

}

void Blank::setNumber()
{
    number= rand()%4+1;

}

void Blank::setButtonPic()
{
    switch(number){
    case 1:button->setIcon(QIcon(QPixmap(":/pic/PIC/1.png")));
           button->setIconSize(button->size());break;
    case 2:button->setIcon(QIcon(QPixmap(":/pic/PIC/2.png")));
           button->setIconSize(button->size());break;
    case 3:button->setIcon(QIcon(QPixmap(":/pic/PIC/3.png")));
           button->setIconSize(button->size());break;
    case 4:button->setIcon(QIcon(QPixmap(":/pic/PIC/4.png")));
           button->setIconSize(button->size());break;
    case 5:button->setIcon(QIcon(QPixmap(":/pic/PIC/5.bmp")));
           button->setIconSize(button->size());break;
    case 11:button->setIcon(QIcon(QPixmap(":/pic/PIC/11.png")));
            button->setIconSize(button->size());break;
    case 21:button->setIcon(QIcon(QPixmap(":/pic/PIC/21.png")));
            button->setIconSize(button->size());break;
    case 31:button->setIcon(QIcon(QPixmap(":/pic/PIC/31.png")));
            button->setIconSize(button->size());break;
    case 41:button->setIcon(QIcon(QPixmap(":/pic/PIC/41.png")));
            button->setIconSize(button->size());break;
    case 12:button->setIcon(QIcon(QPixmap(":/pic/PIC/12.png")));
            button->setIconSize(button->size());break;
    case 22:button->setIcon(QIcon(QPixmap(":/pic/PIC/22.png")));
            button->setIconSize(button->size());break;
    case 32:button->setIcon(QIcon(QPixmap(":/pic/PIC/32.png")));
            button->setIconSize(button->size());break;
    case 42:button->setIcon(QIcon(QPixmap(":/pic/PIC/42.png")));
            button->setIconSize(button->size());break;
    case 13:button->setIcon(QIcon(QPixmap(":/pic/PIC/13.png")));
            button->setIconSize(button->size());break;
    case 23:button->setIcon(QIcon(QPixmap(":/pic/PIC/23.png")));
            button->setIconSize(button->size());break;
    case 33:button->setIcon(QIcon(QPixmap(":/pic/PIC/33.png")));
            button->setIconSize(button->size());break;
    case 43:button->setIcon(QIcon(QPixmap(":/pic/PIC/43.png")));
            button->setIconSize(button->size());break;
    default:button->setIcon(QIcon(QPixmap(":/pic/PIC/")));break;
    }
}

void Blank::operator -(Blank *b)
{
    int tmpNum=b->number;
    b->number=number;
    number=tmpNum;

    connect(time, SIGNAL(timeout()), this, SLOT(moveRight()));
    connect(b->time, SIGNAL(timeout()), b, SLOT(moveLeft()));

    time->start(40);
    b->time->start(40);
}

void Blank::operator |(Blank *b)
{
    int tmpNum=b->number;
    b->number=number;
    number=tmpNum;

    connect(time, SIGNAL(timeout()), this, SLOT(moveDown()));
    connect(b->time, SIGNAL(timeout()), b, SLOT(moveUp()));

    time->start(40);
    b->time->start(40);
}

void Blank::click()
{
    emit Click(row, column);
}

void Blank::moveLeft()
{
    button->setGeometry(column*100-shift*20, row*100, 100, 100);
    shift++;

    if (shift == 6)
    {
        shift=1;
        disconnect(time, SIGNAL(timeout()), this, SLOT(moveLeft()));
        button->setGeometry(column*100, row*100, 100, 100);
        setButtonPic();
        emit finishMove();
    }
}

void Blank::moveRight()
{
    button->setGeometry(column*100+shift*20, row*100, 100,100);
    shift++;

    if (shift == 6)
    {
        shift=1;
        disconnect(time, SIGNAL(timeout()),this, SLOT(moveRight()));
        button->setGeometry(column*100, row*100, 100, 100);
        setButtonPic();
    }
}

void Blank::moveUp()
{
    button->setGeometry(column*100, row*100-shift*20, 100,100);
    shift++;

    if (shift == 6)
    {
        shift=1;
        disconnect(time, SIGNAL(timeout()),this, SLOT(moveUp()));
        button->setGeometry(column*100, row*100, 100, 100);
        setButtonPic();
        emit finishMove();
    }
}

void Blank::moveDown()
{
    button->setGeometry(column*100, row*100+shift*20, 100,100);
    shift++;

    if (shift == 6)
    {
        shift=1;
        disconnect(time, SIGNAL(timeout()),this, SLOT(moveDown()));
        button->setGeometry(column*100, row*100, 100, 100);
        setButtonPic();
    }
}

