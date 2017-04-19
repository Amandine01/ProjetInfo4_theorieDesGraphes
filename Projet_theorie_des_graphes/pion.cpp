#include "pion.h"
#include <string>
/*
Pion::Pion(int nb_pion,char couleur_pion,int ligne_pion,char colonne_pion,bool presence_plateau)
    {
        ///m_nb_pion=_nb_pion;
        m_couleur_pion=couleur_pion;
        m_ligne_pion=ligne_pion;
        m_colonne_pion=colonne_pion;
        m_presence_plateau=presence_plateau;

    }*/
///Constructeur surchargé
Pion::Pion(char _couleur)
{
    m_couleur_pion=_couleur;
}
Pion::~Pion(){

    }

/*
///Accesseurs
int Pion::getLigne_pion(){
    return m_ligne_pion;
}

char Pion::getColonne_pion(){
    return m_colonne_pion;
}

bool Pion::getPresence_plateau(){
    return m_presence_plateau;
}

void Pion::setLigne_pion(int ligne_pion){
    m_ligne_pion = ligne_pion;
}

void Pion::setColonne_pion(char colonne_pion){
    m_colonne_pion = colonne_pion;
}

void Pion::setPresence_plateau(bool presence_plateau){
    m_presence_plateau = presence_plateau;
}*/
char Pion::getCouleur_pion()
{
    return m_couleur_pion;

}
void Pion::setCouleur_pion(char _couleur)
{
    m_couleur_pion=_couleur;
}
