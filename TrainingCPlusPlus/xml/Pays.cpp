#include "stdafx.h"
#include "Pays.h"

Pays::Pays(xml_document<>& doc)
{
	xml_node<> *pays = doc.first_node("pays");
	xml_node<> *departementNode = pays->first_node();

	while (departementNode != NULL)
	{
		Departement departement = Departement::CreateDepartement(departementNode);
		m_departements.push_back(departement);
		departementNode = departementNode->next_sibling();
	}
}

Pays::~Pays()
{
}

string Pays::ToString() const
{
	string output = "";
	for each (Departement dept in m_departements)
	{
		output += dept.ToString();
		output += "\n";
	}

	return output;
}
