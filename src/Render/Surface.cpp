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
    
    void Surface::rotateWeapon(int i, int j, int X, int Y, int tex, int rot, state::Direction d){
        sf::Vertex* quad =&m_vertices_weapon[(i + j * 40)*4];     

        // on en déduit sa position dans la texture du tileset
        int tu = tex % (m_tileset_weapon.getSize().x / 60);
        int tv = tex / (m_tileset_weapon.getSize().x / 60);

        if (d==state::Direction::OUEST){
            if (rot<=25){
                    quad[0].position = sf::Vector2f(X-(rot+rot/5), Y+rot*2-rot/5 );
                    quad[1].position = sf::Vector2f(X+125-(5*rot)/2, Y-rot);
                    quad[2].position = sf::Vector2f(X+125+rot+rot/5, Y+95-rot*2+rot/5);
                    quad[3].position = sf::Vector2f(X+(5*rot)/2, Y+95+rot);
            }
        
            else{
                    quad[0].position = sf::Vector2f(X-60+rot+rot/5, Y+rot*2-rot/10);
                    quad[1].position = sf::Vector2f(X+125-(5*rot)/2, Y-50+rot);
                    quad[2].position = sf::Vector2f(X+125+60-rot-rot/5, Y+95-rot*2+rot/5);
                    quad[3].position = sf::Vector2f(X+(5*rot)/2, Y+145-rot);
            }
        }
        if (d==state::Direction::EST){
            if (rot<=25){
                    quad[0].position = sf::Vector2f(X+(5*rot)/2,Y-rot);
                    quad[1].position = sf::Vector2f(X+125+rot+rot/5, Y+rot*2-rot/5);
                    quad[2].position = sf::Vector2f(X+125-(5*rot)/2, Y+95+rot);
                    quad[3].position = sf::Vector2f(X-rot-rot/5, Y+95-rot*2+rot/5);
            }
        
            else{
                    quad[0].position = sf::Vector2f(X+(5*rot)/2,Y-50+rot);
                    quad[1].position = sf::Vector2f(X+180-rot-rot/10, Y+rot*2-rot/10);
                    quad[2].position = sf::Vector2f(X+125-(5*rot)/2, Y+145-rot);
                    quad[3].position = sf::Vector2f(X-60+rot+rot/5, Y+95-rot*2+rot/10);
            }
        }   
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
    
    void Surface::kill(int i, int j,int X, int Y, int tex){
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
}