#include <assert.h>
#include <memory.h>
#include <iostream>
#include "manager/asset_manager.h"

AssetManager * AssetManager::Instance = nullptr;

AssetManager::AssetManager()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("AssetManager<constructor>") : nullptr;
    
    assert( Instance == nullptr );
    Instance = this;
}

AssetManager::~AssetManager()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("AssetManager<destructor>") : nullptr;
    
    map_Textures.clear();
    Instance = nullptr;
}

sf::Texture& AssetManager::getTexture( std::string const& filename )
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("AssetManager<getTexture>") : nullptr;

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