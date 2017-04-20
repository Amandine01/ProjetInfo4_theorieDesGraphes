#include <vector>
#include "plateau.h"
#include "pion.h"
#include<iostream>
#include <string>
#include <cstdlib>
#include "console.h"
#include <cstdio>
#include <fstream>

using namespace std;
///constructeur plateau
Plateau::Plateau()
{
    /// Ressources
    m_lig=4;
    m_col=4;

    // Creation du plateau
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            tab[i][j]=196;
        }
    }
    // Initialisation des cases
    tab[3][3]= 178;
    tab[4][4]= 178;
    tab[3][4]= 176;
    tab[4][3]= 176;
}

/// Destructeur PLATEAU
Plateau::~Plateau()
{

}

void Plateau::Display()
{
    /// Ressources
    Console* pConsole;

    /// Affichage tableau
    // Afficher les lettres
    pConsole->setColor(COLOR_RED);
    cout<<"  a b c d e f g h"<<endl;
    for(int i=0;i<8;i++)
    {
        // Afficher les chiffres
        pConsole->setColor(COLOR_RED);
        cout<<i+1<<" ";
        for(int j=0;j<8;j++)
        {
            pConsole->setColor(COLOR_GREEN);
            cout << tab[i][j] << " " ;
        }
        pConsole->setColor(COLOR_WHITE);
        cout<<endl;
    }

}

void Plateau::Bouclejeu()
{
    // Afficher le plateau
    this->Display();

    // Si quit est faux
    bool quit = false;

    // Poiteur sur console
    Console* pConsole = NULL;

    // Allouer la mémoire du pointeur
    pConsole = Console::getInstance();

    // Boucle infinie
    while(!quit)
    {
       if(pConsole->isKeyboardPressed())
       {

           char dep=pConsole->getInputKey();
           this->deplacer_curseur(dep, m_lig, m_col);
           this->Display();

       }

    }

    Console::deleteInstance();

}

//void Plateau::menu_jeu()
//{
//    int m_choix_menu;
//    bool m_sortie_menu;
//    bool m_sortie;
//    ///Affiche le menu
//    std::cout << "1- Pour jouer à deux joueur" << std::endl;
//    std::cout << "2- Pour jouer contre l'ordinateur" << std::endl;
//    std::cout << "3- Personnaliser votre partie." << std::endl;
//    std::cout << "4- Pour connaitre les regles du jeu" << std::endl << std::endl;
//    std::cout << "5- Quitter" << std::endl << std::endl;
//    std::cout << "Rentrer la valeur de votre choix : ";
//    //Rentre la valeur voulu par le menu
//    std::cin >> m_choix_menu;
//    std::cout << std::endl << std::endl;
//
//    //applique le choix rentree
//    if(m_choix_menu == 1){
//        m_sortie_menu = 1;
//        system("cls");
//        this->initialiser_plateau();
//        this->deplacer_curseur(dep);
//
//
//    }
//    if(m_choix_menu == 2){
//        //Message d'erreur
//        std::cout << "Pas implemente" << std::endl << std::endl;
//    }
//    if(m_choix_menu == 3){
//        m_sortie_menu = 1;
//        //On va allouer et choisir la valeur pour un plateau pimp
//        int nbrJoueur, nbrPions, nbrColonne, nbrLigne;
//        std::cout << "Rentrer le nombre de Joueur : ";
//        std::cin >> nbrJoueur;
//        std::cout << "Rentrer le nombre de pions par Joueur : ";
//        std::cin >> nbrPions;
//        std::cout << "Rentrer le nombre de Colonne : ";
//        std::cin >> nbrColonne;
//        std::cout << "Rentrer le nombre de Ligne : ";
//        std::cin >> nbrLigne;
//        //On initialise la partie avec les valeurs precedemment rentrée
//        ///this->initialisation_partie(nbrJoueur, nbrPions,nbrColonne, nbrLigne);
//        this->initialiser_plateau();
//    }
//    if(m_choix_menu == 4){
//        this->pageAccueil();
//    }
//    else{
//        system("cls");
//        std::cout << "Votre choix n'existe pas" << std::endl;
//        //inserer la detection de touche
//    }
//
//    system("cls");
//    std::cout << "lejeu se lance";
//    if(m_choix_menu == 5){
//            this->pageSortie();
//    }
//}




void Plateau::deplacer_curseur(char dep, int m_lig, int m_col)
{
    // Ressources
    bool quit = false;
    Console* pConsole = NULL;
    int ligne=0, colonne=0;
    char c = 0;

    // Alloue la mémoire du pointeur
    pConsole = Console::getInstance();

    // Affichage avec gotoligcol et couleur
    pConsole->gotoLigCol(20, 0);

    pConsole->setColor(COLOR_DEFAULT);

    // Boucle événementielle
    while (!quit)
    {

        // Blindage
        if (ligne<1)
        {
            ligne = 1;
        }
        if (ligne>8)
        {
            ligne = 8;
        }

        if (colonne<2)
        {
            colonne = 2;
        }
        if (colonne>16)
        {
            colonne = 16;
        }

        // Si on a appuyé sur une touche du clavier
        if (pConsole->isKeyboardPressed())
        {

            c = pConsole->getInputKey();


            switch(c)
            {
            case 'z':
                ligne--;
                break;
            case 's':
                ligne++;
                break;
            case 'q':
                colonne = colonne-2;
                break;
            case 'd':
                colonne = colonne+2;
                break;
            default:
                break;
            }

        }

        pConsole->gotoLigCol(ligne, colonne);
    }

    // Libère la mémoire du pointeur !
    Console::deleteInstance();

}

//Méthodes affichant des pages de jeu
void Plateau::pageAccueil()
{
    // effacer l'ecran
    system("cls");

    std::ifstream presentation("presentation.txt");
    if(presentation)
    {
        // On stock dans la chaine le fichier
        std::string texte;

        // Tant qu'on a pas atteint la fin de regles.txt
        while(getline(presentation,texte))
        {
            // On affiche les regles du jeu
            std::cout << texte << std::endl;
        }
    }

    // Blindage ouverture du fichier
    else
    {
        std::cout << "Erreur fichier presentation" << std::endl;
    }

    system("PAUSE");
    system("cls");

    ///this->DetectionTouche();
    ///system("cls");
}

void Plateau::pageVictoire()
{
    std::cout << "Bien joue!" << std::endl << std::endl;
    ///Affiche la page de victoire
    ///this->DetectionTouche();
    system("cls");
}

void Plateau::pageSortie()
{
        std::cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl << std::endl;
        std::cout << "                                                 " << std::endl << std::endl;
        std::cout << "                                                 " << std::endl << std::endl;
        std::cout << "                                                 " << std::endl << std::endl;
        std::cout << "                                                 " << std::endl << std::endl;
        std::cout << "              MERCI D'ETRE VENU                  " << std::endl << std::endl;
        std::cout << "          A BIENTOT POUR DE NOUVELLES            "<<std::endl;
        std::cout << "                                                 "<<std::endl;
        std::cout << "                    :)                           "<<std::endl;
        std::cout << "                                                 "<<std::endl;
        std::cout << "                                                 "<<std::endl;
        std::cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl << std::endl;
    ///Affiche la page de victoire
    ///this->DetectionTouche();
    system("cls");
}

