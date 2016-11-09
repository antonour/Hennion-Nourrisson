// Generated by dia2code
#ifndef RENDER__SURFACE__H
#define RENDER__SURFACE__H

#include <vector>
#include <SFML/Graphics.hpp>
#include <string>
#include "../state.hpp"

namespace state {
  class Element;
};
namespace Render {
  class Tile;
};
namespace sf {
  class Transformable;
  class Drawable;
}

#include "Tile.h"

namespace Render {

  /// class Surface - 
  class Surface : public sf::Transformable, public sf::Drawable {
    // Associations
    // Attributes
  public:
    std::vector<int> fieldtab;
    std::vector<int> fowltab;
  private:
    sf::VertexArray m_vertices_fowl;
    sf::Texture m_tileset_fowl;
    sf::VertexArray m_vertices_field;
    sf::Texture m_tileset_field;
    // Operations
  public:
    Surface ();
    ~Surface ();
    virtual void clear ();
    bool loadChar (const std::string& tileset, sf::Vector2u tileSize1, sf::Vector2u tileSize2,  const int* tiles, unsigned int width, unsigned int height);
    bool loadMap (const std::string& tileset, sf::Vector2u tileSize1, sf::Vector2u tileSize2, const int* tiles, unsigned int width, unsigned int height);
    virtual void  draw (sf::RenderTarget& target, sf::RenderStates states) const;
    void generateMap (std::vector<state::Element*>& list, std::vector<int>& tab);
    void moveFowl (int i, int j, int X, int Y, int tex);
    void kill (int i, int j, int tex);
    Tile* getElementTile (state::Element* e);
    Tile* getCharTile (state::Element* e);
  };

};

#endif
