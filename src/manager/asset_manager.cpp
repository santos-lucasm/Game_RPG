#include "manager/asset_manager.h"

AssetManager * AssetManager::_Instance = nullptr;

AssetManager::AssetManager()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("AssetManager<constructor>") : nullptr;
    
    assert( _Instance == nullptr );
    _Instance = this;
}

AssetManager::~AssetManager()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("AssetManager<destructor>") : nullptr;

    /*
    for( auto it = _mapTextures.begin(); it != _mapTextures.end(); ++it)
        delete &(*it);
    */
    
    _mapTextures.clear();
    _Instance = nullptr;
}

sf::Texture& AssetManager::getTexture( std::string const& filename )
{
    std::unique_ptr<Tracer> tmp = (debugged) ? std::make_unique<Tracer>("AssetManager<getTexture>") : nullptr;

    auto& tex_map = _Instance->_mapTextures;
    auto pair = tex_map.find(filename);

    if( pair != tex_map.end() )
    {
        if(debugged) tmp->debug("Passed texture already loaded.");
        return pair->second;
    }
    else
    {   
        if(debugged) tmp->debug("Passed texture still not loaded. Loading...");
        auto& texture = tex_map[filename];
        texture.loadFromFile(filename);
        /*
        TODO: Throw a custom exception here, if cannot load
        https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm
        */
        return texture;
    }
}