#pragma once
#include "Fraction.h"
#include "Centieme.h"
#include <algorithm>

class Centieme :
	public Fraction
{
public:
	Centieme(const int numerateur, const int denominateur);
	Centieme(const int numerateur);
	Centieme();
	string ToText() const;
	~Centieme();
private:
	void SetDenominateur(const int denominateur);
};

