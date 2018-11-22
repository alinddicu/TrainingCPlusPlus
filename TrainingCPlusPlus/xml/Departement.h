#pragma once
#include <string>
#include <vector>
#include "rapidxml.hpp";
#include "XmlUtils.h"
#include "Ville.h"

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
		string surface,
		string dateCreation,
		string chefLieu,
		string nomRegion,
		vector<Ville> villes);
	~Departement();
	static Departement CreateDepartement(xml_node<>* departementNode);
	string ToString();
	string GetNom();
private:
	string m_numero;
	string m_nom;
	string m_imageCarte;
	string m_Url;
	string m_surface;
	string m_dateCreation;
	string m_chefLieu;
	string m_nomRegion;
	vector<Ville> m_villes;
};

ostream& operator<<(ostream& stream, const Departement& d);

