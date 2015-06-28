#ifndef ELIMINATE_H
#define ELIMINATE_H

#include "blank.h"

class eliminate
{
public:
    eliminate();
    virtual ~eliminate();
    virtual void spawn(Blank*b[10][10],Blank*clicked,int mode)=0;
    virtual void elimination(Blank*b[10][10], Blank*clicked)=0;
    virtual int condition(Blank*b[10][10], Blank*clicked)=0;
};

#endif // ELIMINATE_H
