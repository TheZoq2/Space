#ifndef H_TERRAIN_GENERATOR
#define H_TERRAIN_GENERATOR

#include "Mesh.h"
#include "Generator.h"

#include <math.h>


class TerrainGenerator
{
public:
    TerrainGenerator(double seed);

    double getTerrainHeight(double x, double z);

private:
    Generator generator;

    double getPointHeight(double x, double z, double detailLevel);
};

#endif
