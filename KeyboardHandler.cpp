#include "KeyboardHandler.h"

bool KeyboardHandler::handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
{
    if(ea.getEventType() == osgGA::GUIEventAdapter::KEYDOWN)
    {
        if(ea.getKey() == 'w')
        {
            std::cout << "W pressed" << std::endl;

            return false;
        }
    }

    return false;
}

bool KeyboardHandler::accept(osgGA::GUIEventHandlerVisitor& v)
{
    v.visit(*this);

    return false;
}
