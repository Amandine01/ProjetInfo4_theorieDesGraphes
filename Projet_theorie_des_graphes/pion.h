#ifndef PION_H_INCLUDED
#define PION_H_INCLUDED

class Pion
{
private:
    std::string m_couleur;
    int m_nb_pion;

public:
    // Constructeurs
    Pion();
    Pion(std::string _couleur, int _nb_pion);

    // Destructeur
    ~Pion();

    // Methodes
    void afficher_pion();
    bool poser_pion();

    // Accesseurs
    std::string getCouleur();
    int getNb_pion();

    void setCouleur(std::string couleur);
    void setNb_pion(int nb_pion);
};

#endif // PION_H_INCLUDED
