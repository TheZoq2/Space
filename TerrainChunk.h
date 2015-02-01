#ifndef H_TERRAINCHUNK
#define H_TERRAINCHUNK

#include <osg/Geometry>
#include <osg/Matrix>
#include <osg/Texture2D>

#include "Object.h"
#include "Mesh.h"
#include "TerrainGenerator.h"

//The distance between vertecies on the chunk. To avoid gaps, chunk
//Sizes need to be divisible by this number
#define TERRAIN_VERTEX_SIZE 1 

class TerrainChunk
{
public:
    TerrainChunk(TerrainGenerator* generator, int xStart, int zStart, int xSize, int zSize);

private:
    void generateGeometry(TerrainGenerator* generator);

    Mesh* geometry;
    Object* object;

    int xStart;
    int zStart;
    int xSize;
    int zSize;
};

#endif

