#include "clean3v.h"

clean3v::clean3v()
{

}

clean3v::~clean3v()
{

}

void clean3v::spawn(Blank *b[10][10], Blank *clicked, int mode)
{
    int row= clicked->row;
    int col= clicked->column;
    int num= clicked->number;
    int ThreeNum[3]={0};

    switch(mode){
    case 1://TV1 without bomb
        clicked->number=0;

        //check for bomb with in the 5 blocks
        ThreeNum[0]=b[row][col]->number;
        if (b[row+1][col]->number/10 != 0)
            ThreeNum[1]= b[row+1][col]->number%10;
        if (b[row+2][col]->number/10 != 0)
            ThreeNum[2]= b[row+2][col]->number%10;

        //check for the bomb and then eliminate them
        for (int i=0; i<3; i++)
        {
            eliminate *e;

            switch(ThreeNum[i]){
            case 0://歸零
                b[row+i][col]->number=0;break;
            case 1://爆
                e= new vertical;
                e->elimination(b, b[row+i][col]);
                delete e;break;
            case 2://爆
                e= new horizontal;
                e->elimination(b,b[row+i][col]);
                delete e;break;
            case 3://爆
                e= new box;
                e->elimination(b,b[row+i][col]);
                delete e;break;
            }
        }break;

    case 2://TV2 without bomb
        clicked->number=0;

        //check for bomb with in the 5 blocks

        if (b[row-1][col]->number/10 != 0)
            ThreeNum[0]= b[row-1][col]->number%10;
        ThreeNum[1]=b[row][col]->number;
        if (b[row+1][col]->number/10 != 0)
            ThreeNum[2]= b[row+1][col]->number%10;

        //check for the bomb and then eliminate them
        for (int i=0; i<3; i++)
        {
            eliminate *e;

            switch(ThreeNum[i]){
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

    case 3://TV3 without bomb
        clicked->number=0;

        //check for bomb with in the 5 blocks

        if (b[row-2][col]->number/10 != 0)
            ThreeNum[0]= b[row-2][col]->number%10;
        if (b[row-1][col]->number/10 != 0)
            ThreeNum[1]= b[row-1][col]->number%10;
        ThreeNum[2]=b[row][col]->number;

        //check for the bomb and then eliminate them
        for (int i=0; i<3; i++)
        {
            eliminate *e;

            switch(ThreeNum[i]){
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

    case 4://TV4 without bomb
        num=num/10;

        //check for bomb with in the 5 blocks
        ThreeNum[0]=b[row][col]->number%10;
        if (b[row+1][col]->number/10 != 0)
            ThreeNum[1]= b[row+1][col]->number%10;
        if (b[row+2][col]->number/10 != 0)
            ThreeNum[2]= b[row+2][col]->number%10;

        //check for the bomb and then eliminate them
        for (int i=0; i<3; i++)
        {
            eliminate *e;

            switch(ThreeNum[i]){
            case 0://歸零
                b[row+i][col]->number=0;break;
            case 1://爆
                e= new vertical;
                e->elimination(b, b[row+i][col]);
                delete e;break;
            case 2://爆
                e= new horizontal;
                e->elimination(b,b[row+i][col]);
                delete e;break;
            case 3://爆
                e= new box;
                e->elimination(b,b[row+i][col]);
                delete e;break;
            }
        }break;

    case 5://TV5 without bomb
        num=num/10;

        //check for bomb with in the 5 blocks

        if (b[row-1][col]->number/10 != 0)
            ThreeNum[0]= b[row-1][col]->number%10;
        ThreeNum[1]=b[row][col]->number%10;
        if (b[row+1][col]->number/10 != 0)
            ThreeNum[2]= b[row+1][col]->number%10;

        //check for the bomb and then eliminate them
        for (int i=0; i<3; i++)
        {
            eliminate *e;

            switch(ThreeNum[i]){
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

    case 6://TV6 without bomb
        num=num/10;

        //check for bomb with in the 5 blocks

        if (b[row-2][col]->number/10 != 0)
            ThreeNum[0]= b[row-2][col]->number%10;
        if (b[row-1][col]->number/10 != 0)
            ThreeNum[1]= b[row-1][col]->number%10;
        ThreeNum[2]=b[row][col]->number%10;

        //check for the bomb and then eliminate them
        for (int i=0; i<3; i++)
        {
            eliminate *e;

            switch(ThreeNum[i]){
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



    }
}

void clean3v::elimination(Blank *b[10][10], Blank *clicked)
{

}

int clean3v::condition(Blank *b[10][10], Blank *clicked)
{
    int row= clicked->row;
    int col= clicked->column;
    int num= clicked->number;

    if (num!=0 && num!=5)
    {
        if (num/10==0)
        {
            if (row<=7 && (num==b[row+1][col]->number || num==b[row+1][col]->number/10) && (num==b[row+2][col]->number || num==b[row+2][col]->number/10))
            {return 1;}//ThreeVer1 without bomb
            if (row>=1 && row<=8 && (num==b[row-1][col]->number || num==b[row-1][col]->number/10) && (num==b[row+1][col]->number || num==b[row+1][col]->number/10))
            {return 2;}//ThreeVer2 without bomb
            if (row>=2 && (num==b[row-2][col]->number || num==b[row-2][col]->number/10) && (num==b[row-1][col]->number || num==b[row-1][col]->number/10))
            {return 3;}//ThreeVer1 without bomb
        }
        else
            num/=10;//determine the color
            if (row<=7 && (num==b[row+1][col]->number || num==b[row+1][col]->number/10) && (num==b[row+2][col]->number || num==b[row+2][col]->number/10))
            {return 4;}//ThreeVer1 with bomb
            if (row>=1 && row<=8 && (num==b[row-1][col]->number || num==b[row-1][col]->number/10) && (num==b[row+1][col]->number || num==b[row+1][col]->number/10))
            {return 5;}//ThreeVer2 with bomb
            if (row>=2 && (num==b[row-2][col]->number || num==b[row-2][col]->number/10) && (num==b[row-1][col]->number || num==b[row-1][col]->number/10))
            {return 6;}//ThreeVer1 with bomb
    }
    return 0;
}

