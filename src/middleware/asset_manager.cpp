#include "middleware/asset_manager.h"

AssetManager * AssetManager::_Instance = nullptr;

AssetManager::AssetManager()
{   
    db<AssetManager>(TRC) << "AssetManager() @ " << this << "\n";

    assert( _Instance == nullptr );
    _Instance = this;
}

AssetManager::~AssetManager()
{   
    db<AssetManager>(TRC) << "~AssetManager() @ " << this << "\n";

    _mapTextures.clear();
    _Instance = nullptr;
}

sf::Texture& AssetManager::getTexture( std::string const& filename )
{

    auto& tex_map = _Instance->_mapTextures;
    auto pair = tex_map.find(filename);

    if( pair != tex_map.end() )
    {
        db<AssetManager>(INF) << "AssetManager::getTexture(" << filename <<  ") @ Already loaded texture.\n";
        return pair->second;
    }
    else
    {   
        db<AssetManager>(INF) << "AssetManager::getTexture(" << filename <<  ") @ Loading texture.\n";
        auto& texture = tex_map[filename];

        if( !texture.loadFromFile(filename) )
        /*TODO: THROW ERROR */
            throw("Texture could not be loaded!!");

        return texture;
    }
}