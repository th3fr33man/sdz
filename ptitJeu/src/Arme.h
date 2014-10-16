/*
 * Arme.h
 *
 *  Created on: 16 oct. 2014
 *      Author: rip
 */

#ifndef ARME_H_
#define ARME_H_

#include <iostream>
#include <string>

class Arme
{
	public:

	Arme();
	Arme(std::string nom, int degatsMax, int degatsMin);
	virtual ~Arme();

	void changer(std::string nom, int degatsMax, int degatsMin = 0);
	void afficher() const;
	int getDegats();

	private:

	std::string m_nom;
	int m_degatsMin;
	int m_degatsMax;
	int m_derniersDegats;

};

#endif /* ARME_H_ */
