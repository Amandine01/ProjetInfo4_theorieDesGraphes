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
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            tab[i][j]='-';
        }
    }
    // Initialisation des cases
    tab[3][3]= 'B';
    tab[4][4]= 'B';
    tab[3][4]= 'N';
    tab[4][3]= 'N';
}

/// Destructeur PLATEAU
Plateau::~Plateau()
{

}

void Plateau::Display()
{
    /// Ressources
//    Console* pConsole;

    /// Affichage tableau
    // Afficher les lettres
//    pConsole->setColor(COLOR_RED);
    cout<<"  a b c d e f g h"<<endl;
    for(int i=0; i<8; i++)
    {
        // Afficher les chiffres
//        pConsole->setColor(COLOR_RED);
        cout<<i+1<<" ";
        for(int j=0; j<8; j++)
        {
//            pConsole->setColor(COLOR_GREEN);
            cout << tab[i][j] << " " ;
        }
//        pConsole->setColor(COLOR_WHITE);
        cout<<endl;
    }

}

void Plateau::Bouclejeu()
{
    // Afficher le plateau
    this->Display();
    int turn=1;

    // Si quit est faux
    bool quit = false;

    // Poiteur sur console
    Console* pConsole = NULL;

    // Allouer la mémoire du pointeur
    pConsole = Console::getInstance();

    // Boucle infinie
    while(!quit)
    {

        if (turn%2==0) ///JOUEUR NOIR
        {


            ///
            if(pConsole->isKeyboardPressed())
            {
                this->case_possible(turn);
                system("cls");

                this->Display();
                char dep=pConsole->getInputKey();
                this->deplacer_curseur(dep, m_lig, m_col);
                this->Display();
                cout<<"Le premier joueur joue (pions noirs joue)"<<endl;
                ///fonction Poser pion
            }
        }


        if (turn%2==1) ///JOUEUR BLANC
        {

            if(pConsole->isKeyboardPressed())
            {

                this->case_possible(turn);
                system("cls");

                this->Display();
                char dep=pConsole->getInputKey();
                this->deplacer_curseur(dep, m_lig, m_col);
                this->Display();
                cout<<"Le deuxieme joueur joue (pions blancs joue)"<<endl;
                ///fonction Poser pion

            }
        }
        turn++;
    }

    Console::deleteInstance();

}

void Plateau::case_possible (int turn)
{
    if (turn%2==1)
    {
        for(int i=0; i<8; i++)
        {
            for(int j=0; j<8; j++)
            {
                if (tab[i][j]=='B')
                {
                    if ((tab[i+1][j]=='N')&&(tab[i-1][j]=='-'))
                        tab[i-1][j]='X';

                    if ((tab[i+1][j]=='-')&&(tab[i-1][j]=='N'))
                        tab[i+1][j]='X';


                    if ((tab[i-1][j-1]=='-')&&(tab[i+1][j+1]=='N'))
                        tab[i-1][j-1]='X';

                    if  ((tab[i+1][j+1]=='-')&&(tab[i-1][j-1]=='N'))
                        tab[i+1][j+1]='X';

                    if ((tab[i+1][j-1]=='-')&&(tab[i-1][j+1]=='N'))
                        tab[i+1][j-1]='X';

                    if ((tab[i-1][j+1]=='-')&&(tab[i+1][j-1]=='N'))
                        tab[i-1][j+1]='X';

                    if ((tab[i][j-1]=='-')&&(tab[i][j+1]=='N'))
                        tab[i][j-1]='X';

                    if ((tab[i][j+1]=='-')&&(tab[i][j-1]=='N'))
                        tab[i][j+1]='X';
                }
            }
        }

    }

    if (turn%2==0)
    {
        for(int i=0; i<8; i++)
        {
            for(int j=0; j<8; j++)
            {
                if (tab[i][j]=='N')
                {
                    if ((tab[i+1][j]=='B')&&(tab[i-1][j]=='-'))
                        tab[i-1][j]='X';

                    if ((tab[i+1][j]=='-')&&(tab[i-1][j]=='B'))
                        tab[i+1][j]='X';


                    if ((tab[i-1][j-1]=='-')&&(tab[i+1][j+1]=='B'))
                        tab[i-1][j-1]='X';

                    if  ((tab[i+1][j+1]=='-')&&(tab[i-1][j-1]=='B'))
                        tab[i+1][j+1]='X';

                    if ((tab[i+1][j-1]=='-')&&(tab[i-1][j+1]=='B'))
                        tab[i+1][j-1]='X';

                    if ((tab[i-1][j+1]=='-')&&(tab[i+1][j-1]=='B'))
                        tab[i-1][j+1]='X';

                    if ((tab[i][j-1]=='-')&&(tab[i][j+1]=='B'))
                        tab[i][j-1]='X';

                    if ((tab[i][j+1]=='-')&&(tab[i][j-1]=='B'))
                        tab[i][j+1]='X';
                }
            }
        }
    }
}

void Plateau::menu_jeu()
{
    int m_choix_menu;
    ///Affiche le menu
    std::cout << "1- Pour jouer a deux joueur" << std::endl;
    std::cout << "2- Pour jouer contre l'ordinateur" << std::endl;
    std::cout << "3- Pour connaitre les regles du jeu" << std::endl;
    std::cout << "4- Quitter" << std::endl << std::endl;
    std::cout << "Rentrer la valeur de votre choix : ";
    //Rentre la valeur voulu par le menu
    std::cin >> m_choix_menu;
    std::cout << std::endl << std::endl;

    //applique le choix rentree
    if(m_choix_menu == 1)
    {
        system("cls");
        Plateau::Bouclejeu();
    }
    if(m_choix_menu == 2)
    {
        //Message d'erreur
        std::cout << "Pas implemente encore" << std::endl << std::endl;
        Plateau::Bouclejeu();
    }

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
}




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

