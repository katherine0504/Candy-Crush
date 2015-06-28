#ifndef BLANK_H
#define BLANK_H

#include <QPushButton>
#include <QObject>
#include <QTimer>

class Blank:public QObject
{
    Q_OBJECT;
public:
    Blank(int R, int C, QWidget*parent);
    ~Blank();
    const int row;
    const int column;
    int number;
    int shift;
    QPushButton *button;
    QTimer *time;
    void setNumber();
    void setButtonPic();
    void operator -(Blank *b);
    void operator |(Blank *b);

public slots:
    void click();
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();

signals:
    void Click(int R, int C);
    void finishMove();
};

#endif // BLANK_H
