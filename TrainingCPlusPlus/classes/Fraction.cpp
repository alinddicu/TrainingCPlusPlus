#include "stdafx.h"
#include "Fraction.h"

int Fraction::m_nombreFractions = 0;

Fraction::Fraction(const int numerateur, const int denominateur)
{
	m_numerateur = numerateur;
	m_denominateur = denominateur;
	SetNom();
	cout << "Creation de " << ToString() << "(" << GetNom() << ")" << endl;
}

Fraction::Fraction(Fraction& fraction): 
	m_numerateur(fraction.m_numerateur), 
	m_denominateur(fraction.m_denominateur)
{
	SetNom();
	cout << "Creation de " << ToString() << "(" << GetNom() << ")" << endl;
}

Fraction::Fraction()
{
	SetNom();
	cout << "Creation de " << ToString() << "(" << GetNom() << ")" << endl;
}


Fraction::~Fraction()
{
	cout << "Destruction de " << ToString() << "(" << GetNom() << ")" << endl;
}

int Fraction::GetNumerateur() const
{
	return m_numerateur;
}

void Fraction::SetNumerateur(const int numerateur)
{
	m_numerateur = numerateur;
}

int Fraction::GetDenominateur() const
{
	return m_denominateur;
}

void Fraction::SetDenominateur(const int denominateur)
{
	if (denominateur == 0)
	{
		throw DenominateurZero();
		//throw Exception("Denominateur zero");
	}

	m_denominateur = denominateur;
}

double Fraction::GetValeur() const
{
	return (double) GetNumerateur() / (double) GetDenominateur();
}

void Fraction::Simplifier()
{
	int pgcd = GetPgcd(m_numerateur, m_denominateur);
	m_numerateur = m_numerateur / pgcd;
	m_denominateur = m_denominateur / pgcd;
}

string Fraction::ToString() const
{
	return to_string(m_numerateur) + "/" + to_string(m_denominateur);
}

std::string Fraction::GetNom() const
{
	return m_nom;
}

void Fraction::SetNom(const std::string& nom)
{
	if (nom == "")
	{
		m_nom = typeid(this).name() + to_string(++m_nombreFractions);
	}
	else
	{
		m_nom = nom;
	}
}

Fraction Fraction::operator+=(const Fraction & f)
{
	int numerateur = GetNumerateur() * f.GetDenominateur() + GetDenominateur() * f.GetNumerateur();
	int denominateur = f.GetDenominateur() * GetDenominateur();
	SetNumerateur(numerateur);
	SetDenominateur(denominateur);
	Simplifier();
	return *this;
}

int Fraction::GetPgcd(int a, int b)
{
	while (true) 
	{
		int r = a % b;
		if (r == 0) 
		{
			break;
		}

		a = b;
		b = r;
	}

	return b;
}

bool operator==(const Fraction & f1, const Fraction & f2)
{
	return f1.GetNumerateur() * f2.GetDenominateur() == f1.GetDenominateur() * f2.GetNumerateur();
}

bool operator!=(const Fraction & f1, const Fraction & f2)
{
	return f1.GetNumerateur() * f2.GetDenominateur() != f1.GetDenominateur() * f2.GetNumerateur();
}

Fraction operator+(const Fraction & f1, const Fraction & f2)
{
	// (a*d + b*c) / b*d
	Fraction f(
		f1.GetNumerateur() * f2.GetDenominateur() + f1.GetDenominateur() * f2.GetNumerateur(),
		f2.GetDenominateur() * f1.GetDenominateur());
	f.Simplifier();
	return f;
}

ostream& operator<<(ostream& stream, const Fraction& f)
{
	stream << f.ToString();
	return stream;
}
