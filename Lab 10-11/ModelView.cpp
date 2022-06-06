#include "ModelView.h"

int TableModelView::rowCount(const QModelIndex&) const
{
	return (int)srv.srv_get_all().size();
}

int TableModelView::columnCount(const QModelIndex&) const
{
	return 4;
}

QVariant TableModelView::data(const QModelIndex& index, int role) const
{
	if (role == Qt::DisplayRole)
	{
		const auto& produs = srv.srv_get_all()[index.row()];
		if (index.column() == 0)
			return QString::fromStdString(produs.get_nume());
		else if(index.column()==1)
			return QString::fromStdString(produs.get_tip());
		else if(index.column()==2)
			return QString::number(produs.get_pret());
		else if(index.column()==3)
			return QString::fromStdString(produs.get_producator());
	}
	return QVariant{};
}
