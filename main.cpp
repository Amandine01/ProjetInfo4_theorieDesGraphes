#include <iostream>
#include "plateau.h"
#include <vector>
#include "console.h"

// Sources
// M. Segado
// OpenClasseroom -> https://openclassrooms.com/courses/lecture-et-ecriture-dans-les-fichiers-en-c

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
