#include "putellipsoid.h"

putellipsoid::putellipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry, int _rz, float _r,
                           float _g, float _b, float _a){
    xcenter= _xcenter; ycenter= _ycenter; zcenter=_zcenter; rx=_rx; ry= _ry; rz= _rz;
    r=_r; g=_g; b=_b; a=_a;
}
putellipsoid::~putellipsoid(){

}

// adiciona um elipse com base na coordenada do centro e os raios
void putellipsoid::draw(Sculptor &t){
    int i,j,k;
    for(i = xcenter-rx; i<xcenter+rx; i++){
        for(j = ycenter-ry; j<ycenter+ry; j++){
            for(k = zcenter-rz; k<zcenter+rz; k++){
                if(rx != 0 && ry != 0 && rz != 0){
                    if((((float)pow((i-xcenter),2)/(float)pow(rx,2))+((float)pow((j-ycenter),2)/(float)pow(ry,2))+((float)pow((k-zcenter),2)/(float)pow(rz,2)))<=1.0){
                        t.putVoxel(i,j,k);
                        t.setColor(r,g,b,a);
                    }
                }
            }
        }
    }
}


