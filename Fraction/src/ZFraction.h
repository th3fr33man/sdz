/*
 * ZFraction.h
 *
 *  Created on: 13 nov. 2014
 *      Author: rip
 */

#ifndef ZFRACTION_H_
#define ZFRACTION_H_

#include <iostream>

class ZFraction
{

public:

	ZFraction(int a = 0, int b = 1);



	ZFraction& operator+=(ZFraction const& fraction);
	ZFraction& operator-=(ZFraction const& fraction);
	ZFraction& operator/=(ZFraction const& fraction);
	ZFraction& operator*=(ZFraction const& fraction);
	ZFraction& operator%=(ZFraction const& fraction);


	void afficher(std::ostream &out) const;
	bool estEgal(ZFraction const& b) const;
	bool estPlusPetitQue(ZFraction const& b) const;
	int pgcd(int a, int b);
	void simplification();
	double calculNombreReel() const;





	virtual ~ZFraction();

private:

	int m_den;
	int m_num;

};

std::ostream& operator<<(std::ostream& out, ZFraction const& duree);

bool operator==(ZFraction const& a, ZFraction const& b);
bool operator!=(ZFraction const& a, ZFraction const& b);
bool operator>(ZFraction const& a, ZFraction const& b);
bool operator<(ZFraction const& a, ZFraction const& b);
bool operator>=(ZFraction const& a, ZFraction const& b);
bool operator<=(ZFraction const& a, ZFraction const& b);

ZFraction operator+(ZFraction const& a, ZFraction const& b);
ZFraction operator-(ZFraction const& a, ZFraction const& b);
ZFraction operator*(ZFraction const& a, ZFraction const& b);
ZFraction operator/(ZFraction const& a, ZFraction const& b);
ZFraction operator%(ZFraction const& a, ZFraction const& b);


#endif /* ZFRACTION_H_ */
