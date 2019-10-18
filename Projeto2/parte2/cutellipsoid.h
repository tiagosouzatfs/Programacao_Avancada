#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
#include <figurageometrica.h>
#include <sculptor.h>
#include <cmath>

class cutellipsoid: public FiguraGeometrica{
protected:
    int xcenter, ycenter, zcenter, rx, ry, rz;
public:    
    cutellipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry, int _rz);
    virtual ~cutellipsoid();
    void draw(Sculptor &t);
};

#endif // CUTELLIPSOID_H
