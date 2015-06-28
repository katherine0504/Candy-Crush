#ifndef HORIZONTAL_H
#define HORIZONTAL_H

#include "vertical.h"
#include "box.h"
#include "eliminate.h"
#include "blank.h"

class horizontal:public eliminate
{
public:
    horizontal();
    virtual ~horizontal();
    virtual void spawn(Blank*b[10][10],Blank*clicked,int mode);
    virtual void elimination(Blank*b[10][10], Blank*clicked);
    virtual int condition(Blank*b[10][10], Blank*clicked);
};

#endif // HORIZONTAL_H
