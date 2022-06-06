#include <iostream>
#include <fstream>
#include <assert.h>
#include <math.h>
#include <sstream>
#include "teste.h"
#include "domeniu.h"
#include "validare.h"
#include "repo.h"
#include "cos.h"
#include "service.h"
#include "sortare.h"

using std::string;
using std::stringstream;
using std::ofstream;
using std::ifstream;
using std::cout;

void ruleaza_teste_domeniu()
/*Testeaza metodele din domeniu*/
{
	cout << "Start domain tests.\n";

	string nume{ "biscuiti" };
	string tip{ "dulci" };
	const double& pret{ 10.5 };
	string producator{ "Milka" };
	Produs p{ nume, tip, pret, producator };
	assert(p.get_nume() == "biscuiti");
	assert(p.get_tip() == "dulci");
	assert(fabs(p.get_pret() - 10.5) < 0.000001);
	assert(p.get_producator() == "Milka");
	p.set_nume("paste");
	p.set_tip("fainoase");
	p.set_pret(10.10);
	p.set_producator("Maluku");
	assert(p.get_nume() == "paste");
	assert(p.get_tip() == "fainoase");
	assert(fabs(p.get_pret() - 10.10) < 0.000001);
	assert(p.get_producator() == "Maluku");
	Produs p2{ "paste", "fainoase", 10.10, "Maluku" };
	assert(p.produse_egale(p2) == true);
	Produs p3{ "macaroane", "fainoase", 10.10, "Maluku" };
	assert(p.produse_egale(p3) == false);
	assert(p.produs_str() == "paste fainoase 10.100000 Maluku\n");
	assert(p3.produs_str() == "macaroane fainoase 10.100000 Maluku\n");
	p2 = p3;
	assert(p2.produse_egale(p3));

	stringstream ss;
	ss << p;
	assert(ss.str() == "paste fainoase 10.1 Maluku");
	Produs p4;
	ss >> p4;
	assert(p4.get_nume() == "paste");
	assert(p4.get_tip() == "fainoase");
	assert(fabs(p4.get_pret() - 10.1) < 0.000001);
	assert(p4.get_producator() == "Maluku");

	cout << "Stop domain tests.\n";
}

void ruleaza_teste_validare()
/*Testeaza metodele din validare*/
{
	cout << "Start validation tests.\n";

	Valid validator;
	validator.valideaza_produs("paste", "fainoase", 10.10, "Maluku");
	assert(true);
	try
	{
		validator.valideaza_produs("", "fainoase", 10, "Maluku");
	}
	catch (ValidException& ve)
	{
		assert(ve.get_mesaj() == "Nume invalid!\n");
	}
	try
	{
		validator.valideaza_produs("paste", "", 10, "Maluku");
	}
	catch (ValidException& ve)
	{
		assert(ve.get_mesaj() == "Tip invalid!\n");
	}
	try
	{
		validator.valideaza_produs("paste", "fainoase", -10, "Maluku");
	}
	catch (ValidException& ve)
	{
		assert(ve.get_mesaj() == "Pret invalid!\n");
	}
	try
	{
		validator.valideaza_produs("paste", "fainoase", 10, "");
	}
	catch (ValidException& ve)
	{
		assert(ve.get_mesaj() == "Producator invalid!\n");
	}

	cout << "Stopt validation tests.\n";
}

void ruleaza_teste_repo()
/*Testeaza metodele din repository*/
{
	cout << "Start repository tests.\n";

	Repo repo;

	//adauga
	Produs p{ "biscuiti", "dulci", 10.5, "Milka" };
	const auto& produse = repo.get_all();
	assert(produse.size() == 0);
	repo.adauga(p);
	assert(produse.size() == 1);
	assert(p.produse_egale(produse.at(0)) == true);
	Produs p2{ "ciocolata", "aerata", 15, "Milka" };
	repo.adauga(p2);
	assert(produse.size() == 2);
	assert(p.produse_egale(produse.at(0)) == true);
	assert(p2.produse_egale(produse.at(1)) == true);
	try
	{
		repo.adauga(p);
	}
	catch (RepoException& re)
	{
		assert(re.get_mesaj() == "Produs existent!\n");
	}
	assert(produse.size() == 2);
	assert(p.produse_egale(produse.at(0)) == true);
	assert(p2.produse_egale(produse.at(1)) == true);

	//modifica
	Produs pm{ "faina", "ungureasca", 60, "Fabrica" };
	repo.modifica(p, pm);
	assert(produse.at(0).get_nume() == "faina");
	assert(produse.at(0).get_tip() == "ungureasca");
	assert(fabs(produse.at(0).get_pret() - 60) < 0.0000001);
	assert(produse.at(0).get_producator() == "Fabrica");
	Produs pm2{ "condimente", "sarate", 7.79,  "Magi" };
	repo.modifica(p2, pm2);
	assert(produse.at(1).get_nume() == "condimente");
	assert(produse.at(1).get_tip() == "sarate");
	assert(fabs(produse.at(1).get_pret() - 7.79) < 0.0000001);
	assert(produse.at(1).get_producator() == "Magi");
	Produs p3{ "ciocolata", "aerata", 9, "Milka" };
	Produs pm3{ "faina", "malai", 60, "Fabrica" };
	try
	{
		repo.modifica(p3, pm3);
	}
	catch (RepoException& re)
	{
		assert(re.get_mesaj() == "Produs inexistent!\n");
	}

	//cauta
	Produs p6{ "condimente", "sarate", 7.79,  "Magi" };
	assert(p6.produse_egale(repo.cauta("condimente")) == true);
	try
	{
		assert(p2.produse_egale(repo.cauta("macaroane")) == true);
	}
	catch (RepoException& re)
	{
		assert(re.get_mesaj() == "Produs inexistent!\n");
	}

	//sterge
	assert(size(produse) == 2);
	Produs p4{ "faina", "ungureasca", 60, "Fabrica" };
	repo.sterge(p4);
	assert(size(produse) == 1);
	Produs p5{ "condimente", "sarate", 7.79, "Magi" };
	assert(p5.produse_egale(produse.at(0)) == true);
	try
	{
		repo.sterge(p3);
	}
	catch (RepoException& re)
	{
		assert(re.get_mesaj() == "Produs inexistent!\n");
	}
	assert(size(produse) == 1);

	cout << "Stop repository tests.\n";
}

void ruleaza_teste_repolab()
/*Testeaza metodele din lab repository*/
{
	cout << "Start laboratory repository tests.\n";

	RepoLab repo0{ 0 };

	//adauga
	Produs p01{ "biscuiti", "dulci", 10.5, "Milka" };
	vector<Produs>& produse0 = repo0.get_all();
	assert(produse0.size() == 0);
	repo0.adauga(p01);
	produse0 = repo0.get_all();
	assert(produse0.size() == 1);
	assert(p01.produse_egale(produse0.at(0)) == true);
	try
	{
		repo0.adauga(p01);
	}
	catch (RepoException& re)
	{
		assert(re.get_mesaj() == "Produs existent!\n");
	}
	produse0 = repo0.get_all();
	assert(produse0.size() == 1);
	assert(p01.produse_egale(produse0.at(0)) == true);
	Produs p02{ "ciocolata", "aerata", 15, "Milka" };
	repo0.adauga(p02);
	produse0 = repo0.get_all();
	assert(produse0.size() == 2);
	assert(p01.produse_egale(produse0.at(0)) == true);
	assert(p02.produse_egale(produse0.at(1)) == true);
	produse0 = repo0.get_all();
	assert(produse0.size() == 2);
	assert(p01.produse_egale(produse0.at(0)) == true);
	assert(p02.produse_egale(produse0.at(1)) == true);

	//modifica
	Produs pm01{ "faina", "ungureasca", 60, "Fabrica" };
	repo0.modifica(p01, pm01);
	produse0 = repo0.get_all();
	assert(produse0.at(1).get_nume() == "faina");
	assert(produse0.at(1).get_tip() == "ungureasca");
	assert(fabs(produse0.at(1).get_pret() - 60) < 0.0000001);
	assert(produse0.at(1).get_producator() == "Fabrica");
	Produs pm02{ "condimente", "sarate", 7.79,  "Magi" };
	repo0.modifica(p02, pm02);
	produse0 = repo0.get_all();
	assert(produse0.at(0).get_nume() == "condimente");
	assert(produse0.at(0).get_tip() == "sarate");
	assert(fabs(produse0.at(0).get_pret() - 7.79) < 0.0000001);
	assert(produse0.at(0).get_producator() == "Magi");
	Produs p03{ "ciocolata", "aerata", 9, "Milka" };
	Produs pm03{ "faina", "malai", 60, "Fabrica" };
	try
	{
		repo0.modifica(p03, pm03);
	}
	catch (RepoException& re)
	{
		assert(re.get_mesaj() == "Produs inexistent!\n");
	}

	//cauta
	Produs p06{ "condimente", "sarate", 7.79,  "Magi" };
	assert(p06.produse_egale(repo0.cauta("condimente")) == true);
	try
	{
		assert(p02.produse_egale(repo0.cauta("macaroane")) == true);
	}
	catch (RepoException& re)
	{
		assert(re.get_mesaj() == "Produs inexistent!\n");
	}

	//sterge
	produse0 = repo0.get_all();
	assert(size(produse0) == 2);
	Produs p04{ "faina", "ungureasca", 60, "Fabrica" };
	repo0.sterge(p04);
	produse0 = repo0.get_all();
	assert(size(produse0) == 1);
	Produs p05{ "condimente", "sarate", 7.79, "Magi" };
	assert(p05.produse_egale(produse0.at(0)) == true);
	produse0 = repo0.get_all();
	assert(size(produse0) == 1);
	try
	{
		repo0.sterge(p03);
	}
	catch (RepoException& re)
	{
		assert(re.get_mesaj() == "Produs inexistent!\n");
	}
	assert(size(produse0) == 1);

	RepoLab repo1{ 1 };

	//adauga
	Produs p11{ "biscuiti", "dulci", 10.5, "Milka" };
	vector<Produs>& produse1 = repo1.get_all();
	assert(produse1.size() == 0);
	try
	{
		repo1.adauga(p11);
	}
	catch (RepoException& rle)
	{
		assert(rle.get_mesaj() == "Probabilitate mare de a arunca exceptii.\n");
	}
	Produs p12{ "ciocolata", "aerata", 15, "Milka" };
	try
	{
		repo1.adauga(p12);
	}
	catch (RepoException& rle)
	{
		assert(rle.get_mesaj() == "Probabilitate mare de a arunca exceptii.\n");
	}
	produse1 = repo1.get_all();
	assert(produse1.size() == 0);


	cout << "Stop laboratory repository tests.\n";
}

void ruleaza_teste_filerepo()
{
	cout << "Start file repository tests.\n";

	try
	{
		FileRepo repo0{ "test_director/test_produse.txt" };
	}
	catch (FileRepoException& fe)
	{
		assert(fe.get_mesaj() == "Fisierul nu se poate deschide!\n");
	}
	FileRepo repo1{ "test_produse.txt" };
	repo1.set_filename("");
	Produs p{ "biscuiti", "dulci", 10.5, "Milka" };
	try
	{
		repo1.adauga(p);
	}
	catch (FileRepoException& fe)
	{
		assert(fe.get_mesaj() == "Fisierul nu se poate deschide!\n");
	}

	ofstream out("test_produse.txt", std::ios::trunc);
	out.close();
	FileRepo repo{ "test_produse.txt" };

	//adauga
	const auto& produse = repo.get_all();
	assert(produse.size() == 0);
	repo.adauga(p);
	assert(produse.size() == 1);
	assert(p.produse_egale(produse.at(0)) == true);
	Produs p2{ "ciocolata", "aerata", 15, "Milka" };
	repo.adauga(p2);
	assert(produse.size() == 2);
	assert(p.produse_egale(produse.at(0)) == true);
	assert(p2.produse_egale(produse.at(1)) == true);
	try
	{
		repo.adauga(p);
	}
	catch (RepoException& re)
	{
		assert(re.get_mesaj() == "Produs existent!\n");
	}
	assert(produse.size() == 2);
	assert(p.produse_egale(produse.at(0)) == true);
	assert(p2.produse_egale(produse.at(1)) == true);

	//modifica
	Produs pm{ "faina", "ungureasca", 60, "Fabrica" };
	repo.modifica(p, pm);
	assert(produse.at(0).get_nume() == "faina");
	assert(produse.at(0).get_tip() == "ungureasca");
	assert(fabs(produse.at(0).get_pret() - 60) < 0.0000001);
	assert(produse.at(0).get_producator() == "Fabrica");
	Produs pm2{ "condimente", "sarate", 7.79,  "Magi" };
	repo.modifica(p2, pm2);
	assert(produse.at(1).get_nume() == "condimente");
	assert(produse.at(1).get_tip() == "sarate");
	assert(fabs(produse.at(1).get_pret() - 7.79) < 0.0000001);
	assert(produse.at(1).get_producator() == "Magi");
	Produs p3{ "ciocolata", "aerata", 9, "Milka" };
	Produs pm3{ "faina", "malai", 60, "Fabrica" };
	try
	{
		repo.modifica(p3, pm3);
	}
	catch (RepoException& re)
	{
		assert(re.get_mesaj() == "Produs inexistent!\n");
	}

	//cauta
	Produs p6{ "condimente", "sarate", 7.79,  "Magi" };
	assert(p6.produse_egale(repo.cauta("condimente")) == true);
	try
	{
		assert(p2.produse_egale(repo.cauta("macaroane")) == true);
	}
	catch (RepoException& re)
	{
		assert(re.get_mesaj() == "Produs inexistent!\n");
	}

	//sterge
	assert(size(produse) == 2);
	Produs p4{ "faina", "ungureasca", 60, "Fabrica" };
	repo.sterge(p4);
	assert(size(produse) == 1);
	Produs p5{ "condimente", "sarate", 7.79, "Magi" };
	assert(p5.produse_egale(produse.at(0)) == true);
	try
	{
		repo.sterge(p3);
	}
	catch (RepoException& re)
	{
		assert(re.get_mesaj() == "Produs inexistent!\n");
	}
	assert(size(produse) == 1);

	//get all
	const auto& produse_fisier = repo.get_all();
	assert(size(produse_fisier) == 1);
	assert(p5.produse_egale(produse_fisier.at(0)) == true);

	cout << "Stop file repository tests.\n";
}

void ruleaza_teste_cos()
/*Testeaza metodele din cosul de cumparaturi.*/
{
	cout << "Start shopping cart tests.\n";

	Repo repo;
	CosCumparaturi cos{ repo };

	//genereaza
	try
	{
		cos.cos_genereaza(100);
	}
	catch (CosException& ce)
	{
		assert(ce.get_mesaj() == "Nu exita produse adaugate!\n");
	}

	Produs p1{ "biscuiti", "dulci", 11.5, "Milka" };
	Produs p2{ "ciocolata", "aerata", 13.5, "Milka" };
	const auto& produse = repo.get_all();
	repo.adauga(p1);
	repo.adauga(p2);
	assert(produse.size() == 2);

	try
	{
		cos.cos_genereaza(0);
	}
	catch (CosException& ce)
	{
		assert(ce.get_mesaj() == "Numar de produse invalid!\n");
	}
	try
	{
		cos.cos_genereaza(-10);
	}
	catch (CosException& ce)
	{
		assert(ce.get_mesaj() == "Numar de produse invalid!\n");
	}
	const auto& lista_cumparaturi_random1 = cos.cos_genereaza(5);
	assert(lista_cumparaturi_random1.size() == 5);
	const auto& lista_cumparaturi_random2 = cos.cos_genereaza(9);
	assert(lista_cumparaturi_random2.size() == 14);
	cos.cos_goleste();

	//adauga
	const auto& lista_cumparaturi = cos.cos_get_all();
	assert(size(lista_cumparaturi) == 0);
	assert(fabs(cos.cos_get_pret_total() - 0) < 0.000001);
	string nume1 = "biscuiti";
	cos.cos_adauga(nume1);
	assert(size(lista_cumparaturi) == 1);
	assert(fabs(cos.cos_get_pret_total() - 11.5) < 0.000001);
	string nume2 = "ciocolata";
	cos.cos_adauga(nume2);
	assert(size(lista_cumparaturi) == 2);
	assert(fabs(cos.cos_get_pret_total() - 25) < 0.00001);
	cos.cos_adauga(nume1);
	assert(size(lista_cumparaturi) == 3);
	assert(fabs(cos.cos_get_pret_total() - 36.5) < 0.00001);
	cos.cos_adauga(nume1);
	assert(size(lista_cumparaturi) == 4);
	assert(fabs(cos.cos_get_pret_total() - 48) < 0.000001);
	string nume3 = "paste";
	try
	{
		cos.cos_adauga(nume3);
	}
	catch (RepoException& re)
	{
		assert(re.get_mesaj() == "Produs inexistent!\n");
	}


	//sterge
	cos.cos_sterge(nume1);
	assert(size(lista_cumparaturi) == 3);
	assert(fabs(cos.cos_get_pret_total() - 36.5) < 0.00001);
	cos.cos_sterge(nume2);
	assert(size(lista_cumparaturi) == 2);
	assert(fabs(cos.cos_get_pret_total() - 23) < 0.00001);
	try
	{
		cos.cos_sterge("vin");
	}
	catch (RepoException& re)
	{
		assert(re.get_mesaj() == "Produs inexistent!\n");
	}
	try
	{
		cos.cos_sterge(nume2);
	}
	catch (CosException& ce)
	{
		assert(ce.get_mesaj() == "Produs inexistent in cos!\n");
	}

	//exporta
	string fisier = "";
	try
	{
		cos.cos_exporta(fisier);
	}
	catch (CosException& ce)
	{
		assert(ce.get_mesaj() == "Nume de fisier invalid!\n");
	}
	string fisier0 = "director/fisier_test";
	try
	{
		cos.cos_exporta(fisier0);
	}
	catch (CosException& ce)
	{
		assert(ce.get_mesaj() == "Nu se poate deschide fisierul!\n");
	}
	std::ofstream out("fisier_test.csv", std::ios::trunc);
	out.close();
	string fisier1 = "fisier_test";
	cos.cos_exporta(fisier1);
	ifstream in("fisier_test.csv");
	string s1;
	in >> s1;
	assert(s1 == "biscuiti,dulci,11.5,Milka");
	string s2;
	in >> s2;
	assert(s2 == "biscuiti,dulci,11.5,Milka");
	assert(fabs(cos.cos_get_pret_total() - 23) < 0.00001);

	//goleste
	assert(size(lista_cumparaturi) == 2);
	assert(fabs(cos.cos_get_pret_total() - 23) < 0.00001);
	cos.cos_goleste();
	assert(size(lista_cumparaturi) == 0);
	assert(fabs(cos.cos_get_pret_total() - 0) < 0.00001);

	cout << "Stop shopping cart tests.\n";
}

void ruleaza_teste_service()
/*Testeaza metodele din service*/
{
	cout << "Start service tests.\n";

	Repo srv_repo;
	Valid srv_valid;
	Sortare srv_sortare;
	CosCumparaturi srv_cos{ srv_repo };
	Service srv{ srv_repo, srv_valid, srv_sortare, srv_cos };

	//adauga
	const auto& produse = srv.srv_get_all();
	assert(produse.size() == 0);
	srv.srv_adauga("biscuiti", "dulci", 10.5, "Milka");
	assert(produse.size() == 1);
	assert(produse.at(0).get_nume() == "biscuiti");
	assert(produse.at(0).get_tip() == "dulci");
	assert(fabs(produse.at(0).get_pret() - 10.5) < 0.000001);
	assert(produse.at(0).get_producator() == "Milka");
	srv.srv_adauga("ciocolata", "dulce", 15, "Milka");
	assert(produse.size() == 2);
	assert(produse.at(1).get_nume() == "ciocolata");
	assert(produse.at(1).get_tip() == "dulce");
	assert(fabs(produse.at(1).get_pret() - 15) < 0.000001);
	assert(produse.at(1).get_producator() == "Milka");
	srv.srv_adauga("ciocolata", "sanatoasa", 10, "Fitness");
	assert(produse.size() == 3);
	assert(produse.at(2).get_nume() == "ciocolata");
	assert(produse.at(2).get_tip() == "sanatoasa");
	assert(fabs(produse.at(2).get_pret() - 10) < 0.000001);
	assert(produse.at(2).get_producator() == "Fitness");
	srv.srv_adauga("paste", "fainoase", 10, "Firma");
	assert(produse.size() == 4);
	assert(produse.at(3).get_nume() == "paste");
	assert(produse.at(3).get_tip() == "fainoase");
	assert(fabs(produse.at(3).get_pret() - 10) < 0.000001);
	assert(produse.at(3).get_producator() == "Firma");
	srv.srv_adauga("vin", "sec", 30, "Firma");
	assert(produse.size() == 5);
	assert(produse.at(4).get_nume() == "vin");
	assert(produse.at(4).get_tip() == "sec");
	assert(fabs(produse.at(4).get_pret() - 30) < 0.000001);
	assert(produse.at(4).get_producator() == "Firma");
	try
	{
		srv.srv_adauga("", "dulci", 10.5, "Milka");
	}
	catch (ValidException& ve)
	{
		assert(ve.get_mesaj() == "Nume invalid!\n");
	}
	assert(size(produse) == 5);
	try
	{
		srv.srv_adauga("biscuiti", "", 10.5, "Milka");
	}
	catch (ValidException& ve)
	{
		assert(ve.get_mesaj() == "Tip invalid!\n");
	}
	assert(size(produse) == 5);
	try
	{
		srv.srv_adauga("biscuiti", "dulci", -10.5, "Milka");
	}
	catch (ValidException& ve)
	{
		assert(ve.get_mesaj() == "Pret invalid!\n");
	}
	assert(size(produse) == 5);
	try
	{
		srv.srv_adauga("biscuiti", "dulci", 10.5, "");
	}
	catch (ValidException& ve)
	{
		assert(ve.get_mesaj() == "Producator invalid!\n");
	}
	assert(size(produse) == 5);
	try
	{
		srv.srv_adauga("biscuiti", "dulci", 10.5, "Milka");
	}
	catch (RepoException& re)
	{
		assert(re.get_mesaj() == "Produs existent!\n");
	}
	assert(produse.size() == 5);
	assert(produse.at(0).get_nume() == "biscuiti");
	assert(produse.at(0).get_tip() == "dulci");
	assert(fabs(produse.at(0).get_pret() - 10.5) < 0.000001);
	assert(produse.at(0).get_producator() == "Milka");
	assert(produse.at(1).get_nume() == "ciocolata");
	assert(produse.at(1).get_tip() == "dulce");
	assert(fabs(produse.at(1).get_pret() - 15) < 0.000001);
	assert(produse.at(1).get_producator() == "Milka");
	assert(produse.at(2).get_nume() == "ciocolata");
	assert(produse.at(2).get_tip() == "sanatoasa");
	assert(fabs(produse.at(2).get_pret() - 10) < 0.000001);
	assert(produse.at(2).get_producator() == "Fitness");
	assert(produse.at(3).get_nume() == "paste");
	assert(produse.at(3).get_tip() == "fainoase");
	assert(fabs(produse.at(3).get_pret() - 10) < 0.000001);
	assert(produse.at(3).get_producator() == "Firma");
	assert(produse.at(4).get_nume() == "vin");
	assert(produse.at(4).get_tip() == "sec");
	assert(fabs(produse.at(4).get_pret() - 30) < 0.000001);
	assert(produse.at(4).get_producator() == "Firma");

	//modifica
	srv.srv_modifica("biscuiti", "dulci", 10.5, "Milka", "faina", "ungureasca", 60, "Fabrica");
	assert(produse.at(0).get_nume() == "faina");
	assert(produse.at(0).get_tip() == "ungureasca");
	assert(fabs(produse.at(0).get_pret() - 60) < 0.0000001);
	assert(produse.at(0).get_producator() == "Fabrica");
	try
	{
		srv.srv_modifica("ciocolata", "calda", 4, "ChocoToff", "faina", "ungureasca", 60, "Fabrica");
	}
	catch (RepoException& re)
	{
		assert(re.get_mesaj() == "Produs inexistent!\n");
	}
	try
	{
		srv.srv_modifica("", "dulce", 15, "Milka", "faina", "ungureasca", 60, "Fabrica");
	}
	catch (RepoException& re)
	{
		assert(re.get_mesaj() == "Produs inexistent!\n");
	}
	try
	{
		srv.srv_modifica("ciocolata", "dulce", 15, "Milka", "", "ungureasca", 60, "Fabrica");
	}
	catch (ValidException& ve)
	{
		assert(ve.get_mesaj() == "Nume invalid!\n");
	}
	try
	{
		srv.srv_modifica("ciocolata", "", 15, "Milka", "faina", "ungureasca", 60, "Fabrica");
	}
	catch (RepoException& re)
	{
		assert(re.get_mesaj() == "Produs inexistent!\n");
	}
	try
	{
		srv.srv_modifica("ciocolata", "dulce", 15, "Milka", "faina", "", 60, "Fabrica");
	}
	catch (ValidException& ve)
	{
		assert(ve.get_mesaj() == "Tip invalid!\n");
	}
	try
	{
		srv.srv_modifica("ciocolata", "dulce", -15, "Milka", "faina", "ungureasca", 60, "Fabrica");
	}
	catch (RepoException& re)
	{
		assert(re.get_mesaj() == "Produs inexistent!\n");
	}
	try
	{
		srv.srv_modifica("ciocolata", "dulce", 15, "Milka", "faina", "ungureasca", -60, "Fabrica");
	}
	catch (ValidException& ve)
	{
		assert(ve.get_mesaj() == "Pret invalid!\n");
	}
	try
	{
		srv.srv_modifica("ciocolata", "dulce", 15, "", "faina", "ungureasca", 60, "Fabrica");
	}
	catch (RepoException& re)
	{
		assert(re.get_mesaj() == "Produs inexistent!\n");
	}
	try
	{
		srv.srv_modifica("ciocolata", "dulce", 15, "Milka", "faina", "ungureasca", 60, "");
	}
	catch (ValidException& ve)
	{
		assert(ve.get_mesaj() == "Producator invalid!\n");
	}

	//cauta
	const Produs& p = srv.srv_cauta("faina");
	assert(p.get_nume() == "faina");
	assert(p.get_tip() == "ungureasca");
	assert(fabs(p.get_pret() - 60) < 0.00001);
	assert(p.get_producator() == "Fabrica");
	try
	{
		Produs p1 = srv.srv_cauta("macaroane");
	}
	catch (RepoException& re)
	{
		assert(re.get_mesaj() == "Produs inexistent!\n");
	}
	try
	{
		Produs p2 = srv.srv_cauta("");
	}
	catch (ValidException& ve)
	{
		assert(ve.get_mesaj() == "Nume invalid!\n");
	}


	//sterge
	assert(size(produse) == 5);
	srv.srv_sterge("faina", "ungureasca", 60, "Fabrica");
	assert(size(produse) == 4);
	assert(produse.at(0).get_nume() == "ciocolata");
	assert(produse.at(0).get_tip() == "dulce");
	assert(fabs(produse.at(0).get_pret() - 15) < 0.000001);
	assert(produse.at(0).get_producator() == "Milka");
	assert(produse.at(1).get_nume() == "ciocolata");
	assert(produse.at(1).get_tip() == "sanatoasa");
	assert(fabs(produse.at(1).get_pret() - 10) < 0.000001);
	assert(produse.at(1).get_producator() == "Fitness");
	assert(produse.at(2).get_nume() == "paste");
	assert(produse.at(2).get_tip() == "fainoase");
	assert(fabs(produse.at(2).get_pret() - 10) < 0.000001);
	assert(produse.at(2).get_producator() == "Firma");
	assert(produse.at(3).get_nume() == "vin");
	assert(produse.at(3).get_tip() == "sec");
	assert(fabs(produse.at(3).get_pret() - 30) < 0.000001);
	assert(produse.at(3).get_producator() == "Firma");
	try
	{
		srv.srv_sterge("ciocolata", "aerata", 10, "Milka");
	}
	catch (RepoException& re)
	{
		assert(re.get_mesaj() == "Produs inexistent!\n");
	}
	assert(size(produse) == 4);
	try
	{
		srv.srv_sterge("", "aerata", 10, "Milka");
	}
	catch (ValidException& ve)
	{
		assert(ve.get_mesaj() == "Nume invalid!\n");
	}
	assert(size(produse) == 4);
	try
	{
		srv.srv_sterge("ciocolata", "", 10, "Milka");
	}
	catch (ValidException& ve)
	{
		assert(ve.get_mesaj() == "Tip invalid!\n");
	}
	assert(size(produse) == 4);
	try
	{
		srv.srv_sterge("ciocolata", "aerata", -10, "Milka");
	}
	catch (ValidException& ve)
	{
		assert(ve.get_mesaj() == "Pret invalid!\n");
	}
	assert(size(produse) == 4);
	try
	{
		srv.srv_sterge("ciocolata", "aerata", 10, "");
	}
	catch (ValidException& ve)
	{
		assert(ve.get_mesaj() == "Producator invalid!\n");
	}
	assert(size(produse) == 4);

	//filtreaza dupa nume
	vector<Produs> filtrate_dupa_nume{};
	srv.filtreaza_dupa_nume(filtrate_dupa_nume, "ciocolata");
	assert(size(filtrate_dupa_nume) == 2);
	assert(filtrate_dupa_nume.at(0).get_nume() == "ciocolata");
	assert(filtrate_dupa_nume.at(0).get_tip() == "dulce");
	assert(fabs(filtrate_dupa_nume.at(0).get_pret() - 15) < 0.000001);
	assert(filtrate_dupa_nume.at(0).get_producator() == "Milka");
	assert(filtrate_dupa_nume.at(1).get_nume() == "ciocolata");
	assert(filtrate_dupa_nume.at(1).get_tip() == "sanatoasa");
	assert(fabs(filtrate_dupa_nume.at(1).get_pret() - 10) < 0.000001);
	assert(filtrate_dupa_nume.at(1).get_producator() == "Fitness");
	try
	{
		srv.filtreaza_dupa_nume(filtrate_dupa_nume, "");
	}
	catch (ValidException& ve)
	{
		assert(ve.get_mesaj() == "Nume invalid!\n");
	}
	assert(size(filtrate_dupa_nume) == 2);

	//filtreaza dupa pret
	vector<Produs> filtrate_dupa_pret{};
	srv.filtreaza_dupa_pret(filtrate_dupa_pret, 10);
	assert(size(filtrate_dupa_pret) == 2);
	assert(filtrate_dupa_pret.at(0).get_nume() == "ciocolata");
	assert(filtrate_dupa_pret.at(0).get_tip() == "sanatoasa");
	assert(fabs(filtrate_dupa_pret.at(0).get_pret() - 10) < 0.000001);
	assert(filtrate_dupa_pret.at(0).get_producator() == "Fitness");
	assert(filtrate_dupa_pret.at(1).get_nume() == "paste");
	assert(filtrate_dupa_pret.at(1).get_tip() == "fainoase");
	assert(fabs(filtrate_dupa_pret.at(1).get_pret() - 10) < 0.000001);
	assert(filtrate_dupa_pret.at(1).get_producator() == "Firma");
	try
	{
		srv.filtreaza_dupa_pret(filtrate_dupa_pret, -10);
	}
	catch (ValidException& ve)
	{
		assert(ve.get_mesaj() == "Pret invalid!\n");
	}
	assert(size(filtrate_dupa_pret) == 2);

	//filtreaza dupa producator
	vector<Produs> filtrate_dupa_producator{};
	srv.filtreaza_dupa_producator(filtrate_dupa_producator, "Firma");
	assert(size(filtrate_dupa_producator) == 2);
	assert(filtrate_dupa_producator.at(0).get_nume() == "paste");
	assert(filtrate_dupa_producator.at(0).get_tip() == "fainoase");
	assert(fabs(filtrate_dupa_producator.at(0).get_pret() - 10) < 0.000001);
	assert(filtrate_dupa_producator.at(0).get_producator() == "Firma");
	assert(filtrate_dupa_producator.at(1).get_nume() == "vin");
	assert(filtrate_dupa_producator.at(1).get_tip() == "sec");
	assert(fabs(filtrate_dupa_producator.at(1).get_pret() - 30) < 0.000001);
	assert(filtrate_dupa_producator.at(1).get_producator() == "Firma");
	try
	{
		srv.filtreaza_dupa_producator(filtrate_dupa_producator, "");
	}
	catch (ValidException& ve)
	{
		assert(ve.get_mesaj() == "Producator invalid!\n");
	}
	assert(size(filtrate_dupa_producator) == 2);

	//sorteaza dupa nume
	vector<Produs> sortate;
	srv.sorteaza(sortate, "nume");
	assert(size(sortate) == 4);
	assert(size(produse) == 4);
	assert(sortate.at(0).get_nume() == "ciocolata");
	assert(sortate.at(0).get_tip() == "dulce");
	assert(fabs(sortate.at(0).get_pret() - 15) < 0.000001);
	assert(sortate.at(0).get_producator() == "Milka");
	assert(sortate.at(1).get_nume() == "ciocolata");
	assert(sortate.at(1).get_tip() == "sanatoasa");
	assert(fabs(sortate.at(1).get_pret() - 10) < 0.000001);
	assert(sortate.at(1).get_producator() == "Fitness");
	assert(sortate.at(2).get_nume() == "paste");
	assert(sortate.at(2).get_tip() == "fainoase");
	assert(fabs(sortate.at(2).get_pret() - 10) < 0.000001);
	assert(sortate.at(2).get_producator() == "Firma");
	assert(sortate.at(3).get_nume() == "vin");
	assert(sortate.at(3).get_tip() == "sec");
	assert(fabs(sortate.at(3).get_pret() - 30) < 0.000001);
	assert(sortate.at(3).get_producator() == "Firma");

	//sorteaza dupa pret
	srv.sorteaza(sortate, "pret");
	assert(size(sortate) == 4);
	assert(size(produse) == 4);
	assert(sortate.at(0).get_nume() == "ciocolata");
	assert(sortate.at(0).get_tip() == "sanatoasa");
	assert(fabs(sortate.at(0).get_pret() - 10) < 0.000001);
	assert(sortate.at(0).get_producator() == "Fitness");
	assert(sortate.at(1).get_nume() == "paste");
	assert(sortate.at(1).get_tip() == "fainoase");
	assert(fabs(sortate.at(1).get_pret() - 10) < 0.000001);
	assert(sortate.at(1).get_producator() == "Firma");
	assert(sortate.at(2).get_nume() == "ciocolata");
	assert(sortate.at(2).get_tip() == "dulce");
	assert(fabs(sortate.at(2).get_pret() - 15) < 0.000001);
	assert(sortate.at(2).get_producator() == "Milka");
	assert(sortate.at(3).get_nume() == "vin");
	assert(sortate.at(3).get_tip() == "sec");
	assert(fabs(sortate.at(3).get_pret() - 30) < 0.000001);
	assert(sortate.at(3).get_producator() == "Firma");

	//sorteaza dupa nume+tip
	srv.sorteaza(sortate, "nume+tip");
	assert(size(sortate) == 4);
	assert(size(produse) == 4);
	assert(sortate.at(0).get_nume() == "ciocolata");
	assert(sortate.at(0).get_tip() == "dulce");
	assert(fabs(sortate.at(0).get_pret() - 15) < 0.000001);
	assert(sortate.at(0).get_producator() == "Milka");
	assert(sortate.at(1).get_nume() == "ciocolata");
	assert(sortate.at(1).get_tip() == "sanatoasa");
	assert(fabs(sortate.at(1).get_pret() - 10) < 0.000001);
	assert(sortate.at(1).get_producator() == "Fitness");
	assert(sortate.at(2).get_nume() == "paste");
	assert(sortate.at(2).get_tip() == "fainoase");
	assert(fabs(sortate.at(2).get_pret() - 10) < 0.000001);
	assert(sortate.at(2).get_producator() == "Firma");
	assert(sortate.at(3).get_nume() == "vin");
	assert(sortate.at(3).get_tip() == "sec");
	assert(fabs(sortate.at(3).get_pret() - 30) < 0.000001);
	assert(sortate.at(3).get_producator() == "Firma");

	//adauga cos
	const auto& lista_cumparaturi = srv.srv_cos_get_all();
	assert(size(lista_cumparaturi) == 0);
	assert(srv.srv_cos_get_pret_total() == 0);
	srv.srv_cos_adauga("paste");
	assert(size(lista_cumparaturi) == 1);
	assert(srv.srv_cos_get_pret_total() == 10);
	srv.srv_cos_adauga("paste");
	assert(size(lista_cumparaturi) == 2);
	assert(srv.srv_cos_get_pret_total() == 20);
	srv.srv_cos_adauga("vin");
	assert(size(lista_cumparaturi) == 3);
	assert(srv.srv_cos_get_pret_total() == 50);
	srv.srv_cos_adauga("ciocolata");
	assert(size(lista_cumparaturi) == 4);
	assert(srv.srv_cos_get_pret_total() == 65);
	try
	{
		srv.srv_cos_adauga("suc");
	}
	catch (RepoException& re)
	{
		assert(re.get_mesaj() == "Produs inexistent!\n");
	}

	//sterge cos
	srv.srv_cos_sterge("ciocolata");
	assert(size(lista_cumparaturi) == 3);
	assert(srv.srv_cos_get_pret_total() == 50);
	srv.srv_cos_sterge("paste");
	assert(size(lista_cumparaturi) == 2);
	assert(srv.srv_cos_get_pret_total() == 40);
	try
	{
		srv.srv_cos_sterge("bomboane");
	}
	catch (RepoException& re)
	{
		assert(re.get_mesaj() == "Produs inexistent!\n");
	}
	try
	{
		srv.srv_cos_sterge("ciocolata");
	}
	catch (CosException& ce)
	{
		assert(ce.get_mesaj() == "Produs inexistent in cos!\n");
	}

	//exporta
	string fisier0 = "director/fisier_test";
	try
	{
		srv.srv_cos_exporta(fisier0);
	}
	catch (CosException& ce)
	{
		assert(ce.get_mesaj() == "Nu se poate deschide fisierul!\n");
	}
	std::ofstream out("fisier_test.csv", std::ios::trunc);
	out.close();
	string fisier1 = "fisier_test";
	srv.srv_cos_exporta(fisier1);
	ifstream in("fisier_test.csv");
	string s1;
	in >> s1;
	assert(s1 == "paste,fainoase,10,Firma");
	string s2;
	in >> s2;
	assert(s2 == "vin,sec,30,Firma");
	assert(srv.srv_cos_get_pret_total() == 40);

	//genereaza cos
	try
	{
		srv.srv_cos_genereaza(0);
	}
	catch (CosException& ce)
	{
		assert(ce.get_mesaj() == "Numar de produse invalid!\n");
	}
	try
	{
		srv.srv_cos_genereaza(-10);
	}
	catch (CosException& ce)
	{
		assert(ce.get_mesaj() == "Numar de produse invalid!\n");
	}
	const auto& lista_cumparaturi_random1 = srv.srv_cos_genereaza(5);
	assert(lista_cumparaturi_random1.size() == 7);
	const auto& lista_cumparaturi_random2 = srv.srv_cos_genereaza(10);
	assert(lista_cumparaturi_random2.size() == 17);

	//goleste cos
	assert(size(lista_cumparaturi) == 17);
	srv.srv_cos_goleste();
	assert(size(lista_cumparaturi) == 0);
	assert(srv.srv_cos_get_pret_total() == 0);

	//raport
	srv.srv_adauga("prajitura", "dulce", 30, "Fabrica");
	srv.srv_adauga("branza", "dulce", 10, "Almete");
	srv.srv_adauga("macaroane", "fainoase", 10, "Fabrica");
	const auto& rapoarte = srv.raport();
	for (const auto& raport : rapoarte)
	{
		if (raport.first == "dulce")
		{
			assert(raport.second.get_count() == 3);
			assert(raport.second.get_tip() == "dulce");
		}
		if (raport.first == "fainoase")
		{
			assert(raport.second.get_count() == 2);
			assert(raport.second.get_tip() == "fainoase");
		}
		if (raport.first == "sanatoasa")
		{
			assert(raport.second.get_count() == 1);
			assert(raport.second.get_tip() == "sanatoasa");
		}
		if (raport.first == "sec")
		{
			assert(raport.second.get_count() == 1);
			assert(raport.second.get_tip() == "sec");
		}
	}

	cout << "Stop service tests.\n";
}

void ruleaza_teste_undo()
{
	cout << "Start undo tests.\n";

	Repo srv_repo;
	Valid srv_valid;
	Sortare srv_sortare;
	CosCumparaturi srv_cos{ srv_repo };
	Service srv{ srv_repo, srv_valid, srv_sortare, srv_cos };

	//undo adauga
	srv.srv_adauga("laptop", "mic", 1900, "Lenovo");
	srv.srv_adauga("calculator", "gamming", 4000, "Asus");
	srv.srv_adauga("boxe", "portabile", 1000, "Genius");
	srv.srv_adauga("mouse", "gamming", 300, "Genius");
	const auto& produse = srv.srv_get_all();
	assert(size(produse) == 4);
	assert(produse.at(0).get_nume() == "laptop");
	assert(produse.at(0).get_tip() == "mic");
	assert(fabs(produse.at(0).get_pret() - 1900) < 0.000001);
	assert(produse.at(0).get_producator() == "Lenovo");
	assert(produse.at(1).get_nume() == "calculator");
	assert(produse.at(1).get_tip() == "gamming");
	assert(fabs(produse.at(1).get_pret() - 4000) < 0.000001);
	assert(produse.at(1).get_producator() == "Asus");
	assert(produse.at(2).get_nume() == "boxe");
	assert(produse.at(2).get_tip() == "portabile");
	assert(fabs(produse.at(2).get_pret() - 1000) < 0.000001);
	assert(produse.at(2).get_producator() == "Genius");
	assert(produse.at(3).get_nume() == "mouse");
	assert(produse.at(3).get_tip() == "gamming");
	assert(fabs(produse.at(3).get_pret() - 300) < 0.000001);
	assert(produse.at(3).get_producator() == "Genius");
	srv.undo();
	assert(size(produse) == 3);
	assert(produse.at(0).get_nume() == "laptop");
	assert(produse.at(0).get_tip() == "mic");
	assert(fabs(produse.at(0).get_pret() - 1900) < 0.000001);
	assert(produse.at(0).get_producator() == "Lenovo");
	assert(produse.at(1).get_nume() == "calculator");
	assert(produse.at(1).get_tip() == "gamming");
	assert(fabs(produse.at(1).get_pret() - 4000) < 0.000001);
	assert(produse.at(1).get_producator() == "Asus");
	assert(produse.at(2).get_nume() == "boxe");
	assert(produse.at(2).get_tip() == "portabile");
	assert(fabs(produse.at(2).get_pret() - 1000) < 0.000001);
	assert(produse.at(2).get_producator() == "Genius");

	//undo modifica
	srv.srv_modifica("calculator", "gamming", 4000, "Asus", "calculator", "birou", 2500, "LG");
	assert(produse.at(0).get_nume() == "laptop");
	assert(produse.at(0).get_tip() == "mic");
	assert(fabs(produse.at(0).get_pret() - 1900) < 0.000001);
	assert(produse.at(0).get_producator() == "Lenovo");
	assert(produse.at(1).get_nume() == "calculator");
	assert(produse.at(1).get_tip() == "birou");
	assert(fabs(produse.at(1).get_pret() - 2500) < 0.000001);
	assert(produse.at(1).get_producator() == "LG");
	assert(produse.at(2).get_nume() == "boxe");
	assert(produse.at(2).get_tip() == "portabile");
	assert(fabs(produse.at(2).get_pret() - 1000) < 0.000001);
	assert(produse.at(2).get_producator() == "Genius");
	srv.undo();
	assert(size(produse) == 3);
	assert(produse.at(0).get_nume() == "laptop");
	assert(produse.at(0).get_tip() == "mic");
	assert(fabs(produse.at(0).get_pret() - 1900) < 0.000001);
	assert(produse.at(0).get_producator() == "Lenovo");
	assert(produse.at(1).get_nume() == "calculator");
	assert(produse.at(1).get_tip() == "gamming");
	assert(fabs(produse.at(1).get_pret() - 4000) < 0.000001);
	assert(produse.at(1).get_producator() == "Asus");
	assert(produse.at(2).get_nume() == "boxe");
	assert(produse.at(2).get_tip() == "portabile");
	assert(fabs(produse.at(2).get_pret() - 1000) < 0.000001);
	assert(produse.at(2).get_producator() == "Genius");

	//undo sterge
	srv.srv_sterge("calculator", "gamming", 4000, "Asus");
	assert(size(produse) == 2);
	assert(produse.at(0).get_nume() == "laptop");
	assert(produse.at(0).get_tip() == "mic");
	assert(fabs(produse.at(0).get_pret() - 1900) < 0.000001);
	assert(produse.at(0).get_producator() == "Lenovo");
	assert(produse.at(1).get_nume() == "boxe");
	assert(produse.at(1).get_tip() == "portabile");
	assert(fabs(produse.at(1).get_pret() - 1000) < 0.000001);
	assert(produse.at(1).get_producator() == "Genius");
	srv.undo();
	assert(size(produse) == 3);
	assert(produse.at(0).get_nume() == "laptop");
	assert(produse.at(0).get_tip() == "mic");
	assert(fabs(produse.at(0).get_pret() - 1900) < 0.000001);
	assert(produse.at(0).get_producator() == "Lenovo");
	assert(produse.at(1).get_nume() == "boxe");
	assert(produse.at(1).get_tip() == "portabile");
	assert(fabs(produse.at(1).get_pret() - 1000) < 0.000001);
	assert(produse.at(1).get_producator() == "Genius");
	assert(produse.at(2).get_nume() == "calculator");
	assert(produse.at(2).get_tip() == "gamming");
	assert(fabs(produse.at(2).get_pret() - 4000) < 0.000001);
	assert(produse.at(2).get_producator() == "Asus");

	//exceptie
	srv.undo();
	srv.undo();
	srv.undo();
	try
	{
		srv.undo();
	}
	catch (ServiceException& se)
	{
		assert(se.get_mesaj() == "Nu exista actiuni de refacut!\n");
	}

	cout << "Stop undo tests.\n";
}

void Teste::ruleaza_teste()
/*Ruleaza toate testele*/
{
	cout << "Start all tests.\n";

	ruleaza_teste_domeniu();
	ruleaza_teste_validare();
	ruleaza_teste_repo();
	ruleaza_teste_repolab();
	ruleaza_teste_filerepo();
	ruleaza_teste_cos();
	ruleaza_teste_service();
	ruleaza_teste_undo();

	cout << "All tests succesfully finished.\n";
}