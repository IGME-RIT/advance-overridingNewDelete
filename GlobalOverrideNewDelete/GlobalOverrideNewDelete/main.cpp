/*
* C++ program to demonstrate
* Global overriding of
* new and delete operator
*/
#include<iostream>
#include<stdlib.h>

using namespace std;
void * operator new(size_t size)
{
	cout << "New operator overriding " << endl;
	void * p = malloc(size);
	return p;
}

void operator delete(void * p)
{
	cout << "Delete operator overriding " << endl;
	free(p);
}

int main()
{
	int n = 5, i;
	int * p = new int[3];

	for (i = 0; i<n; i++)
		p[i] = i;

	cout << "Array: ";
	for (i = 0; i<n; i++)
		cout << p[i] << " ";

	cout << endl;

	delete p;
}