#include "stdafx.h"
#include "Departement.h"
#include "Ville.h"

Departement::Departement(
	string numero, 
	string nom,
	string imageCarte, 
	string url, 
	double surface, 
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
	m_sDateCreation = dateCreation;
	m_chefLieu = chefLieu;
	m_nomRegion = nomRegion;
	m_villes = villes;
	m_dDateCreation.tm_hour = 0;
	m_dDateCreation.tm_min = 0;
	m_dDateCreation.tm_sec = 0;
	sscanf(m_sDateCreation.c_str(), "%4d-%2d-%2d", &m_dDateCreation.tm_year, &m_dDateCreation.tm_mon, &m_dDateCreation.tm_mday);
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
		XmlUtils::GetNodeValue(departementNode, "no-dept"),
		XmlUtils::GetNodeValue(departementNode, "nom"),
		XmlUtils::GetNodeValue(departementNode, "image-carte"),
		XmlUtils::GetNodeValue(departementNode, "url"),
		atof(XmlUtils::GetNodeValue(departementNode, "surface").c_str()),
		XmlUtils::GetNodeValue(departementNode, "date-creation"),
		XmlUtils::GetNodeValue(departementNode, "chef-lieu"),
		XmlUtils::GetNodeValue(departementNode, "nom-region"),
		villes);

	return departement;
}

string Departement::GetNom() const
{
	return m_nom;
}

string Departement::ToString()
{
	string villes = "[";

	for each (Ville ville in m_villes)
	{
		villes += ville.GetNom() + ", ";
	}
	villes += "]";

	return "Numero:\t" + m_numero + "\n" +
		"Nom:\t" + m_nom + "\n" +
		"Image carte:\t" + m_imageCarte + "\n" +
		"URL:\t" + m_Url + "\n" +
		"Surface:\t" + to_string(m_surface) + "\n" +
		"Date creation:\t" + m_sDateCreation + "\n" +
		"Chef lieu:\t" + m_chefLieu + "\n" +
		"Nom region:\t" + m_nomRegion + "\n" + 
		"Villes:\t" + villes + "\n";
}

ostream& operator<<(ostream& stream, const Departement& d)
{
	stream << d.GetNom();
	return stream;
}
