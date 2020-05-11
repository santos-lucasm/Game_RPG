#include "Manager/asset_manager.h"
#include <assert.h>
#include <iostream>

AssetManager * AssetManager::Instance = nullptr;

AssetManager::AssetManager()
{
    assert( Instance == nullptr );
    Instance = this;

    if(traced) Tracer("AssetManager<constructor>");
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