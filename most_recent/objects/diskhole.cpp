#include "diskhole.h"
#include "cmath"

DiskHole::DiskHole(int nbVertices, float radius, int ndisk) : TriMesh()
{
    _name = "DiskHole";

    addVertex(0,0,-1);
    double angle;

    for (int i=0;i<ndisk;++i) {
        float r = 1-(1-radius)*i/((float)ndisk-1);
        this->addVertex(0,0,0);
        for (float i=0; i<2*M_PI ; i+=(2/_vertices.size())*M_PI)
            this->addVertex(r*cos(i),r*sin(i),0);
    }

    for(int i = 1 ; i < _vertices.size(); i++) {
        this->addTriangle(0, i % _vertices.size(), (i + 1) % _vertices.size());
    }
    this->addTriangle(0, _vertices.size() -1, 1);

    computeNormalsT();
    computeNormalsV();
}
