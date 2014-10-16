/*
 * Personnage.cpp
 *
 *  Created on: 16 oct. 2014
 *      Author: rip
 */

#include "Personnage.h"

using namespace std;

Personnage::Personnage() : m_vie(100), m_mana(100), m_arme("Epée rouillée", 10, 0), m_nom("Gandhalf")
{
	// TODO Auto-generated constructor stub

}


Personnage::Personnage(string nomArme, int degatArmeMax, int degatArmeMin) : m_vie(100), m_mana(100), m_arme(nomArme, degatArmeMax, degatArmeMin), m_nom("Gandhalf")
{
	// TODO Auto-generated constructor stub

}

Personnage::Personnage(string nomPersonnage, string nomArme, int degatArmeMax, int degatArmeMin) : m_vie(100), m_mana(100), m_arme(nomArme, degatArmeMax, degatArmeMin), m_nom(nomPersonnage)
{
	// TODO Auto-generated constructor stub

}

Personnage::~Personnage()
{
	// TODO Auto-generated destructor stub


}

void Personnage::recevoirDegats(int nbDegats)
{
	cout << m_nom << " reçoit " << nbDegats << " de dégats" <<  endl;
	m_vie -= nbDegats;
	if(m_vie < 0)
	{
		m_vie = 0;
	}
}

void Personnage::attaquerAvecArme(Personnage &cible)
{
	cible.recevoirDegats(m_arme.getDegats());
}

void Personnage::attaquerAvecPouvoir(Personnage &cible)
{
	cible.recevoirDegats(m_pouvoir.getDegats());
}

void Personnage::boirePotionDeVie(int quantitePotion)
{
	cout << m_nom << " boit une potion qui lui rend " << quantitePotion << " de points de vie" << endl;
	m_vie += quantitePotion;
	if(m_vie > 100)
	{
		m_vie = 100;
	}
}

void Personnage::changerArme(std::string nomNouvelleArme, int degatsMaxNouvelleArme, int degatsMinNouvelleArme)
{
	cout << m_nom << " change d'arme! " <<  endl;
	m_arme.changer(nomNouvelleArme, degatsMaxNouvelleArme, degatsMinNouvelleArme);
}

bool Personnage::estVivant()
{
	return m_vie > 0;
}

void Personnage::afficherEtat() const
{
	cout << "Vie : " << m_vie << endl;
	cout << "Mana : " << m_mana << endl;
	m_arme.afficher();
}

string Personnage::getNom() const
{
	return m_nom;
}



