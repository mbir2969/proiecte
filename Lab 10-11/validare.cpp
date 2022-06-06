#include <string>
#include <cctype>
#include "validare.h"

using std::string;

string ValidException::get_mesaj()
{
	return mesaj;
}

void Valid::valideaza_produs(string nume, string tip, double pret, string producator)
{
	if (nume == "")
		throw ValidException("Nume invalid!\n");
	if (tip == "")
		throw ValidException("Tip invalid!\n");
	if (pret < 0)
		throw ValidException("Pret invalid!\n");
	if (producator == "")
		throw ValidException("Producator invalid!\n");
}