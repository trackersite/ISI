#include "cube_corner.h"

Cube_corner::Cube_corner()
    : TriMesh()
{
    _name = "Cube_corner";

    // vertex coordinates
    static const GLfloat v[10][3] = {
      {-1,-1,-1},{1,-1,-1},{1,-1,1},{-1,-1,1},
      {-1,1, 1},{-1,1, -1},{0,1, -1},{1,0, -1},
      {1,1,0},{1,1,1}
    };

    // triangles vertex indices
    static const GLint t[16][3] = {
      {0,1,3},{1,2,3},  // bottom triangles
      {0,3,4},{4,5,0},{3,2,9},{3,9,4},{0,5,6},{0,6,1},{1,6,7},{1,7,8},    // side triangles
      {1,8,2},{2,8,9},{4,6,5},{6,4,8},{4,9,8},{6,8,7}   // top triangles
    };

    //--- Fill vertices and triangles vectors

    // Fill vertices vector
    for (int i=0; i<10 ; ++i)
      this->addVertex(v[i][0], v[i][1], v[i][2]);

    // Fill triangles vector
    for (int i=0; i<16; ++i)
      this->addTriangle(t[i][0], t[i][1], t[i][2]);

    // Fill normals vectors
    computeNormalsT();
    computeNormalsV();
}
