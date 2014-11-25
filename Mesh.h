#ifndef H_MESH
#define H_MESH

#include <osg/Geometry>
#include <vector>

class Mesh
{
public:
    Mesh(osg::Vec3Array* verts, std::vector<osg::DrawElementsUInt*>* faces, osg::Vec4Array* colors);

    osg::Geometry* getOsgGeometry();
private:
    osg::Geometry* mGeometry;
    osg::Vec3Array* mVertices;
    std::vector<osg::DrawElementsUInt*>* mFaces;
    osg::Vec4Array* mColors;
};

#endif
