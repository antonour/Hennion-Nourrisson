#include <SFML/Graphics.hpp>
#include <string>
#include "../state.hpp"
#include "../Render.hpp"

namespace Render{
    Surface::Surface(){}
    
    Surface::~Surface(){}
    
    bool Surface::load(const std::string& tileset, sf::Vector2u tileSize1, sf::Vector2u tileSize2, const int* tiles, unsigned int width, unsigned int height)
    {
        // on charge la texture du tileset
        if (!m_tileset.loadFromFile(tileset))
            return false;

        // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
        m_vertices.setPrimitiveType(sf::Quads);
        m_vertices.resize(width * height * 4);

        // on remplit le tableau de vertex, avec un quad par tuile
        for (unsigned int i = 0; i < width; ++i)
            for (unsigned int j = 0; j < height; ++j)
            {
                // on récupère le numéro de tuile courant
                int tileNumber = tiles[i + j * width];

                // on en déduit sa position dans la texture du tileset
                int tu = tileNumber % (m_tileset.getSize().x / tileSize2.x);
                int tv = tileNumber / (m_tileset.getSize().x / tileSize2.x);

                // on récupère un pointeur vers le quad à définir dans le tableau de vertex
                sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

                // on définit ses quatre coins
                quad[0].position = sf::Vector2f(i * tileSize1.x, j * tileSize1.y);
                quad[1].position = sf::Vector2f((i + 1) * tileSize1.x, j * tileSize1.y);
                quad[2].position = sf::Vector2f((i + 1) * tileSize1.x, (j + 1) * tileSize1.y);
                quad[3].position = sf::Vector2f(i * tileSize1.x, (j + 1) * tileSize1.y);

                // on définit ses quatre coordonnées de texture
                quad[0].texCoords = sf::Vector2f(tu * tileSize2.x, tv * tileSize2.y);
                quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize2.x, tv * tileSize2.y);
                quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize2.x, (tv + 1) * tileSize2.y);
                quad[3].texCoords = sf::Vector2f(tu * tileSize2.x, (tv + 1) * tileSize2.y);
            }

        return true;
    }


    void Surface::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // on applique la transformation
        states.transform *= sf::Transformable::getTransform();

        // on applique la texture du tileset
        states.texture = &m_tileset;

        // et on dessine enfin le tableau de vertex
        target.draw(m_vertices, states);
    }
    
    int* Surface::generateMap(std::vector<state::Element*> list){
        int *tab=new int[list.size()];
        state::Fowl* f;
        state::Field* fi;
        int i=0;
        for (state::Element* e : list){
            if (e->getTypeID()==state::TypeID::FOWL){
                f = reinterpret_cast<state::Fowl*>(e);
                if (f->getFowlColor()==state::FowlColor::BLANK){
                    tab[i]=0;
                    i++;
                }
                if (f->getFowlColor()==state::FowlColor::WHITE && f->getFowlStatus()==state::FowlStatus::ALIVE_FACE){
                    tab[i]=1;
                    i++;
                }
                if (f->getFowlColor()==state::FowlColor::WHITE && f->getFowlStatus()==state::FowlStatus::ALIVE_LEFT){
                    tab[i]=3;
                    i++;
                }
                if (f->getFowlColor()==state::FowlColor::WHITE && f->getFowlStatus()==state::FowlStatus::ALIVE_RIGHT){
                    tab[i]=6;
                    i++;
                }
                if (f->getFowlColor()==state::FowlColor::WHITE && f->getFowlStatus()==state::FowlStatus::DEAD){
                    tab[i]=8;
                    i++;
                }
                if (f->getFowlColor()==state::FowlColor::GREEN && f->getFowlStatus()==state::FowlStatus::ALIVE_FACE){
                    tab[i]=10;
                    i++;
                }
                if (f->getFowlColor()==state::FowlColor::GREEN && f->getFowlStatus()==state::FowlStatus::ALIVE_LEFT){
                    tab[i]=12;
                    i++;
                }
                if (f->getFowlColor()==state::FowlColor::GREEN && f->getFowlStatus()==state::FowlStatus::ALIVE_RIGHT){
                    tab[i]=15;
                    i++;
                }
                if (f->getFowlColor()==state::FowlColor::GREEN && f->getFowlStatus()==state::FowlStatus::DEAD){
                    tab[i]=17;
                    i++;
                }
                if (f->getFowlColor()==state::FowlColor::BLACK && f->getFowlStatus()==state::FowlStatus::ALIVE_FACE){
                    tab[i]=19;
                    i++;
                }
                if (f->getFowlColor()==state::FowlColor::BLACK && f->getFowlStatus()==state::FowlStatus::ALIVE_LEFT){
                    tab[i]=21;
                    i++;
                }
                if (f->getFowlColor()==state::FowlColor::BLACK && f->getFowlStatus()==state::FowlStatus::ALIVE_RIGHT){
                    tab[i]=24;
                    i++;
                }
                if (f->getFowlColor()==state::FowlColor::BLACK && f->getFowlStatus()==state::FowlStatus::DEAD){
                    tab[i]=26;
                    i++;
                }
                if (f->getFowlColor()==state::FowlColor::BEIGE && f->getFowlStatus()==state::FowlStatus::ALIVE_FACE){
                    tab[i]=28;
                    i++;
                }
                if (f->getFowlColor()==state::FowlColor::BEIGE && f->getFowlStatus()==state::FowlStatus::ALIVE_LEFT){
                    tab[i]=30;
                    i++;
                }
                if (f->getFowlColor()==state::FowlColor::BEIGE && f->getFowlStatus()==state::FowlStatus::ALIVE_RIGHT){
                    tab[i]=33;
                    i++;
                }
                if (f->getFowlColor()==state::FowlColor::BEIGE && f->getFowlStatus()==state::FowlStatus::DEAD){
                    tab[i]=35;
                    i++;
                }
                if (f->getFowlColor()==state::FowlColor::KHAKI && f->getFowlStatus()==state::FowlStatus::ALIVE_FACE){
                    tab[i]=37;
                    i++;
                }
                if (f->getFowlColor()==state::FowlColor::KHAKI && f->getFowlStatus()==state::FowlStatus::ALIVE_LEFT){
                    tab[i]=39;
                    i++;
                }
                if (f->getFowlColor()==state::FowlColor::KHAKI && f->getFowlStatus()==state::FowlStatus::ALIVE_RIGHT){
                    tab[i]=42;
                    i++;
                }
                if (f->getFowlColor()==state::FowlColor::KHAKI && f->getFowlStatus()==state::FowlStatus::DEAD){
                    tab[i]=44;
                    i++;
                }
                if (f->getFowlColor()==state::FowlColor::BROWN && f->getFowlStatus()==state::FowlStatus::ALIVE_FACE){
                    tab[i]=46;
                    i++;
                }
                if (f->getFowlColor()==state::FowlColor::BROWN && f->getFowlStatus()==state::FowlStatus::ALIVE_LEFT){
                    tab[i]=48;
                    i++;
                }
                if (f->getFowlColor()==state::FowlColor::BROWN && f->getFowlStatus()==state::FowlStatus::ALIVE_RIGHT){
                    tab[i]=51;
                    i++;
                }
                if (f->getFowlColor()==state::FowlColor::BROWN && f->getFowlStatus()==state::FowlStatus::DEAD){
                    tab[i]=53;
                    i++;
                }
                if (f->getFowlColor()==state::FowlColor::GREY && f->getFowlStatus()==state::FowlStatus::ALIVE_FACE){
                    tab[i]=55;
                    i++;
                }
                if (f->getFowlColor()==state::FowlColor::GREY && f->getFowlStatus()==state::FowlStatus::ALIVE_LEFT){
                    tab[i]=57;
                    i++;
                }
                if (f->getFowlColor()==state::FowlColor::GREY && f->getFowlStatus()==state::FowlStatus::ALIVE_RIGHT){
                    tab[i]=60;
                    i++;
                }
                if (f->getFowlColor()==state::FowlColor::GREY && f->getFowlStatus()==state::FowlStatus::DEAD){
                    tab[i]=62;
                    i++;
                }
                if (f->getFowlColor()==state::FowlColor::ORANGE && f->getFowlStatus()==state::FowlStatus::ALIVE_FACE){
                    tab[i]=64;
                    i++;
                }
                if (f->getFowlColor()==state::FowlColor::ORANGE && f->getFowlStatus()==state::FowlStatus::ALIVE_LEFT){
                    tab[i]=66;
                    i++;
                }
                if (f->getFowlColor()==state::FowlColor::ORANGE && f->getFowlStatus()==state::FowlStatus::ALIVE_RIGHT){
                    tab[i]=69;
                    i++;
                }
                if (f->getFowlColor()==state::FowlColor::ORANGE && f->getFowlStatus()==state::FowlStatus::DEAD){
                    tab[i]=71;
                    i++;
                }
            }
            if (e->getTypeID()==state::TypeID::FIELD){
                fi = reinterpret_cast<state::Field*>(e);
                if (fi->getFieldTypeID()==state::FieldTypeID::BIGBROWN1){
                    tab[i]=0;
                    i++;
                }
                if (fi->getFieldTypeID()==state::FieldTypeID::BIGBROWN2){
                    tab[i]=1;
                    i++;
                }
                if (fi->getFieldTypeID()==state::FieldTypeID::BIGBROWN3){
                    tab[i]=2;
                    i++;
                }
                if (fi->getFieldTypeID()==state::FieldTypeID::BIGBROWN4){
                    tab[i]=9;
                    i++;
                }
                if (fi->getFieldTypeID()==state::FieldTypeID::BIGBROWN5){
                    tab[i]=10;
                    i++;
                }
                if (fi->getFieldTypeID()==state::FieldTypeID::BIGBROWN6){
                    tab[i]=11;
                    i++;
                }
                if (fi->getFieldTypeID()==state::FieldTypeID::CIRCLEBROWN1){
                    tab[i]=3;
                    i++;
                }
                if (fi->getFieldTypeID()==state::FieldTypeID::CIRCLEBROWN2){
                    tab[i]=4;
                    i++;
                }
                if (fi->getFieldTypeID()==state::FieldTypeID::CIRCLEBROWN3){
                    tab[i]=12;
                    i++;
                }
                if (fi->getFieldTypeID()==state::FieldTypeID::CIRCLEBROWN4){
                    tab[i]=13;
                    i++;
                }
                if (fi->getFieldTypeID()==state::FieldTypeID::SMALLBROWN1){
                    tab[i]=5;
                    i++;
                }
                if (fi->getFieldTypeID()==state::FieldTypeID::SMALLBROWN2){
                    tab[i]=6;
                    i++;
                }
                if (fi->getFieldTypeID()==state::FieldTypeID::SMALLBROWN3){
                    tab[i]=7;
                    i++;
                }
                if (fi->getFieldTypeID()==state::FieldTypeID::SMALLBROWN4){
                    tab[i]=8;
                    i++;
                }
                if (fi->getFieldTypeID()==state::FieldTypeID::SMALLBROWN5){
                    tab[i]=14;
                    i++;
                }
                if (fi->getFieldTypeID()==state::FieldTypeID::SMALLBROWN6){
                    tab[i]=15;
                    i++;
                }
                if (fi->getFieldTypeID()==state::FieldTypeID::SMALLBROWN7){
                    tab[i]=16;
                    i++;
                }
                if (fi->getFieldTypeID()==state::FieldTypeID::SMALLBROWN8){
                    tab[i]=17;
                    i++;
                }
                if (fi->getFieldTypeID()==state::FieldTypeID::BIGSTONE1){
                    tab[i]=18;
                    i++;
                }
                if (fi->getFieldTypeID()==state::FieldTypeID::BIGSTONE2){
                    tab[i]=19;
                    i++;
                }
                if (fi->getFieldTypeID()==state::FieldTypeID::BIGSTONE3){
                    tab[i]=20;
                    i++;
                }
                if (fi->getFieldTypeID()==state::FieldTypeID::BIGSTONE4){
                    tab[i]=27;
                    i++;
                }
                if (fi->getFieldTypeID()==state::FieldTypeID::BIGSTONE5){
                    tab[i]=28;
                    i++;
                }
                if (fi->getFieldTypeID()==state::FieldTypeID::BIGSTONE6){
                    tab[i]=29;
                    i++;
                }
                if (fi->getFieldTypeID()==state::FieldTypeID::CIRCLESTONE1){
                    tab[i]=21;
                    i++;
                }
                if (fi->getFieldTypeID()==state::FieldTypeID::CIRCLESTONE2){
                    tab[i]=22;
                    i++;
                }
                if (fi->getFieldTypeID()==state::FieldTypeID::CIRCLESTONE3){
                    tab[i]=30;
                    i++;
                }
                if (fi->getFieldTypeID()==state::FieldTypeID::CIRCLESTONE4){
                    tab[i]=31;
                    i++;
                }
                if (fi->getFieldTypeID()==state::FieldTypeID::SMALLSTONE1){
                    tab[i]=23;
                    i++;
                }
                if (fi->getFieldTypeID()==state::FieldTypeID::SMALLSTONE2){
                    tab[i]=24;
                    i++;
                }
                if (fi->getFieldTypeID()==state::FieldTypeID::SMALLSTONE3){
                    tab[i]=25;
                    i++;
                }
                if (fi->getFieldTypeID()==state::FieldTypeID::SMALLSTONE4){
                    tab[i]=26;
                    i++;
                }
                if (fi->getFieldTypeID()==state::FieldTypeID::SMALLSTONE5){
                    tab[i]=32;
                    i++;
                }
                if (fi->getFieldTypeID()==state::FieldTypeID::SMALLSTONE6){
                    tab[i]=33;
                    i++;
                }
                if (fi->getFieldTypeID()==state::FieldTypeID::SMALLSTONE7){
                    tab[i]=34;
                    i++;
                }
                if (fi->getFieldTypeID()==state::FieldTypeID::SMALLSTONE8){
                    tab[i]=35;
                    i++;
                }
                if (fi->getFieldTypeID()==state::FieldTypeID::NEANT){
                    tab[i]=36;
                    i++;
                }
            }
        }
        return tab;
    }
}