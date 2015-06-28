#ifndef CLEAN3V_H
#define CLEAN3V_H

#include "blank.h"
#include "blank.h"
#include "eliminate.h"
#include "box.h"
#include "vertical.h"
#include "horizontal.h"

class clean3v:public eliminate
{
public:
    clean3v();
    virtual ~clean3v();
    virtual void spawn(Blank*b[10][10],Blank*clicked,int mode);
    virtual void elimination(Blank*b[10][10], Blank*clicked);
    virtual int condition(Blank*b[10][10], Blank*clicked);
};

#endif // CLEAN3V_H
