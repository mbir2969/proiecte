#pragma once
#include <iostream>
#include "service.h"

class UI
{
public:
	/*Creeaza o entitate de tip UI
	* Preconditii: ui_srv - entitate de tip service
	* Postcondiiti: ui - entitate de tip UI cu campul srv initializat
	*/
	UI(Service& ui_srv) noexcept : srv{ ui_srv } {};

	/*Constructor de copiere
	* Preconditii: this - entitate de tip UI
	*              other - entitate de tip UI
	* Postconditii: constructorul de copiere a fost eliminat
	*/
	UI(const UI& other) = delete;

	/*Afiseaza produsele adaugate
	* Preconditii: this - entitate de tip UI
	* Postconditii: mesaje de interactiune cu utilizatorul
	*               mesaj de tipul "Nu exista produse adaugate!", daca nu exista produse adaugate
	*               sunt afisate produsele adaugate, altfel
	*/
	void ui_afiseaza();

	/*Adauga un produs in lista de produse
	* Preconditii: this - entitate de tip UI
	* Postconditii: mesaje de interactiune cu utilizatorul
	*               mesaj de tipul "Produs adaugat cu succes!", daca produsul este adaugat cu succes
	*               mesaje de eroare: de tip validare, daca datele introduse nu sunt valide
	*                                 de tip repo, daca produsul exista deja in lista de produse
	*/
	void ui_adauga();

	/*Modifica un produs din lista de produse
	* Preconditii: this - entitate de tip UI
	* Postconditii: mesaje de interactiune cu utilizatorul
	*               mesaj de tipul "Produs modificat cu succes!", daca produsul este modificat cu succes
	*               mesaje de eroare: de tip validare, daca datele introduse nu sunt valide
	*                                 de tip repo, daca produsul nu exista in lista de produse
	*/
	void ui_modifica();

	/*Sterge un produs din lista de produse
	* Preconditii: this - entitate de tip UI
	* Postconditii: mesaje de interactiune cu utilizatorul
	*               mesaj de tipul "Produs sters cu succes!", daca produsul este sters cu succes
	*               mesaje de eroare: de tip validare, daca datele introduse nu sunt valide
	*                                 de tip repo, daca produsul nu exista in lista de produse
	*/
	void ui_sterge();

	/*Cauta un produs in lista de produse
	* Precodnitii: this - entitate de tip UI
	* Postcodnitii: mesaje de interactiune cu utilizatorul
	*               produsul este afisat, daca este gasit in lista de produse
	*               mesaje de eroare: de tip validare, daca datele introduse nu sunt valide
	*                                 de tip repo, daca produsul nu exista in lista de produse
	*/
	void ui_cauta();

	/*Filtreaza lista de produse in functie de un filtru dat
	* Preconditii: this - entitate de tip UI
	* Postconditii: mesaje de interactiune cu utilizatorul
	*               lista cu produsele care respecta filtrul dat, daca exista astfel de produse
	*               mesaj de tipul "Nume invalid!", daca numele introdus este invalid
	*                              "Pret invalid!", daca pretul introdus este invalid
	*                              "Producator invalid!", daca producatorul introdus este invalid
	*                              "Nu exista produse care sa respecte filtrul!", daca nu exista astfel de produse
	*/
	void ui_filtreaza();

	/*Sorteaza lista de produse in functie de o proprietate data
	* Preconditii: this - entitate de tip UI
	* Postconditii: mesaje de interactiune cu utilizatorul
	*               lista cu produsele sortate in functie de o proprietate data
	*               mesaj de tipul  "Nu exista produse care sa respecte proprietatea data!", daca nu exista astfel de produse
	*/
	void ui_sorteaza();

	/*Realizeaza un raport ( tip : nr de produse care au acest tip)
	* Preconditii: this - entitate de tip UI
	* Postconditii: mesaje de interactiune cu utilizatorul
	*               dictionarul ce contine tipurile si numarul de produse corespunzator
	*               mesaj de tipul "Nu exista produse adaugate!", daca nu exista produse in lista de produse
	*/
	void ui_raporteaza();

	/*Afiseaza produsele din cosul de cumparaturi
	* Preconditii: this - entitate de tip UI
	* Postconditii: mesaje de interactiune cu utilizatorul
	*               mesaj de tipul "Nu exita produse adaugate in cos.", daca nu exista produse adaugate in cos
	*               sunt afisate produsele adaugate, altfel
	*/
	void ui_afiseaza_cos();

	/*Adauga un produs in cosul de cumparaturi
	* Preconditii: this - entitate de tip UI
	* Postconditii: mesaje de interactiune cu utilizatorul
	*               produsul este adaugat in cos
	*/
	void ui_adauga_cos();

	/*Sterge un produs din cosul de cumparaturi
	* Preconditii: this - entitate de tip UI
	* Postconditii: mesaje de interactiune cu utilizatorul
	*               mesaj de tipul "Produs inexistent!", daca produsul nu exista in lista de produse
	*                              "Produs inexistent in cos!", daca produsul nu exista in cosul de cumparaturi
	*               produsul este sters din cos, altfel
	*/
	void ui_sterge_cos();

	/*Genereaza produse in cosul de cumparaturi
	* Preconditii: this - entitate de tip UI
	* Postconditii: mesaje de interactiune cu utilizatorul
	*               "Nu exita produse adaugate!", daca nu exista produse adaugate in lista de produse
	*               "Numar de produse invalid!", daca numarul de produse ce trebuie generate este negativ sau nul
	*               lista cu produsele generate in cos, altfel
	*/
	void ui_genereaza_cos();

	/*Exporta produsele din cos intr-un fisier
	* Preconditii: this - entitate de tip UI
	* Postconditii: mesaje de interactiune cu utilizatorul
	*               mesaj de tipul "Nu se poate deschide fisierul!", daca fisierul nu poate fi deschis
	*               produsele sunt transferate in fisier, altfel
	*/
	void ui_exporta_cos();

	/*Goleste cosul de cumparaturi
	* Preconditii: this - entitate de tip UI
	* Postconditii: mesaje de interactiune cu utilizatorul
	*/
	void ui_goleste_cos();

	/*Reface ultima operatie efectuata (adaugare/modificare/stergere)
	* Preconditii: this - entitate de tip UI
	* Postconditii: mesaje de interactiune cu utilizatorul
	*               mesaj de tipul "Nu exista actiuni de refacut!", daca nu mai exista operatii realizate in lista de actiuni
	*               se face undo la ultima operatie efectuata, altfel
	*/
	void ui_undo();

	/*Afiseaza meniul aplictiei
	* Preconditii: ui - entitate de ti UI
	* Postcodnitii: mesaje reprezentand lista de comenzi disponibile
	*/
	void lista_comenzi();

	/*Coordoneaza comenzile
	* Preconditii: ui - entitate de tip UI
	* Postconditii: mesaje de interactiune cu utilizatorul
	*               executa comenzile introduse
	*               mesaj de tipul "Comanda invalida!", daca comanda este invalida
	*/
	void run();
private:
	Service& srv;
};

