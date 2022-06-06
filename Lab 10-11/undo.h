#pragma once

#include "domeniu.h"
#include "repo.h"

class ActiuneUndo {
public:
	/*Reface o anumita operatie
	* Preconditii: this - entitate de tip ActiuneUndo
	* Postconditii: operatia a fost refacuta
	*/
	virtual void doUndo() = 0;

	/*Distruge entitatea de tip ActiuneUndo (destructor implicit)
	* Preconditii: this - entitate de tip ActiuneUndo
	* Postconditii: entitatea a fost distrusa
	*/
	virtual ~ActiuneUndo() = default;
};

class UndoAdauga : public ActiuneUndo {
public:
	/*Creeaza o entitate de tip UndoAdauga
	* Preconditii: this - entitate de tip UndoAdauga
	* Postconditii: entitate de tip UndoAdauga cu campurile repo si produs_adaugat initializate
	*/
	UndoAdauga(RepoAbstract& repo, const Produs& produs_adaugat) : repo{ repo }, produs_adaugat{ produs_adaugat } {};

	/*Reface ultima operatie, daca aceata este adaugare
	* Preconditii: this - entitate de tip UndoAdauga
	* Postconditii: operatia de adaugare a fost refacuta
	*/
	void doUndo() override
	{
		repo.sterge(produs_adaugat);
	}
private:
	Produs produs_adaugat;
	RepoAbstract& repo;
};

class UndoSterge : public ActiuneUndo {
public:
	/*Creeaza o entitate de tip UndoSterge
	* Preconditii: this - entitate de tip UndoSterge
	* Postconditii: entitate de tip UndoSterge cu campurile repo si produs_sters initializate
	*/
	UndoSterge(RepoAbstract& repo, const Produs& produs_sters) : repo{ repo }, produs_sters{ produs_sters } {};

	/*Reface ultima operatie, daca aceata este stergere
	* Preconditii: this - entitate de tip UndoSterge
	* Postconditii: operatia de steregere a fost refacuta
	*/
	void doUndo() override
	{
		repo.adauga(produs_sters);
	}
private:
	Produs produs_sters;
	RepoAbstract& repo;
};

class UndoModifica : public ActiuneUndo {
public:
	/*Creeaza o entitate de tip UndoModifica
	* Preconditii: this - entitate de tip UndoModifica
	* Postconditii: entitate de tip UndoSterge cu campurile repo, produs_nou si produs_vechi initializate
	*/
	UndoModifica(RepoAbstract& repo, const Produs& produs_nou, const Produs& produs_vechi) : repo{ repo }, produs_nou{ produs_nou }, produs_vechi{ produs_vechi }{};

	/*Reface ultima operatie, daca aceata este modificare
	* Preconditii: this - entitate de tip UndoModifica
	* Postconditii: operatia de modificare a fost refacuta
	*/
	void doUndo() override
	{
		repo.modifica(produs_nou, produs_vechi);
	}

private:
	Produs produs_nou;
	Produs produs_vechi;
	RepoAbstract& repo;
};