/*
* C++ program to demonstrate
* Overriding new and delete operator
* for a specific class
*/

#include<iostream>
#include<stdlib.h>
#include<string>
#include<conio.h>
using namespace std;

class Student
{
	string name;
	int age;

public:
	Student()
	{
		cout << "Constructor is called" << endl;
	}

	Student(string name, int age)
	{
		this->name = name;
		this->age = age;
	}

	void display()
	{
		cout << "Name: " << name << endl;
		cout << "Age:" << age << endl;
	}

	void * operator new(size_t size)
	{
		cout << "Overriding new operator (specific to class) with size: " << size << endl;
		void* p = ::new Student();
		//void* p = malloc(size); //Allocation of memory using malloc keyword will also work fine

		return p;
	}

	void operator delete(void* p)
	{
		cout << "Overriding delete operator specific to class" << endl;
		free(p);
	}
};

int main()
{
	Student* s = new Student("John", 23);

	s->display();
	delete s;

	_getch();

	return 0;
}