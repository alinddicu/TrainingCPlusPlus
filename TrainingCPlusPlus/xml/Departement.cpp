#include "stdafx.h"
#include "Departement.h"
#include "Ville.h"
#include <vector>

Departement::Departement(
	string numero, 
	string nom,
	string imageCarte, 
	string url, 
	string surface, 
	string dateCreation, 
	string chefLieu, 
	string nomRegion,
	vector<Ville> villes)
{
	m_numero = numero;
	m_nom = nom;
	m_imageCarte = imageCarte;
	m_Url = url;
	m_surface = surface;
	m_dateCreation = dateCreation;
	m_chefLieu = chefLieu;
	m_nomRegion = nomRegion;
	m_villes = villes;
}

Departement::~Departement()
{
}

Departement Departement::CreateDepartement(xml_node<>* departementNode)
{
	xml_node<> * villesNode = departementNode->first_node("villes");
	xml_node<> * villeNode = villesNode->first_node();

	vector<Ville> villes;
	while (villeNode != NULL)
	{
		villes.push_back(Ville::CreateVille(villeNode));
		villeNode = villeNode->next_sibling();
	}
	
	Departement departement(
		XmlUtils<string>::GetNodeValue(departementNode, "no-dept"),
		XmlUtils<string>::GetNodeValue(departementNode, "nom"),
		XmlUtils<string>::GetNodeValue(departementNode, "image-carte"),
		XmlUtils<string>::GetNodeValue(departementNode, "url"),
		XmlUtils<string>::GetNodeValue(departementNode, "surface"),
		XmlUtils<string>::GetNodeValue(departementNode, "date-creation"),
		XmlUtils<string>::GetNodeValue(departementNode, "chef-lieu"),
		XmlUtils<string>::GetNodeValue(departementNode, "nom-region"),
		villes);

	return departement;
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

ostream& operator<<(ostream& stream, Departement& d)
{
	stream << d.GetNom();
	return stream;
}
