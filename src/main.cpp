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
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19,
        20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
        30, 31, 32, 33, 34, 35, 36, 37, 38
    };

    // on crée la tilemap avec le niveau précédemment défini
    TileMap map;
    if (!map.load("../res/tileset.png", sf::Vector2u(136, 111), level, 10, 4))
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
