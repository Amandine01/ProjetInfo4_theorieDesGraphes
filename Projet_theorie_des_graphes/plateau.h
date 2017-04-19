#ifndef PLATEAU_H_INCLUDED
#define PLATEAU_H_INCLUDED

#include <vector>
#include "pion.h"
#include "console.h"
#include <conio.h>
#include <windows.h>

class Plateau
{
private:
    std::vector <Pion> m_plateau;

public:
    // Constructeurs
    Plateau();
    Plateau(std::vector <Pion> _plateau);

    // Destructeur
    ~Plateau();

    // Methodes
    void afficher_plateau();

    // Accesseurs
    std::vector <Pion> getPlateau();

    void setPlateau(std::vector <Pion> plateau);
};

#endif // PLATEAU_H_INCLUDED
