#pragma once
#include <vector>
#include "domeniu.h"
#include "repo.h"

using std::vector;

class CosException
{
public:
	/*Creeaza o exceptie
	* Preconditii: ce - mesaj de eroare
	* Postconditii: this - entitate de tip CosException cu campul mesaj initializat
	*/
	CosException(string ce) : mesaj{ ce } {};

	/*Returneaza mesajul unei exceptii
	* Preconditii: this - enritate de tip RepoException
	* Postconditii: mesaj - mesajul exceptiei din Cos
	*/
	string get_mesaj();

private:
	string mesaj;
};


class CosCumparaturi
{
public:

	/*Creeaza o entitate de tip CosCumparaturi
	* Preconditii: pret_total - pretul total al produselor din cosul de cumparaturi
	*              repo -  entitate de tip Repo
	*              lista_cumparaturi -  lista de produse din cousl de cumparaturi
	* Postconditii: this - entitate de tip CosCumparaturi cu campurile pret_total, repo si lista_cumparaturi initializate
	*/
	CosCumparaturi(RepoAbstract& cos_repo) noexcept : repo{ cos_repo } {};

	/*Constructor de copiere
	* Preconditii: this - entitate de tip CosCumparaturi
	*              other - entitate de tip CosCumparaturi
	* Postconditii: constructorul de copiere a fost eliminat
	*/
	CosCumparaturi(const CosCumparaturi& other) = delete;

	/*Returneaza lista de produse din cosul de cumparaturi
	* Preconditii: this - entitate de tip CosCumparaturi
	* Postconditii: lista de produse din cosul de cumparaturi
	*/
	const vector<Produs>& cos_get_all() const noexcept;

	/*Retuneaza pretul total al produselor din cosul de cumparaturi
	* Preconditii: this - entitate de tip CosCumparaturi
	* Postconditii: pret_total - pretul total al produselor din cosul de cumparaturi
	*/
	const double& cos_get_pret_total() noexcept;

	/*Adauga un produs in cosul de cumparaturi
	* Preconditii: this - entitate de tip CosCumparaturi
	*              nume - numele produsului (sir de caractere nevid)
	* Postconditii: mesaj de tipul "Produs inexistent!", daca produsul nu exista in lista de produse
	*               produsul este adaugat in cosul de cumparaturi, altfel
	*/
	void cos_adauga(const string& nume);

	/*Sterge un produs din cosul de cumparaturi
	* Preconditii: this - entitate de tip CosCumparaturi
	*              nume - numele produsului (sir de caractere nevid)
	* Postconditii: mesaj de tipul "Produs inexistent!", daca produsul nu exista in lista de produse
	*               produsul este sters din cosul de cumparaturi, altfel
	*/
	void cos_sterge(const string& nume);

	/*Genereaza produse random in cosul de cumparaturi
	* Preconditii: this - entitate de tip CosCumparaturi
	*              nr - numarul de produse ce trebuie generate ( numar natural nenul)
	* Postconditii: lista de produse din cos cu produse generate random
	*/
	vector<Produs> cos_genereaza(int nr);

	/*Goleste cosul de produse
	* Preconditii: this - entitate de tip CosCumparaturi
	* Postconditii: cusul este golit
	*/
	void cos_goleste() noexcept;

	/*Exporta produsele din cos intr-un fisier
	* Preconditii: this - entitate de tip CosCumparaturi
	*			   file_name - numele fisierului in care se face export ( sir de caractere nevid)
	* Postconditii: mesaj de tipul "Nu se poate deschide fisierul!", daca fisierul nu poate fi deschis
	*               produsele din cos sunt exportate, altfel
	*/
	void cos_exporta(string file_name);

private:
	double pret_total = 0;
	RepoAbstract& repo;
	vector<Produs> lista_cumparaturi;
};

