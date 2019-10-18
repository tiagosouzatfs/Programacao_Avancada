#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include <sculptor.h>

class FiguraGeometrica{
public:
    FiguraGeometrica();
    virtual ~FiguraGeometrica();
    virtual void draw(Sculptor &t)=0;
};

#endif // FIGURAGEOMETRICA_H
