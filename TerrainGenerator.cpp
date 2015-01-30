#include "TerrainGenerator.h"

TerrainGenerator::TerrainGenerator(double seed)
{
    this->generator.setSeed(seed);

}

double TerrainGenerator::getTerrainHeight(double x, double z)
{
    
}


/////////////////////////////////////////////////////////////////
//                  Private methods
/////////////////////////////////////////////////////////////////

double TerrainGenerator::getPointHeight(double x, double z, double detailLevel)
{
    //Find the closest points on the specified detail level
    double x1 = floor(x) * detailLevel;
    double x2 = ceil(x) * detailLevel;

    double z1 = floor(z) * detailLevel;
    double z2 = ceil(z) * detailLevel;

    //Generating the height of the four points
    double heightx1z1 = generator.rand2d(x1, z1);
    double heightx1z2 = generator.rand2d(x1, z2);
    double heightx2z1 = generator.rand2d(x2, z1);
    double heightx2z2 = generator.rand2d(x2, z2);
}

