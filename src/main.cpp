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
    //Appelle de la classe servant de Factory pour tous les éléments 
    ElementFactory* fac=new ElementFactory();
    
    //On crée l'état qui s'occupera de gérer les différents éléments
    State s;
    s.setElementFactory(fac);
    Surface* area=new Surface();
    Layer l;
    l.setSurface(area);
    s.registerObserver(&l);
    s.loadChar("../src/fichierperso.txt");
    s.loadLevel("../src/fichiermap.txt");
    
    //On instancie la classe permettant de géer la caméra
    MoveCamera* v = new MoveCamera();
    KillFowl* k= new KillFowl();
    MoveFowl* moving_fowl=new MoveFowl(499);
    
    int next;
    next=s.selectNextFowl();
    cout << next << endl;
    k->setIDX(next);
    moving_fowl->setIDX(next);
        
    sf::RenderWindow window(sf::VideoMode(1500, 1500), "Map"/*, sf::Style::Fullscreen*/);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type==sf::Event::Closed)
            {
                window.close();
            }    
                    //Exemple de commande agissant sur l'état des poules
            if (event.type==sf::Event::KeyReleased && event.key.code==sf::Keyboard::Tab){
                        next=s.selectNextFowl();
                        k->setIDX(next);
                        moving_fowl->setIDX(next);
                        cout << next << endl;
            }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
                        k->apply(s,true);
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
                        moving_fowl->setDir(Direction::OUEST);
                        moving_fowl->apply(s,true);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                        moving_fowl->setDir(Direction::EST);
                        moving_fowl->apply(s,true);
                    }
                    //Set de commandes permettant de bouger la caméra et de zoomer
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

        window.clear(Color(102,102,225,255));
        window.setView(v->getView());
        window.draw(*area);
        window.display();
    }
    
    return 0;
}
