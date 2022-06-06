#include <algorithm>
#include <vector>
#include "domeniu.h"
#include "cos.h"
#include "service.h"
#include "sortare.h"
#include "undo.h"

using std::vector;
using std::sort;
using std::copy_if;

void RaportDTO::numara() noexcept
{
	count++;
}

const int& RaportDTO::get_count() const noexcept
{
	return count;
}

const string& RaportDTO::get_tip() const noexcept
{
	return tip;
}

string ServiceException::get_mesaj()
{
	return mesaj;
}

const vector<Produs>& Service::srv_get_all() noexcept
{
	return repo.get_all();
}

void Service::srv_adauga(string nume, string tip, double pret, string producator)
{
	valid.valideaza_produs(nume, tip, pret, producator);
	Produs p{ nume, tip, pret, producator };
	repo.adauga(p);
	actiuni_undo.push_back(new UndoAdauga{ repo, p });
}

void Service::srv_modifica(string nume, string tip, double pret, string producator, string nume_nou, string tip_nou, double pret_nou, string producator_nou)
{
	valid.valideaza_produs(nume_nou, tip_nou, pret_nou, producator_nou);
	Produs p1{ nume, tip, pret, producator };
	Produs p2{ nume_nou, tip_nou, pret_nou, producator_nou };
	repo.modifica(p1, p2);
	actiuni_undo.push_back(new UndoModifica{ repo, p2, p1 });
}

void Service::srv_sterge(string nume, string tip, double pret, string producator)
{
	valid.valideaza_produs(nume, tip, pret, producator);
	Produs p{ nume, tip, pret, producator };
	repo.sterge(p);
	actiuni_undo.push_back(new UndoSterge{ repo, p });
}

const Produs& Service::srv_cauta(const string& nume) const
{
	valid.valideaza_produs(nume, "default", 1, "default");
	return repo.cauta(nume);
}

void Service::filtreaza_dupa_nume(vector<Produs>& filtrate, const string& nume) const
{
	valid.valideaza_produs(nume, "default", 1, "default");
	const auto& produse = repo.get_all();
	copy_if(produse.begin(), produse.end(), std::back_inserter(filtrate), [&nume](const Produs& p) {return p.get_nume() == nume; });
}

void Service::filtreaza_dupa_pret(vector<Produs>& filtrate, double pret) const
{
	valid.valideaza_produs("default", "default", pret, "default");
	const auto& produse = repo.get_all();
	copy_if(produse.begin(), produse.end(), std::back_inserter(filtrate), [&pret](const Produs& p) noexcept {return p.get_pret() == pret; });
}

void Service::filtreaza_dupa_producator(vector<Produs>& filtrate, const string& producator) const
{
	valid.valideaza_produs("default", "default", 1, producator);
	const auto& produse = repo.get_all();
	copy_if(produse.begin(), produse.end(), std::back_inserter(filtrate), [&producator](const Produs& p) {return p.get_producator() == producator; });
}


void Service::sorteaza(vector<Produs>& sortate, const string& proprietate) const
{
	sortate = repo.get_all();
	if (proprietate == "nume")
		sort(sortate.begin(), sortate.end(), [](const Produs& p1, const Produs& p2) {return p1.get_nume() < p2.get_nume();});
	else if (proprietate == "pret")
		sort(sortate.begin(), sortate.end(), [](const Produs& p1, const Produs& p2) noexcept {return p1.get_pret() < p2.get_pret();});
	else
		sort(sortate.begin(), sortate.end(), [](const Produs& p1, const Produs& p2) {if (p1.get_nume() == p2.get_nume()) return p1.get_tip() < p2.get_tip(); else return p1.get_nume() < p2.get_nume();});
}

const vector<Produs>& Service::srv_cos_get_all() const noexcept
{
	return cos.cos_get_all();
}

const double& Service::srv_cos_get_pret_total()
{
	const double& pret_total = cos.cos_get_pret_total();
	return pret_total;
}

void Service::srv_cos_adauga(const string& nume) 
{
	valid.valideaza_produs(nume, "default", 0, "default");
	cos.cos_adauga(nume);
	notify();
}

void Service::srv_cos_sterge(const string& nume)
{
	valid.valideaza_produs(nume, "default", 0, "default");
	cos.cos_sterge(nume);
	notify();
}

vector<Produs> Service::srv_cos_genereaza(int nr)
{
	const auto& generate = cos.cos_genereaza(nr);
	notify();
	return generate;
}

void Service::srv_cos_goleste() noexcept
{
	cos.cos_goleste();
	notify();
}

void Service::srv_cos_exporta(const string& file_name)
{
	cos.cos_exporta(file_name);
}

unordered_map<string, RaportDTO> Service::raport()
{
	unordered_map<string, RaportDTO> rapoarte;
	const auto& produse = repo.get_all();
	for (const auto& produs : produse)
		if (rapoarte.find(produs.get_tip()) != rapoarte.end())
			rapoarte[produs.get_tip()].numara();
		else
			rapoarte[produs.get_tip()] = RaportDTO(produs.get_tip());
	return rapoarte;
}

void Service::undo()
{
	if (actiuni_undo.empty())
		throw ServiceException("Nu exista actiuni de refacut!\n");
	ActiuneUndo* actiune = actiuni_undo.back();
	actiune->doUndo();
	actiuni_undo.pop_back();
	delete actiune;
}

Service::~Service()
{
	for (ActiuneUndo* actiune : actiuni_undo)
		delete actiune;
}
