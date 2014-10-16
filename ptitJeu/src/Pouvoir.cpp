/*
 * Pouvoir.cpp
 *
 *  Created on: 16 oct. 2014
 *      Author: rip
 */

#include "Pouvoir.h"

using namespace std;

Pouvoir::Pouvoir() : m_nom("Boule de feu"), m_degatsMax(10), m_degatsMin(0), m_derniersDegats(0)
{
	// TODO Auto-generated constructor stub

}

Pouvoir::Pouvoir(string nom, int degatsMax, int degatsMin) : m_nom(nom), m_degatsMax(degatsMax), m_degatsMin(degatsMin), m_derniersDegats(0)
{
	// TODO Auto-generated constructor stub

}



Pouvoir::~Pouvoir()
{
	// TODO Auto-generated destructor stub
}


int Pouvoir::getDegats()
{
	srand(time(0));
	m_derniersDegats =  (rand() % (m_degatsMax - m_degatsMin)) + m_degatsMin;
	return m_derniersDegats;
}

void Pouvoir::changerPouvoir(std::string nom, int degatsMax, int degatsMin)
{
	m_nom = nom;
	m_degatsMax = degatsMax;
	m_degatsMin = degatsMin;
}

