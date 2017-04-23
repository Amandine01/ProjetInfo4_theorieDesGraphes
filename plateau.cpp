#include <vector>
#include "plateau.h"
#include<iostream>
#include <string>
#include <cstdlib>
#include "console.h"
#include <cstdio>
#include <fstream>
#include <map>
#include "conio.h"
#include <ctime>
#include <windows.h>

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

                // Condition de fin
                this->condition_de_fin();

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

                // Conditions de fin
                this->condition_de_fin();

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
<<<<<<< HEAD


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

//                    else
//                    {
//                        system("cls");
//                        this->comptage_points();
//                    }
=======
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
>>>>>>> origin/master
                   else
//                    {
//                        system("cls");
//                        this->comptage_points();
//                    }

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
<<<<<<< HEAD

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

//                    else
//                    {
//                        system("cls");
//                        this->comptage_points();
//                    }
=======
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
>>>>>>> origin/master
                }
            }

        }
    }

}

void Plateau::effacer_case_possible()
{
    for(int i=0; i<8; i++)
<<<<<<< HEAD
    {
        for(int j=0; j<8; j++)
=======
>>>>>>> origin/master
        {
            if (tab[i][j]=='X')
            {
<<<<<<< HEAD
                tab[i][j]='-';
            }
        }
    }
}

void Plateau::poser_pion(int turn,int ligne, int colonne)
{

    int v=ligne-1;
    int w=(colonne-2)/2;

    if (turn%2==0)///Joueur noir
    {
        tab[v][w]='N' ;
        //while (tab[v][w]='N')
        //{
        retournement_pion_blanc(v,w);
        //}

    }
    if (turn%2==1)///Joueur blanc
    {
        tab[v][w]='B' ;
        //while(tab[v][w]='B')

        retournement_pion_noir(v,w);
=======
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
>>>>>>> origin/master

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

<<<<<<< HEAD
    }

}

void Plateau::retournement_pion_blanc (int v, int w)
{
//    for (v,v<(8-v),v++)
//    {
//
//    }
//    for (v,v<(8-v),v--)
    if (tab[v+1][w]=='B')
    {
        tab[v+1][w]='N';
    }
    if (tab[v-1][w]=='B')
    {
        tab[v-1][w]='N';
    }



    if (tab[v+1][w+1]=='B')
    {
        tab[v+1][w+1]='N';
    }



    if  (tab[v-1][w-1]=='B')
    {
        tab[v-1][w-1]='N';
    }

    if (tab[v-1][w+1]=='B')
    {
        tab[v-1][w+1]='N';
    }



    if (tab[v+1][w-1]=='B')
    {
        tab[v+1][w-1]='N';
    }



    if (tab[v][w+1]=='B')
    {
        tab[v][w+1]='N';
    }


    if (tab[v][w-1]=='B')
    {
        tab[v][w-1]='N';
    }


}

void Plateau::retournement_pion_noir(int v,int w)
{
//    for (v,v<(8-v),v++)
//    {
//
//    }
//    for (v,v<(8-v),v--)
    if (tab[v+1][w]=='N')
        tab[v+1][w]='B';


    if (tab[v-1][w]=='N')
        tab[v-1][w]='B';


    if (tab[v+1][w+1]=='N')
        tab[v+1][w+1]='X';


    if  (tab[v-1][w-1]=='N')
        tab[v-1][w-1]='B';


    if (tab[v-1][w+1]=='N')
        tab[v-1][w+1]='B';


    if (tab[v+1][w-1]=='N')
        tab[v+1][w-1]='B';


    if (tab[v][w+1]=='N')
        tab[v][w+1]='B';


    if (tab[v][w-1]=='N')
        tab[v][w-1]='B';


}

void Plateau::condition_de_fin()
{
    int compteurX=0;
    for(int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {
            if (tab[i][j]=='X')
            {
                compteurX++;
                cout<<compteurX<<endl;
            }
        }
    }

    if (compteurX==0)
    {
        cout<<"Plus aucun coup n'est possible."<<endl;
        getch();
        this->comptage_points();
    }
=======
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
>>>>>>> origin/master
}

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
            Bouclejeu_IA();
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
            cout<<"Regles de jeu :"<<endl<<endl<<endl;
            cout<<"Deroulement de la partie :"<<endl<<endl;
            cout<<"Poser un pion --> Ou? : Sur une case vide adjacente a un pion adverse."<<endl;
            cout<<"              --> Comment ? : Le joueur doit encadrer 1 ou plusieurs pions"<<endl;
            cout<<"adverses (dans 1 des 8 directions) entre le pion qu'il pose"<<endl;
            cout<<"et un pion de sa couleur. Ensuite, le joueur retourne le ou les pions"<<endl;
            cout<<"qu'il vient d'encadrer afin que ces derniers soient de sa couleur."<<endl;
            cout<<"Attention : Il n'y a pas de reaction en chaine, les pions retournes"<<endl;
            cout<<"ne peuvent pas servir a en retourner d'autres lors du meme tour de jeu."<<endl<<endl;
            cout<<"Deplacement :"<<endl<<endl;
            cout<<"Haut : z, Bas : s, Droite : d, Gauche : Q, Valider : P"<<endl<<endl;
            cout<<"Fin de la partie :"<<endl<<endl;
            cout<<"Les 2 joueurs ne peuvent plus poser de pions. Le Vainqueur est celui"<<endl;
            cout<<"qui a le plus grand nombre de pions sur l'Othellier."<<endl;
            cout<<"Les cases vides sont donnees au vainqueur"<<endl;



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
    Console* pConsole = NULL;
    int ligne=0, colonne=0;
    char c = 0;
<<<<<<< HEAD
    int d=1;
    int v=0;
=======
    int d = 1;
    int v = 1;
>>>>>>> origin/master

    // Alloue la mémoire du pointeur
    pConsole = Console::getInstance();

    // Affichage avec gotoligcol
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
<<<<<<< HEAD
            case 'p':
                if (tab[ligne-1][(colonne-2)/2]!='X')
                {
                    system("cls");
                    cout<<"Vous ne pouvez pas posez de pion ici. Appuyez sur espace pour continuer";
                    cin>>v;
                    if (v==27)
=======
            case 13:
                if (tab[ligne-1][(colonne-2)/2]!='X')
                {
                    system("cls");
                    pConsole->gotoLigCol(2, 0);
                    cout << "Vous ne pouvez pas posez de pion ici. Appuyez sur '1' pour continuer.";
                    cin >> v;
                    if (v == 1)
>>>>>>> origin/master
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
<<<<<<< HEAD
    int points_supp=0;
    system("cls");
=======
>>>>>>> origin/master
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
<<<<<<< HEAD
            if (tab[i][j]=='-')
            {
                points_supp++;
            }
=======
>>>>>>> origin/master
        }
    }
    difference1=points_blanc-points_noir;
    difference2=points_noir-points_blanc;
    cout<<"Le joueur noir a "<<points_noir<<"points."<<endl;
    cout<<"Le joueur blanc a "<<points_blanc<<"points."<<endl;
    if (points_noir<points_blanc)
    {
        cout<<"Le joueur blanc a donc gagné de "<<difference1<<"points."<<endl;
<<<<<<< HEAD
        cout<<"Le score total est donc de :"<<endl;
        cout<<" "<<points_blanc+points_supp<<" (blanc) à"<<points_noir<<" (noir)."<< endl;

=======
>>>>>>> origin/master
    }
    if (points_noir>points_blanc)
    {
        cout<<"Le joueur noir a donc gagné de "<<difference2<<"points."<<endl;
<<<<<<< HEAD
        cout<<"Le score total est donc de :"<<endl;
        cout<<" "<<points_noir+points_supp<<" (noir) à"<<points_noir<<" (blanc)."<< endl;
    }

    getch();
}

void Plateau::Bouclejeu_IA()
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
            if(pConsole->isKeyboardPressed())
            {
                this->case_possible(turn);
                ///this->condition_de_fin();
                system("cls");
                this->Display();
                char dep=pConsole->getInputKey();
                this->deplacer_curseur(dep, m_lig, m_col,turn);
                system("cls");
                this->effacer_case_possible();
                this->Display();
                ///this->comptage_points();
//                 pConsole->gotoLigCol(10, 0);
//
//                    pConsole->setColor(COLOR_DEFAULT);
//                cout<<"Le premier joueur joue (pions noirs joue). Les X representent les cases où vous pouvez poser votre pion."<<endl;
                //this->poser_pion(turn);
                //system("cls");
                //this->Display();
                turn++;

            }
            Console::deleteInstance();
        }


        if (turn%2==1) ///IA
        {

            this->case_possible_IA();
            ///this->condition_de_fin();
            system("cls");

            this->Display();
            ///system("cls");
            ///this->effacer_case_possible();
            ///this->Display();
            ///this->comptage_points();
            //cout<<"Le deuxieme joueur joue (pions blancs joue)"<<endl;
            //this->poser_pion(turn);
            //system("cls");
            //this->Display();
            turn++;

        }
    }

   }

void Plateau::case_possible_IA()
{
    cout<<"IA lancee";
    system("pause");
    int c=0;
    srand(time(NULL));
    pair<int,int> coordonnees_possibles;
    int lig=0;
    int col=0;
    vector< pair<int,int> > choixIA;
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            if (tab[i][j]=='N')
            {
                if ((tab[i+1][j]=='B')&&(tab[i-1][j]=='-'))
                tab[i-1][j]='X';
                ///system("pause");
                ///Sleep(3000);
                coordonnees_possibles.first=i-1;
                coordonnees_possibles.second=j;
                choixIA.push_back(coordonnees_possibles);

                if ((tab[i+1][j]=='-')&&(tab[i-1][j]=='B'))
               tab[i+1][j]='X';
                ///system("pause");
                ///Sleep(3000);
                coordonnees_possibles.first=i+1;
                coordonnees_possibles.second=j;
                choixIA.push_back(coordonnees_possibles);

                if ((tab[i-1][j-1]=='-')&&(tab[i+1][j+1]=='B'))
                tab[i-1][j-1]='X';
                ///system("pause");
                ///Sleep(3000);
                coordonnees_possibles.first=i-1;
                coordonnees_possibles.second=j-1;
                choixIA.push_back(coordonnees_possibles);

                if  ((tab[i+1][j+1]=='-')&&(tab[i-1][j-1]=='B'))
                tab[i+1][j+1]='X';
                ///system("pause");
                ///Sleep(3000);
                coordonnees_possibles.first=i+1;
                coordonnees_possibles.second=j+1;
                choixIA.push_back(coordonnees_possibles);

                if ((tab[i+1][j-1]=='-')&&(tab[i-1][j+1]=='B'))
                 tab[i+1][j-1]='X';
                 ///system("pause");
                ///Sleep(3000);
                coordonnees_possibles.first=i+1;
                coordonnees_possibles.second=j-1;
                choixIA.push_back(coordonnees_possibles);

                if ((tab[i-1][j+1]=='-')&&(tab[i+1][j-1]=='B'))
                tab[i-1][j+1]='X';
                ///system("pause");
                ///Sleep(3000);
                coordonnees_possibles.first=i-1;
                coordonnees_possibles.second=j+1;
                choixIA.push_back(coordonnees_possibles);

                if ((tab[i][j-1]=='-')&&(tab[i][j+1]=='B'))
                 tab[i][j-1]='X';
                 ///system("pause");
                ///Sleep(3000);
                coordonnees_possibles.first=i;
                coordonnees_possibles.second=j-1;
                choixIA.push_back(coordonnees_possibles);

                if ((tab[i][j+1]=='-')&&(tab[i][j-1]=='B'))
                 tab[i][j+1]='X';
                /// system("pause");
               /// Sleep(3000);
                coordonnees_possibles.first=i;
                coordonnees_possibles.second=j+1;
                choixIA.push_back(coordonnees_possibles);
            }
        }


    }
    /// Test stockage dans vector okk arbre des coups possibles pour l'ordinateur
    cout<< "les choix possibles pour l'ordinateur sont:"<<endl;

    cout<<" a partir des pions deja presents sur le plateau "<<endl;
    cout<<"  __________________________________________________________________________________________________________________"<<endl;
    for (int i=0;i<choixIA.size();i++)
    {
          if (((choixIA[i].first)== (choixIA[i+1].first))&&((choixIA[i].second)== (choixIA[i+1].second)))
          {
              cout<<" ";
          }
          else
          {
            cout<<" ("<<choixIA[i].first<<","<<choixIA[i].second<<")          ";
          }

    }
    cout<<endl;
    cout<<"  _________________________________________________________________________________________________________________"<<endl;
    system("pause");
    c=rand()%choixIA.size()-1;
    lig=choixIA[c].first;
    col=choixIA[c].second;
    this->poser_pion_IA(lig, col);

}

void Plateau::poser_pion_IA(int ligne, int colonne)
{


    int v=ligne-1;
    int w=(colonne-2)/2;

    tab[v][w]='B' ;
    if (tab[v+1][w]=='N')
        tab[v+1][w]='B';


    if (tab[v-1][w]=='N')
        tab[v-1][w]='B';


    if (tab[v+1][w+1]=='N')
        tab[v+1][w+1]='X';


    if  (tab[v-1][w-1]=='N')
        tab[v-1][w-1]='B';


    if (tab[v-1][w+1]=='N')
        tab[v-1][w+1]='B';


    if (tab[v+1][w-1]=='N')
        tab[v+1][w-1]='B';


    if (tab[v][w+1]=='N')
        tab[v][w+1]='B';


    if (tab[v][w-1]=='N')
        tab[v][w-1]='B';

}
=======
    }
}

>>>>>>> origin/master
