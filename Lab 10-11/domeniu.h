#pragma once
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::ostream;
using std::istream;

class Produs
{
public:

	/*Constructor default pt un produs
	* Preconditii: -
	* Postconditii: this - entitate de tip Produs
	*/
	Produs() = default;

	/*Creeaza un produs nou
	* Preconditii: nume - numele produsului (sir de caractere nevid)
	*              tip - tipul produsului (sir de caractere nevid)
	*              pret - pretul produsului (numar rational strict pozitiv)
	*              producator - producatorul produsului (sir de caractere nevid)
	* Postconditii: produs - entitate de tip Produs cu atributele nume, tip, pret, producator initializate
	*/
	Produs(const string& nume, const string& tip, const double& pret, const string& producator) : nume{ nume }, tip{ tip }, pret{ pret }, producator{ producator }{}

	/*Returneaza numele unui produs
	* Preconditii: produs - entitate de tip Produs
	* Postconditii: nume - numele produsului (sir de caractere nevid)
	*/
	string get_nume() const;

	/*Returneaza tipul unui produs
	* Preconditii: produs - entitate de tip Produs
	* Postconditii: tip - tipul produsului (sir de caractere nevid)
	*/
	string get_tip() const;

	/*Returneaza pretul unui produs
	* Preconditii: produs - entitate de tip Produs
	* Postconditii: pret - pretul produsului (numar rational strict pozitiv)
	*/
	double get_pret() const noexcept;

	/*Returneaza producatorul unui produs
	* Preconditii: produs - entitate de tip Produs
	* Postconditii: producator - producatorul produsului (sir de caractere nevid)
	*/
	string get_producator() const;

	/*Modifica numele unui produs
	* Precodnitii: produs - entitat de tip Produs
	*              nume_nou - numele nou al produsului  (sir de caractere nevid)
	* Postconditii: produsul are numele modificat
	*/
	void set_nume(const string& nume_nou);

	/*Modifica tipul unui produs
	* Precodnitii: produs - entitat de tip Produs
	*              tip_nou - tipul nou al produsului  (sir de caractere nevid)
	* Postconditii: produsul are tipul modificat
	*/
	void set_tip(const string& tip_nou);

	/*Modifica pretul unui produs
	* Precodnitii: produs - entitat de tip Produs
	*              pret_nou - pretul nou al produsului  (numar rational strict pozitiv)
	* Postconditii: produsul are pretul modificat
	*/
	void set_pret(const double& pret_nou) noexcept;

	/*Modifica producatorul unui produs
	* Precodnitii: produs - entitat de tip Produs
	*              producator_nou - producatorul nou al produsului  (sir de caractere nevid)
	* Postconditii: produsul are producatorul modificat
	*/
	void set_producator(const string& producator_nou);

	/*Verifica daca doua produse sunt egale
	* Preconditii: produs - entitate de tip Produs
	*              p2 - entitate de tip Produs
	* Postconditii: true, daca produsele sunt egale
	*               false, altfel
	*/
	bool produse_egale(const Produs& p2) const;

	/*Converteste atributele unui produs in siruri de caractere
	* Preconditii: produs - entitate de tip Produs
	* Postconditii: sir de caractere care corespunde atributelor produsului
	*/
	string produs_str() const;

	/*Operator assignment
	* Preconditii: this - entitate de tip Produs
	*              other - entitate de tip Produs
	* Postconditii: campurile entitatii other au continulul campurilor entitatii curente curente
	*/
	Produs& operator=(const Produs& other);


	/*Constructor de copiere
	* Preconditii: produs - entitate de tip Produs
	*              other - entitate de tip Produs
	* Postconditii: produsul a fost copiat
	*/
	/*Produs(const Produs& other) : nume{ other.nume }, tip{ other.tip }, pret{ other.pret }, producator{ other.producator }
	{
		cout <<"Copy constructor called!\n";
	};*/

	/*Operator de insertie
	* Preconditii: stream - streamul in care va fi transferat produsul
	*              p - entitate de tip Produs
	* Postconditii: produsul este trimis la stream
	*/
	friend ostream& operator<<(ostream& stream, const Produs& p);

	/*Operator de extragere
	* Preconditii: stream - streamul din care va fi transferat produsul
	*              p - entitate de tip Produs
	* Postconditii: produsul este trimis de la steam
	*/
	friend istream& operator>>(istream& stream, Produs& p);

private:
	string nume;
	string tip;
	double pret = 0;
	string producator;
};

