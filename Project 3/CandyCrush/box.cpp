#include "box.h"

box::box()
{

}

box::~box()
{

}

void box::spawn(Blank *b[10][10], Blank *clicked, int mode)
{
    int row= clicked->row;
    int col= clicked->column;
    int num= clicked->number;
    int FiveNum[5]={0};

    switch(mode){
    case 1:
        clicked->number=clicked->number*10+3;
        if (row>=1 && (num==b[row-1][col]->number))
        {b[row-1][col]->number=0;}//檢查上面
        if (row>=0 && row<=7 && col>=2 && col<=8 && (num==b[row][col+1]->number))
        {b[row][col+1]->number=0;}//檢查右邊


        if (b[row][col-2]->number/10 != 0)
            FiveNum[0]= b[row][col-2]->number%10;
        if (b[row][col-1]->number/10 != 0)
            FiveNum[1]= b[row][col-1]->number%10;
        FiveNum[2]=b[row][col]->number;
        if (b[row+1][col]->number/10 != 0)
            FiveNum[3]= b[row+1][col]->number%10;
        if (b[row+2][col]->number/10 != 0)
            FiveNum[4]= b[row+2][col]->number%10;

        //check for the bomb and then eliminate them
        for (int i=0; i<3; i++)
        {
            eliminate *e;
            switch(FiveNum[i]){
            case 0://歸零
                b[row][col-2+i]->number=0;break;
            case 1://爆
                e= new vertical;
                e->elimination(b, b[row][col-2+i]);
                delete e;break;
            case 2://爆
                e= new horizontal;
                e->elimination(b,b[row][col-2+i]);
                delete e;break;
            case 3://爆
                e= new box;
                e->elimination(b,b[row][col-2+i]);
                delete e;break;
            }
        }
        for (int i=0; i<2; i++)
        {
            eliminate *e;
            switch(FiveNum[i+3]){
            case 0://歸零
                b[row+1+i][col]->number=0;break;
            case 1://爆
                e= new vertical;
                e->elimination(b, b[row+1+i][col]);
                delete e;break;
            case 2://爆
                e= new horizontal;
                e->elimination(b,b[row+1+i][col]);
                delete e;break;
            case 3://爆
                e= new box;
                e->elimination(b,b[row+1+i][col]);
                delete e;break;
            }
        }
        break;

    case 2:
        clicked->number=clicked->number*10+3;
        if (row<=8 && (num==b[row+1][col]->number))
        {b[row+1][col]->number=0;}//檢查下面
        if (col<=8 && (num==b[row][col+1]->number))
        {b[row][col+1]->number=0;}//檢查右邊


        if (b[row][col-2]->number/10 != 0)
            FiveNum[0]= b[row][col-2]->number%10;
        if (b[row][col-1]->number/10 != 0)
            FiveNum[1]= b[row][col-1]->number%10;
        FiveNum[2]=b[row][col]->number;
        if (b[row-1][col]->number/10 != 0)
            FiveNum[3]= b[row-1][col]->number%10;
        if (b[row-2][col]->number/10 != 0)
            FiveNum[4]= b[row-2][col]->number%10;

        //check for the bomb and then eliminate them
        for (int i=0; i<3; i++)
        {
            eliminate *e;
            switch(FiveNum[i]){
            case 0://歸零
                b[row][col-2+i]->number=0;break;
            case 1://爆
                e= new vertical;
                e->elimination(b, b[row][col-2+i]);
                delete e;break;
            case 2://爆
                e= new horizontal;
                e->elimination(b,b[row][col-2+i]);
                delete e;break;
            case 3://爆
                e= new box;
                e->elimination(b,b[row][col-2+i]);
                delete e;break;
            }
        }
        for (int i=0; i<2; i++)
        {
            eliminate *e;
            switch(FiveNum[i+3]){
            case 0://歸零
                b[row-1-i][col]->number=0;break;
            case 1://爆
                e= new vertical;
                e->elimination(b, b[row-1-i][col]);
                delete e;break;
            case 2://爆
                e= new horizontal;
                e->elimination(b,b[row-1-i][col]);
                delete e;break;
            case 3://爆
                e= new box;
                e->elimination(b,b[row-1-i][col]);
                delete e;break;
            }
        }
        break;

    case 3:
        clicked->number=clicked->number*10+3;
        if (row>=1 && (num==b[row-1][col]->number))
        {b[row-1][col]->number=0;}//檢查上面
        if (col>=1 && (num==b[row][col-1]->number))
        {b[row][col-1]->number=0;}//檢查左邊


        if (b[row+2][col]->number/10 != 0)
            FiveNum[0]= b[row+2][col]->number%10;
        if (b[row+1][col]->number/10 != 0)
            FiveNum[1]= b[row+1][col]->number%10;
        FiveNum[2]=b[row][col]->number;
        if (b[row][col+1]->number/10 != 0)
            FiveNum[3]= b[row][col+1]->number%10;
        if (b[row][col+2]->number/10 != 0)
            FiveNum[4]= b[row][col+2]->number%10;

        //check for the bomb and then eliminate them
        for (int i=0; i<3; i++)
        {
            eliminate *e;
            switch(FiveNum[i]){
            case 0://歸零
                b[row+2-i][col]->number=0;break;
            case 1://爆
                e= new vertical;
                e->elimination(b, b[row+2-i][col]);
                delete e;break;
            case 2://爆
                e= new horizontal;
                e->elimination(b,b[row+2-i][col]);
                delete e;break;
            case 3://爆
                e= new box;
                e->elimination(b,b[row+2-i][col]);
                delete e;break;
            }
        }
        for (int i=0; i<2; i++)
        {
            eliminate *e;
            switch(FiveNum[i+3]){
            case 0://歸零
                b[row][col+1+i]->number=0;break;
            case 1://爆
                e= new vertical;
                e->elimination(b, b[row][col+1+i]);
                delete e;break;
            case 2://爆
                e= new horizontal;
                e->elimination(b,b[row][col+1+i]);
                delete e;break;
            case 3://爆
                e= new box;
                e->elimination(b,b[row][col+1+i]);
                delete e;break;
            }
        }
        break;

    case 4:
        clicked->number=clicked->number*10+3;
        if (row<=8 && (num==b[row+1][col]->number))
        {b[row+1][col]->number=0;}//檢查下面
        if (col>=1 && (num==b[row][col-1]->number))
        {b[row][col-1]->number=0;}//檢查左邊


        if (b[row-2][col]->number/10 != 0)
            FiveNum[0]= b[row-2][col]->number%10;
        if (b[row-1][col]->number/10 != 0)
            FiveNum[1]= b[row-1][col]->number%10;
        FiveNum[2]=b[row][col]->number;
        if (b[row][col+1]->number/10 != 0)
            FiveNum[3]= b[row][col+1]->number%10;
        if (b[row][col+2]->number/10 != 0)
            FiveNum[4]= b[row][col+2]->number%10;

        //check for the bomb and then eliminate them
        for (int i=0; i<3; i++)
        {
            eliminate *e;
            switch(FiveNum[i]){
            case 0://歸零
                b[row-2+i][col]->number=0;break;
            case 1://爆
                e= new vertical;
                e->elimination(b, b[row-2+i][col]);
                delete e;break;
            case 2://爆
                e= new horizontal;
                e->elimination(b,b[row-2+i][col]);
                delete e;break;
            case 3://爆
                e= new box;
                e->elimination(b,b[row-2+i][col]);
                delete e;break;
            }
        }
        for (int i=0; i<2; i++)
        {
            eliminate *e;
            switch(FiveNum[i+3]){
            case 0://歸零
                b[row][col+1+i]->number=0;break;
            case 1://爆
                e= new vertical;
                e->elimination(b, b[row][col+1+i]);
                delete e;break;
            case 2://爆
                e= new horizontal;
                e->elimination(b,b[row][col+1+i]);
                delete e;break;
            case 3://爆
                e= new box;
                e->elimination(b,b[row][col+1+i]);
                delete e;break;
            }
        }
        break;

    case 5:
        num=num/10;
        if (row>=1 && (num==b[row-1][col]->number))
        {b[row-1][col]->number=0;}//檢查上面
        if (col<=8 && (num==b[row][col+1]->number))
        {b[row][col+1]->number=0;}//檢查右邊


        if (b[row][col-2]->number/10 != 0)
            FiveNum[0]= b[row][col-2]->number%10;
        if (b[row][col-1]->number/10 != 0)
            FiveNum[1]= b[row][col-1]->number%10;
        FiveNum[2]=b[row][col]->number%10;
        if (b[row+1][col]->number/10 != 0)
            FiveNum[3]= b[row+1][col]->number%10;
        if (b[row+2][col]->number/10 != 0)
            FiveNum[4]= b[row+2][col]->number%10;

        //check for the bomb and then eliminate them
        for (int i=0; i<3; i++)
        {
            eliminate *e;
            switch(FiveNum[i]){
            case 0://歸零
                b[row][col-2+i]->number=0;break;
            case 1://爆
                e= new vertical;
                e->elimination(b, b[row][col-2+i]);
                delete e;break;
            case 2://爆
                e= new horizontal;
                e->elimination(b,b[row][col-2+i]);
                delete e;break;
            case 3://爆
                e= new box;
                e->elimination(b,b[row][col-2+i]);
                delete e;break;
            }
        }
        for (int i=0; i<2; i++)
        {
            eliminate *e;
            switch(FiveNum[i+3]){
            case 0://歸零
                b[row+1+i][col]->number=0;break;
            case 1://爆
                e= new vertical;
                e->elimination(b, b[row+1+i][col]);
                delete e;break;
            case 2://爆
                e= new horizontal;
                e->elimination(b,b[row+1+i][col]);
                delete e;break;
            case 3://爆
                e= new box;
                e->elimination(b,b[row+1+i][col]);
                delete e;break;
            }
        }
        break;

    case 6:
        num=num/10;
        if (row<=8 && (num==b[row+1][col]->number))
        {b[row+1][col]->number=0;}//檢查下面
        if (col<=8 && (num==b[row][col+1]->number))
        {b[row][col+1]->number=0;}//檢查右邊


        if (b[row][col-2]->number/10 != 0)
            FiveNum[0]= b[row][col-2]->number%10;
        if (b[row][col-1]->number/10 != 0)
            FiveNum[1]= b[row][col-1]->number%10;
        FiveNum[2]=b[row][col]->number%10;
        if (b[row-1][col]->number/10 != 0)
            FiveNum[3]= b[row-1][col]->number%10;
        if (b[row-2][col]->number/10 != 0)
            FiveNum[4]= b[row-2][col]->number%10;

        //check for the bomb and then eliminate them
        for (int i=0; i<3; i++)
        {
            eliminate *e;
            switch(FiveNum[i]){
            case 0://歸零
                b[row][col-2+i]->number=0;break;
            case 1://爆
                e= new vertical;
                e->elimination(b, b[row][col-2+i]);
                delete e;break;
            case 2://爆
                e= new horizontal;
                e->elimination(b,b[row][col-2+i]);
                delete e;break;
            case 3://爆
                e= new box;
                e->elimination(b,b[row][col-2+i]);
                delete e;break;
            }
        }
        for (int i=0; i<2; i++)
        {
            eliminate *e;
            switch(FiveNum[i+3]){
            case 0://歸零
                b[row-1-i][col]->number=0;break;
            case 1://爆
                e= new vertical;
                e->elimination(b, b[row-1-i][col]);
                delete e;break;
            case 2://爆
                e= new horizontal;
                e->elimination(b,b[row-1-i][col]);
                delete e;break;
            case 3://爆
                e= new box;
                e->elimination(b,b[row-1-i][col]);
                delete e;break;
            }
        }
        break;

    case 7:
        num=num/10;
        if (row>=1 && (num==b[row-1][col]->number))
        {b[row-1][col]->number=0;}//檢查上面
        if (col>=1 && (num==b[row][col-1]->number))
        {b[row][col-1]->number=0;}//檢查左邊


        if (b[row+2][col]->number/10 != 0)
            FiveNum[0]= b[row+2][col]->number%10;
        if (b[row+1][col]->number/10 != 0)
            FiveNum[1]= b[row+1][col]->number%10;
        FiveNum[2]=b[row][col]->number%10;
        if (b[row][col+1]->number/10 != 0)
            FiveNum[3]= b[row][col+1]->number%10;
        if (b[row][col+2]->number/10 != 0)
            FiveNum[4]= b[row][col+2]->number%10;

        //check for the bomb and then eliminate them
        for (int i=0; i<3; i++)
        {
            eliminate *e;
            switch(FiveNum[i]){
            case 0://歸零
                b[row+2-i][col]->number=0;break;
            case 1://爆
                e= new vertical;
                e->elimination(b, b[row+2-i][col]);
                delete e;break;
            case 2://爆
                e= new horizontal;
                e->elimination(b,b[row+2-i][col]);
                delete e;break;
            case 3://爆
                e= new box;
                e->elimination(b,b[row+2-i][col]);
                delete e;break;
            }
        }
        for (int i=0; i<2; i++)
        {
            eliminate *e;
            switch(FiveNum[i+3]){
            case 0://歸零
                b[row][col+1+i]->number=0;break;
            case 1://爆
                e= new vertical;
                e->elimination(b, b[row][col+1+i]);
                delete e;break;
            case 2://爆
                e= new horizontal;
                e->elimination(b,b[row][col+1+i]);
                delete e;break;
            case 3://爆
                e= new box;
                e->elimination(b,b[row][col+1+i]);
                delete e;break;
            }
        }
        break;

    case 8:
        num=num/10;
        if (row<=8 && (num==b[row+1][col]->number))
        {b[row+1][col]->number=0;}//檢查下面
        if (col>=1 && (num==b[row][col-1]->number))
        {b[row][col-1]->number=0;}//檢查左邊


        if (b[row-2][col]->number/10 != 0)
            FiveNum[0]= b[row-2][col]->number%10;
        if (b[row-1][col]->number/10 != 0)
            FiveNum[1]= b[row-1][col]->number%10;
        FiveNum[2]=b[row][col]->number%10;
        if (b[row][col+1]->number/10 != 0)
            FiveNum[3]= b[row][col+1]->number%10;
        if (b[row][col+2]->number/10 != 0)
            FiveNum[4]= b[row][col+2]->number%10;

        //check for the bomb and then eliminate them
        for (int i=0; i<3; i++)
        {
            eliminate *e;
            switch(FiveNum[i]){
            case 0://歸零
                b[row-2+i][col]->number=0;break;
            case 1://爆
                e= new vertical;
                e->elimination(b, b[row-2+i][col]);
                delete e;break;
            case 2://爆
                e= new horizontal;
                e->elimination(b,b[row-2+i][col]);
                delete e;break;
            case 3://爆
                e= new box;
                e->elimination(b,b[row-2+i][col]);
                delete e;break;
            }
        }
        for (int i=0; i<2; i++)
        {
            eliminate *e;
            switch(FiveNum[i+3]){
            case 0://歸零
                b[row][col+1+i]->number=0;break;
            case 1://爆
                e= new vertical;
                e->elimination(b, b[row][col+1+i]);
                delete e;break;
            case 2://爆
                e= new horizontal;
                e->elimination(b,b[row][col+1+i]);
                delete e;break;
            case 3://爆
                e= new box;
                e->elimination(b,b[row][col+1+i]);
                delete e;break;
            }
        }
        break;

    case 9:
        clicked->number=clicked->number*10+3;

        if (b[row-2][col]->number/10 != 0)
            FiveNum[0]= b[row-2][col]->number%10;
        if (b[row-1][col]->number/10 != 0)
            FiveNum[1]= b[row-1][col]->number%10;
        if (b[row][col-1]->number/10 != 0)
            FiveNum[2]= b[row][col-1]->number%10;
        FiveNum[3]=b[row][col]->number;
        if (b[row][col+1]->number/10 != 0)
            FiveNum[4]= b[row][col+1]->number%10;

        //check for the bomb and then eliminate them
        for (int i=0; i<2; i++)
        {
            eliminate *e;
            switch(FiveNum[i]){
            case 0://歸零
                b[row-2+i][col]->number=0;break;
            case 1://爆
                e= new vertical;
                e->elimination(b, b[row-2+i][col]);
                delete e;break;
            case 2://爆
                e= new horizontal;
                e->elimination(b,b[row-2+i][col]);
                delete e;break;
            case 3://爆
                e= new box;
                e->elimination(b,b[row-2+i][col]);
                delete e;break;
            }
        }
        for (int i=0; i<3; i++)
        {
            eliminate *e;
            switch(FiveNum[i+2]){
            case 0://歸零
                b[row][col-1+i]->number=0;break;
            case 1://爆
                e= new vertical;
                e->elimination(b, b[row][col-1+i]);
                delete e;break;
            case 2://爆
                e= new horizontal;
                e->elimination(b,b[row][col-1+i]);
                delete e;break;
            case 3://爆
                e= new box;
                e->elimination(b,b[row][col-1+i]);
                delete e;break;
            }
        }
    break;

    case 10:
        clicked->number=clicked->number*10+3;

        if (b[row][col-1]->number/10 != 0)
            FiveNum[0]= b[row][col-1]->number%10;
        FiveNum[1]=b[row][col]->number;
        if (b[row][col+1]->number/10 != 0)
            FiveNum[2]= b[row][col+1]->number%10;
        if (b[row+1][col]->number/10 != 0)
            FiveNum[3]= b[row+1][col]->number%10;
        if (b[row+2][col]->number/10 != 0)
            FiveNum[4]= b[row+2][col]->number%10;

        //check for the bomb and then eliminate them
        for (int i=0; i<3; i++)
        {
            eliminate *e;
            switch(FiveNum[i]){
            case 0://歸零
                b[row][col-1+i]->number=0;break;
            case 1://爆
                e= new vertical;
                e->elimination(b, b[row][col-1+i]);
                delete e;break;
            case 2://爆
                e= new horizontal;
                e->elimination(b,b[row][col-1+i]);
                delete e;break;
            case 3://爆
                e= new box;
                e->elimination(b,b[row][col-1+i]);
                delete e;break;
            }
        }
        for (int i=0; i<2; i++)
        {
            eliminate *e;
            switch(FiveNum[i+3]){
            case 0://歸零
                b[row+1+i][col]->number=0;break;
            case 1://爆
                e= new vertical;
                e->elimination(b, b[row+1+i][col]);
                delete e;break;
            case 2://爆
                e= new horizontal;
                e->elimination(b,b[row+1+i][col]);
                delete e;break;
            case 3://爆
                e= new box;
                e->elimination(b,b[row+1+i][col]);
                delete e;break;
            }
        }
    break;

    case 11:
        clicked->number=clicked->number*10+3;

        if (b[row-1][col]->number/10 != 0)
            FiveNum[0]= b[row-1][col]->number%10;
        FiveNum[1]=b[row][col]->number;
        if (b[row+1][col]->number/10 != 0)
            FiveNum[2]= b[row+1][col]->number%10;
        if (b[row][col+1]->number/10 != 0)
            FiveNum[3]= b[row][col+1]->number%10;
        if (b[row][col+2]->number/10 != 0)
            FiveNum[4]= b[row][col+2]->number%10;

        //check for the bomb and then eliminate them
        for (int i=0; i<3; i++)
        {
            eliminate *e;
            switch(FiveNum[i]){
            case 0://歸零
                b[row-1+i][col]->number=0;break;
            case 1://爆
                e= new vertical;
                e->elimination(b, b[row-1+i][col]);
                delete e;break;
            case 2://爆
                e= new horizontal;
                e->elimination(b,b[row-1+i][col]);
                delete e;break;
            case 3://爆
                e= new box;
                e->elimination(b,b[row-1+i][col]);
                delete e;break;
            }
        }
        for (int i=0; i<2; i++)
        {
            eliminate *e;
            switch(FiveNum[i+3]){
            case 0://歸零
                b[row][col+1+i]->number=0;break;
            case 1://爆
                e= new vertical;
                e->elimination(b, b[row][col+1+i]);
                delete e;break;
            case 2://爆
                e= new horizontal;
                e->elimination(b,b[row][col+1+i]);
                delete e;break;
            case 3://爆
                e= new box;
                e->elimination(b,b[row][col+1+i]);
                delete e;break;
            }
        }
    break;

    case 12:
        clicked->number=clicked->number*10+3;

        if (b[row][col-1]->number/10 != 0)
            FiveNum[0]= b[row][col-1]->number%10;
        FiveNum[1]=b[row][col]->number;
        if (b[row][col+1]->number/10 != 0)
            FiveNum[2]= b[row][col+1]->number%10;
        if (b[row-2][col]->number/10 != 0)
            FiveNum[3]= b[row-2][col]->number%10;
        if (b[row-1][col]->number/10 != 0)
            FiveNum[4]= b[row-1][col]->number%10;

        //check for the bomb and then eliminate them
        for (int i=0; i<3; i++)
        {
            eliminate *e;
            switch(FiveNum[i]){
            case 0://歸零
                b[row-1+i][col]->number=0;break;
            case 1://爆
                e= new vertical;
                e->elimination(b, b[row-1+i][col]);
                delete e;break;
            case 2://爆
                e= new horizontal;
                e->elimination(b,b[row-1+i][col]);
                delete e;break;
            case 3://爆
                e= new box;
                e->elimination(b,b[row-1+i][col]);
                delete e;break;
            }
        }
        for (int i=0; i<2; i++)
        {
            eliminate *e;
            switch(FiveNum[i+3]){
            case 0://歸零
                b[row][col-2+i]->number=0;break;
            case 1://爆
                e= new vertical;
                e->elimination(b, b[row][col-2+i]);
                delete e;break;
            case 2://爆
                e= new horizontal;
                e->elimination(b,b[row][col-2+i]);
                delete e;break;
            case 3://爆
                e= new box;
                e->elimination(b,b[row][col-2+i]);
                delete e;break;
            }
        }
    break;

    case 13:
        num=num/10;

        if (b[row-2][col]->number/10 != 0)
            FiveNum[0]= b[row-2][col]->number%10;
        if (b[row-1][col]->number/10 != 0)
            FiveNum[1]= b[row-1][col]->number%10;
        if (b[row][col-1]->number/10 != 0)
            FiveNum[2]= b[row][col-1]->number%10;
        FiveNum[3]=b[row][col]->number%10;
        if (b[row][col+1]->number/10 != 0)
            FiveNum[4]= b[row][col+1]->number%10;

        //check for the bomb and then eliminate them
        for (int i=0; i<2; i++)
        {
            eliminate *e;
            switch(FiveNum[i]){
            case 0://歸零
                b[row-2+i][col]->number=0;break;
            case 1://爆
                e= new vertical;
                e->elimination(b, b[row-2+i][col]);
                delete e;break;
            case 2://爆
                e= new horizontal;
                e->elimination(b,b[row-2+i][col]);
                delete e;break;
            case 3://爆
                e= new box;
                e->elimination(b,b[row-2+i][col]);
                delete e;break;
            }
        }
        for (int i=0; i<3; i++)
        {
            eliminate *e;
            switch(FiveNum[i+2]){
            case 0://歸零
                b[row][col-1+i]->number=0;break;
            case 1://爆
                e= new vertical;
                e->elimination(b, b[row][col-1+i]);
                delete e;break;
            case 2://爆
                e= new horizontal;
                e->elimination(b,b[row][col-1+i]);
                delete e;break;
            case 3://爆
                e= new box;
                e->elimination(b,b[row][col-1+i]);
                delete e;break;
            }
        }
    break;

    case 14:
        num=num/10;

        if (b[row][col-1]->number/10 != 0)
            FiveNum[0]= b[row][col-1]->number%10;
        FiveNum[1]=b[row][col]->number%10;
        if (b[row][col+1]->number/10 != 0)
            FiveNum[2]= b[row][col+1]->number%10;
        if (b[row+1][col]->number/10 != 0)
            FiveNum[3]= b[row+1][col]->number%10;
        if (b[row+2][col]->number/10 != 0)
            FiveNum[4]= b[row+2][col]->number%10;

        //check for the bomb and then eliminate them
        for (int i=0; i<3; i++)
        {
            eliminate *e;
            switch(FiveNum[i]){
            case 0://歸零
                b[row][col-1+i]->number=0;break;
            case 1://爆
                e= new vertical;
                e->elimination(b, b[row][col-1+i]);
                delete e;break;
            case 2://爆
                e= new horizontal;
                e->elimination(b,b[row][col-1+i]);
                delete e;break;
            case 3://爆
                e= new box;
                e->elimination(b,b[row][col-1+i]);
                delete e;break;
            }
        }
        for (int i=0; i<2; i++)
        {
            eliminate *e;
            switch(FiveNum[i+3]){
            case 0://歸零
                b[row+1+i][col]->number=0;break;
            case 1://爆
                e= new vertical;
                e->elimination(b, b[row+1+i][col]);
                delete e;break;
            case 2://爆
                e= new horizontal;
                e->elimination(b,b[row+1+i][col]);
                delete e;break;
            case 3://爆
                e= new box;
                e->elimination(b,b[row+1+i][col]);
                delete e;break;
            }
        }
    break;

    case 15:
        num=num/10;

        if (b[row-1][col]->number/10 != 0)
            FiveNum[0]= b[row-1][col]->number%10;
        FiveNum[1]=b[row][col]->number%10;
        if (b[row+1][col]->number/10 != 0)
            FiveNum[2]= b[row+1][col]->number%10;
        if (b[row][col+1]->number/10 != 0)
            FiveNum[3]= b[row][col+1]->number%10;
        if (b[row][col+2]->number/10 != 0)
            FiveNum[4]= b[row][col+2]->number%10;

        //check for the bomb and then eliminate them
        for (int i=0; i<3; i++)
        {
            eliminate *e;
            switch(FiveNum[i]){
            case 0://歸零
                b[row-1+i][col]->number=0;break;
            case 1://爆
                e= new vertical;
                e->elimination(b, b[row-1+i][col]);
                delete e;break;
            case 2://爆
                e= new horizontal;
                e->elimination(b,b[row-1+i][col]);
                delete e;break;
            case 3://爆
                e= new box;
                e->elimination(b,b[row-1+i][col]);
                delete e;break;
            }
        }
        for (int i=0; i<2; i++)
        {
            eliminate *e;
            switch(FiveNum[i+3]){
            case 0://歸零
                b[row][col+1+i]->number=0;break;
            case 1://爆
                e= new vertical;
                e->elimination(b, b[row][col+1+i]);
                delete e;break;
            case 2://爆
                e= new horizontal;
                e->elimination(b,b[row][col+1+i]);
                delete e;break;
            case 3://爆
                e= new box;
                e->elimination(b,b[row][col+1+i]);
                delete e;break;
            }
        }
    break;

    case 16:
        num=num/10;

        if (b[row][col-1]->number/10 != 0)
            FiveNum[0]= b[row][col-1]->number%10;
        FiveNum[1]=b[row][col]->number%10;
        if (b[row][col+1]->number/10 != 0)
            FiveNum[2]= b[row][col+1]->number%10;
        if (b[row-2][col]->number/10 != 0)
            FiveNum[3]= b[row-2][col]->number%10;
        if (b[row-1][col]->number/10 != 0)
            FiveNum[4]= b[row-1][col]->number%10;

        //check for the bomb and then eliminate them
        for (int i=0; i<3; i++)
        {
            eliminate *e;
            switch(FiveNum[i]){
            case 0://歸零
                b[row-1+i][col]->number=0;break;
            case 1://爆
                e= new vertical;
                e->elimination(b, b[row-1+i][col]);
                delete e;break;
            case 2://爆
                e= new horizontal;
                e->elimination(b,b[row-1+i][col]);
                delete e;break;
            case 3://爆
                e= new box;
                e->elimination(b,b[row-1+i][col]);
                delete e;break;
            }
        }
        for (int i=0; i<2; i++)
        {
            eliminate *e;
            switch(FiveNum[i+3]){
            case 0://歸零
                b[row][col-2+i]->number=0;break;
            case 1://爆
                e= new vertical;
                e->elimination(b, b[row][col-2+i]);
                delete e;break;
            case 2://爆
                e= new horizontal;
                e->elimination(b,b[row][col-2+i]);
                delete e;break;
            case 3://爆
                e= new box;
                e->elimination(b,b[row][col-2+i]);
                delete e;break;
            }
        }
    break;
    }

}

void box::elimination(Blank *b[10][10], Blank *clicked)
{
    int row= clicked->row;
    int col= clicked->column;
    eliminate *e;

    clicked->number=0;
    int EightNum[8]={0};//用來記錄這八個裡面有沒有特殊炸彈

    //紀錄每個裡面的特殊炸彈的型別
    if (row>=1 && col>=1 && b[row-1][col-1]->number/10!=0)
       EightNum[0]=b[row-1][col-1]->number%10;

    if (row>=1 && b[row-1][col]->number/10!=0)
        EightNum[1]=b[row-1][col]->number%10;

    if (row>=1 && col<=8 && b[row-1][col+1]->number/10!=0)
        EightNum[2]=b[row-1][col+1]->number%10;

    if (col>=1 && b[row-1][col+1]->number/10!=0)
        EightNum[3]=b[row][col-1]->number%10;

    if (col<=8 && b[row][col+1]->number/10!=0)
        EightNum[4]=b[row][col+1]->number%10;

    if (row<=8 && col>=1 && b[row+1][col-1]->number/10)
        EightNum[5]=b[row+1][col-1]->number%10;

    if (row<=8 && b[row+1][col]->number/10)
        EightNum[6]=b[row+1][col]->number%10;

    if (row<=8 && col<=8 && b[row+1][col+1]->number/10)
        EightNum[7]=b[row+1][col+1]->number%10;
    //結束紀錄每個裡面的特殊炸彈的型別


    //一個個引爆特殊炸彈
    if (row>=1 && col>=1)
    {
        switch(EightNum[0]){
        case 0: b[row-1][col-1]->number=0;break;
        case 1://爆
            e= new vertical;
            e->elimination(b, b[row-1][col-1]);
            delete e;break;
        case 2://爆
            e= new horizontal;
            e->elimination(b,b[row-1][col-1]);
            delete e;break;
        case 3://爆
            e= new box;
            e->elimination(b,b[row-1][col-1]);
            delete e;break;
        }
    }

    if (row>=1)
    {
        switch(EightNum[1]){
        case 0: b[row-1][col]->number=0;break;
        case 1://爆
            e= new vertical;
            e->elimination(b, b[row-1][col]);
            delete e;break;
        case 2://爆
            e= new horizontal;
            e->elimination(b,b[row-1][col]);
            delete e;break;
        case 3://爆
            e= new box;
            e->elimination(b,b[row-1][col]);
            delete e;break;
        }
    }

    if (row>=1 && col<=8)
    {
        switch(EightNum[2]){
        case 0: b[row-1][col+1]->number=0;break;
        case 1://爆
            e= new vertical;
            e->elimination(b, b[row-1][col+1]);
            delete e;break;
        case 2://爆
            e= new horizontal;
            e->elimination(b,b[row-1][col+1]);
            delete e;break;
        case 3://爆
            e= new box;
            e->elimination(b,b[row-1][col+1]);
            delete e;break;
        }
    }

    if (col>=1)
    {
        switch(EightNum[3]){
        case 0: b[row][col-1]->number=0;break;
        case 1://爆
            e= new vertical;
            e->elimination(b, b[row][col-1]);
            delete e;break;
        case 2://爆
            e= new horizontal;
            e->elimination(b,b[row][col-1]);
            delete e;break;
        case 3://爆
            e= new box;
            e->elimination(b,b[row][col-1]);
            delete e;break;
        }
    }

    if (col<=8)
    {
        switch(EightNum[4]){
        case 0: b[row][col+1]->number=0;break;
        case 1://爆
            e= new vertical;
            e->elimination(b, b[row][col+1]);
            delete e;break;
        case 2://爆
            e= new horizontal;
            e->elimination(b,b[row][col+1]);
            delete e;break;
        case 3://爆
            e= new box;
            e->elimination(b,b[row][col+1]);
            delete e;break;
        }
    }

    if (row<=8 && col>=1)
    {
        switch(EightNum[5]){
        case 0: b[row+1][col-1]->number=0;break;
        case 1://爆
            e= new vertical;
            e->elimination(b, b[row+1][col-1]);
            delete e;break;
        case 2://爆
            e= new horizontal;
            e->elimination(b,b[row+1][col-1]);
            delete e;break;
        case 3://爆
            e= new box;
            e->elimination(b,b[row+1][col-1]);
            delete e;break;
        }
    }

    if (row<=8)
    {
        switch(EightNum[6]){
        case 0: b[row+1][col]->number=0;break;
        case 1://爆
            e= new vertical;
            e->elimination(b, b[row+1][col]);
            delete e;break;
        case 2://爆
            e= new horizontal;
            e->elimination(b,b[row+1][col]);
            delete e;break;
        case 3://爆
            e= new box;
            e->elimination(b,b[row+1][col]);
            delete e;break;
        }
    }

    if (row<=8 && col<=8)
    {
        switch(EightNum[7]){
        case 0: b[row+1][col+1]->number=0;break;
        case 1://爆
            e= new vertical;
            e->elimination(b, b[row+1][col+1]);
            delete e;break;
        case 2://爆
            e= new horizontal;
            e->elimination(b,b[row+1][col+1]);
            delete e;break;
        case 3://爆
            e= new box;
            e->elimination(b,b[row+1][col+1]);
            delete e;break;
        }
    }
    //結束一個個引爆特殊炸彈
}

int box::condition(Blank *b[10][10], Blank *clicked)
{
    int row= clicked->row;
    int col= clicked->column;
    int num= clicked->number;

    if (num!=0 && num!=5)
    {
        if (num/10==0)
        {
            if (row<=7 && col>=2 && ((num==b[row][col-2]->number) || (num==b[row][col-2]->number/10)) && ((num==b[row][col-1]->number) || (num==b[row][col-1]->number/10)) && ((num==b[row+1][col]->number) || (num==b[row+1][col]->number/10)) && ((num==b[row+2][col]->number) || (num==b[row+2][col]->number/10)))
            {return 1;}//L1 without bomb

            if (row>=2 && col>=2 && ((num==b[row-2][col]->number) || (num==b[row-2][col]->number/10)) && ((num==b[row-1][col]->number) || (num==b[row-1][col]->number/10)) && ((num==b[row][col-2]->number) || (num==b[row][col-2]->number/10)) && ((num==b[row][col-1]->number) || (num==b[row][col-1]->number/10)))
            {return 2;}//L2 without bomb

            if (row<=7 && col<=7 && ((num==b[row+1][col]->number) || (num==b[row+1][col]->number/10)) && ((num==b[row+2][col]->number) || (num==b[row+2][col]->number/10)) && ((num==b[row][col+1]->number) || (num==b[row][col+1]->number/10)) && ((num==b[row][col+2]->number) || (num==b[row][col+2]->number/10)))
            {return 3;}//L3 without bomb

            if (row>=2&& col<=7 && ((num==b[row-1][col]->number) || (num==b[row-1][col]->number/10)) && ((num==b[row-2][col]->number) || (num==b[row-2][col]->number/10)) && ((num==b[row][col+2]->number) || (num==b[row][col+2]->number/10)) && ((num==b[row][col+1]->number) || (num==b[row][col+1]->number/10)))
            {return 4;}//L4 without bomb

            if (row>=2 && col>=1 && col<=8 && ((num==b[row-1][col]->number) || (num==b[row-1][col]->number/10)) && ((num==b[row-2][col]->number) || (num==b[row-2][col]->number/10)) && ((num==b[row][col+1]->number) || (num==b[row][col+1]->number/10)) && ((num==b[row][col-1]->number) || (num==b[row][col-1]->number/10)))
            {return 9;}//T1 without bomb

            if (row<=7 && col>=1 && col<=8 && ((num==b[row+1][col]->number) || (num==b[row+1][col]->number/10)) && ((num==b[row+2][col]->number) || (num==b[row+2][col]->number/10)) && ((num==b[row][col+1]->number) || (num==b[row][col+1]->number/10)) && ((num==b[row][col-1]->number) || (num==b[row][col-1]->number/10)))
            {return 10;}//T2 without bomb

            if (row>=1 && row<=8 && col<=7 && ((num==b[row+1][col]->number) || (num==b[row+1][col]->number/10)) && ((num==b[row-1][col]->number) || (num==b[row-1][col]->number/10)) && ((num==b[row][col+2]->number) || (num==b[row][col+2]->number/10)) && ((num==b[row][col+1]->number) || (num==b[row][col+1]->number/10)))
            {return 11;}//T3 without bomb

            if (row>=1 && row<=8 && col>=2 && ((num==b[row+1][col]->number) || (num==b[row+1][col]->number/10)) && ((num==b[row-1][col]->number) || (num==b[row-1][col]->number/10)) && ((num==b[row][col-1]->number) || (num==b[row][col-1]->number/10)) && ((num==b[row][col-2]->number) || (num==b[row][col-2]->number/10)))
            {return 12;}//T4 without bomb


        }
        else
        {
            num/=10;//determine the color

            if (row<=7 && col>=2 && ((num==b[row][col-2]->number) || (num==b[row][col-2]->number/10)) && ((num==b[row][col-1]->number) || (num==b[row][col-1]->number/10)) && ((num==b[row+1][col]->number) || (num==b[row+1][col]->number/10)) && ((num==b[row+2][col]->number) || (num==b[row+2][col]->number/10)))
            {return 5;}//L1 with bomb

            if (row>=2 && col>=2 && ((num==b[row-2][col]->number) || (num==b[row-2][col]->number/10)) && ((num==b[row-1][col]->number) || (num==b[row-1][col]->number/10)) && ((num==b[row][col-2]->number) || (num==b[row][col-2]->number/10)) && ((num==b[row][col-1]->number) || (num==b[row][col-1]->number/10)))
            {return 6;}//L2 with bomb

            if (row<=7 && col<=7 && ((num==b[row+1][col]->number) || (num==b[row+1][col]->number/10)) && ((num==b[row+2][col]->number) || (num==b[row+2][col]->number/10)) && ((num==b[row][col+1]->number) || (num==b[row][col+1]->number/10)) && ((num==b[row][col+2]->number) || (num==b[row][col+2]->number/10)))
            {return 7;}//L3 with bomb

            if (row>=2&& col<=7 && ((num==b[row-1][col]->number) || (num==b[row-1][col]->number/10)) && ((num==b[row-2][col]->number) || (num==b[row-2][col]->number/10)) && ((num==b[row][col+2]->number) || (num==b[row][col+2]->number/10)) && ((num==b[row][col+1]->number) || (num==b[row][col+1]->number/10)))
            {return 8;}//L4 with bomb

            if (row>=2 && col>=1 && col<=8 && ((num==b[row-1][col]->number) || (num==b[row-1][col]->number/10)) && ((num==b[row-2][col]->number) || (num==b[row-2][col]->number/10)) && ((num==b[row][col+1]->number) || (num==b[row][col+1]->number/10)) && ((num==b[row][col-1]->number) || (num==b[row][col-1]->number/10)))
            {return 13;}//T1 without bomb

            if (row<=7 && col>=1 && col<=8 && ((num==b[row+1][col]->number) || (num==b[row+1][col]->number/10)) && ((num==b[row+2][col]->number) || (num==b[row+2][col]->number/10)) && ((num==b[row][col+1]->number) || (num==b[row][col+1]->number/10)) && ((num==b[row][col-1]->number) || (num==b[row][col-1]->number/10)))
            {return 14;}//T2 without bomb

            if (row>=1 && row<=8 && col<=7 && ((num==b[row+1][col]->number) || (num==b[row+1][col]->number/10)) && ((num==b[row-1][col]->number) || (num==b[row-1][col]->number/10)) && ((num==b[row][col+2]->number) || (num==b[row][col+2]->number/10)) && ((num==b[row][col+1]->number) || (num==b[row][col+1]->number/10)))
            {return 15;}//T3 without bomb

            if (row>=1 && row<=8 && col>=2 && ((num==b[row+1][col]->number) || (num==b[row+1][col]->number/10)) && ((num==b[row-1][col]->number) || (num==b[row-1][col]->number/10)) && ((num==b[row][col-1]->number) || (num==b[row][col-1]->number/10)) && ((num==b[row][col-2]->number) || (num==b[row][col-2]->number/10)))
            {return 16;}//T4 without bomb
        }
    }
    return 0;

}

