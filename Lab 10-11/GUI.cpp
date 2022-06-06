#include <iostream>
#include "GUI.h"
#include "domeniu.h"

void SortGUI::sgui_sorteaza_dupa_nume()
{
	vector<Produs> sortate{};
	srv.sorteaza(sortate, "nume");
	lista->clear();
	for (const auto& produs : sortate)
	{
		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(produs.produs_str()));
		item->setData(Qt::UserRole, QString::fromStdString(produs.get_nume()));
		lista->addItem(item);
	}
}

void SortGUI::sgui_sorteaza_dupa_pret()
{
	vector<Produs> sortate{};
	srv.sorteaza(sortate, "pret");
	lista->clear();
	for (const auto& produs : sortate)
	{
		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(produs.produs_str()));
		item->setData(Qt::UserRole, QString::fromStdString(produs.get_tip()));
		lista->addItem(item);
	}
}

void SortGUI::sgui_sorteaza_dupa_nume_tip()
{
	vector<Produs> sortate{};
	srv.sorteaza(sortate, "nume+tip");
	lista->clear();
	for (const auto& produs : sortate)
	{
		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(produs.produs_str()));
		item->setData(Qt::UserRole, QString::fromStdString(produs.get_nume()));
		lista->addItem(item);
	}

}

void SortGUI::initSortGUI()
{
	//fereastra
	QWidget* wnd = new QWidget;
	wnd->setWindowTitle("Sortare");

	//layout principal
	QHBoxLayout* main_layout = new QHBoxLayout;
	setLayout(main_layout);

	//layout-ul din dreapta ferestrei
	QVBoxLayout* right_layout = new QVBoxLayout{};
	right_layout->addWidget(lista);

	//layout-ul din stanga ferestrei
	QVBoxLayout* left_layout = new QVBoxLayout{};
	left_layout->addWidget(sort_by_name_button);
	left_layout->addWidget(sort_by_price_button);
	left_layout->addWidget(sort_by_name_type_button);
	left_layout->addWidget(reload_button);

	main_layout->addLayout(right_layout);
	main_layout->addLayout(left_layout);
}

void SortGUI::initConnectSortGUI()
{
	QObject::connect(sort_by_name_button, &QPushButton::clicked, this, &SortGUI::sgui_sorteaza_dupa_nume);
	QObject::connect(sort_by_price_button, &QPushButton::clicked, this, &SortGUI::sgui_sorteaza_dupa_pret);
	QObject::connect(sort_by_name_type_button, &QPushButton::clicked, this, &SortGUI::sgui_sorteaza_dupa_nume_tip);
	QObject::connect(reload_button, &QPushButton::clicked, this, &SortGUI::loadData);
}

void SortGUI::loadData()
{
	lista->clear();
	const auto& produse = srv.srv_get_all();
	for (const auto& produs : produse)
	{
		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(produs.produs_str()));
		item->setData(Qt::UserRole, QString::fromStdString(produs.get_nume()));
		lista->addItem(item);
	}
}

void FilterGUI::fgui_filtreaza_dupa_nume()
{
	tabel->clear();
	vector<Produs> filtrate{};
	auto nume = nume_txt->text();
	try
	{
		srv.filtreaza_dupa_nume(filtrate, nume.toStdString());
		if (filtrate.size() != 0)
		{
			loadFilteredData(filtrate);
		}
		else
			QMessageBox::information(nullptr, "Info", "Nu exista produse cu numele dat.");
	}
	catch (ValidException& ve)
	{
		QMessageBox::warning(nullptr, "Eroare filtrare", QString::fromStdString(ve.get_mesaj()));
	}
}
void FilterGUI::fgui_filtreaza_dupa_pret()
{
	tabel->clear();
	vector<Produs> filtrate{};
	//auto pret = pret_txt->text();
	auto pret = spin_box->value();
	try
	{
		srv.filtreaza_dupa_pret(filtrate, pret);
		if (filtrate.size() != 0)
		{
			loadFilteredData(filtrate);
		}
		else
			QMessageBox::information(nullptr, "Info", "Nu exista produse cu pretul dat.");
	}
	catch (ValidException& ve)
	{
		QMessageBox::warning(nullptr, "Eroare filtrare", QString::fromStdString(ve.get_mesaj()));
	}
}
void FilterGUI::fgui_filtreaza_dupa_producator()
{
	tabel->clear();
	vector<Produs> filtrate{};
	auto producator = producator_txt->text();
	try
	{
		srv.filtreaza_dupa_producator(filtrate, producator.toStdString());
		if (filtrate.size() != 0)
		{
			loadFilteredData(filtrate);
		}
		else
			QMessageBox::information(nullptr, "Info", "Nu exista produse cu producatorul dat.");
	}
	catch (ValidException& ve)
	{
		QMessageBox::warning(nullptr, "Eroare filtrare", QString::fromStdString(ve.get_mesaj()));
	}
}



void FilterGUI::initFilterGUI()
{
	//fereastra
	QWidget* wnd = new QWidget;
	wnd->setWindowTitle("Filtrare");

	//layout principal
	QHBoxLayout* main_layout = new QHBoxLayout;
	setLayout(main_layout);

	//layout-ul din dreapta ferestrei
	QVBoxLayout* right_layout = new QVBoxLayout{};
	right_layout->addWidget(tabel);

	right_layout->addWidget(reload_button);

	//layout-ul din stanga ferestrei
	QVBoxLayout* left_layout = new QVBoxLayout{};

	QLabel* label1 = new QLabel{"Filtrare dupa nume: "};
	left_layout->addWidget(label1);
	QFormLayout* form_layout1 = new QFormLayout;
	form_layout1->addRow("Nume", nume_txt);
	left_layout->addLayout(form_layout1);
	left_layout->addWidget(filter_by_name_button);

	QLabel* label2 = new QLabel{ "Filtrare dupa pret: " };
	left_layout->addWidget(label2);
	//QFormLayout* form_layout2 = new QFormLayout;
 	//form_layout2->addRow("Pret", pret_txt);
	//left_layout->addLayout(form_layout2);
	QHBoxLayout* sublayout = new QHBoxLayout;
	QLabel* sublabel = new QLabel{ "Pret" };
	sublayout->addWidget(sublabel);
	sublayout->addWidget(spin_box);
	left_layout->addLayout(sublayout);
	left_layout->addWidget(filter_by_price_button);

	QLabel* label3 = new QLabel{ "Filtrare dupa producator: " };
	left_layout->addWidget(label3);
	QFormLayout* form_layout3 = new QFormLayout;
	form_layout3->addRow("Producator", producator_txt);
	left_layout->addLayout(form_layout3);
	left_layout->addWidget(filter_by_maker_button);

	main_layout->addLayout(right_layout);
	main_layout->addLayout(left_layout);
}

void FilterGUI::initConnectFilterGUI()
{
	QObject::connect(filter_by_name_button, &QPushButton::clicked, this, &FilterGUI::fgui_filtreaza_dupa_nume);
	QObject::connect(filter_by_price_button, &QPushButton::clicked, this, &FilterGUI::fgui_filtreaza_dupa_pret);
	QObject::connect(filter_by_maker_button, &QPushButton::clicked, this, &FilterGUI::fgui_filtreaza_dupa_producator);
	QObject::connect(reload_button, &QPushButton::clicked, this, &FilterGUI::loadData);
}

void FilterGUI::loadData()
{
	tabel->clear();
	tabel->setColumnCount(4);
	const auto& produse = srv.srv_get_all();
	tabel->setRowCount((int)produse.size());
	QTableWidgetItem* item1 = new QTableWidgetItem("Nume");
	tabel->setItem(0, 0, item1);
	QTableWidgetItem* item2 = new QTableWidgetItem("Tip");
	tabel->setItem(0, 1, item2);
	QTableWidgetItem* item3 = new QTableWidgetItem("Pret");
	tabel->setItem(0, 2, item3);
	QTableWidgetItem* item4 = new QTableWidgetItem("Producator");
	tabel->setItem(0, 3, item4);
	int i = 1;
	for (const auto& produs : produse)
	{
		QTableWidgetItem* item5 = new QTableWidgetItem(QString::fromStdString(produs.get_nume()));
		tabel->setItem(i, 0, item5);
		QTableWidgetItem* item6 = new QTableWidgetItem(QString::fromStdString(produs.get_tip()));
		tabel->setItem(i, 1, item6);
		QTableWidgetItem* item7 = new QTableWidgetItem(QString::number(produs.get_pret()));
		tabel->setItem(i, 2, item7);
		QTableWidgetItem* item8 = new QTableWidgetItem(QString::fromStdString(produs.get_producator()));
		tabel->setItem(i, 3, item8);
		i++;
	}
}

void FilterGUI::loadFilteredData(const vector<Produs>& filtrate)
{
	QTableWidgetItem* item1 = new QTableWidgetItem("Nume");
	tabel->setItem(0, 0, item1);
	QTableWidgetItem* item2 = new QTableWidgetItem("Tip");
	tabel->setItem(0, 1, item2);
	QTableWidgetItem* item3 = new QTableWidgetItem("Pret");
	tabel->setItem(0, 2, item3);
	QTableWidgetItem* item4 = new QTableWidgetItem("Producator");
	tabel->setItem(0, 3, item4);
	int i = 1;
	for (const auto& produs : filtrate)
	{
		QTableWidgetItem* item5 = new QTableWidgetItem(QString::fromStdString(produs.get_nume()));
		tabel->setItem(i, 0, item5);
		QTableWidgetItem* item6 = new QTableWidgetItem(QString::fromStdString(produs.get_tip()));
		tabel->setItem(i, 1, item6);
		QTableWidgetItem* item7 = new QTableWidgetItem(QString::number(produs.get_pret()));
		tabel->setItem(i, 2, item7);
		QTableWidgetItem* item8 = new QTableWidgetItem(QString::fromStdString(produs.get_producator()));
		tabel->setItem(i, 3, item8);
		i++;
	}
}

void RaportGUI::initRaportGUI()
{
	QHBoxLayout* main_layout = new QHBoxLayout;
	setLayout(main_layout);
	main_layout->addWidget(tabel);
	
}

void RaportGUI::loadData()
{
	tabel->clear();
	const auto& rapoarte = srv.raport();
	QTableWidgetItem* item1 = new QTableWidgetItem("Tip");
	tabel->setItem(0, 0, item1);
	QTableWidgetItem* item2 = new QTableWidgetItem("Numar");
	tabel->setItem(0, 1, item2);
	int i = 1;
	for (const auto& raport : rapoarte)
	{
		string cheie = raport.first;
		QTableWidgetItem* item3 = new QTableWidgetItem(QString::fromStdString(cheie));
		tabel->setItem(i, 0, item3);
		RaportDTO valoare = raport.second;
		QTableWidgetItem* item4 = new QTableWidgetItem(QString::number(valoare.get_count()));
		tabel->setItem(i, 1, item4);
		i++;
	}
}

void CosGUI::cgui_exit()
{
	QMessageBox::information(nullptr, "Exit", "Doriti sa iesiti din cos?");
	close();
}


void CosGUI::cgui_genereaza()
{
	//auto numar = numar_txt->text();
	auto numar = slider->size().height();
	try
	{
		auto lista_cumparaturi_random = srv.srv_cos_genereaza(numar);
		for (const auto& produs : lista_cumparaturi_random)
		{
			QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(produs.produs_str()));
			item->setData(Qt::UserRole, QString::fromStdString(produs.get_nume()));
			lista_cos->addItem(item);
		}
		const double& pret_total = srv.srv_cos_get_pret_total();
		pret_total_txt->clear();
		pret_total_txt->insert(QString::number(pret_total));
	}
	catch (CosException& ce)
	{
		QMessageBox::warning(nullptr, "Eroare generare cos", QString::fromStdString(ce.get_mesaj()));
	}
	loadData();
}

void CosGUI::cgui_exporta()
{
	auto file_name = fisier_txt->text();
	try
	{
		srv.srv_cos_exporta(file_name.toStdString());
		const double& pret_total = srv.srv_cos_get_pret_total();
		pret_total_txt->clear();
		pret_total_txt->insert(QString::number(pret_total));
		QMessageBox::information(nullptr, "Export", "Export realizat cu succes.");
	}
	catch (CosException& ce)
	{
		QMessageBox::warning(nullptr, "Eroare export", QString::fromStdString(ce.get_mesaj()));
	}
}

void CosGUI::cgui_goleste()
{
	srv.srv_cos_goleste();
	pret_total_txt->clear();
	loadData();
}

void CosGUI::initCosGUI()
{
	//layout principal
	QHBoxLayout* main_layout = new QHBoxLayout{};
	setLayout(main_layout);

	//layout-ul din dreapta ferestrei
	QVBoxLayout* right_layout = new QVBoxLayout{};

	QLabel* label = new QLabel{ "Produsele adaugate in cos sunt: " };
	right_layout->addWidget(label);
	right_layout->addWidget(lista_cos);

	QFormLayout* form_layout1 = new QFormLayout;
	form_layout1->addRow("Pret total", pret_total_txt);
	right_layout->addLayout(form_layout1);

	//layout-ul din stanga ferestrei
	QVBoxLayout* left_layout = new QVBoxLayout;
	
	QFormLayout* form_layout2 = new QFormLayout;
	form_layout2->addRow("Fisier", fisier_txt);
	//form_layout2->addRow("Numar", numar_txt);
	QHBoxLayout* sublayout = new QHBoxLayout;
	QLabel* sublabel = new QLabel{ "Numar" };
	sublayout->addWidget(sublabel);
	slider->setRange(0, 10);
	sublayout->addWidget(slider);
	left_layout->addLayout(sublayout);

	left_layout->addLayout(form_layout2);
	left_layout->addWidget(export_button);
	left_layout->addWidget(generate_button);
	left_layout->addWidget(clear_button);
	left_layout->addWidget(exit_button);

	main_layout->addLayout(right_layout);
	main_layout->addLayout(left_layout);
}

void CosGUI::initConnectCosGUI()
{
	srv.addObserver(this);
	QObject::connect(lista_cos, &QListWidget::itemSelectionChanged, this, &CosGUI::selectItems);
	QObject::connect(exit_button, &QPushButton::clicked, this, &CosGUI::cgui_exit);
	QObject::connect(export_button, &QPushButton::clicked, this, &CosGUI::cgui_exporta);
	QObject::connect(generate_button, &QPushButton::clicked, this, &CosGUI::cgui_genereaza);
	QObject::connect(clear_button, &QPushButton::clicked, this, &CosGUI::cgui_goleste);
}
void CosGUI::selectItems()
{
	auto selected = lista_cos->selectedItems();
	if (selected.isEmpty())
	{
		nume_txt->setText("");
	}
	else
	{
		auto produs_selectat = selected.at(0);
		auto nume = produs_selectat->data(Qt::UserRole).toString();
		nume_txt->setText(nume);
	}
}

void CosGUI::loadData()
{
	lista_cos->clear();
	const auto& produse = srv.srv_cos_get_all();
	if (produse.size() != 0)
		for (const auto& produs : produse)
		{
			QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(produs.produs_str()));
			item->setData(Qt::UserRole, QString::fromStdString(produs.get_nume()));
			lista_cos->addItem(item);
		}
	else
		lista_cos->addItem("Nu exista produse adaugate in cos!");
}

void CosGUI::update()
{
	loadData();
	const double& pret_total = srv.srv_cos_get_pret_total();
	pret_total_txt->clear();
	pret_total_txt->insert(QString::number(pret_total));
}

void CosRDOnlyGUI::paintEvent(QPaintEvent* ev)
{
	ev = nullptr;
	QPainter p{this};
	const auto& lista_cos = srv.srv_cos_get_all();
	for (int i=0;i< lista_cos.size();i++)
	{
		int x = rand()% width();
		int y = rand() % height();
		p.drawRect(x, y, 20, 20);
	}

}

void CosRDOnlyGUI::update()
{
	repaint();
}

void GUI::gui_exit()
{
	QMessageBox::information(nullptr, "Exit", "Doriti sa iesiti din aplicatie?");
	close();
}

void GUI::gui_adauga()
{
	auto nume = nume_txt->text();
	auto tip = tip_txt->text();
	auto pret = pret_txt->text();
	auto producator = producator_txt->text();
	try
	{
		srv.srv_adauga(nume.toStdString(), tip.toStdString(), pret.toDouble(), producator.toStdString());
	}
	catch (RepoException& re)
	{
		QMessageBox::warning(nullptr, "Eroare adaugare", QString::fromStdString(re.get_mesaj()));
	}
	catch (ValidException& ve)
	{
		QMessageBox::warning(nullptr, "Eroare adaugare", QString::fromStdString(ve.get_mesaj()));
	}
	loadData();
}

void GUI::gui_modifica()
{
	auto nume = nume_txt->text();
	auto tip = tip_txt->text();
	auto pret = pret_txt->text();
	auto producator = producator_txt->text();
	auto nume_nou = nume_nou_txt->text();
	auto tip_nou = tip_nou_txt->text();
	//auto pret_nou = pret_nou_txt->text();
	auto pret_nou = spin_box->value();
	auto producator_nou = producator_nou_txt->text();
	try
	{
		srv.srv_modifica(nume.toStdString(), tip.toStdString(), pret.toDouble(), producator.toStdString(), nume_nou.toStdString(), tip_nou.toStdString(), pret_nou, producator_nou.toStdString());
	}
	catch (RepoException& re)
	{
		QMessageBox::warning(nullptr, "Eroare modificare", QString::fromStdString(re.get_mesaj()));
	}
	catch (ValidException& ve)
	{
		QMessageBox::warning(nullptr, "Eroare modificare", QString::fromStdString(ve.get_mesaj()));
	}
	loadData();
}

void GUI::gui_sterge()
{
	auto nume = nume_txt->text();
	auto tip = tip_txt->text();
	auto pret = pret_txt->text();
	auto producator = producator_txt->text();
	try
	{
		srv.srv_sterge(nume.toStdString(), tip.toStdString(), pret.toDouble(), producator.toStdString());
	}
	catch (RepoException& re)
	{
		QMessageBox::warning(nullptr, "Eroare stergere", QString::fromStdString(re.get_mesaj()));
	}
	catch (ValidException& ve)
	{
		QMessageBox::warning(nullptr, "Eroare stergere", QString::fromStdString(ve.get_mesaj()));
	}
	loadData();
}

void GUI::gui_cauta()
{
	auto nume = nume_txt->text();
	try
	{
		const auto& produs = srv.srv_cauta(nume.toStdString());
		QMessageBox::information(nullptr, "Cautare", "Produsul cautat este:\n" + QString::fromStdString(produs.produs_str()));
	}
	catch (RepoException& re)
	{
		QMessageBox::warning(nullptr, "Eroare cautare", QString::fromStdString(re.get_mesaj()));
	}
	catch (ValidException& ve)
	{
		QMessageBox::warning(nullptr, "Eroare cautare", QString::fromStdString(ve.get_mesaj()));
	}
	loadData();
}

void GUI::gui_filtreaza()
{
	const auto& produse = srv.srv_get_all();
	if (produse.size() != 0)
	{
		FilterGUI* fgui = new FilterGUI{ srv };
		fgui->show();
	}
	else
		QMessageBox::warning(nullptr, "Eroare filtrare", "Nu exista produse adaugate!");
}

void GUI::gui_sorteaza()
{
	const auto& produse = srv.srv_get_all();
	if (produse.size() != 0)
	{
		SortGUI* sgui = new SortGUI{ srv };
		sgui->show();
	}
	else
		QMessageBox::warning(nullptr, "Eroare sortare", "Nu exista produse adaugate!");
}


void GUI::gui_raporteaza()
{
	const auto& produse = srv.srv_get_all();
	if (produse.size() != 0)
	{
		RaportGUI* rgui = new RaportGUI{ srv };
		rgui->show();
	}
	else
		QMessageBox::warning(nullptr, "Eroare sortare", "Nu exista produse adaugate!");
}

void GUI::gui_undo()
{
	try
	{
		srv.undo();
	}
	catch (ServiceException& se)
	{
		QMessageBox::warning(nullptr, "Eroare undo", QString::fromStdString(se.get_mesaj()));
	}
	loadData();
}

void GUI::gui_cos()
{
	CosGUI* ccgui = new CosGUI{ srv };
	ccgui->show();
}

void GUI::gui_cos_rdonly()
{
	CosRDOnlyGUI* crdogui = new CosRDOnlyGUI{srv};
	crdogui->show();
}

void GUI::gui_cos_adauga()
{
	auto nume = nume_txt->text();
	try
	{
		srv.srv_cos_adauga(nume.toStdString());
	}
	catch (RepoException& re)
	{
		QMessageBox::warning(nullptr, "Eroare adaugare cos", QString::fromStdString(re.get_mesaj()));
	}
	catch (ValidException& ve)
	{
		QMessageBox::warning(nullptr, "Eroare adaugare cos", QString::fromStdString(ve.get_mesaj()));
	}
	loadData();
}

void GUI::gui_cos_sterge()
{
	auto nume = nume_txt->text();
	try
	{
		srv.srv_cos_sterge(nume.toStdString());
	}
	catch (RepoException& re)
	{
		QMessageBox::warning(nullptr, "Eroare stergere cos", QString::fromStdString(re.get_mesaj()));
	}
	catch (CosException& ce)
	{
		QMessageBox::warning(nullptr, "Eroare stergere cos", QString::fromStdString(ce.get_mesaj()));
	}
	catch (ValidException& ve)
	{
		QMessageBox::warning(nullptr, "Eroare stergere cos", QString::fromStdString(ve.get_mesaj()));
	}
	loadData();
}

void GUI::gui_cos_genereaza()
{
	auto numar = numar_txt->text();
	try
	{
		auto lista_cumparaturi_random = srv.srv_cos_genereaza(numar.toInt());
		for (const auto& produs : lista_cumparaturi_random)
		{
			QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(produs.produs_str()));
			item->setData(Qt::UserRole, QString::fromStdString(produs.get_nume()));
			cgui.lista_cos->addItem(item);
		}
	}
	catch (CosException& ce)
	{
		QMessageBox::warning(nullptr, "Eroare generare cos", QString::fromStdString(ce.get_mesaj()));
	}
	cgui.loadData();
}

void GUI::initGUI()
{
	//fereastra
	QWidget* wnd = new QWidget;
	wnd->setWindowTitle("Magazin");

	//layout principal
	QHBoxLayout* main_layout = new QHBoxLayout{};
	setLayout(main_layout);
	
	//layout-ul din dreapta ferestrei
	QVBoxLayout* right_layout = new QVBoxLayout{};
	
	QLabel* label1 = new QLabel{ "Produsele adaugate sunt: " };
	right_layout->addWidget(label1);
	right_layout->addWidget(lista);

	//layout-ul din stanga ferestrei
	QVBoxLayout* left_layout = new QVBoxLayout;
	
	QLabel* label2 = new QLabel{ "Detalii pentru adaugare/stergere/cautare:" };
	left_layout->addWidget(label2);
	QFormLayout* form_layout1 = new QFormLayout;
	form_layout1->addRow("Nume", nume_txt);
	form_layout1->addRow("Tip", tip_txt);
	form_layout1->addRow("Pret", pret_txt);
	form_layout1->addRow("Producator", producator_txt);
	left_layout->addLayout(form_layout1);

	QHBoxLayout* buttons_layout1 = new QHBoxLayout;
	buttons_layout1->addWidget(add_button);
	buttons_layout1->addWidget(remove_button);
	buttons_layout1->addWidget(find_button);
	left_layout->addLayout(buttons_layout1);

	QLabel* label3 = new QLabel{ "Detalii pentru modificare:" };
	left_layout->addWidget(label3);

	QFormLayout* form_layout2 = new QFormLayout;
	form_layout2->addRow("Nume nou", nume_nou_txt);
	form_layout2->addRow("Tip nou", tip_nou_txt);
	left_layout->addLayout(form_layout2);
	//form_layout2->addRow("Pret nou", pret_nou_txt);
	QHBoxLayout* sublayout = new QHBoxLayout;
	QLabel* sublabel = new QLabel{ "Pret nou" };
	sublayout->addWidget(sublabel);
	sublayout->addWidget(spin_box);
	left_layout->addLayout(sublayout);
	QFormLayout* form_layout3 = new QFormLayout;
	form_layout3->addRow("Producator nou", producator_nou_txt);
	left_layout->addLayout(form_layout3);

	QHBoxLayout* buttons_layout2 = new QHBoxLayout;
	buttons_layout2->addWidget(update_button);
	left_layout->addLayout(buttons_layout2);

	QLabel* label4 = new QLabel{ "Alte comenzi: " };
	left_layout->addWidget(label4);

	QHBoxLayout* buttons_layout3 = new QHBoxLayout;
	buttons_layout3->addWidget(filter_button);
	left_layout->addLayout(buttons_layout3);
	buttons_layout3->addWidget(sort_button);
	left_layout->addLayout(buttons_layout3);

	QHBoxLayout* buttons_layout4 = new QHBoxLayout;
	buttons_layout4->addWidget(report_button);
	buttons_layout4->addWidget(undo_button);
	left_layout->addLayout(buttons_layout4);

	QLabel* label5 = new QLabel{ "Comenzi pentru cos: " };
	left_layout->addWidget(label5);

	QHBoxLayout* buttons_layout5 = new QHBoxLayout;
	buttons_layout5->addWidget(cart_button);
	buttons_layout5->addWidget(cart_rdonly_button);
	left_layout->addLayout(buttons_layout5);

	QHBoxLayout* buttons_layout6 = new QHBoxLayout;
	buttons_layout6->addWidget(add_cart_button);
	buttons_layout6->addWidget(remove_cart_button);
	buttons_layout6->addWidget(generate_cart_button);
	left_layout->addLayout(buttons_layout6);

	QFormLayout* form_layout4 = new QFormLayout;
	form_layout4->addRow("Numar", numar_txt);
	form_layout4->addRow("Pret total cos", pret_total_cos_txt);
	left_layout->addLayout(form_layout4);

	left_layout->addWidget(exit_button);

	main_layout->addLayout(right_layout);
	main_layout->addLayout(left_layout);
}

void GUI::loadData()
{
	lista->clear();
	const auto& produse = srv.srv_get_all();
	if (produse.size() != 0)
		for (const auto& produs : produse)
		{
			QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(produs.produs_str()));
			item->setData(Qt::UserRole, QString::fromStdString(produs.get_nume()));
			lista->addItem(item);
		}
	else
		lista->addItem("Nu exista produse adaugate!");
}

void GUI::selectItems()
{
	auto selected = lista->selectedItems();
	if (selected.isEmpty())
	{
		nume_txt->setText("");
		tip_txt->setText("");
		pret_txt->setText("");
		producator_txt->setText("");
	}
	else
	{
		auto produs_selectat = selected.at(0);
		auto nume = produs_selectat->data(Qt::UserRole).toString();
		nume_txt->setText(nume);
		const auto& produs = srv.srv_cauta(nume.toStdString());
		tip_txt->setText(QString::fromStdString(produs.get_tip()));
		pret_txt->setText(QString::number(produs.get_pret()));
		producator_txt->setText(QString::fromStdString(produs.get_producator()));
	}
}

void GUI::update()
{
	loadData();
	const double& pret_total = srv.srv_cos_get_pret_total();
	pret_total_cos_txt->clear();
	pret_total_cos_txt->insert(QString::number(pret_total));
}

void GUI::initConnect()
{
	srv.addObserver(this);
	QObject::connect(lista, &QListWidget::itemSelectionChanged, this, &GUI::selectItems);
	QObject::connect(exit_button, &QPushButton::clicked, this, &GUI::gui_exit);
	QObject::connect(add_button, &QPushButton::clicked, this, &GUI::gui_adauga );
	QObject::connect(update_button, &QPushButton::clicked, this, &GUI::gui_modifica);
	QObject::connect(remove_button, &QPushButton::clicked, this, &GUI::gui_sterge);
	QObject::connect(find_button, &QPushButton::clicked, this, &GUI::gui_cauta);
	QObject::connect(report_button, &QPushButton::clicked, this, &GUI::gui_raporteaza);
	QObject::connect(filter_button, &QPushButton::clicked, this, &GUI::gui_filtreaza);
	QObject::connect(sort_button, &QPushButton::clicked, this, &GUI::gui_sorteaza);
	QObject::connect(undo_button, &QPushButton::clicked, this, &GUI::gui_undo);
	QObject::connect(cart_button, &QPushButton::clicked, this, &GUI::gui_cos);
	QObject::connect(cart_rdonly_button, &QPushButton::clicked, this, &GUI::gui_cos_rdonly);
	QObject::connect(add_cart_button, &QPushButton::clicked, this, &GUI::gui_cos_adauga);
	QObject::connect(remove_cart_button, &QPushButton::clicked, this, &GUI::gui_cos_sterge);
	QObject::connect(generate_cart_button, &QPushButton::clicked, this, &GUI::gui_cos_genereaza);
}