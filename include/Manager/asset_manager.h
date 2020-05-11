#ifndef _ASSET_MANAGER_H
#define _ASSET_MANAGER_H

#include <SFML/Graphics.hpp>
#include <map>

/*
Description:
    AssetManager class is a singleton, initialized on Game class after
setting window parameters.
    It's responsible for managing textures that'll be used on entities.
*/
class AssetManager
{
public:
    /*
    Description:
        Guarantee that AssetManager is a singleton.
        If it's the first class creation, Instance pointer receives this.
        Else, program stops execution.
    */
    AssetManager();

    /*
    Description:
        Clear private atributes before program finish execution.
    */
    ~AssetManager();

    /*  
    Description:
        Search on the map using the passed string, to find the equivalent texture.
        If it cannot find the string on the list, try to load texture from resources folder.
    Return:
        If a pair is found, return the equivalent texture adress.
        Else if a pair isn't found, tries to load the equivalent texture and return it.
        If the texture cannot be loaded, throw a XXX exception.
    */
    static sf::Texture& getTexture( std::string const& filename );

private:
    /* Maps strings into textures (loadeds and unloadeds) */
    std::map<std::string, sf::Texture> map_Textures;
    /* Pointer to itself */
    static AssetManager * Instance;
    /* Toggle entry fuction points to debugging */
    bool traced;
};

#endif