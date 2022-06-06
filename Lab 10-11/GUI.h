#pragma once
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qlayout.h>
#include <QtWidgets/qlistwidget.h>
#include <QtWidgets/qtablewidget.h>
#include <QtWidgets/qtableview.h>
#include <QtWidgets/qformlayout.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qmessagebox.h>
#include <QtWidgets/qspinbox.h>
#include <qpainter.h>
#include <qdebug.h>
#include <QString>
#include <vector>
#include <string>
#include "service.h"
#include "observer.h"
#include "ModelView.h"

using std::vector;
using std::string;

class FilterGUI :public QWidget {
public:

	/*Creeaza o entitate de tip FilterGUI
	* Preconditii: fgui_srv - entitate de tip Service
	* Postconditii: this - entitate de tip FilterGUI cu campui srv initializat
	*/
	FilterGUI(Service& fgui_srv) :srv{ fgui_srv }
	{
		initFilterGUI();
		initConnectFilterGUI();
		loadData();
	};

	/*Filtreaza datele din tabel dupa un nume dat
	* Preconditii: this - entitate de tip FilterGUI
	* Postconditii: produsele din tabel sunt filtrate dupa numele dat, daca nu sunt probleme
	*               mesaj de tipul "Nu exista produse cu numele dat!", daca nu exista astfel de produse
	*               mesaj de tipul "Nume invalid!", daca numele este invalid
	*/
	void fgui_filtreaza_dupa_nume();

	/*Filtreaza datele din tabel dupa un pret dat
	* Preconditii: this - entitate de tip FilterGUI
	* Postconditii: produsele din tabel sunt filtrate dupa pretul dat, daca nu sunt probleme
	*               mesaj de tipul "Nu exista produse cu pretul dat!", daca nu exista astfel de produse
	*               mesaj de tipul "Pret invalid!", daca pretul este invalid
	*/
	void fgui_filtreaza_dupa_pret();

	/*Filtreaza datele din tabel dupa un producator dat
	* Preconditii: this - entitate de tip FilterGUI
	* Postconditii: produsele din tabel sunt filtrate dupa producatorul dat, daca nu sunt probleme
	*               mesaj de tipul "Nu exista produse cu producatorul dat!", daca nu exista astfel de produse
	*               mesaj de tipul "Producator invalid!", daca producatorul este invalid
	*/
	void fgui_filtreaza_dupa_producator();

private:

	/*Realizeaza design-ul unei ferestre
	* Preconditii: this - entitate de tip FilterGUI
	* Postcontidii: fereastra are un anumit design
	*/
	void initFilterGUI();

	/*Realizeaza legatura dintre un buton si o anumita actiune
	* Preconditii: this - entitate de tip FilterGUI
	* Postconditii: se realizeaza actiunea odata ce este apasat butonul
	*/
	void initConnectFilterGUI();

	/*Incarca datele din fereastra principala in tabelul din fereastra pt filtrare
	* Preconditii: this - entitate de tip FilterGUI
	* Postconditii: datele sunt incarcate in fereastra pt filtrare
	*               mesaj de tipul "Nu exista produse adaugate!", daca nu exista produse adaugate in fereastra principala
	*/
	void loadData();

	/*Incarca datele obtinute dupa filtrare in tabelul din fereastra
	* Preconditii: this - entitate de tip FilterGUI
	*              filtrate - vector de entitati de tip Produs
	* Postconditii: datele sunt incarcate in fereastra
	*/
	void loadFilteredData(const vector<Produs>& filtrate);

private:
	Service& srv;
	QTableWidget* tabel = new QTableWidget{ 100, 4};
	QPushButton* filter_by_name_button = new QPushButton{ "Filtreaza dupa nume" };
	QPushButton* filter_by_price_button = new QPushButton{ "Filtreaza dupa pret" };
	QPushButton* filter_by_maker_button = new QPushButton{ "Filtreaza dupa producator" };
	QPushButton* reload_button = new QPushButton{ "Reload" };
	QLineEdit* nume_txt = new QLineEdit;
	//QLineEdit* pret_txt = new QLineEdit;
	QLineEdit* producator_txt = new QLineEdit;
	QDoubleSpinBox* spin_box = new QDoubleSpinBox;
};

class SortGUI : public QWidget {
public:

	/*Creeaza o entitate de tip SortGUI
	* Preconditii: sgui_srv - entitate de tip Service
	* Postconditii: this - entitate de tip SortGUI cu campul srv initializat
	*/
	SortGUI(Service& sgui_srv) :srv{ sgui_srv }
	{
		initSortGUI();
		initConnectSortGUI();
		loadData();
	};

	/*Sorteaza produsele dupa nume
	* Preconditii: this - entitate de tip SortGUI
	* Postconditii: lista cu produsele sortate dupa nume
	*/
	void sgui_sorteaza_dupa_nume();

	/*Sorteaza produsele dupa pret
	* Preconditii: this - entitate de tip SortGUI
	* Postconditii: lista cu produsele sortate dupa pret
	*/
	void sgui_sorteaza_dupa_pret();

	/*Sorteaza produsele dupa nume si tip
	* Preconditii: this - entitate de tip SortGUI
	* Postconditii: lista cu produsele sortate dupa nume si tip
	*/
	void sgui_sorteaza_dupa_nume_tip();

private:

	/*Realizeaza design-ul unei ferestre
	* Preconditii: this - entitate de tip SortGUI
	* Postcontidii: fereastra are un anumit design
	*/
	void initSortGUI();

	/*Realizeaza legatura dintre un buton si o anumita actiune
	* Preconditii: this - entitate de tip SortGUI
	* Postconditii: se realizeaza actiunea odata ce este apasat butonul
	*/
	void initConnectSortGUI();

	/*Incarca datele din fereastra principala in lista din fereastra pt sortare
	* Preconditii: this - entitate de tip SortGUI
	* Postconditii: datele sunt incarcate in fereastra pt sortare
	*/
	void loadData();

protected:
	QListWidget* lista = new QListWidget;
	QLineEdit* pret_txt = new QLineEdit;
private:
	Service& srv;
	QPushButton* sort_by_name_button = new QPushButton{ "Sorteaza dupa nume" };
	QPushButton* sort_by_price_button = new QPushButton{ "Sorteaza dupa pret" };
	QPushButton* sort_by_name_type_button = new QPushButton{ "Sorteaza dupa nume si tip" };
	QPushButton* reload_button = new QPushButton{ "Reload" };
	QLineEdit* nume_txt = new QLineEdit;
	QLineEdit* producator_txt = new QLineEdit;
};

class RaportGUI : public QWidget {
public:

	/*Creeaza o entitate de tip RaportGUI
	* Preconditii: rgui_srv -  entitate de tip Service
	* Postconditii: this -  entitate de tip RaportGUI cu campul srv initializat
	*/
	RaportGUI(Service& rgui_srv) :srv{ rgui_srv }
	{
		initRaportGUI();
		loadData();
	}
private:

	/*Realizeaza design-ul unei ferestre
	* Preconditii: this - entitate de tip RaportGUI
	* Postcontidii: fereastra are un anumit design
	*/
	void initRaportGUI();

	/*Incarca datele din dictionar in tabelul din fereastra pt raport
	* Preconditii: this - entitate de tip RaportGUI
	* Postconditii: datele sunt incarcate in fereastra pt sortare
	*/
	void loadData();

private:
	Service& srv;
	QTableWidget* tabel = new QTableWidget{ 100, 2 };
};

class CosGUI :public QWidget, public Observer {
public:

	/*Creeaza o entitate de tip CosGUI
	* Preconditii: cgui_srv - entitate de tip Service
	* Postconditi: this - entitate de tip CosGUI
	*/
	CosGUI(Service& cgui_srv) :srv{ cgui_srv }
	{
		initCosGUI();
		initConnectCosGUI();
		loadData();
	};

	/*Inchide fereastra cosului
	* Preconditii: this - entitate de tip CosGUI
	* Postconditii: mesaj de tipul "Doriti sa iesiti din cos?"
	*               iesire din feresatra cosului
	*/
	void cgui_exit();

	/*Adauga un produs in lista din cos
	* Preconditii: this - entitate de tip CosGUI
	* Postconditii: produsul este adaugat in cos, daca nu sunt probleme
	*               mesaj de tipul "Produs inexistent!", daca nu exista produsul cu numele dat
	*                              "Nume invalid!", daca numele este invalid
	*/
	void cgui_adauga();

	/*Sterge un produs din cosul de cumparaturi
	* Preconditii: this - entitate de tip CosGUI
	* Postconditii: mesaj de tipul "Produs inexistent!", daca produsul nu exista in lista de produse
	*                              "Produs inexistent in cos!", daca produsul nu exista in cosul de cumparaturi
	*                              "Nume invalid!", daca numele introdus este invalid
	*                              produsul este sters din cos, altfel
	*/
	void cgui_sterge();

	/*Genereaza produse in cosul de cumparaturi
	* Preconditii: this - entitate de tip CosGUI
	* Postconditii: "Nu exita produse adaugate!", daca nu exista produse adaugate in lista de produse
	*               "Numar de produse invalid!", daca numarul de produse ce trebuie generate este negativ sau nul
	*               lista cu produsele generate in cos, altfel
	*/
	void cgui_genereaza();

	/*Exporta produsele din cos intr-un fisier
	* Preconditii: this - entitate de tip CosGUI
	* Postconditii: mesaj de tipul "Export realizat cu succes.", daca produsele sunte exportate cu succes in fisier
	*               mesaj de tipul "Nu se poate deschide fisierul!", daca fisierul nu poate fi deschis
	*                              "Nume de fisier invalid!", daca numele dat este invalid
	*/
	void cgui_exporta();

	/*Goleste cosul de cumparaturi
	* Preconditii: this - entitate de tip CosGUI
	* Postconditii: cosul este golit
	*/
	void cgui_goleste();

	/*Incarca datele din fereastra principala in lista din fereastra pt cos
	* Preconditii: this - entitate de tip CosGUI
	* Postconditii: datele sunt incarcate in fereastra pt cos
	*               mesaj de tipul "Nu exista produse adaugate!", daca nu exista produse adaugate in fereastra principala
	*/
	void loadData();

private:

	/*Realizeaza design-ul unei ferestre
	* Preconditii: this - entitate de tip CosGUI
	* Postcontidii: fereastra are un anumit design
	*/
	void initCosGUI();

	/*Realizeaza legatura dintre un buton si o anumita actiune
	* Preconditii: this - entitate de tip CosGUI
	* Postconditii: se realizeaza actiunea odata ce este apasat butonul
	*/
	void initConnectCosGUI();


	/*Completeaza campurile de text cu atributele instantei selectate in lista din fereastra
	* Preconditii: this - entitate de tip CosGUI
	* Postconditii: campurile de text sunt completate corespunzator
	*/
	void selectItems();
	
	/*Realizeaza modificarile necesare sinctonizarii cu alte ferestre
	* Preconditii: this - entitate de tip GUI
	* Postconditii: fereastra curenta este sincronizata cu toate celelalte de tip observers
	*/
	void update() override;

public:
	QListWidget* lista_cos = new QListWidget;
	QLineEdit* pret_total_txt = new QLineEdit;
private:
	Service& srv;
	QPushButton* exit_button = new QPushButton{ "Exit" };
	QPushButton* export_button = new QPushButton{ "Exporta" };
	QPushButton* generate_button = new QPushButton{ "Genereaza" };
	QPushButton* clear_button = new QPushButton{ "Goleste" };
	QLineEdit* nume_txt = new QLineEdit;
	QLineEdit* fisier_txt = new QLineEdit;
	//QLineEdit* numar_txt = new QLineEdit;
	QSlider* slider = new QSlider(Qt::Horizontal);

};

class CosRDOnlyGUI : public QWidget, public Observer{
public:
	/*Creeaza o entitate de tip CosRDOnlyGUI
	* Preconditii: crdogui_srv - entitate de tip Service
	* Postconditii: this - entiate de tip CosRDOnlyGUI cu campul srv initializat
	*/
	CosRDOnlyGUI(Service& crdogui_srv) : srv{ crdogui_srv } 
	{
		srv.addObserver(this);
	};

	/*Deseneaza cate o forma geometrica (patrate) pt fiecare produs din cos 
	* Preconditii: this - entitate de tip CosRDOnlyGUI
	* Postconditii: in fereastra se gasesc atatea patrate cate produse sunt adaugate in cos
	*/
	void paintEvent(QPaintEvent* ev) override;

	/*Realizeaza modificarile necesare sinctonizarii cu alte ferestre
	* Preconditii: this - entitate de tip CosRDOnlyGUI
	* Postconditii: fereastra curenta este sincronizata cu toate celelalte de tip observers
	*/
	void update() override;

private:
	Service& srv;
};


class GUI : public QWidget, public Observer{
public:

	/*Creeaza o entitate de tip GUI
	* Preconditii: gui_srv - entitate de tip Service
	* Postconditii: this - entitate de tip GUI cu campul srv initializat
	*/
	GUI(Service& gui_srv, CosGUI& gui_cgui) : srv{ gui_srv }, cgui{gui_cgui}
	{
		initGUI();
		loadData();
		initConnect();
	};

	/*Constructor de copiere
	* Preconditii: this - entitate de tip GUI
	*			   other - entitate de tip GUI
	* Postconditii: nu se pot face copieri
	*/
	GUI(const GUI& other) = delete;

	/*Inchide aplicatia 
	* Preconditii: this - entitate de tip GUI
	* Postconditii: mesaj de tipul "Doriti sa iesiti din aplicatie?"
	*               iesire din aplicatie
	*/
	void gui_exit();

	/*Adauga un produs in lista din fereastra
	* Preconditii: this - entitate de tip GUI
	* Postconditii: produsul este adaugat, daca nu exista probleme 
	*               mesaje de eroare: de tip validare, daca datele introduse nu sunt valide
	*                                 de tip repo, daca produsul exista deja in lista de produse
	*/
	void gui_adauga();

	/*Modifica un produs din lista ferestrei
	* Preconditii: this - entitate de tip GUI
	* Postconditii: produsul se modifica, daca nu exista probleme
	*               mesaje de eroare: de tip validare, daca datele introduse nu sunt valide
	*                                 de tip repo, daca produsul nu exista in lista de produse
	*/
	void gui_modifica();

	/*Sterge un produs din lista ferestrei
	* Preconditii: this - entitate de tip GUI
	* Postconditii: produsul este sters, daca nu exista probleme
	*               mesaje de eroare: de tip validare, daca datele introduse nu sunt valide
	*                                 de tip repo, daca produsul nu exista in lista de produse
	*/
	void gui_sterge();

	/*Cauta un produs in lista ferestrei
	* Precodnitii: this - entitate de tip GUI
	* Postcodnitii: produsul este afisat, daca este gasit in lista ferestrei
	*               mesaje de eroare: de tip validare, daca datele introduse nu sunt valide
	*                                 de tip repo, daca produsul nu exista in lista de produse
	*/
	void gui_cauta();

	/*Filtreaza lista de produse din fereastra
	* Preconditii: this - entitate de tip GUI
	* Postconditii: lista cu produsele care respecta filtrul dat, daca exista astfel de produse
	*               mesaj de tipul "Nume invalid!", daca numele introdus este invalid
	*                              "Pret invalid!", daca pretul introdus este invalid
	*                              "Producator invalid!", daca producatorul introdus este invalid
	*                              "Nu exista produse adaugate!", daca nu exista produse adaugate
	*/
	void gui_filtreaza();

	/*Sorteaza lista de produse in functie de o proprietate data
	* Preconditii: this - entitate de tip GUI
	* Postconditii: lista cu produsele sortate in functie de o proprietate data
	*               mesaj de tipul  "Nu exista produse adaugate!", daca nu exista produse adaugate
	*/
	void gui_sorteaza();

	/*Realizeaza un raport ( tip : nr de produse care au acest tip)
	* Preconditii: this - entitate de tip GUI
	* Postconditii: tabel ce contine tipurile si numarul de produse corespunzator
	*               mesaj de tipul "Nu exista produse adaugate!", daca nu exista produse in lista ferestrei
	*/
	void gui_raporteaza();

	/*Reface ultima operatie efectuata (adaugare/modificare/stergere)
	* Preconditii: this - entitate de tip GUI
	* Postconditii: mesaj de tipul "Nu exista actiuni de refacut!", daca nu mai exista operatii realizate in lista de actiuni
	*               se face undo la ultima operatie efectuata, altfel
	*/
	void gui_undo();

	/*Deschide fereastra destinata cosului
	* Precodnitii: this - entitate de tip GUI
	* Postconditii: ferestra destinata cosului este deschisa
	*/
	void gui_cos();

	/*Deschide o fereastra de tip Cos Read Only
	* Preconditii: this - entitate de tip GUI
	* Postconditii: fereastra destinata cosului de tip Read Only a fost deschisa
	*/
	void gui_cos_rdonly();

	/*Adauga un produs in cosul de cumparauri
	* Precodnitii: this - entitate de tip GUI
	* Postconditii: produsul a fost adaugat in cos
	*/
	void gui_cos_adauga();

	/*Sterge un produs din cosul de cumparaturi
	* Preconditii: this - entitate de tip GUI
	* Postconditii: produsul a fost sters din cos
	*/
	void gui_cos_sterge();

	/*Genereaza aleator produse in cos
	* Preconditii: this - entitate de tip GUI
	* Postconditii: produsele au fost generate in cos
	*/
	void gui_cos_genereaza();

private:
	/*Realizeaza design-ul unei ferestre
	* Preconditii: this - entitate de tip GUI
	* Postcontidii: fereastra are un anumit design
	*/
	void initGUI();

	/*Incarca datele din fisier in lista din fereastra
	* Preconditii: this - entitate de tip GUI 
	* Postconditii: datele sunt incarcate in fereastra
	*               mesaj de tipul "Nu exista produse adaugate!", daca nu exista produse adaugate in fisier
	*/
	void loadData();

	/*Completeaza campurile de text cu atributele instantei selectate in lista din fereastra
	* Preconditii: this - entitate de tip GUI
	* Postconditii: campurile de text sunt completate corespunzator
	*/
	void selectItems();

	/*Realizeaza legatura dintre un buton si o anumita actiune
	* Preconditii: this - entitate de tip GUI
	* Postconditii: se realizeaza actiunea odata ce este apasat butonul
	*/
	void initConnect();

	/*Realizeaza modificarile necesare sinctonizarii cu alte ferestre
	* Preconditii: this - entitate de tip GUI
	* Postconditii: fereastra curenta este sincronizata cu toate celelalte de tip observers
	*/
	void update() override;
private:
	
	CosGUI& cgui;
	Service& srv;
	QListWidget* lista = new QListWidget;
	QPushButton* exit_button = new QPushButton{ "Exit" };
	QPushButton* add_button = new QPushButton{ "Adauga" };
	QPushButton* remove_button = new QPushButton{ "Sterge" };
	QPushButton* update_button = new QPushButton{ "Modifica" };
	QPushButton* find_button = new QPushButton{ "Cauta" };
	QPushButton* filter_button = new QPushButton{ "Filtreaza" };
	QPushButton* sort_button = new QPushButton{ "Sorteaza" };
	QPushButton* report_button = new QPushButton{ "Raporteaza" };
	QPushButton* undo_button = new QPushButton{ "Undo" };
	QPushButton* cart_button = new QPushButton{ "Cos" };
	QPushButton* cart_rdonly_button = new QPushButton{ "Cos Read Only" };
	QPushButton* add_cart_button = new QPushButton{ "Adauga Cos" };
	QPushButton* remove_cart_button = new QPushButton{ "Sterge Cos" };
	QPushButton* generate_cart_button = new QPushButton{ "Genereaza Cos" };
	QLineEdit* nume_txt = new QLineEdit;
	QLineEdit* tip_txt = new QLineEdit;
	QLineEdit* pret_txt = new QLineEdit;
	QLineEdit* producator_txt = new QLineEdit;
	QLineEdit* nume_nou_txt = new QLineEdit;
	QLineEdit* tip_nou_txt = new QLineEdit;
	//QLineEdit* pret_nou_txt = new QLineEdit;
	QDoubleSpinBox* spin_box = new QDoubleSpinBox;
	QLineEdit* producator_nou_txt = new QLineEdit;
	QLineEdit* numar_txt = new QLineEdit;
	QLineEdit* pret_total_cos_txt = new QLineEdit;
};

