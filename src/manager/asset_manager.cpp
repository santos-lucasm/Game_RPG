#include <assert.h>
#include <iostream>
#include "manager/asset_manager.h"

AssetManager * AssetManager::Instance = nullptr;

AssetManager::AssetManager()
{
    if(traced) Tracer("AssetManager<constructor>");
    
    assert( Instance == nullptr );
    Instance = this;
}

AssetManager::~AssetManager()
{
    if(traced) Tracer("AssetManager<destructor>");
    
    map_Textures.clear();
    Instance = nullptr;
}

sf::Texture& AssetManager::getTexture( std::string const& filename )
{
    if(traced) Tracer("AssetManager<getTexture>");

    auto& texMap = Instance->map_Textures;
    auto pair = texMap.find(filename);

    if( pair != texMap.end() )
        return pair->second;
    else
    {
        auto& texture = texMap[filename];
        texture.loadFromFile(filename);
        /*
        TODO: Throw a custom exception here, if cannot load
        https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm
        */
        return texture;
    }
}