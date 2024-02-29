#include "TestScurt.h"
#include <assert.h>
#include "Matrice.h"
#include <iostream>
#include "Iterator.h"
using namespace std;
void testIterator()
{
	Matrice m(4, 4);
	m.modifica(1, 1, 3);
	m.modifica(2, 2, 1);
	m.modifica(2, 1, 4);
	m.modifica(3, 2, 1);
	
	IteratorMatrice it = m.iterator();
	assert(it.element() == 3);
	it.urmator();
	assert(it.element() == 4);
	it.urmator();
	assert(it.element() == 1);
	it.prim();
	while (it.valid())
	{
		int el=it.element();
		it.urmator();
	}

	Matrice m2(3, 3);
	IteratorMatrice it2 = m2.iterator();
	try {
		it2.urmator();
	}
	catch(std::exception){}
	
	try
	{
		it2.element();
	}
	catch (std::exception) {}
}
void testAll() { //apelam fiecare functie sa vedem daca exista
	Matrice m(4,4);
	assert(m.nrLinii() == 4);
	assert(m.nrColoane() == 4);
	//adaug niste elemente
	m.modifica(1,1,5);
	assert(m.element(1,1) == 5);
	m.modifica(1,1,6);
	assert(m.element(1,2) == NULL_TELEMENT);
	testIterator();
}
