#include "clean5.h"

clean5::clean5()
{

}

clean5::~clean5()
{

}

int clean5::condition(Blank *b[10][10], Blank *clicked)//可以產生星星的條件
{
    int row= clicked->row;
    int col= clicked->column;
    int num= clicked->number;

    if (num!=0 && num!=5)
    {
        if (num/10==0)
        {
            if (row>=2 && row<=7 && ((num==b[row-2][col]->number) || (num==b[row-2][col]->number/10)) && ((num==b[row-1][col]->number) || (num==b[row-1][col]->number/10)) && ((num==b[row+1][col]->number) || (num==b[row+1][col]->number/10)) && ((num==b[row+2][col]->number) || (num==b[row+2][col]->number/10)))
            {return 1;}//vertical without bomb

            if (col>=2 && col<=7 && ((num==b[row][col-2]->number) || (num==b[row][col-2]->number/10)) && ((num==b[row][col-1]->number) || (num==b[row][col-1]->number/10)) && ((num==b[row][col+1]->number) || (num==b[row][col+1]->number/10)) && ((num==b[row][col+2]->number) || (num==b[row][col+2]->number/10)))
            {return 2;}//horizontal without bomb

        }
        else
        {
            num/=10;//determine the color
            if (row>=2 && row<=7 && ((num==b[row-2][col]->number) || (num==b[row-2][col]->number/10)) && ((num==b[row-1][col]->number) || (num==b[row-1][col]->number/10)) && ((num==b[row+1][col]->number) || (num==b[row+1][col]->number/10)) && ((num==b[row+2][col]->number) || (num==b[row+2][col]->number/10)))
            {return 3;}//vertical with bomb

            if (col>=2 && col<=7 && ((num==b[row][col-2]->number) || (num==b[row][col-2]->number/10)) && ((num==b[row][col-1]->number) || (num==b[row][col-1]->number/10)) && ((num==b[row][col+1]->number) || (num==b[row][col+1]->number/10)) && ((num==b[row][col+2]->number) || (num==b[row][col+2]->number/10)))
            {return 4;}//horizontal with bomb

        }
    }
    return 0;
}

void clean5::elimination(Blank *b[10][10], Blank *clicked)
{

}

void clean5::spawn(Blank *b[10][10], Blank *clicked, int mode)
{
    int row= clicked->row;
    int col= clicked->column;
    int num= clicked->number;
    int FiveNum[5]={0};

    switch(mode){
    case 1://verital without bomb
        clicked->number=5;
        if (col>=2 && (num==b[row][col-2]->number) && (num==b[row][col-1]->number))
        {
            b[row][col-2]->number=0;
            b[row][col-1]->number=0;
        }//check the left side
        if (col<=7 && (num==b[row][col+2]->number) && (num==b[row][col+1]->number))
        {
            b[row][col+1]->number=0;
            b[row][col+2]->number=0;
        }//check the right side

        //check for bomb with in the 5 blocks
        if (b[row-2][col]->number/10 != 0)
            FiveNum[0]= b[row-2][col]->number%10;
        if (b[row-1][col]->number/10 != 0)
            FiveNum[1]= b[row-1][col]->number%10;
        FiveNum[2]=b[row][col]->number;
        if (b[row+1][col]->number/10 != 0)
            FiveNum[3]= b[row+1][col]->number%10;
        if (b[row+2][col]->number/10 != 0)
            FiveNum[4]= b[row+2][col]->number%10;


        //check for the bomb and then eliminate them
        for (int i=0; i<5; i++)
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
        }break;

    case 2://horizontal without bomb
        clicked->number=5;
        if (row>=2 && (num==b[row-2][col]->number) && (num==b[row-1][col]->number))
        {
            b[row-2][col]->number=0;
            b[row-1][col]->number=0;
        }//check the left side
        if (row<=7 && (num==b[row+2][col]->number) && (num==b[row+1][col]->number))
        {
            b[row+1][col]->number=0;
            b[row+2][col]->number=0;
        }//check the right side

        //check for bomb with in the 5 blocks
        if (b[row][col-2]->number/10 != 0)
            FiveNum[0]= b[row][col-2]->number%10;
        if (b[row][col-1]->number/10 != 0)
            FiveNum[1]= b[row][col-1]->number%10;
        FiveNum[2]=b[row][col]->number;
        if (b[row][col+1]->number/10 != 0)
            FiveNum[3]= b[row][col+1]->number%10;
        if (b[row][col+2]->number/10 != 0)
            FiveNum[4]= b[row][col+2]->number%10;


        //check for the bomb and then eliminate them
        for (int i=0; i<5; i++)
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
        }break;

        case 3://verital with bomb
            num/=10;
            if (col>=2 && (num==b[row][col-2]->number) && (num==b[row][col-1]->number))
            {
                b[row][col-2]->number=0;
                b[row][col-1]->number=0;
            }//check the left side
            if (col<=7 && (num==b[row][col+2]->number) && (num==b[row][col+1]->number))
            {
                b[row][col+1]->number=0;
                b[row][col+2]->number=0;
            }//check the right side

            //check for bomb with in the 5 blocks
            if (b[row-2][col]->number/10 != 0)
                FiveNum[0]= b[row-2][col]->number%10;
            if (b[row-1][col]->number/10 != 0)
                FiveNum[1]= b[row-1][col]->number%10;
            FiveNum[2]=b[row][col]->number%10;
            if (b[row+1][col]->number/10 != 0)
                FiveNum[3]= b[row+1][col]->number%10;
            if (b[row+2][col]->number/10 != 0)
                FiveNum[4]= b[row+2][col]->number%10;


            //check for the bomb and then eliminate them
            for (int i=0; i<5; i++)
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
            }break;

    case 4://horizontal with bomb
        num/=10;
        if (row>=2 && (num==b[row-2][col]->number) && (num==b[row-1][col]->number))
        {
            b[row-2][col]->number=0;
            b[row-1][col]->number=0;
        }//check the left side
        if (row<=7 && (num==b[row+2][col]->number) && (num==b[row+1][col]->number))
        {
            b[row+1][col]->number=0;
            b[row+2][col]->number=0;
        }//check the right side

        //check for bomb with in the 5 blocks
        if (b[row][col-2]->number/10 != 0)
            FiveNum[0]= b[row][col-2]->number%10;
        if (b[row][col-1]->number/10 != 0)
            FiveNum[1]= b[row][col-1]->number%10;
        FiveNum[2]=b[row][col]->number%10;
        if (b[row][col+1]->number/10 != 0)
            FiveNum[3]= b[row][col+1]->number%10;
        if (b[row][col+2]->number/10 != 0)
            FiveNum[4]= b[row][col+2]->number%10;


        //check for the bomb and then eliminate them
        for (int i=0; i<5; i++)
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
        }break;
    }
}

