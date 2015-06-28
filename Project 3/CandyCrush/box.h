#ifndef BOX_H
#define BOX_H

#include "vertical.h"
#include "horizontal.h"
#include "eliminate.h"
#include "blank.h"


class box:public eliminate
{
public:
    box();
    virtual ~box();
    virtual void spawn(Blank*b[10][10],Blank*clicked,int mode);
    virtual void elimination(Blank*b[10][10], Blank*clicked);
    virtual int condition(Blank*b[10][10], Blank*clicked);
};

#endif // BOX_H
