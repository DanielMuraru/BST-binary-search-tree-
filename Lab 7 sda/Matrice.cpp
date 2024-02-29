#include "Matrice.h"
#include "Iterator.h"
#include <exception>
using namespace std;

Nod::Nod(int val,int linie,int coloana, PNod st, PNod dr) :valoare(val),linie(linie),coloana(coloana), st(st), dr(dr){}
int Nod::get_valoare()
{
	return this->valoare;
}

PNod Nod::urmator()
{
	return st!=nullptr?this->st:this->dr;
}
PNod Matrice::adaugaRec(PNod p,std::pair<std::pair<int,int>,TElem> el)
{
	/*if (p == nullptr)
	{
		p = new Nod(el.second, el.first.first, el.first.second, nullptr, nullptr);
	}
	else {
		if (el.first <= make_pair(p->linie,p->coloana))
			p->st = adaugaRec(p->st, el);
		else
		{
			p->dr = adaugaRec(p->dr, el);
		}
	}*/
	if (p == nullptr)
	{
		radacina = new Nod(el.second, el.first.first, el.first.second, nullptr, nullptr);
		return radacina;

	}
	PNod prev = nullptr;
	while (p != nullptr)
	{
		if (el.first <= make_pair(p->linie, p->coloana))
		{
			prev = p;
			p = p->st;
		}
		else 
		{
			prev = p;
			p = p->dr;
		}
	}
	p = new Nod(el.second, el.first.first, el.first.second, nullptr, nullptr);
	if (prev != nullptr)
	{	if (el.first < make_pair(prev->linie, prev->coloana))
				prev->st = p;
			else prev->dr = p;
	}
	return p;

}
void Matrice::distrugeRec(PNod p)
{
	if (p != nullptr)
	{
		distrugeRec(p->st);
		distrugeRec(p->dr);
		delete p;
	}
}
PNod Matrice::cauta_rec(PNod p,std::pair<std::pair<int,int>,TElem> el) const
{
	if (p == NULL || (p->linie == el.first.first && p->coloana == el.first.second))
		return p;
	else
	{
		if (el.first <= make_pair(p->linie, p->coloana))
			cauta_rec(p->st, el);
		else
			cauta_rec(p->dr, el);
	}
}
PNod Matrice::minim(PNod p)
{
	while (p->st != nullptr)
		p = p->st;
	return p;
}
PNod Matrice::stergeRec(PNod p, std::pair<std::pair<int, int>, TElem> el)
{
	/*if (p == nullptr)
		return nullptr;
	else
	{
		if (el.first < make_pair(p->linie, p->coloana))
		{
			p->st = stergeRec(p->st, el);
			return p;
		}
		else
			if (el.first > make_pair(p->linie, p->coloana))
			{
			p->dr = stergeRec(p->dr, el);
			return p;
			}
			else
			{
				if (p->st != nullptr && p->dr != nullptr)
				{
					PNod temp = minim(p->dr);
					p->linie = temp->linie;
					p->coloana = temp->coloana;
					p->valoare = temp->valoare;
					p->dr = stergeRec(p->dr, make_pair(make_pair(p->linie, p->coloana), p->valoare));
					return p;
				}
				else
				{
					PNod temp = p;
					PNod repl=new Nod(0,0,0,nullptr,nullptr);
					if (p->st == nullptr)
					{
						repl = p->dr;

					}
					else 
						repl = p->st;
					delete temp;
					return repl;
				}
			}
	}*/
	if (p == nullptr)
		return nullptr;
	PNod prev = nullptr;
	while (p != nullptr && make_pair(p->linie, p->coloana) != el.first)
	{
		prev = p;
		if (el.first < make_pair(p->linie, p->coloana))
		{
			p = p->st;
		}
		else
			if (el.first > make_pair(p->linie, p->coloana))
			{
				p = p->dr;
			}
	}
	if (p == nullptr)
	{
		return nullptr;
	}
	if (p->st == nullptr || p->dr == nullptr)
	{
		PNod nou=nullptr;
		if (p->st == nullptr)
			nou = p->dr;
		else nou = p->st;

		if (prev == nullptr)
			return nou;
		if (p == prev->st)
			prev->st = nou;
		else prev->dr = nou;
		free(p);

	}
	else
	{
		PNod nod = nullptr;
		PNod temp = nullptr;
		temp = p->dr;
		while (temp->st != nullptr)
		{
			nod = temp;
			temp = temp->st;
		}
		if (nod != nullptr)
			nod->st = temp->dr;
		else
			p->dr = temp->dr;
		p->linie = temp->linie;
		p->coloana = temp->coloana;
		p->valoare = temp->valoare;
		free(temp);
	}
	return p;
}
Matrice::Matrice(int m, int n):nrL(m),nrC(n) {
	/* de adaugat */
	if (m <= 0 || n <= 0) throw std::exception();
	radacina = nullptr;
}
Matrice::~Matrice()
{
	distrugeRec(radacina);
}


int Matrice::nrLinii() const{
	/* de adaugat */
	return nrL;
}


int Matrice::nrColoane() const {
	/* de adaugat */
	return nrC;
}


TElem Matrice::element(int i, int j) const{
	/* de adaugat */
	if (i < 0 || j < 0 || i>=nrL ||j>=nrC )
		throw std::exception();
	PNod el_cautat = cauta_rec(radacina, { {i,j},0 });
	if (el_cautat != nullptr)
		return el_cautat->valoare;
	else
		return NULL_TELEMENT;
}


TElem Matrice::modifica(int i, int j, TElem e) {
	/* de adaugat */
	if (i < 0 || j < 0 || i >= nrL || j>= nrC)
		throw std::exception();
	PNod el_cautat = cauta_rec(radacina, { {i,j},e });
	if (el_cautat == nullptr)
	{
		PNod val=adaugaRec(radacina, { {i,j},e });
		
		return val->valoare;
	}
	else
		if (e == 0)
		{
				radacina=stergeRec(radacina,{{i,j},e});
		}
	else
	{
		el_cautat->valoare = e;
	}
	return radacina->valoare;
}
IteratorMatrice Matrice::iterator()
{
	return IteratorMatrice(*this);
}

