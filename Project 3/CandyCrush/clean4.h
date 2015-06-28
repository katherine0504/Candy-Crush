#ifndef CLEAN4_H
#define CLEAN4_H

#include "blank.h"
#include "blank.h"
#include "eliminate.h"
#include "box.h"
#include "vertical.h"
#include "horizontal.h"


class clean4:public eliminate
{
public:
    clean4();
    virtual ~clean4();
    virtual void spawn(Blank*b[10][10],Blank*clicked,int mode);
    virtual void elimination(Blank*b[10][10], Blank*clicked);
    virtual int condition(Blank*b[10][10], Blank*clicked);
};


#endif // CLEAN4_H
