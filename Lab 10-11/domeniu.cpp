#include "domeniu.h"

using std::to_string;

string Produs::get_nume() const
{
	return nume;
}
string Produs::get_tip() const
{
	return tip;
}
double Produs::get_pret() const noexcept
{
	return pret;
}
string Produs::get_producator() const
{
	return producator;
}

void Produs::set_nume(const string& nume_nou)
{
	nume = nume_nou;
}
void Produs::set_tip(const string& tip_nou)
{
	tip = tip_nou;
}
void Produs::set_pret(const double& pret_nou) noexcept
{
	pret = pret_nou;
}
void Produs::set_producator(const string& producator_nou)
{
	producator = producator_nou;
}

Produs& Produs::operator=(const Produs& other)
{
	this->nume = other.nume;
	this->tip = other.tip;
	this->pret = other.pret;
	this->producator = other.producator;
	return *this;
}

bool Produs::produse_egale(const Produs& p2) const
{
	return (nume == p2.get_nume() && tip == p2.get_tip() && pret == p2.get_pret() && producator == p2.get_producator());
}

string Produs::produs_str() const
{
	return (nume + " " + tip + " " + to_string(pret) + " " + producator + "\n");
}

ostream& operator<<(ostream& stream, const Produs& p)
{
	stream << p.get_nume() << " ";
	stream << p.get_tip() << " ";
	stream << p.get_pret() << " ";
	stream << p.get_producator();
	return stream;
}

istream& operator>>(istream& stream, Produs& p)
{
	stream >> p.nume >> p.tip >> p.pret >> p.producator;
	return stream;
}