#pragma once
#include <string>
#include <vector>
#include "rapidxml.hpp";
#include "XmlUtils.h"
#include "Ville.h"
#include <time.h>

using namespace std;
using namespace rapidxml;

class Departement
{
public:
	Departement::Departement::Departement(
		string numero,
		string nom,
		string imageCarte,
		string url,
		double surface,
		string dateCreation,
		string chefLieu,
		string nomRegion,
		vector<Ville> villes);
	~Departement();
	static Departement CreateDepartement(xml_node<>* departementNode);
	string ToString();
	string GetNom() const;
private:
	string m_numero;
	string m_nom;
	string m_imageCarte;
	string m_Url;
	double m_surface;
	string m_sDateCreation;
	tm m_dDateCreation;
	string m_chefLieu;
	string m_nomRegion;
	vector<Ville> m_villes;
};

ostream& operator<<(ostream& stream, const Departement& d);

