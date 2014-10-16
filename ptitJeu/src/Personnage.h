/*
 * Personnage.h
 *
 *  Created on: 16 oct. 2014
 *      Author: rip
 */

#ifndef PERSONNAGE_H_
#define PERSONNAGE_H_

#include <iostream>
#include "Arme.h"
#include "Pouvoir.h"

class Personnage
{
	public:

	Personnage();
	Personnage(std::string nomArme, int degatArmeMax, int degatArmeMin);
	Personnage(std::string nomPersonnage, std::string nomArme, int degatArmeMax, int degatArmeMin);
	virtual ~Personnage();

    void recevoirDegats(int nbDegats);
    void attaquerAvecArme(Personnage &cible);
    void attaquerAvecPouvoir(Personnage &cible);
    void boirePotionDeVie(int quantitePotion);
    void changerArme(std::string nomNouvelleArme, int degatsMaxNouvelleArme, int degatsMinNouvelleArme);
    bool estVivant();
    void afficherEtat() const;
    std::string getNom() const;

    private:
    int m_vie;
    int m_mana;
    Arme m_arme;
    Pouvoir m_pouvoir;
    std::string m_nom;
};

#endif /* PERSONNAGE_H_ */
