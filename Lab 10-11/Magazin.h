#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Magazin.h"

class Magazin : public QMainWindow
{
    Q_OBJECT

public:
    Magazin(QWidget *parent = Q_NULLPTR);

private:
    Ui::MagazinClass ui;
};
