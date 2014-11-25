cmake_minimum_required(VERSION 2.6)
project(OSGTest)

find_package( OpenThreads )
find_package( osg )
find_package( osgDB )
find_package( osgUtil )
find_package( osgViewer )

macro( config_project PROJNAME LIBNAME )
include_directories( ${${LIBNAME}_INCLUDE_DIR} )
target_link_libraries( ${PROJNAME} ${${LIBNAME}_LIBRARY} )
endmacro()

set(SOURCES
    main.cpp
    Object.cpp
    Object.h
    Mesh.cpp
    Mesh.h
    )

add_executable( MyProject ${SOURCES} )
config_project( MyProject OPENTHREADS )
config_project( MyProject OSG )
config_project( MyProject OSGDB )
config_project( MyProject OSGUTIL )
config_project( MyProject OSGVIEWER )
