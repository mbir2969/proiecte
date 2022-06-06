#pragma once
#include <vector>
#include <map>
#include "domeniu.h"

using std::vector;
using std::map;
using std::pair;

class RepoException
{
public:
	/*Creeaza o exceptie
	* Preconditii: re - mesaj de eroare
	* Postconditii: this - entitate de tip RepoException cu campul mesaj initializat
	*/
	RepoException(string re) : mesaj{ re } {};

	/*Returneaza mesajul unei exceptii
	* Preconditii: this - enritate de tip RepoException
	* Postconditii: mesaj - mesajul exceptiei din Repo
	*/
	string get_mesaj();
private:
	string mesaj;
};

class RepoAbstract {
public:
	/*Returneaza lista tuturor produselor adaugate (functie abstracta)
	* Preconditii: this - entitate de tip Repo ce contine lista de produse
	* Postconditii: produse - lista de produse adaugate
	*/
	virtual const vector<Produs>& get_all() = 0;

	/*Adauga un produs in lista de produse (functie abstracta)
	* Preconditii: this - entitate de tip Repo ce contine lista de produse
	*              p - entitate de tip Produs
	* Postconditii: mesaj de tipul "Prosud existent!" daca produsul exista deja inlista de produse
	*               produsul este adaugat, altfel
	*/
	virtual void adauga(const Produs& p) = 0;

	/*Modifica un produs din lista de produse (functie abstracta)
	* Preconditii: this - entitate de tip Repo ce contine lista de produse
	*              p1 - entitate de tip Produs
	*              p2 - entitate de tip Produs
	* Postconditii: mesaj de tipul "Produs inexistent!", daca produsul p1 nu exista in lista de produse
	*               produsul este modificat, altfel
	*/
	virtual void modifica(const Produs& p1, const Produs& p2) = 0;

	/*Sterge un produs din lista de produse (functie abstracta)
	* Precodnitii: this - entitate de tip Repo ce contine lista de produse
	*              p - entitate de tip Produs
	* Postconditii: mesaj de tipul "Produs inexistent!", daca produsul nu exista in lista de produse
	*               produsul este sters, altfel
	*/
	virtual void sterge(const Produs& p) = 0;

	/*Cauta un produs in lista de produse (functie abstracta)
	* Preconditii: this - entitate de tip Repo ce contine lista de produse
	*              p - entitate de tip Produs
	* Postconditii: mesaj de tipul "Produs inexistent!", daca produsul cautat nu exita in lista de produse
	*               produsul cautat, altfel
	*/
	virtual const Produs& cauta(const string& nume) = 0;

	/*Destructor default pt. clasa abstracta RepoAbstract
	* Preconditii: this - interfata RepoAbstract
	* Postconditii: interfata a fost distrusa
	*/
	virtual ~RepoAbstract() = default;
};

class Repo : public RepoAbstract {
public:
	/*Creeaza o entitate de tip Repo (constructor implicit)
	* Preconditii: -
	* Postconditii: this - entitate de tip Repo
	*/
	Repo() = default;

	/*Constructor de copiere
	* Preconditii: this - entitate de tip Repo
	*              other - entitate de tip Repo
	* Postconditii: constructorul de copiere a fost eliminat
	*/
	Repo(const Repo& other) = delete;

	/*Returneaza lista tuturor produselor adaugate
	* Preconditii: this - entitate de tip Repo ce contine lista de produse
	* Postconditii: produse - lista de produse adaugate
	*/
	virtual const vector<Produs>& get_all() noexcept override;

	/*Adauga un produs in lista de produse
	* Preconditii: this - entitate de tip Repo ce contine lista de produse
	*              p - entitate de tip Produs
	* Postconditii: mesaj de tipul "Produs existent!" daca produsul exista deja inlista de produse
	*               produsul este adaugat, altfel
	*/
	virtual void adauga(const Produs& p) override;

	/*Modifica un produs din lista de produse
	* Preconditii: this - entitate de tip Repo ce contine lista de produse
	*              p1 - entitate de tip Produs
	*              p2 - entitate de tip Produs
	* Postconditii: mesaj de tipul "Produs inexistent!", daca produsul p1 nu exista in lista de produse
	*               produsul este modificat, altfel
	*/
	virtual void modifica(const Produs& p1, const Produs& p2) override;

	/*Sterge un produs din lista de produse
	* Precodnitii: this - entitate de tip Repo ce contine lista de produse
	*              p - entitate de tip Produs
	* Postconditii: mesaj de tipul "Produs inexistent!", daca produsul nu exista in lista de produse
	*               produsul este sters, altfel
	*/
	virtual void sterge(const Produs& p) override;

	/*Cauta un produs in lista de produse
	* Preconditii: this - entitate de tip Repo ce contine lista de produse
	*              p - entitate de tip Produs
	* Postconditii: mesaj de tipul "Produs inexistent!", daca produsul cautat nu exita in lista de produse
	*               produsul cautat, altfel
	*/
	virtual const Produs& cauta(const string& nume) override;

	/*Distruge entitatea de tip Repo (destructor implicit)
	* Preconditii: this - entitate de tip Repo
	* Postconditii: entitatea a fost distrusa
	*/
	virtual ~Repo() = default;

protected:
	vector<Produs> produse;
};

class FileRepoException {
public:
	/*Creeaza o exceptie
	* Preconditii: fre - mesaj de eroare
	* Postconditii: this - entitate de tip FileRepoException cu campul mesaj initializat
	*/
	FileRepoException(string fre) : mesaj{ fre } {};

	/*Returneaza mesajul unei exceptii
	* Preconditii: this - enritate de tip FileRepoException
	* Postconditii: mesaj - mesajul exceptiei din FileRepo
	*/
	string get_mesaj();
private:
	string mesaj;
};

class FileRepo : public Repo {
public:
	/*Creeaza o entitate de tip FileRepo
	* Precodnitii: this - entitate de tip FileRepo
	*              filename - numele fisierului ( sir de caracatere nevid)
	* Postconditii: entitatea a fost creata
	*/
	FileRepo(string filename) : Repo(), filename{ filename }
	{
		citeste_din_fisier();
	};

	/*Constructor de copiere
	* Preconditii: this - entitate de tip FileRepo
	*              other - entitate de tip FileRepo
	* Postconditii: constructorul de copiere a fost eliminat
	*/
	FileRepo(const FileRepo& other) = delete;

	/*Returneaza lista tuturor produselor adaugate
	* Preconditii: this - entitate de tip FileRepo ce contine fisierul
	* Postconditii: produse - lista de produse adaugate
	*/
	const vector<Produs>& get_all() noexcept override;

	/*Adauga un produs in fisier
	* Preconditii: this - entitate de tip FileRepo ce contine fisierul
	*              p - entitate de tip Produs
	* Postconditii: mesaj de tipul "Produs existent!" daca produsul exista deja in fisier
	*               produsul este adaugat, altfel
	*/
	void adauga(const Produs& p) override;

	/*Sterge un produs din fisier
	* Precodnitii: this - entitate de tip FileRepo ce contine fisierul
	*              p - entitate de tip Produs
	* Postconditii: mesaj de tipul "Produs inexistent!", daca produsul nu exista in fisier
	*               produsul este sters, altfel
	*/
	void sterge(const Produs& p) override;

	/*Modifica un produs din fisier
	* Preconditii: this - entitate de tip FileRepo ce contine fisierul
	*              p1 - entitate de tip Produs
	*              p2 - entitate de tip Produs
	* Postconditii: mesaj de tipul "Produs inexistent!", daca produsul p1 nu exista in fisier
	*               produsul este modificat, altfel
	*/
	void modifica(const Produs& p1, const Produs& p2) override;

	/*Cauta un produs in lista de produse
	* Preconditii: this - entitate de tip Repo ce contine lista de produse
	*              p - entitate de tip Produs
	* Postconditii: mesaj de tipul "Produs inexistent!", daca produsul cautat nu exita in lista de produse
	*               produsul cautat, altfel
	*/
	const Produs& cauta(const string& nume) override;

	/*Modifica numele unui fisier
	* Preconditii: this - entitate de tip FileRepo
	*			   filename_nou - numele nou al fisierului ( sir de caractere nevid)
	* Postconditii: numele fisierului este modificat
	*/
	void set_filename(string finename_nou);

	/*Distruge entitatea de tip FileRepo (destructor implicit)
	* Preconditii: this - entitate de tip FileRepo
	* Postconditii: entitatea a fost distrusa
	*/
	~FileRepo() = default;

private:
	string filename;

	/*Incarca podusele din fisier in lista de produse
	* Preconditii: this - entitate de tip FileRepo
	* Postconditii: produsele sunt incarcate in lista de produse
	*/
	void citeste_din_fisier();

	/*Incarca produsele din lista de produse in fisier
	* Preconditii: this - entitate de tip FileRepo
	* Postconditii: produsele sunt incarcate in fisier
	*/
	void scrie_in_fisier();
};

class RepoLab : public RepoAbstract {
public:
	/*Creeaza o entitate de tip RepoLab (constructor explicit)
	* Preconditii: probabilitate - o probabilitate ( numar real cuprins intre 0 si 1)
	* Postconditii: this - entitate de tip RepoLab
	*/
	RepoLab(double probabilitate) : probabilitate{ probabilitate } {};

	/*Returneaza lista tuturor produselor adaugate
	* Preconditii: this - entitate de tip RepoLab ce contine lista de produse
	* Postconditii: produse - lista de produse adaugate
	*/
	vector<Produs>& get_all() override;

	/*Adauga un produs in dictionarul de produse
	* Preconditii: this - entitate de tip RepoLab ce contine dictionarul de produse
	*              p - entitate de tip Produs
	* Postconditii: mesaj de tipul "Produs existent!" daca produsul exista deja in dictionarul de produse
	*                              "Probabilitate mare de a arunca exceptie.", daca se genereaza un numar mai mare decat probabilitatea data
	*               produsul este adaugat, altfel
	*/
	void adauga(const Produs& p) override;

	/*Modifica un produs din dictionarul de produse
	* Preconditii: this - entitate de tip RepoLab ce contine dictionarul de produse
	*              p1 - entitate de tip Produs
	*              p2 - entitate de tip Produs
	* Postconditii: mesaj de tipul "Produs inexistent!", daca produsul p1 nu exista in dictionarul de produse
	*                              "Probabilitate mare de a arunca exceptie.", daca se genereaza un numar mai mare decat probabilitatea data
	*               produsul este modificat, altfel
	*/
	void modifica(const Produs& p1, const Produs& p2) override;

	/*Sterge un produs din dictionarul de produse
	* Precodnitii: this - entitate de tip RepoLab ce contine dictionarul de produse
	*              p - entitate de tip Produs
	* Postconditii: mesaj de tipul "Produs inexistent!", daca produsul nu exista in dictionarul de produse
	*                              "Probabilitate mare de a arunca exceptie.", daca se genereaza un numar mai mare decat probabilitatea data
	*               produsul este sters, altfel
	*/
	void sterge(const Produs& p) override;

	/*Cauta un produs in dictionarul de produse
	* Preconditii: this - entitate de tip RepoLab ce contine dictionarul de produse
	*              p - entitate de tip Produs
	* Postconditii: mesaj de tipul "Produs inexistent!", daca produsul cautat nu exita in dictionarul de produse
	*                              "Probabilitate mare de a arunca exceptie.", daca se genereaza un numar mai mare decat probabilitatea data
	*               produsul cautat, altfel
	*/
	const Produs& cauta(const string& nume)  override;

private:
	/*Arunca exceptie de tip RepoException
	* Preconditii: this - entitate de tip RepoLab
	* Postconditii: arunca exceptie daca se genereaza un numar mai mare decat probabilitatea data
	*				-, altfel
	*/
	void exceptie();

	double probabilitate;
	map<pair<string, string>, Produs> map_produse;
	vector<Produs> produse;
};