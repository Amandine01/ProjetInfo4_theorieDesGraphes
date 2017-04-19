#include <vector>
#include "plateau.h"
#include "pion.h"
#include<iostream>
#include <string>
#include <cstdlib>
#include "console.h"
#include <cstdio>
#include <fstream>

Plateau::Plateau()
{
std::cout<<"le plateau a bien ete cree"<<std::endl;
}

// Destructeur
Plateau::~Plateau(){
}

void Plateau::initialiser_plateau()
{
      Pion pion_noir('N');
      Pion pion_blanc('B');
      std::vector<std::vector<Pion> > p;

   for(int i=0;i<8;i++)
   {
       std::vector<Pion> t;

         for(int j=0;j<8;j++)
       {
           t.push_back(i);
       }
       p.push_back(t);
   }
   std::cout<<" ABCDEFGH"<<std::endl;
   for (int i=0;i<p.size();i++)
   {
       std::cout<<i+1;
       for(int j=0;j<p[i].size();j++)
       {
          if((i==4)&(j==4)||(i==3)&(j==3))
          {
            std::cout<<pion_noir.getCouleur_pion();
          }
          else if ((i==4)&(j==3)||(i==3)&(j==4))
          {
             std::cout<<pion_blanc.getCouleur_pion();
          }
          else
          {
              std::cout<<"-";
          }
       }
       std::cout<<std::endl;
   }

}
void Plateau::menu_jeu()
{
    int m_choix_menu;
    bool m_sortie_menu;
    bool m_sortie;
    ///Affiche le menu
    std::cout << "1- Pour jouer à deux joueur" << std::endl;
    std::cout << "2- Pour jouer contre l'ordinateur" << std::endl;
    std::cout << "3- Personnaliser votre partie." << std::endl;
    std::cout << "4- Pour connaitre les regles du jeu" << std::endl << std::endl;
    std::cout << "5- Quitter" << std::endl << std::endl;
    std::cout << "Rentrer la valeur de votre choix : ";
    //Rentre la valeur voulu par le menu
    std::cin >> m_choix_menu;
    std::cout << std::endl << std::endl;

    //applique le choix rentree
    if(m_choix_menu == 1){
        m_sortie_menu = 1;
        system("cls");
        this->initialiser_plateau();
        this->deplacer_curseur();


    }
    if(m_choix_menu == 2){
        //Message d'erreur
        std::cout << "Pas implemente" << std::endl << std::endl;
    }
    if(m_choix_menu == 3){
        m_sortie_menu = 1;
        //On va allouer et choisir la valeur pour un plateau pimp
        int nbrJoueur, nbrPions, nbrColonne, nbrLigne;
        std::cout << "Rentrer le nombre de Joueur : ";
        std::cin >> nbrJoueur;
        std::cout << "Rentrer le nombre de pions par Joueur : ";
        std::cin >> nbrPions;
        std::cout << "Rentrer le nombre de Colonne : ";
        std::cin >> nbrColonne;
        std::cout << "Rentrer le nombre de Ligne : ";
        std::cin >> nbrLigne;
        //On initialise la partie avec les valeurs precedemment rentrée
        ///this->initialisation_partie(nbrJoueur, nbrPions,nbrColonne, nbrLigne);
        this->initialiser_plateau();
    }
    if(m_choix_menu == 4){
        this->pageAccueil();
    }
    else{
        system("cls");
        std::cout << "Votre choix n'existe pas" << std::endl;
        //inserer la detection de touche
    }

    system("cls");
    std::cout << "lejeu se lance";
    if(m_choix_menu == 5){
            this->pageSortie();
    }
}


void Plateau::Display()
{

}

void Plateau::deplacer_curseur()
{

bool quit = false;
    Console* pConsole = NULL;

    // Alloue la mémoire du pointeur
    pConsole = Console::getInstance();
    int lig,col;
    lig=4;
    col=4;
    // Affichage avec gotoligcol et couleur
    pConsole->gotoLigCol(lig,col);

    pConsole->setColor(COLOR_DEFAULT);

    // Boucle événementielle
    while (!quit)
    {
        // Si on a appuyé sur une touche du clavier
        if (pConsole->isKeyboardPressed())
        {
            // Récupère le code ASCII de la touche
            char key = pConsole->getInputKey();

            switch(key)
            {
            case 'q':
                col--;
                break;

            case 'd':
                col++;
                break;

            case 'z':
                lig--;
                break;

            case's':
                lig++;
                break;
            }


            ///q est la touche directionnelle permettant daller vers la gauche
            /*if (key==115)/// code ascii de la lettre q
                pConsole->gotoLigCol(x-1,y);
            if (key==122)/// code ascii de la lettre d
                pConsole->gotoLigCol(x+1,y);
             if (key==113)/// code ascii de la lettre z
                pConsole->gotoLigCol(x,y+1);
            if (key==100)/// code asciide la lettre s
                pConsole->gotoLigCol(x,y-1);
            //if (key==27)
                 //pConsole->gotoLigCol(x,y);
                 //std::cout<< "N";*/

            if (key == 'a' ) // 27 = touche escape
            {
                quit = true;
            }
        }
    }

    // Libère la mémoire du pointeur !
    Console::deleteInstance();
}

//Méthodes affichant des pages de jeu
void Plateau::pageAccueil(){

    system("cls");

    std::ifstream presentation("presentation.txt");
    if(presentation)
    {
        // On stock dans la chaine le fichier
        std::string texte;

        // Tant qu'on a pas atteint la fin de regles.txt
        while(getline(presentation,texte))
        {
            // On affiche les règles du jeu
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

void Plateau::pageVictoire(){
    std::cout << "Bien joue!" << std::endl << std::endl;
    ///Affiche la page de victoire
    ///this->DetectionTouche();
    system("cls");
}

void Plateau::pageSortie(){
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

