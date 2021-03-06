// Classes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Fraction.h"
#include "Centieme.h"
#include <iostream>

using namespace std;

void testClasses()
{
	Fraction f1;
	f1.SetNumerateur(4);
	f1.SetDenominateur(10);
	Fraction f2(f1);
	cout << f2.ToString() << endl;

	cout << f1.GetValeur() << endl;
	cout << f1.ToString() << endl;
	f1.Simplifier();
	cout << f1.ToString() << endl;
	Fraction f3(2, 7);
	cout << f3.ToString() << endl;
	Fraction f4(f3);
	cout << f4.GetNom() << endl;
}

void testSurchargesOperateurs()
{
	Fraction f1(2, 7);
	Fraction f2(3, 5);
	cout << "inegalite: " << to_string(f1 != f2) << endl;
	cout << "somme f1 + f2: " << f1 + f2 << endl;
	
	Fraction f3(2, 7);
	Fraction f4(6, 21);
	cout << "egalite: " << to_string(f3 == f4) << endl;
	cout << "somme (f3 += f4): " << (f3 += f4) << endl;
}

void testCentieme()
{
	Centieme c1(7);
	cout << c1.ToString() << endl;
	cout << endl;
	cout << c1.ToText() << endl;
	cout << endl;

	Centieme c2(75);
	cout << c2.ToText() << endl;
}

void testException()
{
	try
	{
		Fraction f1;
		f1.SetDenominateur(0);
	}
	catch (const DenominateurZero& e)
	{
		cout << "Exception DenominateurZero!!!! " << e.what() << endl;
	}
	catch (const exception& e)
	{
		cout << "Exception systeme!!!! " << e.what() << endl;
	}
}

int main()
{
	// testClasses();
	// testSurchargesOperateurs();
	// testCentieme();

	testException();
	
	getchar();
	getchar();
    return 0;
}

