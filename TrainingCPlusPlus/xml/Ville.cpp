#include "stdafx.h"
#include "Ville.h"

Ville::Ville(string nom, string typeVille)
{
	m_nom = nom;
	m_typeVile = ConvertTypeVille(typeVille);
}

Ville::~Ville()
{
}

Ville Ville::CreateVille(xml_node<>* villeNode)
{
	return Ville(villeNode->value(), villeNode->first_attribute()->value());
}

string Ville::ToString() const
{
	return m_nom;
}

string Ville::GetNom() const
{
	return ToString();
}

TypeVille Ville::ConvertTypeVille(string typeVille)
{
	if (typeVille == "sous-prefecture")
	{
		return SousPrefecture;
	}

	return Prefecture;
}

ostream& operator<<(ostream& stream, const Ville& v)
{
	stream << v.GetNom();
	return stream;
}
