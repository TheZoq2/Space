#ifndef H_MATERIAL
#define H_MATERIAL

#include <osg/StateSet>
#include <osg/Texture>
#include <osg/Texture2D>

#include <map>

class Material
{
public:
    Material();

    void setTexture(int id, osg::Texture2D* texture);

    osg::StateSet* getStateSet();
    
private:
    osg::StateSet* mStateSet;

    //std::vector< osg::Texture > mTextures;
    std::map<int, osg::Texture2D*> mTextures;
};

#endif
