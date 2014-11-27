#ifndef H_KBDHandler
#define H_KBDHandler

#include <osgGA/GUIEventHandler>
#include <osgGA/GUIEventAdapter>

#include <iostream>

class KeyboardHandler : public osgGA::GUIEventHandler
{
public:
    virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa);
    virtual bool accept(osgGA::GUIEventHandlerVisitor& v);
private:

};

#endif
