#include <iostream>
#include <map>
#include <memory>

//Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include <string>
#include "TileMap.hpp"
#include "state.hpp"

using namespace sf;
using namespace std;
using namespace state;

int main(int argc,char* argv[]) 
{
    State s;
    int* level=new int[121];
    level=s.loadLevel("../src/fichiermap.txt");
    cout << level[2] << endl;
    return 0;
}
