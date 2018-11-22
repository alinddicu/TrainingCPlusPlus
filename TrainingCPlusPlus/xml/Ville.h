#pragma once
#include <string>
#include "rapidxml.hpp";

using namespace std;
using namespace rapidxml;

enum TypeVille { Prefecture, SousPrefecture };

class Ville
{
public:
	Ville(string nom, string typeVille);
	~Ville();
	static Ville CreateVille(xml_node<>* villeNode);
	string ToString() const;
	string GetNom()const;
private:
	string m_nom;
	TypeVille m_typeVile;
	TypeVille ConvertTypeVille(string typeVille);
};

ostream& operator<<(ostream& stream, Ville& d);

