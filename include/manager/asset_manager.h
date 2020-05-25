#ifndef _ASSET_MANAGER_H
#define _ASSET_MANAGER_H

#include "utils/tracer.h"

/*! @class
    AssetManager class is a singleton, initialized on Game class after
setting window parameters.
    It's responsible for managing textures that'll be used on entities.
*/
class AssetManager
{
public:
    /*! @brief
        Guarantee that AssetManager is a singleton, i.e., if it's the
    first class creation, Instance pointer receives this.
        Else, program stops execution.
    */
    AssetManager();

    /*! @brief
        Clear loaded textures before program finish execution. */
    ~AssetManager();

    /*! @brief
        Search on the map using the passed string, to find the equivalent texture.
        If it cannot find the string on the map, try to load texture from resources folder.
    @param  filename  Name of resource file in which there's is a texture to be loaded.
    @return
        If a pair is found, return the equivalent texture adress.
        Else, if a pair isn't found, tries to load the equivalent texture and return it.
        If the texture cannot be loaded, throw a XXX exception.
    */
    static sf::Texture& getTexture( std::string const& filename);

private:
    /*! @property
    Maps strings into loaded textures. */
    std::map<std::string, sf::Texture> _mapTextures;

    /*! @property
    Pointer to itself. */
    static AssetManager * _Instance;

    /*! @property
    Traits flag that allow debug if class debug and tracer debug are active. */
    static const bool debugged = Traits<AssetManager>::debugged && Tracer::debugActive;

    /*! @property
    Traits flag that allow tracing if class tracing and tracer are active. */
    static const bool traced = Traits<AssetManager>::traced && Tracer::traceActive;
};

#endif