#include <iostream>
#include <map>
#include <memory>
//Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include <string>
#include "state.hpp"
#include "Render.hpp"
#include "engine.hpp"

using namespace sf;
using namespace std;
using namespace state;
using namespace Render;
using namespace engine;

int main(int argc,char* argv[]) 
{
    ElementFactory* fac=new ElementFactory();
    
    sf::RenderWindow window(sf::VideoMode(1500, 1500), "Map"/*, sf::Style::Fullscreen*/);
    //sf::View view;
    //view.setCenter(3000,3000);
    //view.zoom(6.f);
    
    MoveCamera* v = new MoveCamera();
    
    State s;
    s.setElementFactory(fac);
    
    Surface* pers=new Surface();
    
    Layer l1;
    l1.setSurface(pers);
    
    s.registerObserver(&l1);
    s.loadChar("../src/fichierperso.txt");
    
    
    State ter;
    ter.setElementFactory(fac);
    
    Surface* area=new Surface();
    
    Layer l2;
    l2.setSurface(area);
    
    ter.registerObserver(&l2);
    ter.loadLevel("../src/fichiermap.txt");
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type==sf::Event::Closed)
            {
                window.close();
            }    
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
                        {s.killFowls();}                    
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                        {v->MoveOnLeft();}
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                        {v->MoveOnRight();}
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                        {v->MoveOnUp();}
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                        {v->MoveOnDown();}     
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add))
                        {v->ZoomIn();}
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract))
                        {v->ZoomOut();}

        }

        
        window.clear();
        window.setView(v->getView());
        window.draw(*area);
        window.draw(*pers);
        window.display();
    }
    
    return 0;
}
