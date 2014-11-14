/*
 * ZFraction.cpp
 *
 *  Created on: 13 nov. 2014
 *      Author: rip
 */
#include <iostream>
#include "ZFraction.h"

using namespace std;

/**
 *
 */
ZFraction::ZFraction(int a, int b) : m_num(a) , m_den(b)
{
	// simplification
	simplification();
}

int ZFraction::pgcd(int a, int b)
{
    while (b != 0)
    {
        const int t = b;
        b = a%b;
        a=t;
    }
    return a;
}

void ZFraction::simplification()
{
	int m_pgcd = pgcd(m_num, m_den);
	m_num /= m_pgcd;
	m_den /= m_pgcd;
}


double ZFraction::calculNombreReel() const
{
	double m_reel = (double)m_num/m_den;
	return m_reel;
}


ZFraction& ZFraction::operator +=(const ZFraction& fraction)
{
	// mise au même dénominateur
	int m_nouveauNumA = m_num * fraction.m_den;
	int m_nouveauNumB = fraction.m_num * m_den;
	int m_nouveauDen = m_den * fraction.m_den;

	m_num = m_nouveauNumA + m_nouveauNumB;
	m_den = m_nouveauDen;


	// simplification de la fraction
	simplification();
	return *this;

}

ZFraction& ZFraction::operator -=(const ZFraction& fraction)
{
	// mise au même dénominateur
	int m_nouveauNumA = m_num * fraction.m_den;
	int m_nouveauNumB = fraction.m_num * m_den;
	int m_nouveauDen = m_den * fraction.m_den;

	m_num = m_nouveauNumA - m_nouveauNumB;
	m_den = m_nouveauDen;


	// simplification de la fraction
	simplification();
	return *this;
}

ZFraction& ZFraction::operator /=(const ZFraction& fraction)
{
	m_num *= fraction.m_den;
	m_den *= fraction.m_num;

	simplification();
	return *this;
}

ZFraction& ZFraction::operator *=(const ZFraction& fraction)
{
	m_num *= fraction.m_num;
	m_den *= fraction.m_den;

	simplification();
	return *this;
}

ZFraction& ZFraction::operator %=(const ZFraction& fraction)
{

}

void ZFraction::afficher(std::ostream& out) const
{
	out << m_num << "/" << m_den  ;
}

bool ZFraction::estEgal(const ZFraction& b) const
{
	return m_num/m_den == b.m_num/b.m_den;
}

bool ZFraction::estPlusPetitQue(const ZFraction& b) const
{
	// on met au même dénominateur
	int m_nouveauNumA = m_num * b.m_den;
	int m_nouveauNumB = b.m_num * m_den;
	return m_nouveauNumA < m_nouveauNumB;
}

ZFraction::~ZFraction()
{
	// TODO Auto-generated destructor stub
}


//======Operateurs================================================================

ostream& operator<<(ostream& out, ZFraction const& fraction)
{
	fraction.afficher(out) ;
    return out;
}


bool operator ==(const ZFraction& a, const ZFraction& b)
{
	return a.estEgal(b);
}

bool operator !=(const ZFraction& a, const ZFraction& b)
{
	return !(a == b);
}

bool operator >(const ZFraction& a, const ZFraction& b)
{
	return b.estPlusPetitQue(a);
}

bool operator <(const ZFraction& a, const ZFraction& b)
{
	return a.estPlusPetitQue(b);
}

bool operator >=(const ZFraction& a, const ZFraction& b)
{
	return a > b && a == b;
}

bool operator <=(const ZFraction& a, const ZFraction& b)
{
	return a < b && a == b;
}

ZFraction operator +(const ZFraction& a, const ZFraction& b)
{
	ZFraction copie(a);
	copie +=b;
	return copie;
}

ZFraction operator -(const ZFraction& a, const ZFraction& b)
{
	ZFraction copie(a);
	copie -=b;
	return copie;
}

ZFraction operator *(const ZFraction& a, const ZFraction& b)
{
	ZFraction copie(a);
	copie *=b;
	return copie;
}

ZFraction operator /(const ZFraction& a, const ZFraction& b)
{
	ZFraction copie(a);
	copie /=b;
	return copie;
}

ZFraction operator %(const ZFraction& a, const ZFraction& b)
{

}
