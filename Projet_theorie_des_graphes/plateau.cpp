#include <iostream>
#include <vector>
#include "plateau.h"
#include <conio.h>
#include <windows.h>
#include <fstream>

using namespace std;

// Constructeurs
Plateau :: Plateau()
         : m_plateau(0)
{

}

Plateau :: Plateau(std::vector <Pion> _plateau)
         : m_plateau(_plateau)
{

}

// Destructeur
Plateau :: ~Plateau()
{
}

// Methodes
void Plateau :: afficher_plateau()
{
    /// Ressources
    // Pointeur sur Console
    Console * pConsole = NULL;

    /// Affichage du tableau
    // Aller a la position 0,0
    pConsole -> gotoLigCol(0,0);

    //Colorer le plateau
    pConsole->setColor(COLOR_GREEN);

    // Ouverture du fichier
    std::ifstream plateau("plateau.txt");

    if(plateau)
    {
        // On stock dans la chaine le fichier
        std::string texte;

        // Tant qu'on a pas atteint la fin de regles.txt
        while(getline(plateau,texte))
        {
            // On affiche les règles du jeu
            std::cout << texte << std::endl;
        }
    }
    // Blindage ouverture du fichier
    else
    {
        std::cout << "Erreur fichier plateau" << std::endl;
    }
    pConsole->setColor(COLOR_WHITE);

    // Aller a la position (40,40)
    pConsole -> gotoLigCol(40,40);
}

// Accesseurs

std::vector <Pion> Plateau :: getPlateau()
{
    return m_plateau;
}

void Plateau :: setPlateau(std::vector <Pion> plateau)
{
    m_plateau = plateau;
}
