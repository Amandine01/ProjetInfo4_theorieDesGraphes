#ifndef PLATO_H_INCLUDED
#define PLATO_H_INCLUDED
#include "pion.h"
#include "console.h"
#include <vector>

class Plateau
{
private:
    //std::vector <Pion> m_plateau;
    ///
    int m_longueur_plateau;
    int m_largeur_plateau;
    char tab[8][8];
    ///Console* pConsole;
    int m_lig;
    int m_col;
public:
    ///Constructeur et destructeur
    Plateau();
    ~Plateau();

    // Methodes
    void afficher_grille_jeu();
    void initialiser_plateau();
    void menu_jeu();
    void deplacer_curseur(char dep, int lig, int col, int turn);
    void enregistrer_partie();
    void pageAccueil();
    void pageSortie();
    void pageVictoire();
    void Display();
    void Bouclejeu();
    void case_possible (int turn);
    void poser_pion(int turn,int ligne, int colonne);
    void comptage_points();
    ///accesseurs

    int getLongueur_plateau();
    int getLargeur_plateau();
    //Setter

    void setLongueur_plateau(int longueur_plateau);
    void setLargeur_plateau(int largeur_plateau);
};





#endif // PLATO_H_INCLUDED
