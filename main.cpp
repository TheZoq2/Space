#include <vector>

#include <osgDB/ReadFile>
#include <osgViewer/Viewer>
#include <osg/Geometry>
#include <osg/Matrix>
#include <osg/Texture2D>

#include "Object.h"
#include "Mesh.h"
#include "Camera.h"
#include "KeyboardHandler.h"
#include "Material.h"

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
    /*
    colors->push_back(osg::Vec4(0.0f, 0.0f, 0.0f, 1.0f));
    colors->push_back(osg::Vec4(0.0f, 0.0f, 1.0f, 1.0f));
    colors->push_back(osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f));
    colors->push_back(osg::Vec4(0.0f, 1.0f, 1.0f, 1.0f));
    colors->push_back(osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f));
    colors->push_back(osg::Vec4(1.0f, 0.0f, 1.0f, 1.0f));
    colors->push_back(osg::Vec4(1.0f, 1.0f, 0.0f, 1.0f));
    colors->push_back(osg::Vec4(1.0f, 1.0f, 1.0f, 1.0f));
    */

    for(int i = 0; i < 8; i++)
    {
        colors->push_back(osg::Vec4(1.0f, 1.0f, 1.0f, 1.0f));
    }

    //Setting texture coords
    osg::Vec2Array* texCoords = new osg::Vec2Array(8);
    (*texCoords)[0].set(1.0f, 1.0f);
    (*texCoords)[1].set(0.0f, 1.0f);
    (*texCoords)[2].set(1.0f, 0.0f);
    (*texCoords)[3].set(0.0f, 0.0f);
    (*texCoords)[4].set(1.0f, 1.0f);
    (*texCoords)[5].set(0.0f, 1.0f);
    (*texCoords)[6].set(1.0f, 0.0f);
    (*texCoords)[7].set(0.0f, 1.0f);
    (*texCoords)[8].set(0.0f, 0.0f);
    
    verts->push_back( osg::Vec3(1, 1, 1));
    verts->push_back( osg::Vec3(-1, 1, 1));
    verts->push_back( osg::Vec3(1, 1, -1));
    verts->push_back( osg::Vec3(-1, 1, -1));
    //Bottom faces
    verts->push_back( osg::Vec3(1, -1, 1));
    verts->push_back( osg::Vec3(-1, -1, 1));
    verts->push_back( osg::Vec3(1, -1, -1));
    verts->push_back( osg::Vec3(-1, -1, -1));

    Mesh result(verts, faces, colors);
    return result;
}

int main()
{
    Mesh cubeGeometry = createCubeGeometry();
    Object skybox(&cubeGeometry);
    
    int sceneryAmount = 100;
    int maxSize = 30;
    std::vector<Object> scenery;

    osg::Group* root = new osg::Group();

    root->addChild(skybox.getRoot());

    int worldSize = 100000;

    //skybox.setPosition(osg::Vec3(0, 0, -3));
    skybox.setPosition(osg::Vec3(0, 0, 0));
    //skybox.setScale(osg::Vec3(0.1f, 0.1f, 0.1f));
    skybox.setScale(osg::Vec3(worldSize, worldSize, worldSize));
    //skybox.setRotation(0.5, 0.5, 0.5);

    //Loading skybox texture
    osg::Texture2D* skyboxTexture = new osg::Texture2D();
    osg::Image* skyboxImage = osgDB::readImageFile("../media/stars.png");

    if(!skyboxImage)
    {
        std::cout << "Failed to load image" << std::endl;
    }
    
    skyboxTexture->setImage(skyboxImage);

    Material skyboxMaterial;
    skyboxMaterial.setTexture(0, skyboxTexture);

    skybox.setMaterial(skyboxMaterial);

	osgViewer::Viewer viewer;

    //KeyboardHandler* kbdHandler = new KeyboardHandler();
    //viewer.addEventHandler(kbdHandler);

    Camera camera(viewer.getCamera());

    float cameraAngle = 0;
    float objectAngle = 0;


	viewer.setSceneData( root );
    while(viewer.done() == false)
    {
        cameraAngle += 0.03;

        skybox.setRotation(0.5, 0, objectAngle);

        camera.setRotation(osg::Vec3(0, sin(cameraAngle), 0));
        viewer.frame();
    }
}
