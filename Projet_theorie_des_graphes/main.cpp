#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "plateau.h"
#include "pion.h"
#include "console.h"

using namespace std;

int main()
{
    // Ressources
    Plateau plateau;

    // Affichage plateau
    plateau.afficher_plateau();

    return 0;
}
