#ifndef VERTICAL_H
#define VERTICAL_H

#include "horizontal.h"
#include "box.h"
#include "eliminate.h"
#include "blank.h"

class vertical:public eliminate
{
public:
    vertical();
    virtual ~vertical();
    virtual void spawn(Blank*b[10][10],Blank*clicked,int mode);
    virtual void elimination(Blank*b[10][10], Blank*clicked);
    virtual int condition(Blank*b[10][10], Blank*clicked);
};

#endif // VERTICAL_H
