#include <iostream>
#include <map>
#include <memory>

#include <SFML/Graphics.hpp>
#include <string>
#include "state.hpp"
#include "Render.hpp"
#include "engine.hpp"
#include "ia.hpp"
#include <ctime>

using namespace sf;
using namespace std;
using namespace state;
using namespace Render;
using namespace engine;
using namespace ia;

int main(int argc,char* argv[]) 
{
    
    //Appel de diverses classes utiles aux grandes classes
    Clock C;
    Time T;
    ElementFactory* fac=new ElementFactory();
    CommandSet* CS=new CommandSet();
    Surface* area=new Surface();
    Layer l;
    l.setSurface(area);

    
    //On crée l'état qui s'occupera de gérer les différents éléments
    State s;
    s.setElementFactory(fac);
    s.registerObserver(&l);
    
    
    ActionList* AL= new ActionList(&s,true);
    Ruler* rules= new Ruler(AL,&s,CS); 
    
    Engine engine;
    engine.setState(&s);
    engine.loadlevel();
    engine.takeCommands(CS);
    engine.setRuler(rules);
    
   
    
    
    int next;
    next=s.selectNextFowl();
        
    //On instancie la classe permettant de géer la caméra
    MoveCamera* v = new MoveCamera();
    KillFowl* k= new KillFowl(next);
    MoveFowl* moving_fowl=new MoveFowl(499);
    
    state::Element * e=s.getMobileElement(499);
       

    moving_fowl->setIDX(next);
    e=s.getMobileElement(next);
    v->setCenter(e->getX(),e->getY());
    
    DumbIA* ia = new DumbIA();
    int ite_ia=0;
    
    //On instancie les différentes classes qui généreront les commandes
    MoveCommand* MC= new MoveCommand(0,0,MoveID::CAMERA,0,Direction::NONE);
    KillCommand* KC= new KillCommand(0);
//    LoadCommand* LC= new LoadCommand(true);
//    FireCommand* FC= new FireCommand(0,0,0,true);
        
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

                    if (event.type==sf::Event::KeyReleased && event.key.code==sf::Keyboard::Tab){
                                next=s.selectNextFowl();
                                KC->setIDX(next);
                                moving_fowl->setIDX(next);
                                e=s.getMobileElement(next);
                                v->setCenter (e->getX(), e->getY());
                    }

                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)){
                        ia->runDumbIA(&s,moving_fowl,k,v,ite_ia);
                        ite_ia++;
                    }
            
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
                        engine.addCommand(KC);
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
                        MC->setMove(0,0,next,Direction::OUEST);
                        MC->setMoveID(MoveID::CHICKEN);
                        engine.addCommand(MC);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                        MC->setMove(0,0,next,Direction::EST);
                        MC->setMoveID(MoveID::CHICKEN);
                        engine.addCommand(MC);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
                        moving_fowl->Jump(s,true);
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
        //moving_fowl->isFlying (s,true);
        T=C.getElapsedTime();
        if (engine.update(T.asMilliseconds())){
            T=C.restart();
        }
        window.clear(Color(102,102,225,255));
        window.setView(v->getView());
        window.draw(*area);
        window.display();
    }
    
    return 0;
}
