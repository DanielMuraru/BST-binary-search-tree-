#include "Matrice.h"
#include <stack>
using std::stack;
class IteratorMatrice
{
	friend class Matrice;
private:
	Matrice& m;
	//std::stack < std::pair<std::pair<int, int>, int>> s;
	std::stack<PNod> s;
	PNod curent;

public:
	IteratorMatrice(Matrice& ma) :m(ma) { prim(); }
	
	
	// reseteaza pozitia iteratorului la inceputul containerului
	//teta(h)
	void prim();


	// muta iteratorul in container
	// arunca exceptie daca iteratorul nu e valid
	//O(h)
	void urmator();

	// returneaza valoarea elementului din container referit de iterator
	// arunca exceptie daca iteratorul nu e valid
	//teta(1)
	TElem element();


	// verifica daca iteratorul e valid (indica un element al containerului)
	//teta(1)
	bool valid();
	
	~IteratorMatrice() = default;


};