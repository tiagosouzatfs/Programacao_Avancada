#include <putbox.h>

PutBox::PutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1, float _r,
               float _g, float _b, float _a){
    x0=_x0; x1=_x1; y0=_y0; y1=_y1; z0=_z0; z1=_z1;
    a=_a; b=_b; r=_r; g=_g;
};

PutBox::~PutBox(){

}

// adiciona um cubo
void PutBox::draw(Sculptor &t){

    int i,j,k;
    // verificação das dimensões atribuida.
        for(i = x0; i<=x1; i++){
            for(j = y0; j<=y1; j++){
                for(k = z0; k<=z1;k++){
                   t.putVoxel(i,j,k);
                   t.setColor(r, g, b, a);
                }
            }
      }
}
