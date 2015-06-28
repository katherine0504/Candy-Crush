#ifndef CLEAN3H_H
#define CLEAN3H_H

#include "blank.h"
#include "blank.h"
#include "eliminate.h"
#include "box.h"
#include "vertical.h"
#include "horizontal.h"

class clean3h:public eliminate
{
public:
    clean3h();
    virtual ~clean3h();
    virtual void spawn(Blank*b[10][10],Blank*clicked,int mode);
    virtual void elimination(Blank*b[10][10], Blank*clicked);
    virtual int condition(Blank*b[10][10], Blank*clicked);
};

#endif // CLEAN3H_H
