#include "cone.h"
#include "disk.h"
#include "cmath"

Cone::Cone(int nbVertices) : TriMesh()
{
    _name = "Cone";

    Disk* disk = new Disk(nbVertices);
    double angle;

    for(int i = 0; i < nbVertices; i++) {
        this->addVertex(disk->getVertex(i).x, disk->getVertex(i).y, -1);
    }

    addVertex(0,0,1);

    for(int i = 0; i < nbVertices; i++) {
        angle = 2 * M_PI * i / nbVertices;
        this->addVertex(cos(angle), sin(angle), -1);
    }

    for(int i = 1; i < _vertices.size(); i++) {
        this->addTriangle(0, i % _vertices.size(), (i + 1) % _vertices.size());
    }
    this->addTriangle(0, _vertices.size() -1, 1);

    computeNormalsT();
    computeNormalsV();
}
