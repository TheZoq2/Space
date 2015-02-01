#include "TerrainChunk.h"

TerrainChunk::TerrainChunk(TerrainGenerator* generator, int xStart, int zStart, int xSize, int zSize)
{
    this->xStart = xStart;
    this->zStart = zStart;
    this->xSize = xSize;
    this->zSize = zSize;

    //Generating the new geometry
    generateGeometry(generator);
}

void TerrainChunk::generateGeometry(TerrainGenerator* generator)
{
    osg::Vec3Array* vertecies = new osg::Vec3Array();

    for(double x = 0; x < xSize; x += xSize)
    {
        for(double z = 0; z < zSize; z += zSize)
        {
            double xCoord = x + xStart;
            double zCoord = z + zStart;
            //Calculate the height of the point
            float height = generator->getTerrainHeight(xCoord, zCoord);

            vertecies->push_back(osg::Vec3(x, height, z));
        }
    }
}
