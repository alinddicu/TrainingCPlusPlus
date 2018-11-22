// xml.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "resource.h"
#include <string>
#include "rapidxml.hpp";
#include <iostream>
#include <fstream>
#include <vector>
#include "Departement.h"

using namespace std;
using namespace rapidxml;


string GetNodeValue(xml_node<> *node, string nodeName)
{
	xml_node<> *sibling = node->first_node();
	string currentNodeName = sibling->name();
	while (sibling != NULL && nodeName != currentNodeName)
	{
		sibling = sibling->next_sibling();
		currentNodeName = sibling->name();
	}

	return sibling->value();
}

int main()
{
	ifstream theFile("C:\\temp\\departements.xml");
	vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
	buffer.push_back('\0');

	xml_document<> doc;    // character type defaults to char
	doc.parse<0>(&buffer[0]);    // 0 means default parse flags
	
	xml_node<> *pays = doc.first_node("pays");	
	xml_node<> *departementNode = pays->first_node();

	vector<Departement> departements;
	while (departementNode != NULL)
	{
		Departement departement(
			GetNodeValue(departementNode, "no-dept"),
			GetNodeValue(departementNode, "nom"),
			GetNodeValue(departementNode, "image-carte"),
			GetNodeValue(departementNode, "url"),
			GetNodeValue(departementNode, "surface"),
			GetNodeValue(departementNode, "date-creation"),
			GetNodeValue(departementNode, "chef-lieu"),
			GetNodeValue(departementNode, "nom-region"));

		departements.push_back(departement);
		cout << departement.ToString() << endl;
		departementNode = departementNode->next_sibling();
	}
	
	getchar();
	getchar();
    return 0;
}

