#include "horizontal.h"

horizontal::horizontal()
{

}

horizontal::~horizontal()
{

}

void horizontal::spawn(Blank *b[10][10], Blank *clicked, int mode)
{

}

void horizontal::elimination(Blank *b[10][10], Blank *clicked)
{

    clicked->number=0;
    eliminate *e;
    int row= clicked->row;
    int TenNum[10]={0};

    for (int i=0; i<10; i++)
    {
        if(b[row][i]->number/10 !=0)
            TenNum[i]=b[row][i]->number%10;
    }

    for (int i=0; i<10; i++)
    {
        switch (TenNum[i]){
        case 0: b[row][i]->number=0;break;
        case 1://爆
            e= new vertical;
            e->elimination(b, b[row][i]);
            delete e;break;
        case 2://爆
            e= new horizontal;
            e->elimination(b,b[row][i]);
            delete e;break;
        case 3://爆
            e= new box;
            e->elimination(b,b[row][i]);
            delete e;break;
        }
    }
}

int horizontal::condition(Blank *b[10][10], Blank *clicked)
{

}

