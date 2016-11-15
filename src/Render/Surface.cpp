#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "../state.hpp"
#include "../Render.hpp"

using namespace std;

namespace Render{
    Surface::Surface(){
        for (int i=0;i<1200;i++){
            this->arrowtab.push_back(1);
            this->weapontab.push_back(29);
        }
    }
    
    Surface::~Surface(){}
    
    bool Surface::loadMap(const std::string& tileset, sf::Vector2u tileSize1, sf::Vector2u tileSize2, const int* tiles, unsigned int width, unsigned int height)
    {
        // on charge la texture du tileset
        if (!m_tileset_field.loadFromFile(tileset))
            return false;

        // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
        m_vertices_field.setPrimitiveType(sf::Quads);
        m_vertices_field.resize(width * height * 4);

        // on remplit le tableau de vertex, avec un quad par tuile
        for (unsigned int i = 0; i < width; ++i)
            for (unsigned int j = 0; j < height; ++j)
            {
                // on récupère le numéro de tuile courant
                int tileNumber = tiles[i + j * width];

                // on en déduit sa position dans la texture du tileset
                int tu = tileNumber % (m_tileset_field.getSize().x / tileSize2.x);
                int tv = tileNumber / (m_tileset_field.getSize().x / tileSize2.x);

                // on récupère un pointeur vers le quad à définir dans le tableau de vertex
                sf::Vertex* quad = &m_vertices_field[(i + j * width) * 4];

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
    
    bool Surface::loadChar(const std::string& tileset, sf::Vector2u tileSize1, sf::Vector2u tileSize2, const int* tiles, unsigned int width, unsigned int height)
    {
        // on charge la texture du tileset
        if (!m_tileset_fowl.loadFromFile(tileset))
            return false;

        // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
        m_vertices_fowl.setPrimitiveType(sf::Quads);
        m_vertices_fowl.resize(width * height * 4);

        // on remplit le tableau de vertex, avec un quad par tuile
        for (unsigned int i = 0; i < width; ++i)
            for (unsigned int j = 0; j < height; ++j)
            {
                // on récupère le numéro de tuile courant
                int tileNumber = tiles[i + j * width];

                // on en déduit sa position dans la texture du tileset
                int tu = tileNumber % (m_tileset_fowl.getSize().x / tileSize2.x);
                int tv = tileNumber / (m_tileset_fowl.getSize().x / tileSize2.x);

                // on récupère un pointeur vers le quad à définir dans le tableau de vertex
                sf::Vertex* quad = &m_vertices_fowl[(i + j * width) * 4];

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
    
    bool Surface::loadArrow(const std::string& tileset, sf::Vector2u tileSize1, sf::Vector2u tileSize2, const int* tiles, unsigned int width, unsigned int height)
    {
        // on charge la texture du tileset
        if (!m_tileset_arrow.loadFromFile(tileset))
            return false;

        // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
        m_vertices_arrow.setPrimitiveType(sf::Quads);
        m_vertices_arrow.resize(width * height * 4);
        
        // on remplit le tableau de vertex, avec un quad par tuile
        for (unsigned int i = 0; i < width; ++i)
            for (unsigned int j = 0; j < height; ++j)
            {
                // on récupère le numéro de tuile courant
                int tileNumber = tiles[i + j * width];

                // on en déduit sa position dans la texture du tileset
                int tu = tileNumber % (m_tileset_arrow.getSize().x / tileSize2.x);
                int tv = tileNumber / (m_tileset_arrow.getSize().x / tileSize2.x);

                // on récupère un pointeur vers le quad à définir dans le tableau de vertex
                sf::Vertex* quad = &m_vertices_arrow[(i + j * width) * 4];

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
    
    bool Surface::loadWeapons(const std::string& tileset, sf::Vector2u tileSize1, sf::Vector2u tileSize2, const int* tiles, unsigned int width, unsigned int height)
    {
        // on charge la texture du tileset
        if (!m_tileset_weapon.loadFromFile(tileset))
            return false;

        // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
        m_vertices_weapon.setPrimitiveType(sf::Quads);
        m_vertices_weapon.resize(width * height * 4);
        
        // on remplit le tableau de vertex, avec un quad par tuile
        for (unsigned int i = 0; i < width; ++i)
            for (unsigned int j = 0; j < height; ++j)
            {
                // on récupère le numéro de tuile courant
                int tileNumber = tiles[i + j * width];

                // on en déduit sa position dans la texture du tileset
                int tu = tileNumber % (m_tileset_weapon.getSize().x / tileSize2.x);
                int tv = tileNumber / (m_tileset_weapon.getSize().x / tileSize2.x);

                // on récupère un pointeur vers le quad à définir dans le tableau de vertex
                sf::Vertex* quad = &m_vertices_weapon[(i + j * width) * 4];

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

    void Surface::moveFowl(int i, int j, int X, int Y, int tex){
        sf::Vertex* quad =&m_vertices_fowl[(i + j * 40)*4];     

        // on en déduit sa position dans la texture du tileset
        int tu = tex % (m_tileset_fowl.getSize().x / 48);
        int tv = tex / (m_tileset_fowl.getSize().x / 48);
        
        // on définit ses quatre coins
        quad[0].position = sf::Vector2f(X, Y);
        quad[1].position = sf::Vector2f(X+125, Y);
        quad[2].position = sf::Vector2f(X+125, Y+97);
        quad[3].position = sf::Vector2f(X, Y+97);
        
        // on définit ses quatre coordonnées de texture
        quad[0].texCoords = sf::Vector2f(tu * 48, tv * 48);
        quad[1].texCoords = sf::Vector2f((tu + 1) * 48, tv * 48);
        quad[2].texCoords = sf::Vector2f((tu + 1) * 48, (tv + 1) * 48);
        quad[3].texCoords = sf::Vector2f(tu * 48, (tv + 1) * 48);
       
    }
    
    void Surface::dispWeapon(int i, int j, int X, int Y, int tex){
        sf::Vertex* quad =&m_vertices_weapon[(i + j * 40)*4];     

        // on en déduit sa position dans la texture du tileset
        int tu = tex % (m_tileset_weapon.getSize().x / 60);
        int tv = tex / (m_tileset_weapon.getSize().x / 60);
        
        // on définit ses quatre coins
        quad[0].position = sf::Vector2f(X, Y);
        quad[1].position = sf::Vector2f(X+125, Y);
        quad[2].position = sf::Vector2f(X+125, Y+97);
        quad[3].position = sf::Vector2f(X, Y+97);
        
        // on définit ses quatre coordonnées de texture
        quad[0].texCoords = sf::Vector2f(tu * 60, tv * 60);
        quad[1].texCoords = sf::Vector2f((tu + 1) * 60, tv * 60);
        quad[2].texCoords = sf::Vector2f((tu + 1) * 60, (tv + 1) * 60);
        quad[3].texCoords = sf::Vector2f(tu * 60, (tv + 1) * 60);
       
    }
    
    void Surface::moveArrow(int i, int j, int X, int Y, int tex){
        sf::Vertex* quad =&m_vertices_arrow[(i + j * 40)*4];     

        // on en déduit sa position dans la texture du tileset
        int tu = tex % (m_tileset_arrow.getSize().x / 48);
        int tv = tex / (m_tileset_arrow.getSize().x / 48);
        
        // on définit ses quatre coins
        quad[0].position = sf::Vector2f(X, Y);
        quad[1].position = sf::Vector2f(X+125, Y);
        quad[2].position = sf::Vector2f(X+125, Y+97);
        quad[3].position = sf::Vector2f(X, Y+97);
        
        // on définit ses quatre coordonnées de texture
        quad[0].texCoords = sf::Vector2f(tu * 48, tv * 48);
        quad[1].texCoords = sf::Vector2f((tu + 1) * 48, tv * 48);
        quad[2].texCoords = sf::Vector2f((tu + 1) * 48, (tv + 1) * 48);
        quad[3].texCoords = sf::Vector2f(tu * 48, (tv + 1) * 48);
       
    }
    
    void Surface::kill(int i, int j, int tex){
        sf::Vertex* quad =&m_vertices_fowl[(i + j * 40)*4];     

        // on en déduit sa position dans la texture du tileset
        int tu = tex % (m_tileset_fowl.getSize().x / 48);
        int tv = tex / (m_tileset_fowl.getSize().x / 48);
        
        // on définit ses quatre coordonnées de texture
        quad[0].texCoords = sf::Vector2f(tu * 48, tv * 48);
        quad[1].texCoords = sf::Vector2f((tu + 1) * 48, tv * 48);
        quad[2].texCoords = sf::Vector2f((tu + 1) * 48, (tv + 1) * 48);
        quad[3].texCoords = sf::Vector2f(tu * 48, (tv + 1) * 48);
    }

    void Surface::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // on applique la transformation
        states.transform *= getTransform();

        // on applique la texture du tileset
        states.texture = &m_tileset_field;
        // et on dessine enfin le tableau de vertex
        target.draw(m_vertices_field, states);
        
        // on applique la texture du tileset
        states.texture = &m_tileset_fowl;
        // et on dessine enfin le tableau de vertex
        target.draw(m_vertices_fowl, states);
        
        // on applique la texture du tileset
        states.texture = &m_tileset_arrow;
        // et on dessine enfin le tableau de vertex
        target.draw(m_vertices_arrow, states);
        
        // on applique la texture du tileset
        states.texture = &m_tileset_weapon;
        // et on dessine enfin le tableau de vertex
        target.draw(m_vertices_weapon, states);
        
    }
    
    void Surface::clear(){}
    
    void Surface::generateMap(std::vector<state::Element*>& list, std::vector<int>& tab){
        

        for (state::Element* el : list){
            
            if (el->getTypeID()==state::TypeID::FOWL){
                state::Fowl* e;
                e = reinterpret_cast<state::Fowl*>(el);
                if (e->getFowlColor()==state::FowlColor::BLANK){
                    tab.push_back(0);
                }
                if (e->getFowlColor()==state::FowlColor::WHITE && e->getFowlStatus()==state::FowlStatus::ALIVE_FACE){
                    tab.push_back(1);
                }
                if (e->getFowlColor()==state::FowlColor::WHITE && e->getFowlStatus()==state::FowlStatus::ALIVE_LEFT){
                    tab.push_back(3);
                }
                if (e->getFowlColor()==state::FowlColor::WHITE && e->getFowlStatus()==state::FowlStatus::ALIVE_RIGHT){
                    tab.push_back(6);
                }
                if (e->getFowlColor()==state::FowlColor::WHITE && e->getFowlStatus()==state::FowlStatus::DEAD){
                    tab.push_back(8);
                }
                if (e->getFowlColor()==state::FowlColor::GREEN && e->getFowlStatus()==state::FowlStatus::ALIVE_FACE){
                    tab.push_back(10);
                    
                }
                if (e->getFowlColor()==state::FowlColor::GREEN && e->getFowlStatus()==state::FowlStatus::ALIVE_LEFT){
                    tab.push_back(12);
                    
                }
                if (e->getFowlColor()==state::FowlColor::GREEN && e->getFowlStatus()==state::FowlStatus::ALIVE_RIGHT){
                    tab.push_back(15);
                    
                }
                if (e->getFowlColor()==state::FowlColor::GREEN && e->getFowlStatus()==state::FowlStatus::DEAD){
                    tab.push_back(17);
                    
                }
                if (e->getFowlColor()==state::FowlColor::BLACK && e->getFowlStatus()==state::FowlStatus::ALIVE_FACE){
                    tab.push_back(19);
                    
                }
                if (e->getFowlColor()==state::FowlColor::BLACK && e->getFowlStatus()==state::FowlStatus::ALIVE_LEFT){
                    tab.push_back(21);
                    
                }
                if (e->getFowlColor()==state::FowlColor::BLACK && e->getFowlStatus()==state::FowlStatus::ALIVE_RIGHT){
                    tab.push_back(24);
                    
                }
                if (e->getFowlColor()==state::FowlColor::BLACK && e->getFowlStatus()==state::FowlStatus::DEAD){
                    tab.push_back(26);
                    
                }
                if (e->getFowlColor()==state::FowlColor::BEIGE && e->getFowlStatus()==state::FowlStatus::ALIVE_FACE){
                    tab.push_back(28);
                    
                }
                if (e->getFowlColor()==state::FowlColor::BEIGE && e->getFowlStatus()==state::FowlStatus::ALIVE_LEFT){
                    tab.push_back(30);
                    
                }
                if (e->getFowlColor()==state::FowlColor::BEIGE && e->getFowlStatus()==state::FowlStatus::ALIVE_RIGHT){
                    tab.push_back(33);
                    
                }
                if (e->getFowlColor()==state::FowlColor::BEIGE && e->getFowlStatus()==state::FowlStatus::DEAD){
                    tab.push_back(35);
                    
                }
                if (e->getFowlColor()==state::FowlColor::KHAKI && e->getFowlStatus()==state::FowlStatus::ALIVE_FACE){
                    tab.push_back(37);
                    
                }
                if (e->getFowlColor()==state::FowlColor::KHAKI && e->getFowlStatus()==state::FowlStatus::ALIVE_LEFT){
                    tab.push_back(39);
                    
                }
                if (e->getFowlColor()==state::FowlColor::KHAKI && e->getFowlStatus()==state::FowlStatus::ALIVE_RIGHT){
                    tab.push_back(42);
                    
                }
                if (e->getFowlColor()==state::FowlColor::KHAKI && e->getFowlStatus()==state::FowlStatus::DEAD){
                    tab.push_back(44);
                    
                }
                if (e->getFowlColor()==state::FowlColor::BROWN && e->getFowlStatus()==state::FowlStatus::ALIVE_FACE){
                    tab.push_back(46);
                    
                }
                if (e->getFowlColor()==state::FowlColor::BROWN && e->getFowlStatus()==state::FowlStatus::ALIVE_LEFT){
                    tab.push_back(48);
                    
                }
                    if (e->getFowlColor()==state::FowlColor::BROWN && e->getFowlStatus()==state::FowlStatus::ALIVE_RIGHT){
                        tab.push_back(51);
                    }
                    if (e->getFowlColor()==state::FowlColor::BROWN && e->getFowlStatus()==state::FowlStatus::DEAD){
                        tab.push_back(53);
                    }
                    if (e->getFowlColor()==state::FowlColor::GREY && e->getFowlStatus()==state::FowlStatus::ALIVE_FACE){
                        tab.push_back(55);
                    }
                    if (e->getFowlColor()==state::FowlColor::GREY && e->getFowlStatus()==state::FowlStatus::ALIVE_LEFT){
                        tab.push_back(57);
                    }
                    if (e->getFowlColor()==state::FowlColor::GREY && e->getFowlStatus()==state::FowlStatus::ALIVE_RIGHT){
                        tab.push_back(60);
                    }
                    if (e->getFowlColor()==state::FowlColor::GREY && e->getFowlStatus()==state::FowlStatus::DEAD){
                        tab.push_back(62);
                    }
                    if (e->getFowlColor()==state::FowlColor::ORANGE && e->getFowlStatus()==state::FowlStatus::ALIVE_FACE){
                        tab.push_back(64);
                    }
                    if (e->getFowlColor()==state::FowlColor::ORANGE && e->getFowlStatus()==state::FowlStatus::ALIVE_LEFT){
                        tab.push_back(66);
                    }
                    if (e->getFowlColor()==state::FowlColor::ORANGE && e->getFowlStatus()==state::FowlStatus::ALIVE_RIGHT){
                        tab.push_back(69);
                    }
                    if (e->getFowlColor()==state::FowlColor::ORANGE && e->getFowlStatus()==state::FowlStatus::DEAD){
                        tab.push_back(71);
                    }
            }
            else if (el->getTypeID()==state::TypeID::FIELD){
                state::Field* e;
                e = reinterpret_cast<state::Field*>(el);
                
                if (e->getFieldTypeID()==state::FieldTypeID::BIGBROWN1){
                    tab.push_back(0);                    
                }
                if (e->getFieldTypeID()==state::FieldTypeID::BIGBROWN2){
                    tab.push_back(1);
                }
                if (e->getFieldTypeID()==state::FieldTypeID::BIGBROWN3){
                    tab.push_back(2);                    
                }
                if (e->getFieldTypeID()==state::FieldTypeID::BIGBROWN4){
                    tab.push_back(9);                
                }
                if (e->getFieldTypeID()==state::FieldTypeID::BIGBROWN5){
                    tab.push_back(10);
                }
                if (e->getFieldTypeID()==state::FieldTypeID::BIGBROWN6){
                    tab.push_back(11);
                }
                if (e->getFieldTypeID()==state::FieldTypeID::CIRCLEBROWN1){
                    tab.push_back(3);
                }
                if (e->getFieldTypeID()==state::FieldTypeID::CIRCLEBROWN2){
                    tab.push_back(4);
                }
                if (e->getFieldTypeID()==state::FieldTypeID::CIRCLEBROWN3){
                    tab.push_back(12);
                }
                if (e->getFieldTypeID()==state::FieldTypeID::CIRCLEBROWN4){
                    tab.push_back(13);
                }
                if (e->getFieldTypeID()==state::FieldTypeID::SMALLBROWN1){
                    tab.push_back(5);
                }
                if (e->getFieldTypeID()==state::FieldTypeID::SMALLBROWN2){
                    tab.push_back(6);
                }
                if (e->getFieldTypeID()==state::FieldTypeID::SMALLBROWN3){
                    tab.push_back(7);
                }
                if (e->getFieldTypeID()==state::FieldTypeID::SMALLBROWN4){
                    tab.push_back(8);
                }
                if (e->getFieldTypeID()==state::FieldTypeID::SMALLBROWN5){
                    tab.push_back(14);
                }
                if (e->getFieldTypeID()==state::FieldTypeID::SMALLBROWN6){
                    tab.push_back(15);
                }
                if (e->getFieldTypeID()==state::FieldTypeID::SMALLBROWN7){
                    tab.push_back(16);
                }
                if (e->getFieldTypeID()==state::FieldTypeID::SMALLBROWN8){
                    tab.push_back(17);
                }
                if (e->getFieldTypeID()==state::FieldTypeID::BIGSTONE1){
                    tab.push_back(18);
                }
                if (e->getFieldTypeID()==state::FieldTypeID::BIGSTONE2){
                    tab.push_back(19);
                }
                if (e->getFieldTypeID()==state::FieldTypeID::BIGSTONE3){
                    tab.push_back(20);
                }
                if (e->getFieldTypeID()==state::FieldTypeID::BIGSTONE4){
                    tab.push_back(27);
                }
                if (e->getFieldTypeID()==state::FieldTypeID::BIGSTONE5){
                    tab.push_back(28);
                }
                if (e->getFieldTypeID()==state::FieldTypeID::BIGSTONE6){
                    tab.push_back(29);
                }
                if (e->getFieldTypeID()==state::FieldTypeID::CIRCLESTONE1){
                    tab.push_back(21);
                }
                if (e->getFieldTypeID()==state::FieldTypeID::CIRCLESTONE2){
                    tab.push_back(22);
                }
                if (e->getFieldTypeID()==state::FieldTypeID::CIRCLESTONE3){
                    tab.push_back(30);
                }
                if (e->getFieldTypeID()==state::FieldTypeID::CIRCLESTONE4){
                    tab.push_back(31);
                }
                if (e->getFieldTypeID()==state::FieldTypeID::SMALLSTONE1){
                    tab.push_back(23);
                }
                if (e->getFieldTypeID()==state::FieldTypeID::SMALLSTONE2){
                    tab.push_back(24);
                }
                if (e->getFieldTypeID()==state::FieldTypeID::SMALLSTONE3){
                    tab.push_back(25);
                }
                if (e->getFieldTypeID()==state::FieldTypeID::SMALLSTONE4){
                    tab.push_back(26);
                }
                if (e->getFieldTypeID()==state::FieldTypeID::SMALLSTONE5){
                    tab.push_back(32);
                }
                if (e->getFieldTypeID()==state::FieldTypeID::SMALLSTONE6){
                    tab.push_back(33);
                }
                if (e->getFieldTypeID()==state::FieldTypeID::SMALLSTONE7){
                    tab.push_back(34);
                }
                if (e->getFieldTypeID()==state::FieldTypeID::SMALLSTONE8){
                    tab.push_back(35);
                }
                if (e->getFieldTypeID()==state::FieldTypeID::NEANT){
                    tab.push_back(36);
                }
            }
        }
    }
    
    Tile* Surface::getElementTile (state::Element* e){
        
        if (e->isStatic()){
            StaticTile* t1 = new StaticTile(0,0,0,0);
            state::StaticElement* e1;
            e1 = reinterpret_cast<state::StaticElement*>(e);
            if (e1->isSpace()){//si c'est un space
                      
            }
            
            else{
            //dimensions correspondantes à l'image tileset.png
                state::Field* fi;
                fi = reinterpret_cast<state::Field*>(e1);
                if(fi->getFieldTypeID()==state::FieldTypeID::NEANT){
                        t1->x=0;
                        t1->y=388;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==state::FieldTypeID::BIGBROWN1){
                        t1->x=0;
                        t1->y=0;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==state::FieldTypeID::BIGBROWN2){
                        t1->x=125;
                        t1->y=0;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==state::FieldTypeID::BIGBROWN3){
                        t1->x=250;
                        t1->y=0;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==state::FieldTypeID::BIGBROWN4){
                        t1->x=0;
                        t1->y=97;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==state::FieldTypeID::BIGBROWN5){
                        t1->x=125;
                        t1->y=97;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==state::FieldTypeID::BIGBROWN6){
                        t1->x=250;
                        t1->y=97;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==state::FieldTypeID::BIGSTONE1){
                        t1->x=0;
                        t1->y=194;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==state::FieldTypeID::BIGSTONE2){
                        t1->x=125;
                        t1->y=194;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==state::FieldTypeID::BIGSTONE3){
                        t1->x=250;
                        t1->y=194;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==state::FieldTypeID::BIGSTONE4){
                        t1->x=0;
                        t1->y=291;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==state::FieldTypeID::BIGSTONE5){
                        t1->x=150;
                        t1->y=291;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==state::FieldTypeID::BIGSTONE6){
                        t1->x=250;
                        t1->y=291;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==state::FieldTypeID::CIRCLEBROWN1){
                        t1->x=375;
                        t1->y=0;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==state::FieldTypeID::CIRCLEBROWN2){
                        t1->x=500;
                        t1->y=0;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==state::FieldTypeID::CIRCLEBROWN3){
                        t1->x=375;
                        t1->y=97;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==state::FieldTypeID::CIRCLEBROWN4){
                        t1->x=500;
                        t1->y=97;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==state::FieldTypeID::CIRCLESTONE1){
                        t1->x=375;
                        t1->y=194;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==state::FieldTypeID::CIRCLESTONE2){
                        t1->x=500;
                        t1->y=194;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==state::FieldTypeID::CIRCLESTONE3){
                        t1->x=375;
                        t1->y=291;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==state::FieldTypeID::CIRCLESTONE4){
                        t1->x=500;
                        t1->y=291;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==state::FieldTypeID::SMALLBROWN1){
                        t1->x=625;
                        t1->y=0;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==state::FieldTypeID::SMALLBROWN2){
                        t1->x=750;
                        t1->y=0;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==state::FieldTypeID::SMALLBROWN3){
                        t1->x=875;
                        t1->y=0;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==state::FieldTypeID::SMALLBROWN4){
                        t1->x=1000;
                        t1->y=0;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==state::FieldTypeID::SMALLBROWN5){
                        t1->x=625;
                        t1->y=97;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==state::FieldTypeID::SMALLBROWN6){
                        t1->x=750;
                        t1->y=97;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==state::FieldTypeID::SMALLBROWN7){
                        t1->x=875;
                        t1->y=97;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==state::FieldTypeID::SMALLBROWN8){
                        t1->x=1000;
                        t1->y=97;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==state::FieldTypeID::SMALLSTONE1){
                        t1->x=625;
                        t1->y=194;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==state::FieldTypeID::SMALLSTONE2){
                        t1->x=750;
                        t1->y=194;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==state::FieldTypeID::SMALLSTONE3){
                        t1->x=875;
                        t1->y=194;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==state::FieldTypeID::SMALLSTONE4){
                        t1->x=1000;
                        t1->y=194;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==state::FieldTypeID::SMALLSTONE5){
                        t1->x=625;
                        t1->y=291;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==state::FieldTypeID::SMALLSTONE6){
                        t1->x=750;
                        t1->y=291;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==state::FieldTypeID::SMALLSTONE7){
                        t1->x=875;
                        t1->y=291;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==state::FieldTypeID::SMALLSTONE8){
                        t1->x=1000;
                        t1->y=291;
                        t1->width=125;
                        t1->height=97;
                    }      
                else{}
                
        }
        return t1;
        }
        
        else{
            AnimatedTile* t2 = new AnimatedTile(0,0,0,0);
            state::MobileElement* e2;
            e2 = reinterpret_cast<state::MobileElement*>(e);
            if (e2->isFowl()){
            //dimensions correspondantes à l'image chicken_large.png
            state::Fowl* fo;
            fo = reinterpret_cast<state::Fowl*>(e2);
                if (fo->getFowlColor()==state::FowlColor::BLANK){
                    t2->x=0;
                    t2->y=0;
                    t2->width=48;
                    t2->height=48;

                }
                else if (fo->getFowlColor()==state::FowlColor::WHITE){

                    if (fo->getFowlStatus()==state::FowlStatus::ALIVE_FACE){
                    t2->x=48;
                    t2->y=0;
                    t2->width=48;
                    t2->height=48;}
                    else if (fo->getFowlStatus()==state::FowlStatus::ALIVE_LEFT){
                    t2->x=144;
                    t2->y=0;
                    t2->width=48;
                    t2->height=48;    
                    }
                    else if (fo->getFowlStatus()==state::FowlStatus::ALIVE_RIGHT){
                    t2->x=288;
                    t2->y=0;
                    t2->width=48;
                    t2->height=48;    
                    }
                    else if (fo->getFowlStatus()==state::FowlStatus::DEAD){
                    t2->x=384;
                    t2->y=0;
                    t2->width=48;
                    t2->height=48;    
                    }
                    else{}

                }
                else if (fo->getFowlColor()==state::FowlColor::GREEN){
                    if (fo->getFowlStatus()==state::FowlStatus::ALIVE_FACE){
                    t2->x=48;
                    t2->y=48;
                    t2->width=48;
                    t2->height=48;}
                    else if (fo->getFowlStatus()==state::FowlStatus::ALIVE_LEFT){
                    t2->x=144;
                    t2->y=48;
                    t2->width=48;
                    t2->height=48;    
                    }
                    else if (fo->getFowlStatus()==state::FowlStatus::ALIVE_RIGHT){
                    t2->x=288;
                    t2->y=48;
                    t2->width=48;
                    t2->height=48;    
                    }
                    else if (fo->getFowlStatus()==state::FowlStatus::DEAD){
                    t2->x=384;
                    t2->y=48;
                    t2->width=48;
                    t2->height=48;    
                    }
                    else{}
                }
                else if (fo->getFowlColor()==state::FowlColor::BLACK){
                    if (fo->getFowlStatus()==state::FowlStatus::ALIVE_FACE){
                    t2->x=48;
                    t2->y=96;
                    t2->width=48;
                    t2->height=48;}
                    else if (fo->getFowlStatus()==state::FowlStatus::ALIVE_LEFT){
                    t2->x=144;
                    t2->y=96;
                    t2->width=48;
                    t2->height=48;    
                    }
                    else if (fo->getFowlStatus()==state::FowlStatus::ALIVE_RIGHT){
                    t2->x=288;
                    t2->y=96;
                    t2->width=48;
                    t2->height=48;    
                    }
                    else if (fo->getFowlStatus()==state::FowlStatus::DEAD){
                    t2->x=384;
                    t2->y=96;
                    t2->width=48;
                    t2->height=48;    
                    }
                }
                else if (fo->getFowlColor()==state::FowlColor::BEIGE){
                    if (fo->getFowlStatus()==state::FowlStatus::ALIVE_FACE){
                    t2->x=48;
                    t2->y=144;
                    t2->width=48;
                    t2->height=48;}
                    else if (fo->getFowlStatus()==state::FowlStatus::ALIVE_LEFT){
                    t2->x=144;
                    t2->y=144;
                    t2->width=48;
                    t2->height=48;    
                    }
                    else if (fo->getFowlStatus()==state::FowlStatus::ALIVE_RIGHT){
                    t2->x=288;
                    t2->y=144;
                    t2->width=48;
                    t2->height=48;    
                    }
                    else if (fo->getFowlStatus()==state::FowlStatus::DEAD){
                    t2->x=384;
                    t2->y=144;
                    t2->width=48;
                    t2->height=48;    
                    }
                }
                else if (fo->getFowlColor()==state::FowlColor::KHAKI){
                    if (fo->getFowlStatus()==state::FowlStatus::ALIVE_FACE){
                    t2->x=48;
                    t2->y=192;
                    t2->width=48;
                    t2->height=48;}
                    else if (fo->getFowlStatus()==state::FowlStatus::ALIVE_LEFT){
                    t2->x=144;
                    t2->y=192;
                    t2->width=48;
                    t2->height=48;    
                    }
                    else if (fo->getFowlStatus()==state::FowlStatus::ALIVE_RIGHT){
                    t2->x=288;
                    t2->y=192;
                    t2->width=48;
                    t2->height=48;    
                    }
                    else if (fo->getFowlStatus()==state::FowlStatus::DEAD){
                    t2->x=384;
                    t2->y=192;
                    t2->width=48;
                    t2->height=48;    
                    }
                }
                else if (fo->getFowlColor()==state::FowlColor::BROWN){
                    if (fo->getFowlStatus()==state::FowlStatus::ALIVE_FACE){
                    t2->x=48;
                    t2->y=240;
                    t2->width=48;
                    t2->height=48;}
                    else if (fo->getFowlStatus()==state::FowlStatus::ALIVE_LEFT){
                    t2->x=144;
                    t2->y=240;
                    t2->width=48;
                    t2->height=48;    
                    }
                    else if (fo->getFowlStatus()==state::FowlStatus::ALIVE_RIGHT){
                    t2->x=288;
                    t2->y=240;
                    t2->width=48;
                    t2->height=48;    
                    }
                    else if (fo->getFowlStatus()==state::FowlStatus::DEAD){
                    t2->x=384;
                    t2->y=240;
                    t2->width=48;
                    t2->height=48;    
                    }
                }
                else if (fo->getFowlColor()==state::FowlColor::GREY){
                    if (fo->getFowlStatus()==state::FowlStatus::ALIVE_FACE){
                    t2->x=48;
                    t2->y=288;
                    t2->width=48;
                    t2->height=48;}
                    else if (fo->getFowlStatus()==state::FowlStatus::ALIVE_LEFT){
                    t2->x=144;
                    t2->y=288;
                    t2->width=48;
                    t2->height=48;    
                    }
                    else if (fo->getFowlStatus()==state::FowlStatus::ALIVE_RIGHT){
                    t2->x=288;
                    t2->y=288;
                    t2->width=48;
                    t2->height=48;    
                    }
                    else if (fo->getFowlStatus()==state::FowlStatus::DEAD){
                    t2->x=384;
                    t2->y=288;
                    t2->width=48;
                    t2->height=48;    
                    }
                }
                else if (fo->getFowlColor()==state::FowlColor::ORANGE){
                    if (fo->getFowlStatus()==state::FowlStatus::ALIVE_FACE){
                    t2->x=48;
                    t2->y=336;
                    t2->width=48;
                    t2->height=48;}
                    else if (fo->getFowlStatus()==state::FowlStatus::ALIVE_LEFT){
                    t2->x=144;
                    t2->y=336;
                    t2->width=48;
                    t2->height=48;    
                    }
                    else if (fo->getFowlStatus()==state::FowlStatus::ALIVE_RIGHT){
                    t2->x=288;
                    t2->y=336;
                    t2->width=48;
                    t2->height=48;    
                    }
                    else if (fo->getFowlStatus()==state::FowlStatus::DEAD){
                    t2->x=384;
                    t2->y=336;
                    t2->width=48;
                    t2->height=48;    
                    }
                }
                else{}}
            else{//si c'est une arme
            }
                
            
            return t2;
            }

        }
}