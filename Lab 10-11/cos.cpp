#include <random>
#include <algorithm>
#include <fstream>
#include "cos.h"

using std::find;
using std::ofstream;

string CosException::get_mesaj()
{
	return mesaj;
}

const vector<Produs>& CosCumparaturi::cos_get_all() const noexcept
{
	return lista_cumparaturi;
}

const double& CosCumparaturi::cos_get_pret_total() noexcept
{
	return pret_total;
}

void CosCumparaturi::cos_adauga(const string& nume)
{
	const Produs& p = repo.cauta(nume);
	pret_total = pret_total + p.get_pret();
	lista_cumparaturi.push_back(p);
}

void CosCumparaturi::cos_sterge(const string& nume)
{
	const Produs& produs = repo.cauta(nume);
	auto it_produs = find_if(lista_cumparaturi.begin(), lista_cumparaturi.end(), [&nume](const Produs& p) {return p.get_nume() == nume;});
	if (it_produs != lista_cumparaturi.end())
	{
		lista_cumparaturi.erase(it_produs);
		pret_total = pret_total - produs.get_pret();
	}
	else
		throw CosException("Produs inexistent in cos!\n");
}

vector<Produs> CosCumparaturi::cos_genereaza(int nr)
{
	const auto& produse = repo.get_all();
	if (size(produse) == 0)
		throw CosException("Nu exita produse adaugate!\n");
	if (nr <= 0)
		throw CosException("Numar de produse invalid!\n");
	std::mt19937 mt{ std::random_device{}() };
	const std::uniform_int_distribution<> dist(0, static_cast<int>(produse.size() - 1));
	while (nr > 0)
	{
		const int& rndNr = dist(mt);
		lista_cumparaturi.push_back(produse.at(rndNr));
		pret_total = pret_total + produse.at(rndNr).get_pret();
		nr--;
	}
	return lista_cumparaturi;
}

void CosCumparaturi::cos_goleste() noexcept
{
	while (size(lista_cumparaturi) > 0)
		lista_cumparaturi.pop_back();
	pret_total = 0;
}

void CosCumparaturi::cos_exporta(string file_name)
{
	if (file_name == "")
		throw CosException("Nume de fisier invalid!\n");
	string csv{ ".csv" };
	if (!(file_name.find(csv) != std::string::npos))
		file_name = file_name + csv;
	ofstream out;
	out.open(file_name, std::ios::out | std::ios::trunc);
	if (!out.is_open())
		throw CosException("Nu se poate deschide fisierul!\n");
	const auto& produse = cos_get_all();
	for (const Produs& produs : produse)
		out << produs.get_nume() << "," << produs.get_tip() << "," << produs.get_pret() << "," << produs.get_producator() << "\n";
	out.close();
}