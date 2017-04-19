#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "pion.h"
#include "console.h"

// Constructeurs
Pion :: Pion()
         : m_couleur(" "), m_nb_pion(0)
{

}

Pion :: Pion(std::string _couleur, int _nb_pion)
         : m_couleur(_couleur), m_nb_pion(_nb_pion)
{

}

// Destructeur
Pion :: ~Pion()
{
}

// Methodes
// Fonction verifiant si le pion se trouve sur le plateau ou non
bool Pion :: poser_pion()
{
    /*if ()
    {
        std::cout << "Le pion est sur le plateau" << std::endl;
        return true;
    }
    else
    {
        std::cout << "Le pion n est pas sur le plateau. Veuillez le placer sur le plateau" << std::endl;
        return false;
    }*/
}

// Afficher les pions a l etat initial
void Pion :: afficher_pion()
{
    /// Ressources
    // Trou
    char trou = '-';

    // Pion noir
    char noir = 249;

    // Pion blanc
    char blanc = 'O';

    // Compteur
    int cpt = 0;

    // Pointeur sur Console
    Console * pConsole = NULL;

   /*/// Afficher pions
    for(int i = 0; i<7; i++)
    {
        pConsole -> gotoLigCol(i*2+2,1);
        std::cout << E;
        //tab[i*2+2][j]
    }

    // Afficher Rhinoceros
    for(int i = 0; i<5; i++)
    {
        pConsole -> gotoLigCol(i*2+2,24);
        std::cout << R;
    }
    pConsole -> gotoLigCol(30,0);

    // Afficher Montagnes
    for(int i = 0; i<3; i++)
    {
        pConsole -> gotoLigCol(i*2+4,12);
        std::cout << M;
    }*/
    pConsole -> gotoLigCol(30,0);
}


// Accesseurs

std::string Pion :: getCouleur()
{
    return m_couleur;
}

int Pion :: getNb_pion()
{
    return m_nb_pion;
}

void Pion :: setCouleur(std::string couleur)
{
    m_couleur = couleur;
}

void Pion :: setNb_pion(int nb_pion)
{
    m_nb_pion = nb_pion;
}
