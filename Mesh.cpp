#include "Mesh.h"

Mesh::Mesh(osg::Vec3Array* verts, std::vector<osg::DrawElementsUInt*>* faces, osg::Vec4Array* colors)
{
    this->mGeometry = new osg::Geometry();

    this->mVertices = verts;
    this->mFaces = faces;
    this->mColors = colors;

    mGeometry->setVertexArray(mVertices);
    
    for(unsigned int i = 0; i < faces->size(); i++)
    {
        mGeometry->addPrimitiveSet(faces->at(i));
    }

    mGeometry->setColorArray(colors);
    mGeometry->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
}

void Mesh::setTextureCoords(osg::Vec2Array* texCoords)
{
    mGeometry->setTexCoordArray(0, texCoords);
}

osg::Geometry* Mesh::getOsgGeometry()
{
    return this->mGeometry;
}
