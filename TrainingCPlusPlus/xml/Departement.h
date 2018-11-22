#pragma once
#include <string>

using namespace std;

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
		string nomRegion);
	~Departement();
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
};

ostream& operator<<(ostream& stream, const Departement& d);

