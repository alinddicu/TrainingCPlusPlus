#include "stdafx.h"
#include "Centieme.h"

Centieme::Centieme(const int numerateur, const int denominateur) 
	: Fraction(numerateur * 100 / denominateur, 100)
{
}

Centieme::Centieme(const int numerateur)
	: Fraction(numerateur, 100)
{
}

Centieme::Centieme()
	: Fraction()
{
}

Centieme::~Centieme()
{
	cout << "Destruction de " << ToString() << "(" << GetNom() << ")" << endl;
}

string Centieme::ToText() const
{
	int chiffresNominateur = static_cast<int>(to_string(GetNumerateur()).length());
	int chiffresDenominateur = static_cast<int>(to_string(GetDenominateur()).length());
	int paddingNominateur = chiffresDenominateur - chiffresNominateur;

	string text = string();
	for (int i = 0; i < paddingNominateur; i++)
	{
		text += " ";
	}

	text += to_string(GetNumerateur());
	text += "\n";

	int nombreBarettesFraction = max(chiffresNominateur, chiffresDenominateur);
	for (int i = 0; i < nombreBarettesFraction; i++)
	{
		text += "-";
	}

	text += "\n";
	text += to_string(GetDenominateur());
	return text;
}