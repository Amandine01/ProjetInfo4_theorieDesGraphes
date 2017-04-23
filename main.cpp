#include <iostream>
#include "plateau.h"
#include <vector>
#include "console.h"


using namespace std;

int main()
{
    // Ressources
    Plateau p;
    Console* pConsole;

    // Lancer la boucle de jeu
    pConsole->setColor(COLOR_BLUE);
    p.pageAccueil();
    pConsole->setColor(COLOR_DEFAULT);
    p.menu_jeu();
    //p.menu_jeu();

    return 0;
}
