#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include <figurageometrica.h>
#include <sculptor.h>

class cutvoxel: public FiguraGeometrica{
protected:
    int x, y, z;
public:
    cutvoxel(int _x, int _y, int _z);
    virtual ~cutvoxel();
    void draw(Sculptor &t);
};

#endif // CUTVOXEL_H
