#include <iostream>
#include <fstream>
#include <string>
#include "sculptor.h"


using namespace std;

int main()
{
    Sculptor escultor(90,90,90);
    escultor.setColor(0.5,1.0,0.5,0.2);

    escultor.putVoxel(5,5,5);
    //escultor.cutVoxel(5,5,5);

    escultor.putBox(10,25,10,25,10,25);
    //escultor.cutBox(10,25,10,25,10,25);

    escultor.putSphere(35,30,30,15);
    //escultor.cutSphere(35,30,30,15);

    escultor.putEllipsoid(50,35,70,22,15,17);
    //escultor.cutEllipsoid(50,35,70,22,15,17);
    
    string filename = "/home/tiago/Área de Trabalho/programacaoAvancada/project2/arquivo.off";
    escultor.writeOFF(filename);


    return 0;
}
