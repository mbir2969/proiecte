#pragma once
#include <QAbstractTableModel>
#include <vector>
#include "service.h"

using std::vector;

class TableModelView: public QAbstractTableModel{
public:
	TableModelView(Service& srv) : srv{ srv } {};
	int rowCount(const QModelIndex& /*parent = QModelIndex()*/) const override;
	int columnCount(const QModelIndex& /*parent = QModelIndex()*/) const override;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

private:
	Service& srv;
};

