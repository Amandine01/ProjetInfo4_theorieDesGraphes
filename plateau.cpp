#include <vector>
#include "plateau.h"
#include "pion.h"
#include<iostream>
#include <string>
#include <cstdlib>
#include "console.h"
#include <cstdio>
#include <fstream>
#include <map>
#include "conio.h"


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
    Console* pConsole;

    /// Affichage tableau
    // Afficher les lettres
    pConsole->setColor(COLOR_RED);
    cout<<"  a b c d e f g h"<<endl;
    for(int i=0; i<8; i++)
    {
        // Afficher les chiffres
        pConsole->setColor(COLOR_RED);
        cout<<i+1<<" ";
        for(int j=0; j<8; j++)
        {
            if(tab[i][j] == 'N')
            {
                pConsole->setColor(COLOR_BLACK);
                cout << tab[i][j] << " " ;
            }
            else
            {
                if(tab[i][j] == 'B')
                {
                    pConsole->setColor(COLOR_WHITE);
                    cout << tab[i][j] << " " ;
                }
                else
                {
                     pConsole->setColor(COLOR_GREEN);
                    cout << tab[i][j] << " " ;
                }

            }
        }
        pConsole->setColor(COLOR_DEFAULT);
        cout<<endl;
    }

}

void Plateau::Bouclejeu()
{
    // Afficher le plateau
    this->Display();
    int turn=0;


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
                // Afficher les croix
                this->case_possible(turn);

                // Effacer l'ecran
                system("cls");

                // Afficher le plateau
                this->Display();

                // Variable deplacement
                char dep = pConsole->getInputKey();

                // Deplacer le curseur
                this->deplacer_curseur(dep, m_lig, m_col,turn);

                // Effacer l'ecran
                system("cls");

                // Effacer cases possibles
                this->effacer_case_possible();

                // Afficher le plateau
                this->Display();

                // Afficher le joueur suivant
                pConsole->gotoLigCol(3,20);
                cout << "C'est au tour des pions blancs de jouer." << endl;
                pConsole->gotoLigCol(4,20);
                cout << "Les X representent les cases ou vous pouvez poser votre pion." << endl;
                pConsole->gotoLigCol(5,20);
                cout << "Appuyer sur entree pour valider" << endl;

                // Incrementation de turn
                turn++;

                ///this->comptage_points();
//              pConsole->gotoLigCol(10, 0);
//
//              pConsole->setColor(COLOR_DEFAULT);
                //this->poser_pion(turn);
                //system("cls");
                //this->Display();

            }
        }


        if (turn%2==1) ///JOUEUR BLANC
        {

            if(pConsole->isKeyboardPressed())
            {

                // Afficher les croix
                this->case_possible(turn);

                // Effacer l'ecran
                system("cls");

                // Afficher le plateau
                this->Display();

                // Variable deplacement
                char dep = pConsole->getInputKey();

                // Deplacer le curseur
                this->deplacer_curseur(dep, m_lig, m_col,turn);

                // Effacer l'ecran
                system("cls");

                // Effacer cases possibles
                this->effacer_case_possible();

                // Afficher le plateau
                this->Display();

                // Afficher le joueur suivant
                pConsole->gotoLigCol(4,20);
                pConsole->gotoLigCol(3,20);
                cout << "C'est au tour des pions noirs de jouer." << endl;
                pConsole->gotoLigCol(4,20);
                cout << "Les X representent les cases ou vous pouvez poser votre pion." << endl;
                pConsole->gotoLigCol(5,20);
                cout << "Appuyer sur entree pour valider" << endl;

                // Incrementation de turn
                turn++;

                ///this->comptage_points();
                //this->poser_pion(turn);
                //system("cls");
                //this->Display();
            }
        }
    }

    Console::deleteInstance();



}

void Plateau::case_possible (int turn)
{
    pair<int,int> coordonnees_possibles;

    if (turn%2==0)/// joueur noir
    {
        for(int i=0; i<8; i++)
        {
            for(int j=0; j<8; j++)
            {
                if (tab[i][j]=='B')
                {
                    if ((tab[i+1][j]=='N')&&(tab[i-1][j]=='-'))
                        tab[i-1][j]='X';
                    coordonnees_possibles.first=j;
                    coordonnees_possibles.second=i-1;

                    if ((tab[i+1][j]=='-')&&(tab[i-1][j]=='N'))
                        tab[i+1][j]='X';
                    coordonnees_possibles.first=j;
                    coordonnees_possibles.second=i+1;

                    if ((tab[i-1][j-1]=='-')&&(tab[i+1][j+1]=='N'))
                        tab[i-1][j-1]='X';
                    coordonnees_possibles.first=j-1;
                    coordonnees_possibles.second=i-1;

                    if  ((tab[i+1][j+1]=='-')&&(tab[i-1][j-1]=='N'))
                        tab[i+1][j+1]='X';
                    coordonnees_possibles.first=j+1;
                    coordonnees_possibles.second=i+1;

                    if ((tab[i+1][j-1]=='-')&&(tab[i-1][j+1]=='N'))
                        tab[i+1][j-1]='X';
                    coordonnees_possibles.first=j-1;
                    coordonnees_possibles.second=i+1;

                    if ((tab[i-1][j+1]=='-')&&(tab[i+1][j-1]=='N'))
                        tab[i-1][j+1]='X';
                    coordonnees_possibles.first=j+1;
                    coordonnees_possibles.second=i-1;

                    if ((tab[i][j-1]=='-')&&(tab[i][j+1]=='N'))
                        tab[i][j-1]='X';
                    coordonnees_possibles.first=j-1;
                    coordonnees_possibles.second=i;

                    if ((tab[i][j+1]=='-')&&(tab[i][j-1]=='N'))
                        tab[i][j+1]='X';
                    coordonnees_possibles.first=j+1;
                    coordonnees_possibles.second=i;

                }

                // cout<<"("<<coordonnees_possibles.first<<"."<<coordonnees_possibles.second<<")"<<endl;
            }
        }


    }

    if (turn%2==1)///joueur blanc
    {
        for(int i=0; i<8; i++)
        {
            for(int j=0; j<8; j++)
            {
                if (tab[i][j]=='N')
                {
                    if ((tab[i+1][j]=='B')&&(tab[i-1][j]=='-'))
                        tab[i-1][j]='X';
                    coordonnees_possibles.first=j;
                    coordonnees_possibles.second=i-1;

                    if ((tab[i+1][j]=='-')&&(tab[i-1][j]=='B'))
                        tab[i+1][j]='X';
                    coordonnees_possibles.first=j;
                    coordonnees_possibles.second=i+1;

                    if ((tab[i-1][j-1]=='-')&&(tab[i+1][j+1]=='B'))
                        tab[i-1][j-1]='X';
                    coordonnees_possibles.first=j-1;
                    coordonnees_possibles.second=i-1;

                    if  ((tab[i+1][j+1]=='-')&&(tab[i-1][j-1]=='B'))
                        tab[i+1][j+1]='X';
                    coordonnees_possibles.first=j+1;
                    coordonnees_possibles.second=i+1;

                    if ((tab[i+1][j-1]=='-')&&(tab[i-1][j+1]=='B'))
                        tab[i+1][j-1]='X';
                    coordonnees_possibles.first=j-1;
                    coordonnees_possibles.second=i+1;

                    if ((tab[i-1][j+1]=='-')&&(tab[i+1][j-1]=='B'))
                        tab[i-1][j+1]='X';
                    coordonnees_possibles.first=j+1;
                    coordonnees_possibles.second=i-1;

                    if ((tab[i][j-1]=='-')&&(tab[i][j+1]=='B'))
                        tab[i][j-1]='X';
                    coordonnees_possibles.first=j-1;
                    coordonnees_possibles.second=i;

                    if ((tab[i][j+1]=='-')&&(tab[i][j-1]=='B'))
                        tab[i][j+1]='X';
                    coordonnees_possibles.first=j+1;
                    coordonnees_possibles.second=i;
                }
            }

        }
    }

}

void Plateau::effacer_case_possible()
{
    for(int i=0; i<8; i++)
        {
            for(int j=0; j<8; j++)
            {
                if (tab[i][j]=='X')
                {
                    tab[i][j]='-';
                }
            }
        }
}

void Plateau::poser_pion(int turn,int ligne, int colonne)
{
    Console* pConsole = NULL;
    // Alloue la mémoire du pointeur
    pConsole = Console::getInstance();

    // Affichage avec gotoligcol et couleur
    //pConsole->gotoLigCol(20, 0);
    char c;

    if (turn%2==0)///Joueur noir
    {
        tab[ligne-1][(colonne-2)/2]='N' ;
    }

    if (turn%2==1)///Joueur blanc
    {
        tab[ligne-1][(colonne-2)/2]='B' ;
    }

//        for(int i=0; i<8; i++)
//        {
//            for(int j=0; j<8; j++)
//            {
//                if (tab[i][j]=='X')
//                 {
//                     pConsole->gotoLigCol(i, j);
//                    if (turn%2==0)//JOUEUR NOIR
//                    {
//                        if (pConsole->isKeyboardPressed())
//                       {
//
//                           c = pConsole->getInputKey();
//                           switch(c)
//                          {
//                              case 'p':
//                              tab[i][j] = 'N';
//                              break;
//                              default:
//                             break;
//                           }
//
//                         }
//
//                       }
//
//                       if (turn%2==1)// JOUEUR BLANC
//                      {
//                        if (pConsole->isKeyboardPressed())
//                        {
//
//                           c = pConsole->getInputKey();
//                           switch(c)
//                           {
//                             case 'p':
//                            tab[i][j] = 'B';
//                             break;
//                             default:
//                             break;
//                           }
//
//                         }
//
//                       }
//
//
//             }
//            }
//
//        }
    // Libère la mémoire du pointeur !
    // Console::deleteInstance();
}

///void Plateau::retournement_pion

void Plateau::menu_jeu()
{
    int m_choix_menu;
    int a=1;
while (a!=2)
{
    ///Affiche le menu
    std::cout << "1- Pour jouer a deux joueur" << std::endl;
    std::cout << "2- Pour jouer contre l'ordinateur" << std::endl;
    std::cout << "3- Pour charger une partie" <<endl;
    std::cout << "4- Pour connaitre les regles du jeu" << std::endl;
    std::cout << "5- Quitter" << std::endl << std::endl;
    std::cout << "Rentrer la valeur de votre choix : ";
    //Rentre la valeur voulu par le menu
    std::cin >> m_choix_menu;
    std::cout << std::endl << std::endl;
    switch(m_choix_menu)
    {
    case 1:
        system("cls");
        Plateau::Bouclejeu();
        break;
    case 2:
    {
        system("cls");
        //Message d'erreur
        std::cout << "Pas implemente encore" << std::endl << std::endl;
        Plateau::Bouclejeu();
        break;
    }

    case 3:
    {
        system("cls");
        cout<<"charger une partie "<<endl;
        break;
    }

    case 4:
    {
        system("cls");
        cout<<"Affichage des regles. Appuyez sur la touche espace pour revenir au menu"<<endl;
        if (getch()==27)
        {
            system("cls");
            a=1;
            m_choix_menu=0;
        }
        break;

    }

    case 5:
    {
        system("cls");
        if (getch()==27)
        {
            system("cls");
            a=2;
            m_choix_menu=0;
        }
        break;
    }

    default :
        {
            system("cls");
            cout<<"Cette option n'existe pas. Saisissez espace pour revenir au menu"<<endl;
            if (getch()==27)
            {
                system("cls");
                a=1;
                m_choix_menu=0;
            }
        }
}


}
}




void Plateau::deplacer_curseur(char dep, int m_lig, int m_col,int turn)
{
    // Ressources
    bool quit = false;
    Console* pConsole = NULL;
    int ligne=0, colonne=0;
    char c = 0;
    int d=1;
    int v=0;

    // Alloue la mémoire du pointeur
    pConsole = Console::getInstance();

    // Affichage avec gotoligcol et couleur
    pConsole->gotoLigCol(20, 0);

    pConsole->setColor(COLOR_DEFAULT);

    // Boucle événementielle
    while (d!=2)
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
        if (colonne>18)
        {
            colonne = 18;
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
            case 13:
                if (tab[ligne-1][(colonne-2)/2]!='X')
                {
                    system("cls");
                    cout<<"Vous ne pouvez pas posez de pion ici. Appuyez sur espace pour continuer";
                    cin>>v;
                    if (v==27)
                    {
                        system("cls");
                        this->Display();
                    }
                    d=1;
                }
                else
                {
                    this->poser_pion(turn,ligne,colonne);
                    d=2;
                }

                ///pConsole->gotoLigCol(ligne, colonne);
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

void Plateau::comptage_points()
{
    int points_noir=0;
    int points_blanc=0;
    int difference1=0;
    int difference2=0;
    for (int i=0; i<8; i++)
    {
        for (int j=0; j<8; j++)
        {
            if (tab[i][j]=='B')
            {
                points_blanc++;
            }
            if (tab[i][j]=='N')
            {
                points_noir++;
            }
        }
    }
    difference1=points_blanc-points_noir;
    difference2=points_noir-points_blanc;
    cout<<"Le joueur noir a "<<points_noir<<"points."<<endl;
    cout<<"Le joueur blanc a "<<points_blanc<<"points."<<endl;
    if (points_noir<points_blanc)
    {
        cout<<"Le joueur blanc a donc gagné de "<<difference1<<"points."<<endl;
    }
    if (points_noir>points_blanc)
    {
        cout<<"Le joueur noir a donc gagné de "<<difference2<<"points."<<endl;
    }
}

