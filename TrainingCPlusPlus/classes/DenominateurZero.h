#pragma once

#include <string>

using namespace std;

class DenominateurZero: public std::exception
{
public:
	DenominateurZero();
	virtual ~DenominateurZero();
};

