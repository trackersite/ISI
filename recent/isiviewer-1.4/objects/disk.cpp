#include "disk.h"

Disk::Disk() : TriMesh()
{

    _name = "Disk";

    // vertex coordinates
    static const GLfloat v[4][3] = {
      {-1,-1,1},{1,-1,1},{1,1,1},{-1,1,1},
    };

    // triangles vertex indices
    static const GLint t[2][3] = {
      {0,1,3},{1,2,3}
    };

    //--- Fill vertices and triangles vectors

    // Fill vertices vector
    for (int i=0; i<4 ; ++i)
      this->addVertex(v[i][0], v[i][1], v[i][2]);

    // Fill triangles vector
    for (int i=0; i<2; ++i)
      this->addTriangle(t[i][0], t[i][1], t[i][2]);

    // Fill normals vectors
    computeNormalsT();
    computeNormalsV();

}
