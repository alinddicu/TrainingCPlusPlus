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
	stream << v;
	return stream;
}
