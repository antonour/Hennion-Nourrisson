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
    
    sf::RenderWindow window(sf::VideoMode(1500, 1500), "Map"/*, sf::Style::Fullscreen*/);
    Animation* A= new Animation(AnimID::HIT,&window);
    
    ElementFactory* fac=new ElementFactory();
    CommandSet* CS=new CommandSet();
    Surface* area=new Surface();
    Layer l;
    l.setSurface(area);
    l.setAnimation(1,A);
    A->setSurface(area);
    bool autorundumb=false;
    bool autorunheuristic=false;

    
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
    MoveFowl* moving_fowl=new MoveFowl(499);
    
    state::Element * e=s.getMobileElement(499);
       

    moving_fowl->setIDX(next);
    e=s.getMobileElement(next);
    v->setCenter(e->getX(),e->getY());
    
    DumbIA* DIA = new DumbIA();
    HeuristicIA* HIA= new HeuristicIA();
    int ite_dia=0;
    int ite_hia=0;
    
    //On instancie les différentes classes qui généreront les commandes
    MoveCommand* MC= new MoveCommand(0,0,MoveID::CAMERA,0,Direction::NONE);
    KillCommand* KC= new KillCommand(0);
//    LoadCommand* LC= new LoadCommand(true);
//    FireCommand* FC= new FireCommand(0,0,0,true);
        


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
                        autorundumb=true;
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)){
                        autorunheuristic=true;
                    }
                    
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
                        s.killFowl();
                        //engine.addCommand(KC);
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
                        MC->setMove(0,0,next,Direction::OUEST);
                        MC->setMoveID(MoveID::CHICKEN_WALK);
                        engine.addCommand(MC);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                        MC->setMove(0,0,next,Direction::EST);
                        MC->setMoveID(MoveID::CHICKEN_WALK);
                        engine.addCommand(MC);
                    }
                    if (event.type==sf::Event::KeyReleased && event.key.code==sf::Keyboard::Return){
                        MC->setMove(0,0,next,MC->getDir());
                        MC->setMoveID(MoveID::CHICKEN_JUMP);
                        engine.addCommand(MC);
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
        if (autorundumb){
            Command* cmd=DIA->runDumbIA(&s,next);
            engine.addCommand(cmd);
            ite_dia++;
            if (ite_dia==200){
                next=s.selectNextFowl();
                ite_dia=0;
            }
        }
        if (autorunheuristic){
            Command* cmd=HIA->runHeuristicIA(&s,next);
            engine.addCommand(cmd);
            ite_hia++;
            if (ite_hia==200){
                next=s.selectNextFowl();
                ite_hia=0;
            }
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
