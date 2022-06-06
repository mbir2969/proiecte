#pragma once
#include <vector>
#include <algorithm>

using std::vector;
using std::remove;

class Observer
{
public:
	/*Functie pur abstracta care realizeaza modificarile necesare sinctonizarii cu toti cei ce observa
	* Preconditii: this - entitate de tip Observer
	* Postconditii: "observatorul" curent este sinconizat cu toti ceilalti observatori
	*/
	virtual void update() = 0;
};

class Observable {
private:
	vector<Observer*> interesati;
protected:

	/*Notifica observatorii in legatura cu anumite modificari suferite de obiectul observat
	* Preconditii: this - entitate de tip Observable
	* Postconditii: toti observatorii sunt notificati de catre un observator care face modificarea
	*/
	void notify();
public:
	/*Adauga o entitate la multimea de observatori ai obiectului observat
	* Preconditii: this - entitate de tip Observable
	*              o - entitate de tip Observer
	* Postconditii: entiatatea de tip Observer "observa" entitatea de tip Observable (este notificata in legatura cu modificarile suferite de entiatea observata)
	*/
	void addObserver(Observer* o);

	/*Elimina un observator din multimea observatorilor obiectului obervabil
	* Preconditii: this - entitate de tip Observable
	*              o - entitate de tip Observer
	* Postconditii: entitatea de tip Observer nu mai "observa" entitatea de tip Observable ( nu mai este notificata in legatura cu modificarile suferite de entiatea observata)
	*/
	void removeObserver(Observer* o);
};

