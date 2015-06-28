#include "clean3h.h"

clean3h::clean3h()
{

}

clean3h::~clean3h()
{

}

void clean3h::spawn(Blank *b[10][10], Blank *clicked, int mode)
{
    int row= clicked->row;
    int col= clicked->column;
    int num= clicked->number;
    int ThreeNum[3]={0};

    switch(mode){
    case 1://TH1 without bomb
        clicked->number=0;

        //check for bomb with in the 5 blocks
        ThreeNum[0]=b[row][col]->number;
        if (b[row][col+1]->number/10 != 0)
            ThreeNum[1]= b[row][col+1]->number%10;
        if (b[row][col+2]->number/10 != 0)
            ThreeNum[2]= b[row][col+2]->number%10;

        //check for the bomb and then eliminate them
        for (int i=0; i<3; i++)
        {
            eliminate *e;

            switch(ThreeNum[i]){
            case 0://歸零
                b[row][col+i]->number=0;break;
            case 1://爆
                e= new vertical;
                e->elimination(b, b[row][col+i]);
                delete e;break;
            case 2://爆
                e= new horizontal;
                e->elimination(b,b[row][col+i]);
                delete e;break;
            case 3://爆
                e= new box;
                e->elimination(b,b[row][col+i]);
                delete e;break;
            }
        }break;

    case 2://TH2 without bomb
        clicked->number=0;

        //check for bomb with in the 5 blocks

        if (b[row][col-1]->number/10 != 0)
            ThreeNum[0]= b[row][col-1]->number%10;
        ThreeNum[1]=b[row][col]->number;
        if (b[row][col+1]->number/10 != 0)
            ThreeNum[2]= b[row][col+1]->number%10;

        //check for the bomb and then eliminate them
        for (int i=0; i<3; i++)
        {
            eliminate *e;

            switch(ThreeNum[i]){
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

    case 3://TH3 without bomb
        clicked->number=0;

        //check for bomb with in the 5 blocks

        if (b[row][col-2]->number/10 != 0)
            ThreeNum[0]= b[row][col-2]->number%10;
        if (b[row][col-1]->number/10 != 0)
            ThreeNum[1]= b[row][col-1]->number%10;
        ThreeNum[2]=b[row][col]->number;

        //check for the bomb and then eliminate them
        for (int i=0; i<3; i++)
        {
            eliminate *e;

            switch(ThreeNum[i]){
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

    case 4://TH1 with bomb
        num=num/10;

        //check for bomb with in the 5 blocks
        ThreeNum[0]=b[row][col]->number%10;
        if (b[row][col+1]->number/10 != 0)
            ThreeNum[1]= b[row][col+1]->number%10;
        if (b[row][col+2]->number/10 != 0)
            ThreeNum[2]= b[row][col+2]->number%10;

        //check for the bomb and then eliminate them
        for (int i=0; i<3; i++)
        {
            eliminate *e;

            switch(ThreeNum[i]){
            case 0://歸零
                b[row][col+i]->number=0;break;
            case 1://爆
                e= new vertical;
                e->elimination(b, b[row][col+i]);
                delete e;break;
            case 2://爆
                e= new horizontal;
                e->elimination(b,b[row][col+i]);
                delete e;break;
            case 3://爆
                e= new box;
                e->elimination(b,b[row][col+i]);
                delete e;break;
            }
        }break;

    case 5://TH2 without bomb
        num=num/10;

        //check for bomb with in the 5 blocks

        if (b[row][col-1]->number/10 != 0)
            ThreeNum[0]= b[row][col-1]->number%10;
        ThreeNum[1]=b[row][col]->number%10;
        if (b[row][col+1]->number/10 != 0)
            ThreeNum[2]= b[row][col+1]->number%10;

        //check for the bomb and then eliminate them
        for (int i=0; i<3; i++)
        {
            eliminate *e;

            switch(ThreeNum[i]){
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

    case 6://TH3 without bomb
        num=num/10;

        //check for bomb with in the 5 blocks

        if (b[row][col-2]->number/10 != 0)
            ThreeNum[0]= b[row][col-2]->number%10;
        if (b[row][col-1]->number/10 != 0)
            ThreeNum[1]= b[row][col-1]->number%10;
        ThreeNum[2]=b[row][col]->number%10;

        //check for the bomb and then eliminate them
        for (int i=0; i<3; i++)
        {
            eliminate *e;

            switch(ThreeNum[i]){
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

void clean3h::elimination(Blank *b[10][10], Blank *clicked)
{

}

int clean3h::condition(Blank *b[10][10], Blank *clicked)
{
    int row= clicked->row;
    int col= clicked->column;
    int num= clicked->number;

    if (num!=0 && num!=5)
    {
        if (num/10==0)
        {
            if (col<=7 && (num==b[row][col+1]->number || num==b[row][col+1]->number/10) && (num==b[row][col+2]->number || num==b[row][col+2]->number/10))
            {return 1;}//ThreeHor1 without bomb
            if (col>=1 && col<=8 && (num==b[row][col-1]->number || num==b[row][col-1]->number/10) && (num==b[row][col+1]->number || num==b[row][col+1]->number/10))
            {return 2;}//ThreeHor2 without bomb
            if (col>=2 && (num==b[row][col-2]->number || num==b[row][col-2]->number/10) && (num==b[row][col-1]->number || num==b[row][col-1]->number/10))
            {return 3;}//ThreeHor1 without bomb
        }
        else
        {
            num/=10;//determine the color
            if (col<=7 && (num==b[row][col+1]->number || num==b[row][col+1]->number/10) && (num==b[row][col+2]->number || num==b[row][col+2]->number/10))
            {return 4;}//ThreeHor1 with bomb
            if (col>=1 && col<=8 && (num==b[row][col-1]->number || num==b[row][col-1]->number/10) && (num==b[row][col+1]->number || num==b[row][col+1]->number/10))
            {return 5;}//ThreeHor2 with bomb
            if (col>=2 && (num==b[row][col-2]->number || num==b[row][col-2]->number/10) && (num==b[row][col-1]->number || num==b[row][col-1]->number/10))
            {return 6;}//ThreeHor1 with bomb
        }
    }
    return 0;
}

