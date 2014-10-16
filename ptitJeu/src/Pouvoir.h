/*
 * Pouvoir.h
 *
 *  Created on: 16 oct. 2014
 *      Author: rip
 */

#ifndef POUVOIR_H_
#define POUVOIR_H_

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

class Pouvoir
{
	public:

	Pouvoir();
	Pouvoir(std::string nom, int degatsMax, int degatsMin);
	virtual ~Pouvoir();

	int getDegats();
	void changerPouvoir(std::string nom, int degatsMax, int degatsMin);


	private:

	int m_degatsMin;
	int m_degatsMax;
	int m_derniersDegats;
	std::string m_nom;
};

#endif /* POUVOIR_H_ */
