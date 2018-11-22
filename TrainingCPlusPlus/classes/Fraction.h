#pragma once

#include <string>
#include <iostream>
#include "DenominateurZero.h"
#include "Exception.h"

using namespace std;

class Fraction
{
public:
	Fraction(const int numerateur, const int denominateur);
	Fraction::Fraction(Fraction& fraction);
	Fraction();
	~Fraction();
	int GetNumerateur() const;
	void SetNumerateur(const int numerateur);
	int GetDenominateur() const;
	void SetDenominateur(const int denominateur);
	double GetValeur() const;
	void Simplifier();
	string ToString() const;
	string GetNom() const;
	void SetNom(const std::string& nom = "");
	Fraction operator += (const Fraction& f);
protected:
	int GetPgcd(int a, int b);
	string m_nom;
private:
	static int m_nombreFractions;
	int m_numerateur;
	int m_denominateur;
};

bool operator == (const Fraction& f1, const Fraction& f2);
bool operator != (const Fraction& f1, const Fraction& f2);
Fraction operator + (const Fraction& f1, const Fraction& f2);
ostream& operator << (ostream& stream, const Fraction& f);

