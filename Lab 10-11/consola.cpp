#include <iostream>
#include <string>
#include "domeniu.h"
#include "consola.h"

using std::string;
using std::vector;
using std::cin;
using std::cout;

void UI::ui_afiseaza()
{
	const auto& produse = srv.srv_get_all();
	if (size(produse) != 0)
	{
		cout << "Produsele adaugate sunt: \n";
		for (auto& produs : produse)
		{
			auto str = produs.produs_str();
			cout << str;
		}
	}
	else
		cout << "Nu exista produse adaugate!\n";
}
void UI::ui_adauga()
{
	string nume = "";
	string tip = "";
	double pret = 0;
	string producator = "";
	cout << "Introduceti numele produsului: ";
	cin >> nume;
	cout << "Introduceti tipul produsului: ";
	cin >> tip;
	cout << "Introduceti pretul produsului: ";
	cin >> pret;
	cout << "Introduceti producatorul produsului: ";
	cin >> producator;
	try
	{
		srv.srv_adauga(nume, tip, pret, producator);
		cout << "Produs adaugat cu succes!\n";
	}
	catch (RepoException& re)
	{
		cout << re.get_mesaj();
	}
	catch (ValidException& ve)
	{
		cout << ve.get_mesaj();
	}
}
void UI::ui_modifica()
{
	string nume = "", nume_nou = "";
	string tip = "", tip_nou = "";
	double pret = 0, pret_nou = 0;
	string producator = "", producator_nou = "";
	cout << "Introduceti numele produsului de modificat: ";
	cin >> nume;
	cout << "Introduceti tipul produsului de modificat: ";
	cin >> tip;
	cout << "Introduceti pretul produsului de modificat: ";
	cin >> pret;
	cout << "Introduceti producatorul produsului de modificat: ";
	cin >> producator;
	cout << "Introduceti numele nou: ";
	cin >> nume_nou;
	cout << "Introduceti tipul nou: ";
	cin >> tip_nou;
	cout << "Introduceti pretul nou: ";
	cin >> pret_nou;
	cout << "Introduceti producatorul nou: ";
	cin >> producator_nou;
	try
	{
		srv.srv_modifica(nume, tip, pret, producator, nume_nou, tip_nou, pret_nou, producator_nou);
		cout << "Produs modificat cu succes!\n";
	}
	catch (RepoException& re)
	{
		cout << re.get_mesaj();
	}
	catch (ValidException& ve)
	{
		cout << ve.get_mesaj();
	}
}
void UI::ui_sterge()
{
	string nume = "";
	string tip = "";
	double pret = 0;
	string producator = "";
	cout << "Introduceti numele produsului: ";
	cin >> nume;
	cout << "Introduceti tipul produsului: ";
	cin >> tip;
	cout << "Introduceti pretul produsului: ";
	cin >> pret;
	cout << "Introduceti producatorul produsului: ";
	cin >> producator;
	try
	{
		srv.srv_sterge(nume, tip, pret, producator);
		cout << "Produs sters cu succes.\n";
	}
	catch (RepoException& re)
	{
		cout << re.get_mesaj();
	}
	catch (ValidException& ve)
	{
		cout << ve.get_mesaj();
	}
}
void UI::ui_cauta()
{
	string nume = "";
	cout << "Introduceti numele produsului cautat: ";
	cin >> nume;
	try
	{
		const Produs& p = srv.srv_cauta(nume);
		cout << "Produsul cautat este: ";
		cout << p.produs_str();
	}
	catch (RepoException& re)
	{
		cout << re.get_mesaj();
	}
	catch (ValidException& ve)
	{
		cout << ve.get_mesaj();
	}
}

void UI::ui_filtreaza()
{
	string filtru = "";
	cout << "Introduceti filtrul dorit (nume/pret/producator): ";
	cin >> filtru;
	vector<Produs> filtrate{};
	if (filtru == "nume")
	{
		string nume;
		cout << "Introduceti numele dupa care sa se faca filtrarea: ";
		cin >> nume;
		try
		{
			srv.filtreaza_dupa_nume(filtrate, nume);
			if (size(filtrate) != 0)
			{
				cout << "Produsele filtrate dupa numele \"" << nume << "\" sunt: \n";
				for (auto& produs : filtrate)
				{
					const auto& str = produs.produs_str();
					cout << str;
				}
			}
			else
				cout << "Nu exista produse care sa respecte filtrul!\n";
		}
		catch (ValidException& ve)
		{
			cout << ve.get_mesaj();
		}

	}
	else if (filtru == "pret")
	{
		double pret;
		cout << "Introduceti pretul dupa care sa se faca filtrarea: ";
		cin >> pret;
		try
		{
			srv.filtreaza_dupa_pret(filtrate, pret);
			if (size(filtrate) != 0)
			{
				cout << "Produsele filtrate dupa pretul \"" << pret << "\" sunt: \n";
				for (auto& produs : filtrate)
				{
					const auto& str = produs.produs_str();
					cout << str;
				}
			}
			else
				cout << "Nu exista produse care sa respecte filtrul!\n";
		}
		catch (ValidException& ve)
		{
			cout << ve.get_mesaj();
		}
	}
	else if (filtru == "producator")
	{
		string producator;
		cout << "Introduceti producatorul dupa care sa se faca filtrarea: ";
		cin >> producator;
		try
		{
			srv.filtreaza_dupa_producator(filtrate, producator);
			if (size(filtrate) != 0)
			{
				cout << "Produsele filtrate dupa producatorul \"" << producator << "\" sunt: \n";
				for (auto& produs : filtrate)
				{
					const auto& str = produs.produs_str();
					cout << str;
				}
			}
			else
				cout << "Nu exista produse care sa respecte filtrul!\n";
		}
		catch (ValidException& ve)
		{
			cout << ve.get_mesaj();
		}
	}
	else
		cout << "Filtru invalid!\n";
}

void UI::ui_sorteaza()
{
	string proprietate = "";
	cout << "Introduceti proprietatea dupa care sa se faca sortarea (nume/pret/nume+tip): ";
	cin >> proprietate;
	vector<Produs> sortate{};
	if (proprietate == "nume" || proprietate == "pret" || proprietate == "nume+tip")
	{
		srv.sorteaza(sortate, proprietate);
		if (size(sortate) > 0)
		{
			cout << "Produsele sortate sunt:\n";
			for (const auto& produs : sortate)
			{
				const auto& str = produs.produs_str();
				cout << str;
			}
		}
		else
			cout << "Nu exista produse care sa resprecte proprietatea data!\n";
	}
	else
		cout << "Proprietate invalida!\n";
}

void UI::ui_raporteaza()
{
	const auto& rapoarte = srv.raport();
	if (size(rapoarte) != 0)
	{
		cout << "Tip" << " " << "Numar" << "\n";
		for (const auto& raport : rapoarte)
		{
			string cheie = raport.first;
			RaportDTO valoare = raport.second;
			cout << " " << cheie << "    " << valoare.get_count() << "\n";
		}
	}
	else
		cout << " Nu exista produse adaugate!";
}

void UI::ui_afiseaza_cos()
{
	const auto& lista_cumparaturi = srv.srv_cos_get_all();
	if (size(lista_cumparaturi) != 0)
	{
		cout << "Produse adaugate in cos sunt:\n";
		for (const auto& produs : lista_cumparaturi)
		{
			auto str = produs.produs_str();
			cout << str;
		}
	}
	else
		cout << "Nu exita produse adaugate in cos.\n";
	const double& pret_total = srv.srv_cos_get_pret_total();
	cout << "Pretul total al produselor din cos este: " << pret_total << ".\n";
}

void UI::ui_adauga_cos()
{
	string nume = "";
	cout << "Introduceti numele produsului: ";
	cin >> nume;
	try
	{
		srv.srv_cos_adauga(nume);
	}
	catch (RepoException& re)
	{
		cout << re.get_mesaj();
	}
	const double& pret_total = srv.srv_cos_get_pret_total();
	cout << "Pretul total al produselor din cos este: " << pret_total << ".\n";
}

void UI::ui_sterge_cos()
{
	string nume = "";
	cout << "Introduceti numele produsului: ";
	cin >> nume;
	try
	{
		srv.srv_cos_sterge(nume);
	}
	catch (RepoException& re)
	{
		cout << re.get_mesaj();
	}
	catch (CosException& ce)
	{
		cout << ce.get_mesaj();
	}
	const double& pret_total = srv.srv_cos_get_pret_total();
	cout << "Pretul total al produselor din cos este: " << pret_total << ".\n";
}

void UI::ui_exporta_cos()
{
	string file_name = "";
	cout << "Introduceti numele fisierului: ";
	cin >> file_name;
	try
	{
		srv.srv_cos_exporta(file_name);
		const double& pret_total = srv.srv_cos_get_pret_total();
		cout << "Pretul total al produselor din cos este: " << pret_total << ".\n";
	}
	catch (CosException& ce)
	{
		cout << ce.get_mesaj();
	}
}

void UI::ui_goleste_cos()
{
	srv.srv_cos_goleste();
	const double& pret_total = srv.srv_cos_get_pret_total();
	cout << "Pretul total al produselor din cos este: " << pret_total << ".\n";
}

void UI::ui_genereaza_cos()
{
	int nr = 0;
	cout << "Introduceti numarul total de produse pt. generare: ";
	cin >> nr;
	try
	{
		auto lista_cumparaturi_random = srv.srv_cos_genereaza(nr);
		cout << "Produse generate in cos sunt:\n";
		for (const auto& produs : lista_cumparaturi_random)
		{
			auto str = produs.produs_str();
			cout << str;
		}
		const double& pret_total = srv.srv_cos_get_pret_total();
		cout << "Pretul total al produselor din cos este: " << pret_total << ".\n";
	}
	catch (CosException& ce)
	{
		cout << ce.get_mesaj();
	}
}

void UI::ui_undo()
{
	try
	{
		srv.undo();
	}
	catch (ServiceException& se)
	{
		cout << se.get_mesaj();
	}
}
void UI::lista_comenzi()
{
	cout << '\n';
	cout << "exit - Iesire din aplicatie.\n";
	cout << "afiseaza - Afiseaza lista de produse.\n";
	cout << "adauga - Adauga un produs.\n";
	cout << "sterge - Sterge un produs.\n";
	cout << "modifica - Modifica un produs.\n";
	cout << "cauta - Cauta un produs.\n";
	cout << "filtreaza - Filtreaza lista de produse dupa o proprietate (pret/nume/producator).\n";
	cout << "sorteaza - Sorteaza lista de produse dupa o proprietate (pret/nume/nume+tip).\n";
	cout << "raporteaza - Raport tip : numar de produse care au tipul respectiv.\n";
	cout << "undo - Reface ultima operatie efectuata (adauga/sterge/modifica).\n";
	cout << "-------------------------------------------------------------------------------------\n";
	cout << "Funcationalitati pentru cosul de cumparaturi:\n";
	cout << "afiseaza_cos - Afiseaza produsele adaugate in cos.\n";
	cout << "adauga_cos - Adauga un produs in cos.\n";
	cout << "sterge_cos - Sterge un produs din cos.\n";
	cout << "genereaza_cos - Populeaza cosul cu produse generate aleator.\n";
	cout << "goleste_cos - Goleste cosul.\n";
	cout << "exporta_cos - Exporta produsele din cos intr-un fisier dat.\n";
	cout << '\n';
}
void UI::run()
{
	string cmd = "";
	lista_comenzi();
	while (true)
	{
		cout << "Introduceti comanda: ";
		cin >> cmd;

		if (cmd == "exit")
		{
			cout << "Iesire din aplicatie.\n";
			break;
		}
		if (cmd == "")
			continue;
		if (cmd == "afiseaza")
			ui_afiseaza();
		else if (cmd == "adauga")
			ui_adauga();
		else if (cmd == "modifica")
			ui_modifica();
		else if (cmd == "sterge")
			ui_sterge();
		else if (cmd == "cauta")
			ui_cauta();
		else if (cmd == "filtreaza")
			ui_filtreaza();
		else if (cmd == "sorteaza")
			ui_sorteaza();
		else if (cmd == "raporteaza")
			ui_raporteaza();
		else if (cmd == "afiseaza_cos")
			ui_afiseaza_cos();
		else if (cmd == "adauga_cos")
			ui_adauga_cos();
		else if (cmd == "sterge_cos")
			ui_sterge_cos();
		else if (cmd == "goleste_cos")
			ui_goleste_cos();
		else if (cmd == "genereaza_cos")
			ui_genereaza_cos();
		else if (cmd == "exporta_cos")
			ui_exporta_cos();
		else if (cmd == "undo")
			ui_undo();
		else
		{
			cout << "Comanda invalida!\n";
			continue;
		}
	}
}