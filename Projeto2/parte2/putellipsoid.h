#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include <figurageometrica.h>
#include <sculptor.h>
#include <cmath>

class putellipsoid: public FiguraGeometrica{
protected:
    int xcenter, ycenter, zcenter, rx, ry, rz;
    float r, g, b, a;
public:
    putellipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry, int _rz, float _r, float _g, float _b, float _a);
    virtual ~putellipsoid();
    void draw(Sculptor &t);
};

#endif // PUTELLIPSOID_H

