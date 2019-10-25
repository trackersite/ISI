#ifndef DISKHOLE_H
#define DISKHOLE_H

#include "triMesh.h"

class DiskHole : public TriMesh
{
public:
    DiskHole(int nbVertices, float radius, int ndisk);
    virtual ~DiskHole(){};
};

#endif // DISKHOLE_H
