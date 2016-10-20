#include <iostream>
#include <map>
#include <memory>

//Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include <string>
#include "Render/Surface.hpp"
#include "state.hpp"

using namespace sf;
using namespace std;
using namespace state;

int main(int argc,char* argv[]) 
{
    sf::RenderWindow window(sf::VideoMode(1500, 1500), "Map"/*, sf::Style::Fullscreen*/);
    sf::View view;
    view.setCenter(3000,3000);
    view.zoom(6.f);
    
    State s;
    int* level=new int[121];
    level=s.loadLevel("../src/fichiermap.txt");
    cout << level[2] << endl;
    
    Surface map;
    if (!map.load("../res/tileset.png", sf::Vector2u(125, 97), level, 40, 30))
        return -1;
    

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
        window.draw(map);
        window.display();
    }
    
    return 0;
}
