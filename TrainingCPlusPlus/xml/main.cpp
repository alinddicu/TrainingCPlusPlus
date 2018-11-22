// xml.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "resource.h"
#include <string>
#include "rapidxml.hpp";
#include <iostream>
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
	char text[633] = "<?xml version=\"1.0\" encoding=\"ISO-8859-1\" standalone=\"yes\" ?><pays>	<departement id=\"D01\">		<no-dept>01</no-dept>		<image-carte>dept_map_01.png</image-carte>		<nom>Ain</nom>		<url>http://fr.wikipedia.org/wiki/Ain_(d%C3%A9partement)</url>		<surface>5762</surface>		<date-creation>1790-03-04</date-creation>		<chef-lieu>Bourg-en-Bresse</chef-lieu>		<nom-region>Rhône-Alpes</nom-region>		<villes>			<ville type=\"sous-prefecture\">Belley</ville>			<ville type=\"prefecture\">Bourg-en-Bresse</ville>			<ville type=\"sous-prefecture\">Gex</ville>			<ville type=\"sous-prefecture\">Nantua</ville>		</villes>	</departement></pays>";
	xml_document<> doc;    // character type defaults to char
	doc.parse<0>(text);    // 0 means default parse flags

	//cout << "Name of my first node is: " << doc.first_node()->name() << "\n";

	xml_node<> *pays = doc.first_node("pays");
	xml_node<> *firstDepartement = pays->first_node();
	//cout << "no-dept value: " << firstDepartement->first_node()->value() << endl;
	//cout << "image-carte value: " << firstDepartement->first_node()->next_sibling()->value() << endl;
	//cout << "nom: " << firstDepartement->first_node()->next_sibling()->next_sibling()->value() << endl;
	
	Departement d(
		GetNodeValue(firstDepartement, "no-dept"),
		GetNodeValue(firstDepartement, "nom"),
		GetNodeValue(firstDepartement, "image-carte"),
		GetNodeValue(firstDepartement, "url"),
		GetNodeValue(firstDepartement, "surface"),
		GetNodeValue(firstDepartement, "date-creation"),
		GetNodeValue(firstDepartement, "chef-lieu"),
		GetNodeValue(firstDepartement, "nom-region"));
	cout << d.ToString() << endl;

	getchar();
	getchar();
    return 0;
}

