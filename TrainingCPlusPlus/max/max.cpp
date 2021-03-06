// max.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string.h"
#include <string>
#include <map>
#include "stdlib.h"
#include <time.h>

using namespace std;

void max();
int max(int* nombres, int length);
void motDePasse();
bool isMotDePasseValide(const char* motDePasse, const char* motDePasseValide);
void tri();
void tri(int* nombres, int taille);
void printTab(int* tab, int taille);
void crypter();
std::string crypter(const std::string s);
void checkNumeroSecu();
bool isNumerSecuValide();
void clearBuffer();
bool getLongLong(long long* value);
bool getString(char* text, int lg);
long long getFileSize(char fileName[]);
void negativeImage();

int main()
{
	//max();
	//motDePasse();
	//tri();
	//crypter();
	//checkNumeroSecu();

	negativeImage();
	
	getchar();
	getchar();

    return 0;
}

void negativeImage()
{
	char* fileName = "c:\\temp\\alin.bmp";
	// Déterminer la taille du fichier et créer le tableau des pixels :
	long long size = getFileSize(fileName);
	unsigned char* data = (unsigned char *)malloc(size);

	// Lire le fichier image :
	FILE * file = fopen(fileName, "rb");
	for (long long i = 0; i < size; i++)
	{
		char character = fgetc(file);
		if (character != EOF)
		{
			data[i] = character;
		}
	}

	fclose(file);

	// Déterminer le début des pixels de l'image :
	long long offset = data[10] + data[11] * 256 + data[12] * 65536 + data[13] * 16777216;
	// Calculer le négatif de chaque pîxel (pixel = 255 - pixel)

	file = fopen(fileName, "r");
	for (long long i = offset; i < size; i++)
	{
		char character = fgetc(file);
		data[i] = character / 2;
	}

	fclose(file);

	// Ecrire l'image dans le fichier negatif.bmp
	FILE * newfile = fopen("c:\\temp\\alin-negative.bmp", "wb");
	for (long long i = 0; i < size; i++) 
	{
		fputc(data[i], newfile);
	}

	fclose(newfile);

	free(data);
}

long long getFileSize(char fileName[]) 
{
	long long size = 0;
	FILE * file = fopen(fileName, "r");
	while (fgetc(file) != EOF) { size++; }
	fclose(file);
	return size;
}

void checkNumeroSecu()
{
	while (!isNumerSecuValide())
	{
		printf("Saisie invalide \n");
	}

	printf("Numero secu valide !!!");
}

bool getString(char * text, int lg) 
{
	if (fgets(text, lg, stdin) == NULL) 
	{
		clearBuffer();
		return 0;
	}

	if (strchr(text, '\n') == NULL) 
	{
		clearBuffer();
	}

	return 1;
}

bool getLongLong(long long* value)
{
	char text[20];
	getString(text, 20);
	char* cEnd;
	*value = atoll(text);
	return true;
}

void clearBuffer() 
{
	int c = 0;
	while (c != '\n' && c != EOF) { c = getchar(); }
}

bool isNumerSecuValide()
{
	char* numeroSecuSansCle[20];
	char* cle[2];
	printf("Saisissez le numero de secu sans cle\n");
	long long lNumeroSecuSansCle;
	getLongLong(&lNumeroSecuSansCle);

	printf("Saisissez la cle\n");
	long long lCle;
	getLongLong(&lCle);

	return (97 - (2550814168025 % 97)) == lCle;
}

void crypter() 
{
	printf("%s \n", crypter(" ei ").c_str());
}


std::string crypter(const std::string stringToCypher)
{
	std::map<char, char> cypher;
	cypher[' '] = 'l';
	cypher['e'] = 'k';
	cypher['i'] = ' ';
	std:string cypheredString = stringToCypher;
	for (int i = 0; i < stringToCypher.size(); i++)
	{
		char character = stringToCypher[i];
		if (cypher.find(character) != cypher.end())
		{
			cypheredString[i] = cypher[character];
		}
	}

	return cypheredString;
}

void tri()
{
	srand(time(0));
	const int taille = 10;
	int nombres[taille];

	for (int i = 0; i < taille; i++)
	{
		nombres[i] = rand();
	}

	printTab(nombres, taille);
	tri(nombres, taille);
	//printTab(nombres, taille);
}

void printTab(int* tab, int taille)
{
	std::string output = "[";
	for (int i = 0; i < taille; i++)
	{
		if (i < taille - 1)
		{
			output += std::to_string(tab[i]) + ", ";
		}
		else
		{
			output += std::to_string(tab[i]);
		}
	}

	output += "]";

	printf("%s \n", output.c_str());
}

void tri(int* nombres, int taille)
{
	bool permutationFaite = false;
	for (int i = 0; i < taille - 1; i++)
	{
		int gauche = nombres[i];
		int droite = nombres[i + 1];
		if (gauche > droite)
		{
			nombres[i] = droite;
			nombres[i + 1] = gauche;
			permutationFaite = true;
		}
	}

	printTab(nombres, taille);
	if (permutationFaite)
	{
		tri(nombres, taille);
	}
}

void motDePasse()
{
	const int taille = 20;
	char pwd_essai[taille];
	char pwd_correct[taille] = "bidule";

	printf("Saisissez\n");
	scanf("%s", pwd_essai);

	while (!isMotDePasseValide(pwd_essai, pwd_correct))
	{
		printf("Saisie invalide, saisissez de nouveau \n");
		scanf("%s", pwd_essai);
	}

	printf("Saisie valide !!!");
}

bool isMotDePasseValide(const char* pwd_essai, const char* pwd_correct)
{
	return strcmp(pwd_essai, pwd_correct) == 0;
}

void max()
{
	const int taille = 5;
	int nombres[taille];

	for (int i = 0; i < taille; i++)
	{
		printf("Tapez un nombre: \n");
		scanf("%d", &nombres[i]);
	}

	printf("La valeur la plus grande est: %d", max(nombres, taille));
}

int max(int* nombres, int taille)
{
	auto max = *nombres;
	for (auto i = 0; i < taille; i++)
	{
		auto nombreCourant = nombres[i];
		if (nombreCourant > max)
		{
			max = nombreCourant;
		}
	}

	return max;
}

