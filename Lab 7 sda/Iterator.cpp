#include "Iterator.h"

void IteratorMatrice::prim()
{
	while (!s.empty())
		s.pop();
	curent = m.radacina;
	while (curent != nullptr)
	{
		s.push(curent);
		curent = curent->st;
	}
	if (!s.empty())
	{
		curent = s.top();
	}
	
}
void IteratorMatrice::urmator()
{
	if (curent == NULL || m.radacina == NULL)
	{
		throw std::exception();
	}
	s.pop();
	if (curent->dr != NULL)
	{
		curent = curent->dr;
		while (curent != NULL)
		{
			s.push(curent);
			curent = curent->st;
		}
	}
	if (!s.empty())
	{
		curent = s.top();
	}
	else { curent = NULL; }

}
TElem IteratorMatrice::element()
{
	if (curent == NULL || m.radacina == NULL)
		throw std::exception();

	return curent->valoare;

}
bool IteratorMatrice::valid()
{

	return curent == NULL || m.radacina == NULL;
}