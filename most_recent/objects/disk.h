#ifndef DISK_H
#define DISK_H

#include "triMesh.h"

class Disk : public TriMesh
{
public:
    Disk(int nbVertices);
    virtual ~Disk(){};
};

#endif // DISK_H
