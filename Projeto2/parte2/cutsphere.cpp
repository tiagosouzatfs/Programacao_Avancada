#include "cutsphere.h"

cutsphere::cutsphere(int _xcenter, int _ycenter, int _zcenter, int _radius){
    xcenter= _xcenter; ycenter= _ycenter; zcenter= _zcenter; radius= _radius;
}

cutsphere::~cutsphere(){

}


// faz o corte no formato de uma esfera com base na coordenada do centro da esfera e o seu raio
void cutsphere::draw(Sculptor &t){
    int i,j,k;
    for(i = xcenter-radius; i<xcenter+radius; i++){
        for(j = ycenter-radius; j<ycenter+radius; j++){
            for(k = zcenter-radius; k<zcenter+radius; k++){
                if((pow((i-xcenter),2)+pow((j-ycenter),2)+pow((k-zcenter),2))<=pow(radius,2)){
                    t.cutVoxel(i,j,k);
                }
            }
        }
    }

}
