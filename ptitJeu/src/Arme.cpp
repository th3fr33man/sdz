/*
 * Arme.cpp
 *
 *  Created on: 16 oct. 2014
 *      Author: rip
 */

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Arme.h"
using namespace std;

Arme::Arme() : m_nom("Epée rouillée"), m_degatsMax(10), m_degatsMin(0), m_derniersDegats(0)
{
	// TODO Auto-generated constructor stub

}

Arme::Arme(string nom, int degatsMax, int degatsMin) : m_nom(nom),  m_degatsMax(degatsMax) ,m_degatsMin(degatsMin), m_derniersDegats(0)
{


}

Arme::~Arme()
{
	// TODO Auto-generated destructor stub

}

void Arme::changer(std::string nom, int degatsMax, int degatsMin)
{
	m_nom = nom;
	m_degatsMax = degatsMax;
	m_degatsMin = degatsMin;
}

void Arme::afficher() const
{
	cout << "Arme : " << m_nom << " (Dégâts : " << m_degatsMin << " - " << m_degatsMax << ")" << endl;
}

int Arme::getDegats()
{
	srand(time(0));
	m_derniersDegats =  (rand() % (m_degatsMax - m_degatsMin)) + m_degatsMin;
	return m_derniersDegats;
}






