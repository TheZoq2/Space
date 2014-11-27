#include "Material.h"

Material::Material()
{
    this->mStateSet = new osg::StateSet();
}

void Material::setTexture(int id, osg::Texture2D* texture)
{
    //If there is a texture with that ID already
    if(mTextures.count(id) != 0)
    {
        //delete mTextures[id];
    }

    this->mTextures[id] = texture;

    this->mStateSet->setTextureAttributeAndModes(id, texture, osg::StateAttribute::ON);
}
