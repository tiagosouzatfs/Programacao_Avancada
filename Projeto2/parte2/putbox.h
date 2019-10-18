#ifndef PUTBOX_H
#define PUTBOX_H
#include <figurageometrica.h>
#include <sculptor.h>

class PutBox: public FiguraGeometrica {
protected:
    int x0, x1, y0, y1, z0, z1;
    float r,g,b,a;
public:
    PutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1, float _r, float _g, float _b, float _a);
    virtual ~PutBox();
    void draw(Sculptor &t);
};

#endif // PUTBOX_H
