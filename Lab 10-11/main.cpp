#include "Magazin.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include <stdlib.h>
#include "validare.h"
#include "repo.h"
#include "cos.h"
#include "sortare.h"
#include "service.h"
#include "GUI.h"
#include "teste.h"

using std::cin;
using std::cout;
using std::string;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	Teste teste;
	teste.ruleaza_teste();
	//Repo repo;
	FileRepo repo{ "produse.txt" };
	//const double& probabilitate = 0.7;
	//RepoLab repo{ probabilitate };
	Valid valid;
	Sortare sortare;
	CosCumparaturi cos{ repo };
	Service srv{ repo, valid, sortare, cos };
	CosGUI cgui{ srv };
	GUI gui{ srv , cgui};
	gui.show();

    return a.exec();
}
