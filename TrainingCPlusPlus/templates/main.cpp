// templates.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Alea.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
	vector<string> vect{ "10", "20", "30", "40", "45" };
	Alea<string> alea;
	alea.Put(vect);
	cout << alea.Get() << endl;
	cout << alea.Get() << endl;
	cout << alea.Get() << endl;
	cout << alea.Get() << endl;
	cout << alea.Get() << endl;

	getchar();
	getchar();
    return 0;
}

