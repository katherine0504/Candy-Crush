#ifndef CLEAN5_H
#define CLEAN5_H

#include "blank.h"
#include "eliminate.h"
#include "box.h"
#include "vertical.h"
#include "horizontal.h"

class clean5:public eliminate
{
public:
    clean5();
    virtual ~clean5();
    virtual void spawn(Blank*b[10][10],Blank*clicked,int mode);
    virtual void elimination(Blank*b[10][10], Blank*clicked);
    virtual int condition(Blank*b[10][10], Blank*clicked);
};

#endif // CLEAN5_H
