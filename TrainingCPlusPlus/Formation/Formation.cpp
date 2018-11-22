// Formation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int factorielleFor(int n);
int factorielleRecursive(int n);

int main()
{
	printf("Tapes un nombre entier!\n");

	int n = 0;
	scanf("%d", &n);

	int f = factorielleRecursive(n);

	printf("La factorielle de %d est %d", n, f);

	getchar();
	getchar();
	return 0;
}

int factorielleFor(int n)
{
	int f = 1;
	for (int i = 2; i <= n; i++)
	{
		f = i * f;
	}

	return f;
}


int factorielleRecursive(int n)
{
	return n > 1 ? n*factorielleRecursive(n - 1) : 1;
}

