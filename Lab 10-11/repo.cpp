#include <algorithm>
#include <random>
#include <fstream>
#include "domeniu.h"
#include "repo.h"

using std::find;
using std::find_if;
using std::ifstream;
using std::ofstream;
using std::pair;

string RepoException::get_mesaj()
{
	return mesaj;
}

const vector<Produs>& Repo::get_all() noexcept
{
	return produse;
}

void Repo::adauga(const Produs& produs)
{
	for (const Produs& p : produse)
		if (produs.produse_egale(p) == true)
			throw RepoException("Produs existent!\n");
	produse.push_back(produs);
}

void Repo::modifica(const Produs& p1, const Produs& p2)
{
	for (auto& produs : produse)
		if (p1.produse_egale(produs))
		{
			produs.set_nume(p2.get_nume());
			produs.set_tip(p2.get_tip());
			produs.set_pret(p2.get_pret());
			produs.set_producator(p2.get_producator());
			return;
		}
	throw RepoException("Produs inexistent!\n");
}

void Repo::sterge(const Produs& p)
{
	auto it_produs = find_if(produse.begin(), produse.end(), [&p](const Produs& produs) {return p.produse_egale(produs);});
	if (it_produs != produse.end())
		produse.erase(it_produs);
	else
		throw RepoException("Produs inexistent!\n");
}

const Produs& Repo::cauta(const string& nume)
{
	auto it_produs = find_if(produse.begin(), produse.end(), [&nume](const Produs& p) {return p.get_nume() == nume;});
	if (it_produs == produse.end())
		throw RepoException("Produs inexistent!\n");
	return *it_produs;
}

string FileRepoException::get_mesaj()
{
	return mesaj;
}

void FileRepo::citeste_din_fisier()
{
	ifstream in(filename);
	if (!in.is_open())
		throw FileRepoException("Fisierul nu se poate deschide!\n");
	Produs p{ "default", "default", 0, "default" };
	while (in.good())
	{
		in >> p;
		if (in.eof())
			break;
		produse.push_back(p);
	}
	in.close();
}

void FileRepo::scrie_in_fisier()
{
	ofstream out(filename);
	//out.open(filename, std::ios::out);
	if (!out.is_open())
		throw FileRepoException("Fisierul nu se poate deschide!\n");
	const auto& p = get_all();
	for (const auto& produs : p)
	{
		out << produs.get_nume() << ' ' << produs.get_tip() << ' ' << produs.get_pret() << ' ' << produs.get_producator() << '\n';
	}
	out.close();
}

const vector<Produs>& FileRepo::get_all() noexcept
{
	return produse;
}

void FileRepo::adauga(const Produs& p)
{
	Repo::adauga(p);
	scrie_in_fisier();
}

void FileRepo::modifica(const Produs& p1, const Produs& p2)
{
	Repo::modifica(p1, p2);
	scrie_in_fisier();
}

void FileRepo::sterge(const Produs& p)
{
	Repo::sterge(p);
	scrie_in_fisier();
}


const Produs& FileRepo::cauta(const string& nume)
{
	return Repo::cauta(nume);
}

void FileRepo::set_filename(string filename_nou)
{
	filename = filename_nou;
}

void RepoLab::exceptie()
{
	std::random_device rd;
	std::default_random_engine eng(rd());
	const std::uniform_real_distribution<float> distr(0, 1);
	const auto nr = distr(eng);
	if (probabilitate - nr > 0.00001)
		throw RepoException("Probabilitate mare de a arunca exceptii.\n");
}

vector<Produs>& RepoLab::get_all()
{
	produse.clear();
	for (auto& elem : map_produse)
		produse.push_back(elem.second);
	return produse;
}

void RepoLab::adauga(const Produs& p)
{
	exceptie();
	for (const Produs& produs : produse)
		if (p.produse_egale(produs) == true)
			throw RepoException("Produs existent!\n");
	pair<string, string> cheie{ p.get_nume(), p.get_tip() };
	map_produse.insert(pair<pair<string, string>, Produs>(cheie, p));
}
void RepoLab::modifica(const Produs& p1, const Produs& p2)
{
	exceptie();
	for (auto& elem : map_produse)
		if (elem.second.produse_egale(p1) == true)
		{
			pair<string, string> cheie_veche{ p1.get_nume(), p1.get_tip() };
			pair<string, string> cheie_noua{ p2.get_nume(), p2.get_tip() };
			auto it = map_produse.find(cheie_veche);
			map_produse.erase(it);
			map_produse[cheie_noua] = p2;
			return;
		}
	throw RepoException("Produs inexistent!\n");
}
void RepoLab::sterge(const Produs& p)
{
	exceptie();
	pair<string, string> cheie{ p.get_nume(),p.get_tip() };
	auto it_produs = map_produse.find(cheie);
	if (it_produs != map_produse.end())
		map_produse.erase(it_produs);
	else
		throw RepoException("Produs inexistent!\n");
}
const Produs& RepoLab::cauta(const string& nume)
{
	exceptie();
	for (auto& elem : map_produse)
		if (elem.first.first == nume)
			return elem.second;
	throw RepoException("Produs inexistent!\n");
}