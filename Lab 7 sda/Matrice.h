#pragma once
#include <utility>
typedef int TElem;
class Nod;
typedef Nod *PNod;

#define NULL_TELEMENT 0
class IteratorMatrice;
class Nod
{
	friend class Matrice;
	friend class IteratorMatrice;
private:
	int linie, coloana;
	TElem valoare;
	PNod st;
	PNod dr;

public:
	Nod(int val,int linie,int coloana, PNod st, PNod dr);
	int get_valoare();
	PNod urmator();
};
class Matrice {
	friend class Nod;
	friend class IteratorMatrice;
private:
	/* aici e reprezentarea */
	int nrL;
	int nrC;
	PNod radacina;
	PNod adaugaRec(PNod p,std::pair<std::pair<int,int>,TElem> el);
	void distrugeRec(PNod p);
	PNod cauta_rec(PNod p, std::pair<std::pair<int, int>,TElem> el) const;
	PNod stergeRec(PNod p, std::pair<std::pair<int, int>, TElem> el);
	PNod minim(PNod p);
public:

	//constructor
	//se arunca exceptie daca nrLinii<=0 sau nrColoane<=0
	//Teta(1)
	Matrice(int nrLinii, int nrColoane);


	//destructor
	~Matrice();

	//returnare element de pe o linie si o coloana
	//se arunca exceptie daca (i,j) nu e pozitie valida in Matrice
	//indicii se considera incepand de la 0
	//O(h)
	TElem element(int i, int j) const;


	// returnare numar linii
	int nrLinii() const;

	// returnare numar coloane
	int nrColoane() const;


	// modificare element de pe o linie si o coloana si returnarea vechii valori
	// se arunca exceptie daca (i,j) nu e o pozitie valida in Matrice
	//O(h)
	TElem modifica(int i, int j, TElem);

	IteratorMatrice iterator();

};







