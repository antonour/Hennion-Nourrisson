#include <iostream>

//hhhhLes lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

#include "state.hpp"

using namespace std;
using namespace state;

int main(int argc,char* argv[]) 
{
    Exemple exemple;
    exemple.setX(3);

    cout << "It works So Well !" << endl;

    return 0;
}
