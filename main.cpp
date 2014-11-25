#include <vector>

#include <osgDB/ReadFile>
#include <osgViewer/Viewer>
#include <osg/Geometry>
#include <osg/Matrix>

#include "Object.h"
#include "Mesh.h"

Mesh createCubeGeometry()
{
osg::Vec3Array* verts = new osg::Vec3Array;

//Creating vertices
//Top face
verts->push_back( osg::Vec3(1, 1, 1));
verts->push_back( osg::Vec3(-1, 1, 1));
verts->push_back( osg::Vec3(1, 1, -1));
verts->push_back( osg::Vec3(-1, 1, -1));
//Bottom faces
verts->push_back( osg::Vec3(1, -1, 1));
verts->push_back( osg::Vec3(-1, -1, 1));
verts->push_back( osg::Vec3(1, -1, -1));
verts->push_back( osg::Vec3(-1, -1, -1));

//Creating faces
std::vector< osg::DrawElementsUInt* >* faces = new std::vector< osg::DrawElementsUInt* >;

//Top face
osg::DrawElementsUInt* face = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES);
face->push_back(0);
face->push_back(1);
face->push_back(2);
faces->push_back(face);

face = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES);
face->push_back(1);
face->push_back(2);
face->push_back(3);
faces->push_back(face);

//Bottom face
face = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES);
face->push_back(4);
face->push_back(5);
face->push_back(6);
faces->push_back(face);

face = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES);
face->push_back(5);
face->push_back(6);
face->push_back(7);
faces->push_back(face);

//Front face
face = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES);
face->push_back(0);
face->push_back(2);
face->push_back(4);
faces->push_back(face);

face = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES);
face->push_back(2);
face->push_back(4);
face->push_back(6);
faces->push_back(face);

//Back face
face = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES);
face->push_back(1);
face->push_back(3);
face->push_back(5);
faces->push_back(face);

face = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES);
face->push_back(3);
face->push_back(5);
face->push_back(7);
faces->push_back(face);

//Left face
face = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES);
face->push_back(0);
face->push_back(1);
face->push_back(4);
faces->push_back(face);

face = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES);
face->push_back(1);
face->push_back(4);
face->push_back(5);
faces->push_back(face);

//Left face
face = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES);
face->push_back(2);
face->push_back(3);
face->push_back(6);
faces->push_back(face);

face = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES);
face->push_back(3);
face->push_back(6);
face->push_back(7);
faces->push_back(face);

//Colors
osg::Vec4Array* colors = new osg::Vec4Array;
colors->push_back(osg::Vec4(0.0f, 0.0f, 0.0f, 1.0f));
colors->push_back(osg::Vec4(0.0f, 0.0f, 1.0f, 1.0f));
colors->push_back(osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f));
colors->push_back(osg::Vec4(0.0f, 1.0f, 1.0f, 1.0f));
colors->push_back(osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f));
colors->push_back(osg::Vec4(1.0f, 0.0f, 1.0f, 1.0f));
colors->push_back(osg::Vec4(1.0f, 1.0f, 0.0f, 1.0f));
colors->push_back(osg::Vec4(1.0f, 1.0f, 1.0f, 1.0f));

Mesh result(verts, faces, colors);
return result;
}

int main( int argc, char** argv )
{
    Mesh cubeGeometry = createCubeGeometry();
    Object skybox(&cubeGeometry);
    
    osg::Group* root = new osg::Group();

    root->addChild(skybox.getRoot());

    osg::Matrixd cameraRotation;
    osg::Matrixd cameraPosition;
    osg::Matrixd cameraMatrix;

    cameraRotation.makeRotate(
            0, osg::Vec3(0, 1, 0),
            0, osg::Vec3(1, 0, 0),
            0, osg::Vec3(0, 0, 1)
        );

    cameraMatrix = cameraRotation * cameraPosition;

	osgViewer::Viewer viewer;
	viewer.setSceneData( root );
    while(viewer.done() == false)
    {
        viewer.getCamera()->setViewMatrix(cameraMatrix);
        viewer.frame();
    }
    //return viewer.run();
}
