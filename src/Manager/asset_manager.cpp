#include "Manager/asset_manager.h"
#include <assert.h>
#include <iostream>

AssetManager * AssetManager::Instance = nullptr;

AssetManager::AssetManager()
{
    assert( Instance == nullptr );
    Instance = this;

    traced = false;
    if(traced) std::cout << "AssetManager<constructor>: IN" << std::endl;

    if(traced) std::cout << "AssetManager<constructor>: OUT" << std::endl;
}

AssetManager::~AssetManager()
{
    std::cout << "AssetManager<destructor>: IN" << std::endl;
    map_Textures.clear();
    Instance = nullptr;
    std::cout << "AssetManager<destructor>: OUT" << std::endl;
}

sf::Texture& AssetManager::getTexture( std::string const& filename )
{
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