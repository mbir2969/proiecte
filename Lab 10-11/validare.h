#pragma once
#include <string>

using std::string;

class ValidException
{
public:
	/*Creeaza o exceptie
	* Preconditii: ve - mesaj de eroare
	* Postconditii: validexception entitate de tip ValidException cu campul mesaj initializat
	*/
	ValidException(string ve) : mesaj{ ve } {};

	/*Returneaza mesajul unei exceptii de validare
	* Preconditii: validexception - entitate de tip ValidException
	* Postconditii: mesaj - mesajul exceptiei de validare
	*/
	string get_mesaj();
private:
	string mesaj;
};

class Valid
{
public:
	/*Valideaza un produs
	* Preconditii: nume - numele produsului (sir de caractere)
	*              tip - tipul produsului (sir de caractere)
	*              pret - pretul produsului (numar rational)
	*              produscator - producatorul produsului ( sir de caractere)
	* Postcondiiti: mesaje de tipul: "Nume invalid!", daca produsul are numele invalid
	*                                "Tip invalid!", daca produsul are tipul invalid
	*                                "Pret invalid!", daca produsul are pretul invalid
	*                                "Producator invalid!", daca produsul are producatorul invalid
	*               - , daca produsul are atributele valide
	*/
	void valideaza_produs(string nume, string tip, double pret, string producator);
};

