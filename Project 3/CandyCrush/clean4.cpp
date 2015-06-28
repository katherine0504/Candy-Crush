#include "clean4.h"

clean4::clean4()
{

}

clean4::~clean4()
{

}

void clean4::spawn(Blank *b[10][10], Blank *clicked, int mode)
{
    int row= clicked->row;
    int col= clicked->column;
    int num= clicked->number;
    int FourNum[4]={0};

    switch(mode){
    case 1://I1 without bomb
        clicked->number=clicked->number*10+1;

        //check for bomb with in the 5 blocks
        if (b[row-1][col]->number/10 != 0)
            FourNum[0]= b[row-1][col]->number%10;
        FourNum[1]=b[row][col]->number;
        if (b[row+1][col]->number/10 != 0)
            FourNum[2]= b[row+1][col]->number%10;
        if (b[row+2][col]->number/10 != 0)
            FourNum[3]= b[row+2][col]->number%10;

        //check for the bomb and then eliminate them
        for (int i=0; i<4; i++)
        {
            eliminate *e;

            switch(FourNum[i]){
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
        }break;

    case 2://I2 without bomb
        clicked->number=clicked->number*10+1;

        //check for bomb with in the 5 blocks
        if (b[row-2][col]->number/10 != 0)
            FourNum[0]= b[row-2][col]->number%10;
        if (b[row-1][col]->number/10 != 0)
            FourNum[1]= b[row-1][col]->number%10;
        FourNum[2]=b[row][col]->number;
        if (b[row+1][col]->number/10 != 0)
            FourNum[3]= b[row+1][col]->number%10;

        //check for the bomb and then eliminate them
        for (int i=0; i<4; i++)
        {
            eliminate *e;

            switch(FourNum[i]){
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
        }break;

    case 3://I3 without bomb
        clicked->number=clicked->number*10+2;

        //check for bomb with in the 5 blocks
        if (b[row][col-1]->number/10 != 0)
            FourNum[0]= b[row][col-1]->number%10;
        FourNum[1]=b[row][col]->number;
        if (b[row][col+1]->number/10 != 0)
            FourNum[2]= b[row][col+1]->number%10;
        if (b[row][col+2]->number/10 != 0)
            FourNum[3]= b[row][col+2]->number%10;

        //check for the bomb and then eliminate them
        for (int i=0; i<4; i++)
        {
            eliminate *e;

            switch(FourNum[i]){
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
        }break;

    case 4://I4 without bomb
        clicked->number=clicked->number*10+2;

        //check for bomb with in the 5 blocks
        if (b[row][col-2]->number/10 != 0)
            FourNum[0]= b[row][col-2]->number%10;
        if (b[row][col-1]->number/10 != 0)
            FourNum[1]= b[row][col-1]->number%10;
        FourNum[2]=b[row][col]->number;
        if (b[row][col+1]->number/10 != 0)
            FourNum[3]= b[row][col+1]->number%10;

        //check for the bomb and then eliminate them
        for (int i=0; i<4; i++)
        {
            eliminate *e;

            switch(FourNum[i]){
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
        }break;

    case 5://I1 with bomb
        num=num/10;

        //check for bomb with in the 5 blocks
        if (b[row-1][col]->number/10 != 0)
            FourNum[0]= b[row-1][col]->number%10;
        FourNum[1]=b[row][col]->number%10;
        if (b[row+1][col]->number/10 != 0)
            FourNum[2]= b[row+1][col]->number%10;
        if (b[row+2][col]->number/10 != 0)
            FourNum[3]= b[row+2][col]->number%10;

        //check for the bomb and then eliminate them
        for (int i=0; i<4; i++)
        {
            eliminate *e;

            switch(FourNum[i]){
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
        }break;

    case 6://I2 with bomb
        num=num/10;

        //check for bomb with in the 5 blocks
        if (b[row-2][col]->number/10 != 0)
            FourNum[0]= b[row-2][col]->number%10;
        if (b[row-1][col]->number/10 != 0)
            FourNum[1]= b[row-1][col]->number%10;
        FourNum[2]=b[row][col]->number%10;
        if (b[row+1][col]->number/10 != 0)
            FourNum[3]= b[row+1][col]->number%10;

        //check for the bomb and then eliminate them
        for (int i=0; i<4; i++)
        {
            eliminate *e;

            switch(FourNum[i]){
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
        }break;

    case 7://I3 with bomb
        num=num/10;

        //check for bomb with in the 5 blocks
        if (b[row][col-1]->number/10 != 0)
            FourNum[0]= b[row][col-1]->number%10;
        FourNum[1]=b[row][col]->number%10;
        if (b[row][col+1]->number/10 != 0)
            FourNum[2]= b[row][col+1]->number%10;
        if (b[row][col+2]->number/10 != 0)
            FourNum[3]= b[row][col+2]->number%10;

        //check for the bomb and then eliminate them
        for (int i=0; i<4; i++)
        {
            eliminate *e;

            switch(FourNum[i]){
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
        }break;

    case 8://I4 with bomb
        num=num/10;

        //check for bomb with in the 5 blocks
        if (b[row][col-2]->number/10 != 0)
            FourNum[0]= b[row][col-2]->number%10;
        if (b[row][col-1]->number/10 != 0)
            FourNum[1]= b[row][col-1]->number%10;
        FourNum[2]=b[row][col]->number%10;
        if (b[row][col+1]->number/10 != 0)
            FourNum[3]= b[row][col+1]->number%10;

        //check for the bomb and then eliminate them
        for (int i=0; i<4; i++)
        {
            eliminate *e;

            switch(FourNum[i]){
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
        }break;
    }
}

void clean4::elimination(Blank *b[10][10], Blank *clicked)
{

}

int clean4::condition(Blank *b[10][10], Blank *clicked)
{
    int row= clicked->row;
    int col= clicked->column;
    int num= clicked->number;

    if (num!=0 && num!=5)
    {
        if (num/10==0)
        {
            if (row>=1 && row<=7 && ((num==b[row-1][col]->number) || (num==b[row-1][col]->number/10)) && ((num==b[row+1][col]->number) || (num==b[row+1][col]->number/10)) && ((num==b[row+2][col]->number) || (num==b[row+2][col]->number/10)))
            {return 1;}//I1 without bomb
            if (row>=2 && row<=8 && ((num==b[row-2][col]->number) || (num==b[row-2][col]->number/10)) && ((num==b[row-1][col]->number) || (num==b[row-1][col]->number/10)) && ((num==b[row+1][col]->number) || (num==b[row+1][col]->number/10)))
            {return 2;}//I2 without bomb
            if (col>=1 && col<=7 && ((num==b[row][col-1]->number) || (num==b[row][col-1]->number/10)) && ((num==b[row][col+1]->number) || (num==b[row][col+1]->number/10)) && ((num==b[row][col+2]->number) || (num==b[row][col+2]->number/10)))
            {return 3;}//I3 without bomb
            if (col>=2 && col<=8 && ((num==b[row][col-2]->number) || (num==b[row][col-2]->number/10)) && ((num==b[row][col-1]->number) || (num==b[row][col-1]->number/10)) && ((num==b[row][col+1]->number) || (num==b[row][col+1]->number/10)))
            {return 4;}//I4 without bomb
        }
        else
        {
            num/=10;//determine the color
            if (row>=1 && row<=7 && ((num==b[row-1][col]->number) || (num==b[row-1][col]->number/10)) && ((num==b[row+1][col]->number) || (num==b[row+1][col]->number/10)) && ((num==b[row+2][col]->number) || (num==b[row+2][col]->number/10)))
            {return 5;}//I1 with bomb
            if (row>=2 && row<=8 && ((num==b[row-2][col]->number) || (num==b[row-2][col]->number/10)) && ((num==b[row-1][col]->number) || (num==b[row-1][col]->number/10)) && ((num==b[row+1][col]->number) || (num==b[row+1][col]->number/10)))
            {return 6;}//I2 with bomb
            if (col>=1 && col<=7 && ((num==b[row][col-1]->number) || (num==b[row][col-1]->number/10)) && ((num==b[row][col+1]->number) || (num==b[row][col+1]->number/10)) && ((num==b[row][col+2]->number) || (num==b[row][col+2]->number/10)))
            {return 7;}//I3 with bomb
            if (col>=2 && col<=8 && ((num==b[row][col-2]->number) || (num==b[row][col-2]->number/10)) && ((num==b[row][col-1]->number) || (num==b[row][col-1]->number/10)) && ((num==b[row][col+1]->number) || (num==b[row][col+1]->number/10)))
            {return 8;}//I4 with bomb
        }
    }
    return 0;
}

