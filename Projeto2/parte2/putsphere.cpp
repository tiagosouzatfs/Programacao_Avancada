#include "putsphere.h"

putsphere::putsphere(int _xcenter, int _ycenter, int _zcenter, int _radius, float _r, float _g, float _b, float _a){
    xcenter= _xcenter; ycenter= _ycenter; zcenter= _zcenter; radius= _radius;
    r=_r; g=_g; b=_b; a=_a;
}

putsphere::~putsphere(){

}

// adiciona uma esfera com base na coordenada do centro da esfera e o seu raio
void putsphere::draw(Sculptor &t){
    int i,j,k;
    for(i = xcenter-radius; i<xcenter+radius; i++){
        for(j = ycenter-radius; j<ycenter+radius; j++){
            for(k = zcenter-radius; k<zcenter+radius; k++){
                // utilizando a equação da esfera para adicionar os voxel's
                if((pow((i-xcenter),2)+pow((j-ycenter),2)+pow((k-zcenter),2))<=pow(radius,2)){
                    t.putVoxel(i,j,k);
                    t.setColor(r,g,b,a);
                }
            }
        }
    }
}
