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
    Animation* A1= new Animation(AnimID::HIT,&window);
    Animation* A2= new Animation(AnimID::JUMP,&window);
    
    ElementFactory* fac=new ElementFactory();
    CommandSet* CS=new CommandSet();
    Surface* area=new Surface(&window);
    Layer l;
    l.setSurface(area);
    l.setAnimation(1,A1);
    l.setAnimation(2,A2);
    A1->setSurface(area);
    A2->setSurface(area);
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
    int next=s.selectNextFowl(false);
        
    //On instancie la classe permettant de géer la caméra
    MoveCamera* v = new MoveCamera();
    MoveFowl* moving_fowl=new MoveFowl(499);
    moving_fowl->setMoveCamera(v);
    
    state::Element * e=s.getMobileElement(499);
       

    moving_fowl->setIDX(s.getSelected());
    e=s.getMobileElement(s.getSelected());
    v->setCenter(e->getX(),e->getY());
    
    DumbIA* DIA = new DumbIA(&s);
    HeuristicIA* HIA= new HeuristicIA(&s);
    int ite_dia=0;
    int ite_hia=0;
    
    //On instancie les différentes classes qui généreront les commandes
    MoveCommand* MC= new MoveCommand(0,0,MoveID::CAMERA,0,Direction::NONE);
    KillCommand* KC= new KillCommand(0);
    //LoadCommand* LC= new LoadCommand(true);
    FireCommand* FC= new FireCommand(0,Direction::NONE); 
    NextCommand* NC= new NextCommand(s.getSelected(),v,moving_fowl,KC,false,false);
    
    MC->setMoveCamera(v);


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
                                NC->setNextCommand(s.getSelected(),v,moving_fowl,KC,false,NC->getFowlHasMoved());
                                engine.addCommand(NC);
                    }
                    
                    //Intelligence Artificielle Médiocre
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)){
                        autorundumb=true;
                        autorunheuristic=false;
                        ite_dia=0;
                    }
                    
                    //Intelligence Artificielle Moyenne
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)){
                        autorundumb=false;
                        autorunheuristic=true;
                        ite_hia=0;
                    }
                    
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
                        MC->setMove(0,0,s.getSelected(),Direction::OUEST);
                        MC->setMoveID(MoveID::CHICKEN_WALK);
                        engine.addCommand(MC);
                        NC->setFowlHasMoved(true);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                        MC->setMove(0,0,s.getSelected(),Direction::EST);
                        MC->setMoveID(MoveID::CHICKEN_WALK);
                        engine.addCommand(MC);
                        NC->setFowlHasMoved(true);
                    }
                    if (event.type==sf::Event::KeyReleased && event.key.code==sf::Keyboard::Return){
                        MC->setMove(0,0,s.getSelected(),MC->getDir());
                        MC->setMoveID(MoveID::CHICKEN_JUMP);
                        engine.addCommand(MC);
                        NC->setFowlHasMoved(true);
                    }
                    
                    if (event.type==sf::Event::KeyReleased && event.key.code==sf::Keyboard::Space){
                        FC->setFire(s.getSelected(),MC->getDir());
                        FC->setNextCommand(NC);
                        engine.addCommand(FC);
                        rules->resetJump();
                        NC->setFowlHasMoved(false);
                        
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
            Command* cmd=DIA->run(&s);
            engine.addCommand(cmd);
        }
        if (autorunheuristic){
            Command* cmd=HIA->run(&s);
            engine.addCommand(cmd);
        }
        
        if(FC->getMaxFowlDeadByTeam()>=4)
                    {
            std::cout<<"Partie Finie"<<std::endl;
                        window.close();
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
