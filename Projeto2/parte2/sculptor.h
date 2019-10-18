#ifndef ESCULTOR_H
#define ESCULTOR_H
#include <string>
#include <voxel.h>

using namespace std;

class Sculptor {
protected:
  Voxel ***v;  // 3D matrix
  int nx,ny,nz; // Dimensions
  float r,g,b,a; // Current drawing color
public:
  Sculptor(int _nx, int _ny, int _nz);
  ~Sculptor();
  void setColor(float _r, float _g, float _b, float alpha);
  void putVoxel(int x, int y, int z);
  void cutVoxel(int x, int y, int z);
  void writeOFF(string filename);
};

#endif // ESCULTOR_H
