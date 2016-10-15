#include <iostream>

//Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include "TileMap.hpp"

using namespace sf;

int testSFML() {
    // on crée la fenêtre
    sf::RenderWindow window(sf::VideoMode(1500, 1500), "Tilemap");

    // on définit le niveau à l'aide de numéro de tuiles
    const int level[] =
    {
        36,36,36,36,36,36,36,36,36,36,36,
        36,36,36,15,36,36,36,15,36,36,36,
        4,36,36,36,36,36,36,36,36,36,36,
        36,36,36,36,36,36,36,36,36,3,2,
        36,36,36,36,15,36,36,36,36,36,11,
        16,36,36,36,36,36,15,36,36,3,11,
        36,36,15,36,36,36,36,36,36,36,11,
        36,36,36,36,36,36,36,36,36,36,11,
        12,1,13,12,1,13,12,1,13,12,11
    };

    // on crée la tilemap avec le niveau précédemment défini
    TileMap map;
    if (!map.load("../res/tileset.png", sf::Vector2u(125, 97), level, 11, 9))
        return -1;

    // on fait tourner la boucle principale
    while (window.isOpen())
    {
        // on gère les évènements
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        // on dessine le niveau
        window.clear();
        window.draw(map);
        window.display();
    }
    
    return 0;
    
}

// Fin test SFML

#include "state.hpp"

using namespace std;
using namespace state;

int main(int argc,char* argv[]) 
{
    
    int x;
    x=testSFML();
    
    return x;
}
