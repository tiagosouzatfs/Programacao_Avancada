#include "sculptor.h"
#include <cmath>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

Sculptor::Sculptor(int _nx, int _ny, int _nz){
nx=_nx; ny=_ny; nz=_nz;

//alocação do array auxiliar de array's
v=new Voxel**[nx];
if( v == nullptr){
    cout << "novo erro\n";
}

//alocação de outro array auxiliar salvando a posição no array de array's
v[0]=new Voxel*[nx*ny];
if( v[0] == nullptr){
    cout << "new error\n";
}

//alocação da matriz 3D
v[0][0]=new Voxel[nx*ny*nz];
if( v[0][0] == nullptr){
    cout << "new error\n";
}
for(int i=0; i< nx; i++){
    if (i<(nx-1)){
        v[i+1] = v[i]+ny;
    }
    for(int j=1; j< ny; j++){
        v[i][j] = v[i][j-1]+nz;
        if(j==ny-1 && i!=(nx-1)){
            v[i+1][0] = v[i][j]+nz;
        }
    }
}

// preenchimento da matriz alocada com o isOn do struct de Voxel = false
for(int i = 0; i < nx; i++){
    for(int j = 0; j < ny; j++){
        for(int k = 0; k < nz; k++){
            v[i][j][k].isOn=false;
        }
    }
}
cout<< "construtor" << endl;
}

// destrutor que tem como função liberar a memoria
Sculptor::~Sculptor(){
    delete [] v[0][0];
    delete [] v[0];
    delete [] v;
    cout <<"destrutor" << endl;
}
// atribui as cores
void Sculptor::setColor(float r, float g, float b, float alpha){
    this -> r = r;
    this -> g = g;
    this -> b = b;
    this -> a = alpha;
}

// cria um voxel
void Sculptor::putVoxel(int x, int y, int z){
    // verificação das dimensões atribuida.
    if(x>=0 && y>=0 && z>=0 && x<nx && y<ny && z<nz)    {
       // atribuições das cores para o Voxel selecionado e acionando o isOn do referido voxel
        v[x][y][z].r = r;
        v[x][y][z].g = g;
        v[x][y][z].b = b;
        v[x][y][z].a = a;
        v[x][y][z].isOn = true;
    }
}
// apagar um voxel
void Sculptor::cutVoxel(int x, int y, int z){
    // verificação das dimensões atribuida.
    if(x>=0 && y>=0 && z>=0 && x<nx && y<ny && z<nz){
        // Setando o isOn do voxel selecionado para false
        v[x][y][z].isOn=false;

    }
}


// gera o arquivo OFF com base nos metodos da classe sculptor utilizados
void Sculptor::writeOFF(string filename){
    int NV = 0, NF = 0;
    int i,j,k;
    // variavel para efetuar as funções de fluxos de dados
    ofstream fout;
    // abrindo o arquivo
    fout.open(filename);
    // conta a quantidade de faces e vertices que estão com isOn verdadeiro.
    if(!fout.is_open()){
        exit(0);
    }
    for(i = 0; i < nx; i++){
        for(j = 0; j < ny; j++){
            for(k = 0; k < nz; k++){
                if(v[i][j][k].isOn){
                    NV += 8;
                    NF += 6;
                }
            }
        }
    }
    // linha de reconhecimento do tipo do arquivo
    fout<<"OFF"<<endl;
    // numero de vertices, faces e das arestas que sempre será 0
    fout<<NV<<" "<<NF<<" "<<0<<endl;
    // dimensionamento dos vertices em relação aos voxel's com isOn verdadeiro
    for(i = 0; i < nx; i++){
        for(j = 0; j < ny; j++){
            for(k = 0; k < nz; k++){
                if(v[i][j][k].isOn){
                    fout<<i-0.5<<" "<<j+0.5<<" "<<k-0.5<<endl;
                    fout<<i-0.5<<" "<<j-0.5<<" "<<k-0.5<<endl;
                    fout<<i+0.5<<" "<<j-0.5<<" "<<k-0.5<<endl;
                    fout<<i+0.5<<" "<<j+0.5<<" "<<k-0.5<<endl;
                    fout<<i-0.5<<" "<<j+0.5<<" "<<k+0.5<<endl;
                    fout<<i-0.5<<" "<<j-0.5<<" "<<k+0.5<<endl;
                    fout<<i+0.5<<" "<<j-0.5<<" "<<k+0.5<<endl;
                    fout<<i+0.5<<" "<<j+0.5<<" "<<k+0.5<<endl;
                }
            }
        }
    }

    // dimensionamento de cada face e atribuição das cores
    int aux = 0;
    for(i = 0; i < nx; i++){
        for(j = 0; j < ny; j++){
            for(k = 0; k < nz; k++){
                if(v[i][j][k].isOn){
                    fout<<"4 "<<0+8*aux<<" "<<3+8*aux<<" "<<2+8*aux<<" "<<1+8*aux<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    fout<<"4 "<<4+8*aux<<" "<<5+8*aux<<" "<<6+8*aux<<" "<<7+8*aux<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    fout<<"4 "<<0+8*aux<<" "<<1+8*aux<<" "<<5+8*aux<<" "<<4+8*aux<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    fout<<"4 "<<0+8*aux<<" "<<4+8*aux<<" "<<7+8*aux<<" "<<3+8*aux<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    fout<<"4 "<<3+8*aux<<" "<<7+8*aux<<" "<<6+8*aux<<" "<<2+8*aux<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    fout<<"4 "<<1+8*aux<<" "<<2+8*aux<<" "<<6+8*aux<<" "<<5+8*aux<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    aux++;
                }
            }
        }
    }
    fout.close();
}
