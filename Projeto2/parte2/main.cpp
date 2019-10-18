#include <iostream>
#include <fstream>
#include <string>
#include "sculptor.h"
#include <figurageometrica.h>
#include <sstream>
#include <vector>
#include <putvoxel.h>
#include <cutvoxel.h>
#include <putbox.h>
#include <cutbox.h>
#include <putsphere.h>
#include <cutsphere.h>
#include <putellipsoid.h>
#include <cutellipsoid.h>

using namespace std;

int main(){
    //cria o arquivo caso ele não exista
    //ofstream entrada;
    //entrada.open("/home/tiago/PA_parte2/entrada.txt");
    //entrada.close();

    //abrir o arquivo caso ele exista e mostra as inforamaçoes dentro dele na tela
    ifstream arquivo;
    string linha;
    stringstream aux;
    Sculptor *escultor = nullptr;
    vector<FiguraGeometrica*>figura;

    arquivo.open("/home/tiago/PA_parte2/entrada.txt");
    if(arquivo.is_open() and arquivo.good()){
        while(getline(arquivo, linha)){
            aux.clear();
            aux.str(linha);
            aux>>linha;
            cout << linha << endl;
            if(linha.compare("dim")==0){
                int x, y, z;
                aux >> x >> y >> z;
                escultor = new Sculptor(x,y,z);
            }
            else if(linha.compare("putvoxel")==0){
                int x, y, z; float r, g, b, a;
                aux >> x >> y >> z >> r >> g >> b >> a;
                figura.push_back(new putvoxel(x,y,z,r,g,b,a));
            }
            else if(linha.compare("cutvoxel")==0){
                int x, y, z;
                aux >> x >> y >> z ;
                figura.push_back(new cutvoxel(x,y,z));
            }
            else if(linha.compare("putbox")==0){
                int x0, y0, z0, x1, y1, z1; float r, g, b, a;
                aux >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
                figura.push_back(new PutBox(x0,x1,y0,y1,z0,z1,r,g,b,a));

            }
            else if(linha.compare("cutbox")==0){
                int x0, y0, z0, x1, y1, z1;
                aux >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 ;
                figura.push_back(new CutBox(x0,x1,y0,y1,z0,z1));

            }
            else if(linha.compare("putesphere")==0){
                int xcenter, ycenter, zcenter, radius;
                float r, g, b, a;
                aux >> xcenter >> ycenter >> zcenter >> radius >> r >> g >> b >> a;
                figura.push_back(new putsphere(xcenter,ycenter,zcenter,radius,r,g,b,a));

            }
            else if(linha.compare("cutesphere")==0){
                int xcenter, ycenter, zcenter, radius;
                aux >> xcenter >> ycenter >> zcenter >> radius;
                figura.push_back(new cutsphere(xcenter,ycenter,zcenter,radius));

            }
            else if(linha.compare("putellipsoid")==0){
                int xcenter, ycenter, zcenter, rx, ry, rz;
                float r, g, b, a;
                aux >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b >> a;
                figura.push_back(new putellipsoid(xcenter,ycenter,zcenter,rx,ry,rz,r,g,b,a));

            }
            else if(linha.compare("cutellipsoid")==0){
                int xcenter, ycenter, zcenter, rx, ry, rz;
                aux >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz;
                figura.push_back(new cutellipsoid(xcenter,ycenter,zcenter,rx,ry,rz));

            }
        }
    }    else {
        cout << "Não foi possível abrir o arquivo!" << endl;
    }

    cout << endl;

    for(int i=0; i<figura.size(); i++){
            figura[i]->draw(*escultor);
    }

    string filename = "/home/tiago/PA_parte2/arquivo.off";
    escultor->writeOFF(filename);
    escultor->~Sculptor();

    arquivo.close();

    return 0;
}
