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
///Constructeur plateau
Plateau::Plateau()
{
    /// Ressources
    m_lig=4;
    m_col=4;

    /// Creation du plateau (double for pour un tableau en 2D)
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            tab[i][j]='-';
        }
    }
    /// Initialisation des cases de la situation initiale
    tab[3][3]= 'B';
    tab[4][4]= 'B';
    tab[3][4]= 'N';
    tab[4][3]= 'N';
}

///Destructeur plateau
Plateau::~Plateau()
{

}

///Affichage plateau
void Plateau::Display()
{
    /// Ressources
    Console* pConsole = NULL;

    /// Affichage tableau
    /// affichage des chiffres
    pConsole->setColor(COLOR_RED);
    cout<<"  a b c d e f g h"<<endl;

    ///Double boucle for pour un tableau en 2D
    for(int i=0; i<8; i++)
    {
        /// Afficher les chiffres
        pConsole->setColor(COLOR_RED);
        cout<<i+1<<" ";

        for(int j=0; j<8; j++)
        {
            if(tab[i][j] == 'N') ///Afficher les pions noirs
            {
                pConsole->setColor(COLOR_BLACK);
                cout << tab[i][j] << " " ;
            }
            else
            {
                if(tab[i][j] == 'B') ///Afficher les pions blancs
                {
                    pConsole->setColor(COLOR_WHITE);
                    cout << tab[i][j] << " " ;
                }
                else
                {
                    pConsole->setColor(COLOR_GREEN);
                    cout << tab[i][j] << " " ; ///Afficher les cases vides
                }

            }
        }
        pConsole->setColor(COLOR_DEFAULT);
        cout<<endl;
    }
    pConsole->gotoLigCol(15,0);
    cout << "Appuyer sur echap pour sauvegarder et quitter" << endl;
}

void Plateau :: sauvegarder_partie()
{
    /// Sauvegarde
    // Ouverture du fichier en écriture avec effacement du fichier ouvert
    ofstream fichier("sauvegarde.txt", ios::out | ios::trunc);

        if(fichier)
        {
            for(int i=0; i<8; i++)
            {
                for(int j=0; j<8; j++)
                {
                    fichier << tab[i][j];
                }
                fichier << endl;
            }

            // Fermer ficher
            fichier.close();
        }
        else
                cerr << "Impossible d'ouvrir le fichier !" << endl;

}

void Plateau :: charger_partie()
{
    // Ouverture du fichier
    std::ifstream presentation("sauvegarder.txt",ios::in);
    if(presentation)
    {
        for(int i=0; i<8; i++)
        {
            for(int j=0; j<8; j++)
            {
                // Ecrire dans le tableau
                presentation >> tab[i][j];
            }
        }
    }
}

///Boucle de jeu (joueur contre joueur)
void Plateau::Bouclejeu()
{
    /// Afficher le plateau
    this->Display();

    ///Variable tour qui s'incrémentera pour décider de l'ordre des joueurs
    int turn=0;

    ///Variable de condition de boucle while
    int z=5;

    /// Pointeur sur console
    Console* pConsole = NULL;

    /// Allouer la mémoire du pointeur
    pConsole = Console::getInstance();

    ///Boucle de jeu
    while(z==5)
    {

        if (turn%2==0) ///JOUEUR NOIR
        {
            if(pConsole->isKeyboardPressed()) ///Si on appuie sur une touche
            {


                /// Afficher les croix des cases possibles
                this->case_possible(turn);

                ///Fonction condition de fin qui sera toujours appelé, pour vérifier s'il n'y a plus de cases possibles
                this->condition_de_fin();

                /// Effacer l'ecran
                system("cls");

                /// Afficher le plateau
                this->Display();

                /// Variable deplacement
                char dep = pConsole->getInputKey();

                /// Deplacer le curseur
                this->deplacer_curseur(dep, m_lig, m_col,turn);

                /// Effacer l'ecran
                system("cls");

                /// Effacer cases possibles
                this->effacer_case_possible();

                /// Afficher le plateau
                this->Display();

                /// Afficher le joueur suivant
                pConsole->gotoLigCol(3,20);
                cout << "C'est au tour des pions blancs de jouer." << endl;
                pConsole->gotoLigCol(4,20);
                cout << "Les X representent les cases ou vous pouvez poser votre pion." << endl;
                pConsole->gotoLigCol(5,20);
                cout << "Pour valider votre choix appuyer sur entree." << endl;
                pConsole->gotoLigCol(7,20);
                cout << "Appuyez sur une touche pour continuer." << endl;

                /// Incrementation de turn
                turn++;
            }
        }


        if (turn%2==1) ///JOUEUR BLANC
        {

            if(pConsole->isKeyboardPressed())
            {
                /// Afficher les croix des cases possibles
                this->case_possible(turn);

                ///Fonction condition de fin qui sera toujours appelé, pour vérifier s'il n'y a plus de cases possibles
                this->condition_de_fin();

                /// Effacer l'ecran
                system("cls");

                /// Afficher le plateau
                this->Display();

                /// Variable deplacement
                char dep = pConsole->getInputKey();

                /// Deplacer le curseur
                this->deplacer_curseur(dep, m_lig, m_col,turn);

                /// Effacer l'ecran
                system("cls");

                /// Effacer cases possibles
                this->effacer_case_possible();

                /// Afficher le plateau
                this->Display();

                /// Afficher le joueur suivant
                pConsole->gotoLigCol(3,20);
                cout << "C'est au tour des pions noirs de jouer." << endl;
                pConsole->gotoLigCol(4,20);
                cout << "Les X representent les cases ou vous pouvez poser votre pion." << endl;
                pConsole->gotoLigCol(5,20);
                cout << "Pour valider votre choix appuyer sur entree." << endl;
                pConsole->gotoLigCol(7,20);
                cout << "Appuyez sur une touche pour continuer." << endl;

                /// Incrementation de turn
                turn++;
            }
        }
    }///Fin boucle while

    Console::deleteInstance();
}

///Fonction montrant les choix possibles pour le joueur
void Plateau::case_possible (int turn)
{
    ///Variables
    pair<int,int> coordonnees_possibles;

    if (turn%2==0)/// joueur noir
    {
        for(int i=0; i<8; i++) ///Double for pour les tableaux en 2D
        {
            for(int j=0; j<8; j++)
            {
                if (tab[i][j]=='B')
                {
                    if ((tab[i+1][j]=='N')&&(tab[i-1][j]=='-')) ///Vérification de la case au dessus et en dessous
                        tab[i-1][j]='X';


                    if ((tab[i+1][j]=='-')&&(tab[i-1][j]=='N')) ///Vérification de la case au dessus et en dessous
                        tab[i+1][j]='X';

                    if ((tab[i-1][j-1]=='-')&&(tab[i+1][j+1]=='N')) ///Vérification des cases en diagonale (haut gauche, bas droite)
                        tab[i-1][j-1]='X';

                    if  ((tab[i+1][j+1]=='-')&&(tab[i-1][j-1]=='N')) ///Vérification des cases en diagonale (haut gauche, bas droite)
                        tab[i+1][j+1]='X';

                    if ((tab[i+1][j-1]=='-')&&(tab[i-1][j+1]=='N')) ///Vérification des cases en diagonale (bas gauche, haut droite)
                        tab[i+1][j-1]='X';

                    if ((tab[i-1][j+1]=='-')&&(tab[i+1][j-1]=='N')) ///Vérification des cases en diagonale (bas gauche, haut droite)
                        tab[i-1][j+1]='X';

                    if ((tab[i][j-1]=='-')&&(tab[i][j+1]=='N')) ///Vérification de la case à gauche et à droite
                        tab[i][j-1]='X';

                    if ((tab[i][j+1]=='-')&&(tab[i][j-1]=='N')) ///Vérification de la case à gauche et à droite
                        tab[i][j+1]='X';

                }
            }
        }


    }///Fin du if turn joueur noir

    if (turn%2==1)///joueur blanc
    {
        for(int i=0; i<8; i++)///Double for pour les tableaux en 2D
        {
            for(int j=0; j<8; j++)
            {
                if (tab[i][j]=='N')
                {
                    if ((tab[i+1][j]=='B')&&(tab[i-1][j]=='-')) ///Identique au joueur blanc
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
    }///Fin du if joueur blanc
}

///Fonction effaçant les choix possibles pour le joueur
void Plateau::effacer_case_possible()
{
    for(int i=0; i<8; i++) ///Double for pour les tableaux en 2D
    {
        for(int j=0; j<8; j++)
        {
            if (tab[i][j]=='X')
            {
                tab[i][j]='-'; ///Les cases avec des X redeviennent vide
            }
        }
    }
}

///Fonction permettant de poser un pion
void Plateau::poser_pion(int turn,int ligne, int colonne)
{
    ///Variables
    int v=ligne-1; ///calcul nécessaire pour les vraies dimensions de notre tableau visuellement
    int w=(colonne-2)/2; ///calcul nécessaire pour les vraies dimensions de notre tableau visuellement

    if (turn%2==0)///Joueur noir
    {
        tab[v][w]='N' ;
        retournement(turn,v,w); ///Fonction retournement des pions
        system("cls");
        Display();

    }
    if (turn%2==1)///Joueur blanc
    {
        tab[v][w]='B' ;
        retournement(turn,v,w); ///Fonction retournement des pions
        system("cls");
        Display();
    }
}

///Fonction qui permet de voir s'il n'y a plus de cas possible
void Plateau::condition_de_fin()
{
    /// Pointeur sur console
    Console* pConsole = NULL;

    /// Allouer la mémoire du pointeur
    pConsole = Console::getInstance();

    ///Variable
    int compteurX=0; ///Compteur d'incrémentation


    for(int i=0; i<8; i++) ///Double for pour les tableaux en 2D
    {
        for (int j=0; j<8; j++)
        {
            if (tab[i][j]=='X')
            {
                compteurX++; ///Incrémentation si on trouve un X
                //cout<<compteurX<<endl;
            }
        }
    }

    if (compteurX==0) ///Si notre compteur est égal à 0, donc s'il n'y a plus de choix possibles
    {
        system("cls");
        cout<<"Plus aucun coup n'est possible."<<endl;
        system("pause");
        system("cls");
        this->comptage_points(); ///Appel de la fonction comptage de points
    }

    Console::deleteInstance();
}

///Fonction du menu de jeu
void Plateau::menu_jeu()
{
    ///Variables
    int m_choix_menu; ///Variable du switch
    int a=1; ///Variable de sortie de la boucle

    while (a!=2)
    {
        ///Affiche le menu

        cout << "Voulez-vous :" << endl << endl;
        cout << "1 - Jouer a deux joueur" << endl << endl;
        cout << "2 - Jouer contre l'ordinateur" << endl << endl;
        cout << "3 - Charger une partie" <<endl << endl;
        cout << "4 - Sauvegarder une partie"<<endl << endl;
        cout << "5 - Connaitre les regles du jeu" << endl << endl;
        cout << "6 - Quitter" << endl << endl << endl;
        cout << "Rentrer la valeur de votre choix : ";

        ///Rentre la valeur voulu
        cin >> m_choix_menu;
        cout << endl << endl;

        switch(m_choix_menu)
        {
        case 1:
            system("cls");
            Plateau::Bouclejeu(); ///Appel de la boucle de jeu
            break;
        case 2:
        {
            system("cls");
            Bouclejeu_IA(); ///Appel de la boucle de jeu IA
            break;
        }

        case 3:
        {
            system("cls");
            this->charger_partie();
            this->Bouclejeu();
            break;
        }

        case 4:
        {
            system("cls");
            cout<<"sauvegarder une partie "<<endl;
            break;
        }

        case 5:
        {
            system("cls");
            ///Affichage des règles
            cout<<"Regles de jeu :"<<endl<<endl<<endl;
            cout<<"Deroulement de la partie :"<<endl<<endl;
            cout<<"Poser un pion --> Ou ? : Sur une case vide adjacente a un pion adverse."<<endl;
            cout<<"              --> Comment ? : Le joueur doit encadrer 1 ou plusieurs pions"<<endl;
            cout<<"adverses (dans 1 des 8 directions) entre le pion qu'il pose"<<endl;
            cout<<"et un pion de sa couleur. Ensuite, le joueur retourne le ou les pions"<<endl;
            cout<<"qu'il vient d'encadrer afin que ces derniers soient de sa couleur."<<endl;
            cout<<"Attention : Il n'y a pas de reaction en chaine, les pions retournes"<<endl;
            cout<<"ne peuvent pas servir a en retourner d'autres lors du meme tour de jeu."<<endl<<endl;
            cout<<"Deplacement :"<<endl<<endl;
            cout<<"Haut : z, Bas : s, Droite : d, Gauche : q, Valider : entree"<<endl<<endl;
            cout<<"Fin de la partie :"<<endl<<endl;
            cout<<"Les 2 joueurs ne peuvent plus poser de pions. Le Vainqueur est celui"<<endl;
            cout<<"qui a le plus grand nombre de pions sur l'Othellier."<<endl;
            cout<<"Les cases vides sont donnees au vainqueur."<<endl<<endl;

            system("pause");
            system("cls");
//            if (getch()==27)
//            {
//                system("cls");
//                a=1;
//                m_choix_menu=0;
//            }
            break;

        }

        case 6:
        {
            a=2;
            break;
        }

        default :
        {
            system("cls");
            cout<<"Cette option n'existe pas"<<endl;
            system("pause");
            break;
        }
        }


    }
}

///Fonction de déplacement de curseur
void Plateau::deplacer_curseur(char dep, int m_lig, int m_col,int turn)
{
    /// Ressources
    Console* pConsole = NULL;
    int ligne=0, colonne=0; ///similaire à x et y
    char c = 0; ///Variable d'entrée pour le switch
    int d = 1; ///Variable de condition de sortie de boucle while


    /// Alloue la mémoire du pointeur
    pConsole = Console::getInstance();

    /// Affichage avec gotoligcol et couleur
    pConsole->gotoLigCol(20, 0);
    pConsole->setColor(COLOR_DEFAULT);

    /// Boucle événementielle
    while (d!=2)
    {

        /// Blindage des bords du plateau
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

        /// Si on a appuyé sur une touche du clavier
        if (pConsole->isKeyboardPressed())
        {

            c = pConsole->getInputKey();


            switch(c)
            {
            case 'z':  ///Monter
                ligne--;
                break;
            case 's': ///Descendre
                ligne++;
                break;
            case 'q': ///Gauche
                colonne = colonne-2; ///Incrémentation par 2, venant du fait de l'affichage spécial de notre tableau
                break;
            case 'd': ///Droite
                colonne = colonne+2;///Incrémentation par 2, venant du fait de l'affichage spécial de notre tableau
                break;
            case 27:
                sauvegarder_partie();
                system("cls");
                menu_jeu();
                break;
            case 13 : ///Entrée
                if (tab[ligne-1][(colonne-2)/2]!='X') ///Calcul dépendant de l'affichage de notre tableau
                {
                    pConsole->gotoLigCol(3, 20);
                    cout << "Vous ne pouvez pas posez de pion ici."<<endl;
                    pConsole->gotoLigCol(4,20);
                    system("pause");
                    system("cls");
                    Display();
                }
                else
                {
                    this->poser_pion(turn,ligne,colonne); ///Appel de la fonction poser pion
                    d=2;
                }
                break;

            default:  ///Pour blinder les autres touches
                break;
            }

        }

        pConsole->gotoLigCol(ligne, colonne); ///Pour que le curseur soit à la position voulue
    }

    /// Libère la mémoire du pointeur !
    Console::deleteInstance();

}

void Plateau :: page_victoire()
{
    // Effacer l'ecran
    system("cls");

    std::ifstream presentation("page_victoire.txt");
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
}

void Plateau::pageAccueil()
{
    /// effacer l'ecran
    system("cls");

    std::ifstream presentation("presentation.txt");
    if(presentation)
    {
        /// On stock dans la chaine le fichier
        std::string texte;

        /// Tant qu'on a pas atteint la fin de regles.txt
        while(getline(presentation,texte))
        {
            /// On affiche les regles du jeu
            std::cout << texte << std::endl;
        }
    }

    /// Blindage ouverture du fichier
    else
    {
        std::cout << "Erreur fichier presentation" << std::endl;
    }

    system("PAUSE");
    system("cls");
}

//void Plateau::pageSortie()
//{
//    std::cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl << std::endl;
//    std::cout << "                                                 " << std::endl << std::endl;
//    std::cout << "                                                 " << std::endl << std::endl;
//    std::cout << "                                                 " << std::endl << std::endl;
//    std::cout << "                                                 " << std::endl << std::endl;
//    std::cout << "              MERCI D'ETRE VENU                  " << std::endl << std::endl;
//    std::cout << "          A BIENTOT POUR DE NOUVELLES            "<<std::endl;
//    std::cout << "                                                 "<<std::endl;
//    std::cout << "                    :)                           "<<std::endl;
//    std::cout << "                                                 "<<std::endl;
//    std::cout << "                                                 "<<std::endl;
//    std::cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl << std::endl;
//    ///Affiche la page de victoire
//    ///this->DetectionTouche();
//    system("cls");
//}

///Fonction pour compter les points lorsque le jeu est fini
void Plateau::comptage_points()
{
    ///Variables
    int points_noir=0;
    int points_blanc=0;
    int difference1=0;
    int difference2=0;
    int points_supp=0; ///Représente les cases vides


    for (int i=0; i<8; i++)///double for pour les tableaux en 2D
    {
        for (int j=0; j<8; j++)
        {
            if (tab[i][j]=='B')
            {
                points_blanc++;///On incrémente les points blancs lorsqu'on tombe sur un pion blanc
            }
            if (tab[i][j]=='N')
            {
                points_noir++; ///On incrémente les points noirs lorsqu'on tombe sur un pion noir
            }
            if (tab[i][j]=='-')
            {
                points_supp++; ///On incrémente les points supplémentaires lorsque l'on tombe sur une case vide
            }
        }
    }
    difference1=points_blanc-points_noir;
    difference2=points_noir-points_blanc;
//    pConsole->gotoLigCol(3,20);
//    system("cls");
    cout<<"Le joueur noir a "<<points_noir<<"points."<<endl;
//    pConsole->gotoLigCol(4,20);
//    system("cls");
    cout<<"Le joueur blanc a "<<points_blanc<<"points."<<endl;
    cout<<"De plus, il y a "<<points_supp<<"cases vides qui vont au vainqueur."<<endl;
    if (points_noir<points_blanc)
    {
//        pConsole->gotoLigCol(5,20);
//        system("cls");
        cout<<"Le joueur blanc a donc gagne de "<<difference1<<"points."<<endl;
//        pConsole->gotoLigCol(6,20);
//        system("cls");
        cout<<"Le score total est donc de :"<<endl;
        cout<<" "<<points_blanc+points_supp<<" (blanc) a "<<points_noir<<" (noir)."<< endl<<endl<<endl;

    }
    if (points_noir>points_blanc)
    {
//        pConsole->gotoLigCol(5,20);
//        system("cls");
        cout<<"Le joueur noir a donc gagne de "<<difference2<<"points."<<endl;
//        pConsole->gotoLigCol(6,20);
//        system("cls");
        cout<<"Le score total est donc de :"<<endl;
        cout<<" "<<points_noir+points_supp<<" (noir) a"<<points_blanc<<" (blanc)."<< endl<<endl<<endl;
    }

    if (points_noir==points_blanc)
    {
        cout<<"C'est une egalite."<<endl<<endl<<endl;
    }

    system("pause");
    system("cls");

    menu_jeu();

    Console::deleteInstance();
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
                this->condition_de_fin();
                system("cls");
                this->Display();
                char dep=pConsole->getInputKey();
                this->deplacer_curseur(dep, m_lig, m_col,turn);
                system("cls");
                this->effacer_case_possible();
                this->Display();
                turn++;

            }
            Console::deleteInstance();
        }


        if (turn%2==1) ///IA
        {

            this->case_possible_IA();
            this->condition_de_fin();
            system("cls");
            this->Display();
            ///system("cls");
            ///this->effacer_case_possible();
            ///this->Display();
            turn++;

        }
    }

}

void Plateau::case_possible_IA()
{
    cout<<"L'IA reflechit..."<<endl;
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
                {
                    tab[i-1][j]='X';
                    ///system("pause");
                    ///Sleep(3000);
                    coordonnees_possibles.first=i-1;
                    coordonnees_possibles.second=j;
                    choixIA.push_back(coordonnees_possibles);
                }


                if ((tab[i+1][j]=='-')&&(tab[i-1][j]=='B'))

                {
                    tab[i+1][j]='X';
                    ///system("pause");
                    ///Sleep(3000);
                    coordonnees_possibles.first=i+1;
                    coordonnees_possibles.second=j;
                    choixIA.push_back(coordonnees_possibles);

                }


                if ((tab[i-1][j-1]=='-')&&(tab[i+1][j+1]=='B'))
                {
                    tab[i-1][j-1]='X';
                    ///system("pause");
                    ///Sleep(3000);
                    coordonnees_possibles.first=i-1;
                    coordonnees_possibles.second=j-1;
                    choixIA.push_back(coordonnees_possibles);
                }


                if  ((tab[i+1][j+1]=='-')&&(tab[i-1][j-1]=='B'))
                {
                    tab[i+1][j+1]='X';
                    ///system("pause");
                    ///Sleep(3000);
                    coordonnees_possibles.first=i+1;
                    coordonnees_possibles.second=j+1;
                    choixIA.push_back(coordonnees_possibles);
                }


                if ((tab[i+1][j-1]=='-')&&(tab[i-1][j+1]=='B'))
                {
                    tab[i+1][j-1]='X';
                    ///system("pause");
                    ///Sleep(3000);
                    coordonnees_possibles.first=i+1;
                    coordonnees_possibles.second=j-1;
                    choixIA.push_back(coordonnees_possibles);
                }


                if ((tab[i-1][j+1]=='-')&&(tab[i+1][j-1]=='B'))
                {
                    tab[i-1][j+1]='X';
                    ///system("pause");
                    ///Sleep(3000);
                    coordonnees_possibles.first=i-1;
                    coordonnees_possibles.second=j+1;
                    choixIA.push_back(coordonnees_possibles);
                }


                if ((tab[i][j-1]=='-')&&(tab[i][j+1]=='B'))
                {
                    tab[i][j-1]='X';
                    ///system("pause");
                    ///Sleep(3000);
                    coordonnees_possibles.first=i;
                    coordonnees_possibles.second=j-1;
                    choixIA.push_back(coordonnees_possibles);
                }


                if ((tab[i][j+1]=='-')&&(tab[i][j-1]=='B'))
                {
                    tab[i][j+1]='X';
                    /// system("pause");
                    /// Sleep(3000);
                    coordonnees_possibles.first=i;
                    coordonnees_possibles.second=j+1;
                    choixIA.push_back(coordonnees_possibles);
                }

            }
        }


    }
    /// Test stockage dans vector okk arbre des coups possibles pour l'ordinateur
    cout<< "les choix possibles pour l'ordinateur sont :"<<endl;

    cout<<" a partir des pions deja presents sur le plateau "<<endl;
    cout<<"  __________________________________________________________________________________________________________________"<<endl;

    cout<<" |                   |                |                  |                          |                       "<<endl;
    for (unsigned int i=0; i<choixIA.size(); i++)
    {
        if (((choixIA[i].first)== (choixIA[i+1].first))&&((choixIA[i].second)== (choixIA[i+1].second)))
        {
            cout<<"  ";
        }
        else
        {

            cout<<" ("<<choixIA[i].first<<","<<choixIA[i].second<<")          ";
        }

    }

    cout<<"  _________________________________________________________________________________________________________________"<<endl;
    system("pause");
    c=rand()%choixIA.size()-1;
    lig=choixIA[c].first;
    col=choixIA[c].second;
    this->poser_pion_IA(lig, col);


}

void Plateau::poser_pion_IA(int ligne, int colonne)
{

    int turn=1;
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

    this->retournement(turn,v,w);

}



void Plateau::retournement(int turn, int v, int w)
{
    char allie;
    if (turn%2==0)
    {
        allie='N';
    }
    if(turn%2==1)
    {
        allie='B';
    }


    for(int i= v+1; i<8; i++)// a bas
    {
        if(tab[i][w] == '-')
        {
            break;
            i=9;
        }
        else if(tab[i][w] == allie) ///Si t'as un symbole pareil que celui que tu poses sur la ligne en dessous
        {
            for(int j= i-1; j>v; j--)
            {
                tab[j][w]= allie;

            }
        }
    }
    for(int i= v-1; i>-1; i--)// a haut
    {
        if(tab[i][w] == '-')
        {
            break;
            i= -3;
        }
        else if(tab[i][w] == allie)
        {
            for(int j= i+1; j<v; j++)
            {
                tab[j][w]= allie;

            }
        }
    }
    for(int i= w-1; i>-1; i--)// en gauche
    {
        if(tab[v][i] == '-')
        {
            break;
            i= -3;
        }
        else if(tab[v][i] == allie)
        {
            for(int j= i+1; j<w; j++)
            {
                tab[v][j]= allie;

            }
        }
    }
    for(int i= w+1; i<8; i++)// en droite
    {
        if(tab[v][i] == '-')
        {
            break;
            i=9;
        }
        else if(tab[v][i] == allie)
        {
            for(int j= i-1; j>w; j--)
            {
                tab[v][j]= allie;

            }
        }
    }
//    int z=1;
//    while(v-z < 6|| v-z > -2 || w-z < 6 || w-z> -2)// diagonale haut gauche (c'est les bords)
//    {
//
//        if(tab[v-z][w-z] == '-')
//        {
//            break;
//            i=9;
//        }
//        else if(tab[v-z][w-z] == allie)
//        {
//            int j=1;
//            while(v-z+j != v && w-z+j != w)
//            {
//                tab[v-z+j][w-z+j]= allie;
//                j++;
//            }
//        }
//        z++;
//    }
//
//
//    int k=1;
//    while(v+k < 6 || v+k > -2 || w-k < 6 || w-k> -2) ///Diagonale bas droite
//    {
//
//        if(tab[v+k][w+k] == '-')
//        {
//            break;
//            k=9;
//        }
//        else if(tab[v+k][w+k] == allie)
//        {
//            int j=1;
//            while(v+k-j != v && w+k-j != w)
//            {
//                tab[v+k-j][w+k-j]= allie;
//                j++;
//            }
//        }
//        k++;
//    }
//
//
//    int a=1;
//
//    while(v-a < 6 || v-a > -2 || w+a < 6 || w+a> -2) ///Diagonale haut droite
//    {
//
//        if(tab[v-a][w+a] == '-')
//        {
//            break;
//            a=9;
//        }
//        else if(tab[v-a][w+a] == allie)
//        {
//            int j=1;
//            while(v-a+j != v && w+a-j != w)
//            {
//                tab[v-a+j][w+a-j]= allie;
//                j++;
//            }
//        }
//        a++;
//    }
//
//
//
//int b=1;
//    while(v+b < 6 || v+b > -2 || w-b < 6 || w-b> -2)// diagonale bas gauche
//    {
//
//        if(tab[v+b][w-b] == '-')
//        {
//            break;
//            b=9;
//        }
//        else if(tab[v+b][w-b] == allie)
//        {
//            int j=1;
//            while(v+b-j != v && w-b+j != w)
//            {
//                tab[v+b-j][w-b+j]= allie;
//                j++;
//            }
//        }
//        b++;
//    }
}
