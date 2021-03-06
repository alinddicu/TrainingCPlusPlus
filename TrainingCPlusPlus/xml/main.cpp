// xml.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "resource.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Departement.h"
#include "Pays.h"
#include "rapidxml.hpp"

int main()
{
	ifstream theFile("C:\\temp\\departements.xml");
	vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
	buffer.push_back('\0');

	xml_document<> doc;    // character type defaults to char
	doc.parse<0>(&buffer[0]);    // 0 means default parse flags
	
	Pays pays(doc);
	
	cout << pays.ToString();

	getchar();
	getchar();
    return 0;
}

