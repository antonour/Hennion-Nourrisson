#include <iostream>
#include <map>
#include <memory>

//Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include <string>
#include "Render/Surface.hpp"
#include "state.hpp"
#include "Render.hpp"

using namespace sf;
using namespace std;
using namespace state;
using namespace Render;

int main(int argc,char* argv[]) 
{
    ElementFactory* fac=new ElementFactory();
    
    sf::RenderWindow window(sf::VideoMode(1500, 1500), "Map"/*, sf::Style::Fullscreen*/);
    sf::View view;
    view.setCenter(3000,3000);
    view.zoom(6.f);
    
    State s;
    Layer l;
    //Surface* area=new Surface;
    TileSet* ts=new TileSet;
    //l.setSurface(area);
    l.setTileSet(ts);
    s.registerObserver(&l);
    s.setElementFactory(fac);
    vector<Element*> level;
    vector<Element*> perso;
    level=s.loadLevel("../src/fichiermap.txt");
    perso=s.loadChar("../src/fichierperso.txt");
    /*
    Surface map;
    if (!map.load("../res/tileset.png", sf::Vector2u(125, 97),sf::Vector2u(125,97), level, 40, 30))
        return -1;
    
    Surface perso;
    if (!perso.load("../res/chicken_large.png", sf::Vector2u(125, 97),sf::Vector2u(48,48), level1, 40, 30))
        return -1;
    
*/
    while (window.isOpen())
    {
          sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type==sf::Event::Closed)
            {
                window.close();
            }    
   
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    {view.setCenter(view.getCenter()-sf::Vector2f (75.f, 0.f));}
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    {view.setCenter(view.getCenter()+sf::Vector2f (75.f, 0.f));}
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    {view.setCenter(view.getCenter()-sf::Vector2f (0.f, 75.f));}
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    {view.setCenter(view.getCenter()+sf::Vector2f (0.f, 75.f));}
                 
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add))
                    {view.zoom(0.9f);}
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract))
                    {view.zoom(1.1f);}
                
        }

        
        window.clear();
        window.setView(view);
        //window.draw(map);
        //window.draw(perso);
        window.display();
    }
    
    return 0;
}
