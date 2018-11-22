#pragma once

#include "rapidxml.hpp"
#include <vector>
#include "Departement.h"

using namespace std;
using namespace rapidxml;

class Pays
{
public:
	Pays(xml_document<>& doc);
	~Pays();
	string ToString() const;
private:
	vector<Departement> m_departements;
};

