#include "vertical.h"

vertical::vertical()
{

}

vertical::~vertical()
{

}

void vertical::spawn(Blank *b[10][10], Blank *clicked, int mode)
{

}

void vertical::elimination(Blank *b[10][10], Blank *clicked)
{
    clicked->number=0;
    eliminate *e;
    int col= clicked->column;
    int TenNum[10]={0};

    for (int i=0; i<10; i++)
    {
        if(b[i][col]->number/10 !=0)
            TenNum[i]=b[i][col]->number%10;
    }

    for (int i=0; i<10; i++)
    {
        switch (TenNum[i]){
        case 0: b[i][col]->number=0;break;
        case 1://爆
            e= new vertical;
            e->elimination(b, b[i][col]);
            delete e;break;
        case 2://爆
            e= new horizontal;
            e->elimination(b,b[i][col]);
            delete e;break;
        case 3://爆
            e= new box;
            e->elimination(b,b[i][col]);
            delete e;break;
        }
    }
}

int vertical::condition(Blank *b[10][10], Blank *clicked)
{

}

