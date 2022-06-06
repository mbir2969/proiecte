#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "validare.h"
#include "repo.h"
#include "cos.h"
#include "sortare.h"
#include "undo.h"
#include "observer.h"

using std::string;
using std::vector;
using std::unordered_map;

class RaportDTO
{
public:

	/*Creeaza o entitate de tip RaportDTO
	* Preconditii: this - entitate de tip RaportDTO
	*              tip - tipul produselor
	*              count - numarul de produse care au tipul respectiv (numar natural nenul)
	* Postonditii: this - entitate de tip RaportDTO cu campurile tip si count initializate
	*/
	RaportDTO() noexcept :tip{ "default" }, count{ 0 }{};

	/*Creeaza o entitate de tip RaportDTO
	* Preconditii: this - entitate de tip RaportDTO
	*              tip - tipul produselor
	* Postonditii: this - entitate de tip RaportDTO cu campurile tip si count initializate
	*/
	RaportDTO(string tip) : tip{ tip }, count{ 1 }{};

	/*Incrementeaza campul count
	* Preconditii: this - entitate de tip RaportDTO
	* Postconditii: campul count este incrementat
	*/
	void numara() noexcept;

	/*Returneaza numarul de produse care au tipul "tip"
	* Preconditii: this - entitate de tip RaportDTO
	* Postconditii: count - numarul de produse care au tipul "tip"
	*/
	const int& get_count() const noexcept;

	/*Returneaza tipul produselor adaugate
	* Preconditii: this - entitate de tip RaportDTO
	* Postconditii: tip - tipul produselor adaugate
	*/
	const string& get_tip() const noexcept;

private:
	string tip;
	int count;
};

class ServiceException
{
public:
	/*Creeaza o exceptie
	* Preconditii: se - mesaj de eroare
	* Postconditii: this - entitate de tip ServiceException cu campul mesaj initializat
	*/
	ServiceException(string se) : mesaj{ se } {};

	/*Returneaza mesajul unei exceptii
	* Preconditii: this - enritate de tip ServiceException
	* Postconditii: mesaj - mesajul exceptiei din Service
	*/
	string get_mesaj();
private:
	string mesaj;
};


class Service :public Observable
{
public:
	/*Creeaza o entitate de tip Service (constructor explicit)
	* Preconditii: srv_repo - entitate de tip Repo
	*              srv_valid - entitate de tip Valid
	* Postconditii: service - entitate de tip service cu atributele repo si valid initializate
	*/
	Service(RepoAbstract& srv_repo, Valid& srv_valid, Sortare& srv_sortare, CosCumparaturi& srv_cos) noexcept : repo{ srv_repo }, valid{ srv_valid }, sortare{ srv_sortare }, cos{ srv_cos }{};

	/*Creeaza o entitate de tip service (constructor implicit)
	* Preconditii: -
	* Postconditii: this - entitate de tip Service cu atributele repo si valid initializate
	*/
	Service() = default;

	/*Constructor de copiere
	* Precodnitii: this - entitate de tip Service
	*              other - entitate de tip Service
	* Postconditii: constructorul de copiere a fost eliminat
	*/
	Service(const Service& other) = delete;

	/*Returneaza lista de produse
	* Preconditii: this - entitate de tip Service
	* Postconditii: lista de produse
	*/
	const vector<Produs>& srv_get_all() noexcept;

	/*Coordoneaza adaugarea unui produs la lista de produse
	* Preconditii: this - entitate de tip Service
	*              nume - numele produsului
	*              tip - tipul produsului
	*              pret - pretul produsului
	*              producator - proucatorul produsului
	* Postconditii: mesaje de tipul: "Nume invalid!", daca produsul are numele invalid
	*                                "Tip invalid!", daca produsul are tipul invalid
	*                                "Pret invalid!", daca produsul are pretul invalid
	*                                "Producator invalid!", daca produsul are producatorul invalid
	*                                "Produs existent!", daca produsul exista deja in lista de produse
	*               produsul este adaugat, daca nu sunt erori
	*/
	void srv_adauga(string nume, string tip, double pret, string producator);

	/*Coordoneaza modificarea unui produs
	* Preconditii: this - entitate de tip Service
	*              nume - numele produsului
	*              tip - tipul produsului
	*              pret - pretul produsului
	*              producator - proucatorul produsului
	*              nume_nou - numele nou al produsului
	*              tip_nou - tipul nou al produsului
	*              pret_nou - pretul nou al produsului
	*              producator_nou - proucatorul nou al produsului
	* Postconditii: mesaje de tipul: "Nume invalid!", daca numele nou este invalid
	*                                "Tip invalid!", daca tipul nou este invalid
	*                                "Pret invalid!", daca pretul nou este  invalid
	*                                "Producator invalid!", daca producatorul nou este invalid
	*                                "Produs inexistent!", daca produsul nu exista in lista de produse
	*               produsul este modificat, daca nu sunt erori
	*/
	void srv_modifica(string nume, string tip, double pret, string producator, string nume_nou, string tip_nou, double pret_nou, string producator_nou);

	/*Coordoneaza stergerea unui produs din lista de produse
	* Preconditii: this - entitate de tip Service
	*              nume - numele produsului
	*              tip - tipul produsului
	*              pret - pretul produsului
	*              producator - proucatorul produsului
	* Postconditii: mesaje de tipul: "Nume invalid!", daca numele introdus este invalid
	*                                "Tip invalid!", daca tipul introdus este invalid
	*                                "Pret invalid!", daca pretul introdus este  invalid
	*                                "Producator invalid!", daca producatorul introdus este invalid
	*                                "Produs inexistent!", daca produsul nu exista in lista de produse
	*               produsul este sters, daca nu sunt erori
	*/
	void srv_sterge(string nume, string tip, double pret, string producator);

	/*Coordoneaza cautarea unui produs in lista de produse
	* Preconditii: this - entitate de tip Service
	*              nume - numele produsului
	*              tip - tipul produsului
	*              pret - pretul produsului
	*              producator - proucatorul produsului
	* Postconditii: mesaje de tipul: "Nume invalid!", daca numele introdus este invalid
	*                                "Tip invalid!", daca tipul introdus este invalid
	*                                "Pret invalid!", daca pretul introdus este  invalid
	*                                "Producator invalid!", daca producatorul introdus este invalid
	*                                "Produs inexistent!", daca produsul nu exista in lista de produse
	*               produsul este returnat, daca nu sunt erori
	*/
	const Produs& srv_cauta(const string& nume) const;

	/*Filtreaza lista de produse dupa nume
	* Preconditii: this - entitate de tip Service
	*              filtrate - lista care contine produsele filtrate
	*              nume - numele dupa care se cauta in lista (sir de caractere)
	* Postconditii: lista de produse care au numele dat
	*/
	void filtreaza_dupa_nume(vector<Produs>& filtrate, const string& nume) const;

	/*Filtreaza lista de produse dupa pret
	* Preconditii: this - entitate de tip Service
	*              filtrate - lista care contine produsele filtrate
	*              pret - pretul dupa care se cauta in lista (numar rational)
	* Postconditii: lista de produse care au pretul dat
	*/
	void filtreaza_dupa_pret(vector<Produs>& filtrate, double pret) const;

	/*Filtreaza lista de produse dupa producator
	* Preconditii: this - entitate de tip Service
	*              filtrate - lista care contine produsele filtrate
	*              producator - producatorul dupa care se cauta in lista (sirde caractere)
	* Postconditii: lista de produse care au producatorul dat
	*/
	void filtreaza_dupa_producator(vector<Produs>& filtrate, const  string& producator) const;


	/*Sorteaza lista de produse dupa o proprietate data
	* Preconditii: this - entitate de tip Service
	*              sortate - lista care contine produsele sortate
	*              proprietate - proprietatea dupa care se va face sortarea
	* Postconditii: lista de produse sortata dupa proprietatea data
	*/
	void sorteaza(vector<Produs>& sortate, const string& proprietate) const;

	/*Returneaza lista de produse adaugate in cos
	* Preconditii: this - entitate de tip Service
	* Postconditii: lista de produse din cosul de cumparaturi
	*/
	const vector<Produs>& srv_cos_get_all() const noexcept;

	/*Returneaza pretul total al produselor din colu de cumparaturi
	* Preconditii: this - entitate de tip Service
	* Postconditii: pretul total al produselor din cosul de cumparaturi
	*/
	const double& srv_cos_get_pret_total();

	/*Coodoneaza adaugarea unui produs in cosul de cumparaturi
	* Preconditii: this - entitate de tip Service
	*              nume - numele produsului (sir de caractere nevid)
	* Postconditii: produsul este adaugat in cosul de cumparaturi
	*/
	void srv_cos_adauga(const string& nume);

	/*Coordoneaza stergerea unui produs din cosul de cumparaturi
	* Preconditii: this - entitate de tip Service
	*              nume - numele produsului (sir de caractere nevid)
	* Postconditii: mesaj de tipul "Produs inexistent in cos!", daca produsul nu exista in cosul de cumparaturi
	*               produsul este sters, altfel
	*/
	void srv_cos_sterge(const string& nume);

	/*Coordoneaza generarea random de produse in cosul de cumparaturi
	* Preconditii: this - entitate de tip Service
	*              nr - numarul de produse ce trebuie generate (numar natural nenul)
	* Postconditii: mesaje de tipul "Nu exita produse adaugate!", daca nu exista produse in lista de produse
	*                               "Numar de produse invalid!", daca numarul de produse este negativ sau nul
	*               lista cu produsele generate in cosul de cumparaturi, altfel
	*/
	vector<Produs> srv_cos_genereaza(int nr);

	/*Coordoneaza golirea cosului de cumparaturi
	* Preconditii: this - entitate de tip Service
	* Postconditii: cosul de cumparaturi este golit
	*/
	void srv_cos_goleste() noexcept;

	/*Exporta produsele din cos intr-un fisier
	* Preconditii: this - entitate de tip Service
	*			   file_name - numele fisierului in care se face export ( sir de caractere nevid)
	* Postconditii: mesaj de tipul "Nu se poate deschide fisierul!", daca fisierul nu poate fi deschis
	*               produsele din cos sunt exportate, altfel
	*/
	void srv_cos_exporta(const string& file_name);

	/*Retureaza rapoartele tip:numar de produse ce au tipul "tip"
	* Preconditii: this - entitata de tip Service
	* Postconditii: rapoarte - dictionar cu cheie = tip si valoare = numar de produse cu tipul "tip"
	*/
	unordered_map<string, RaportDTO> raport();

	/*Realizeaza undo la ultima operatie efectuata (adaugare/modificare/stergere)
	* Preconditii: this - entitate de tip Service
	* Postconditii: mesaj de tipul "Nu exista actiuni de refacut!", daca nu mai exista operatii realizate in lista de actiuni
	*               se face undo la ultima operatie efectuata, altfel
	*/
	void undo();

	/*Distrtuge entitatea de tip Service (destructor explicit)
	* Preconditii: this - entitate de tip Service
	* Postconditii: entitatea este distrusa
	*/
	~Service();

private:
	RepoAbstract& repo;
	Valid& valid;
	Sortare& sortare;
	CosCumparaturi& cos;
	vector<ActiuneUndo*> actiuni_undo;
};
