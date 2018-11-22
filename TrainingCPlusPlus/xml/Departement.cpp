#include "stdafx.h"
#include "Departement.h"

Departement::Departement(
	string numero, 
	string nom,
	string imageCarte, 
	string url, 
	string surface, 
	string dateCreation, 
	string chefLieu, 
	string nomRegion)
{
	m_numero = numero;
	m_nom = nom;
	m_imageCarte = imageCarte;
	m_Url = url;
	m_surface = surface;
	m_dateCreation = dateCreation;
	m_chefLieu = chefLieu;
	m_nomRegion = nomRegion;
}

Departement::~Departement()
{
}

string Departement::GetNom()
{
	return m_nom;
}

string Departement::ToString()
{
	return "Numero: " + m_numero + "\n" +
		"Nom: " + m_nom + "\n" +
		"Image carte: " + m_imageCarte + "\n" +
		"URL: " + m_Url + "\n" +
		"Surface: " + m_surface + "\n" +
		"Date creation: " + m_dateCreation + "\n" +
		"Chef lieu: " + m_chefLieu + "\n" +
		"Nom region: " + m_nomRegion + "\n";
}

ostream& operator<<(ostream& stream, const Departement& d)
{
	stream << "";
	return stream;
}
