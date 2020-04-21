#include "pch.h"
#include<iostream>
#include<cassert>
#include "cheltuieli.h"
#include "tests.h"
#include "Repo.h"

using namespace std;
void testCheltuieli()
{
	Cheltuieli c1 = Cheltuieli();//empty cheltuieli
	assert(c1.getType() == NULL);
	assert(c1.getDay() == 0);
	assert(c1.getSum() == 0);

	char *t = new char[8];
	strcpy_s(t,8, "mancare");
	Cheltuieli c2= Cheltuieli(5, 80,t);// cheltuiala cu informatii
	assert(c2.getDay() == 5);
	assert(c2.getSum() == 80);
	assert(strcmp(c2.getType(),t) == 0);

	/*Cheltuieli c3 = Cheltuieli(c2);///c3= a copy of c2
	assert(strcmp(c3.getType(),t) == 0);
	assert(c3.getDay() == 5);
	assert(c3.getSum() == 80);
	
	assert(c2.operator==(c3) == true);*/
	c2.setDay(10);
	assert(c2.getDay() == 10);

	//assert(c2.operator!=(c3) == true);

	c2.setSum(100);
	assert(c2.getSum() == 100);
	cout << "test from Cheltuieli run ok" << endl;
	//c3.~Cheltuieli();
	c2.~Cheltuieli();
	c1.~Cheltuieli();
	return;
}
void testRepo()
{
	Repo l=Repo();
	//assert(l.getAll());
	assert(l.getSize() == 0);
	cout << "test Repo default constructor run ok" << endl;

	Cheltuieli *x = new Cheltuieli[2];
	char *t = new char[8];
	strcpy_s(t, 8, "mancare");
	char *t1 = new char[6];
	strcpy_s(t1, 6, "haine");
	Cheltuieli c1 = Cheltuieli(5, 80, t);
	Cheltuieli c2 = Cheltuieli(10, 100, t1);

	x[0] = c1;
	x[1] = c2;
	Repo l1 = Repo(2, x);
	assert(l1.getAll() == x);
	assert(l1.getSize() == 2);
	cout << "test Repo constructor with parameters run ok" << endl;
}
void testGetAll()
{
	Cheltuieli *x = new Cheltuieli[2];
	char *t = new char[8];
	strcpy_s(t, 8, "mancare");
	char *t1 = new char[6];
	strcpy_s(t1, 6, "haine");
	Cheltuieli c1 = Cheltuieli(5, 80, t);
	Cheltuieli c2 = Cheltuieli(10, 100, t1);

	x[0] = c1;
	x[1] = c2;
	Repo l1 = Repo(2, x);
	assert(l1.getAll()[0] == c1);
	assert(l1.getAll()[1] == c2);
	assert(l1.getSize() == 2);
	cout << "test GetAll run ok" << endl;
}
void testADDElem()
{
	Cheltuieli *x = new Cheltuieli[2];
	char *t = new char[8];
	strcpy_s(t, 8, "mancare");
	char *t1 = new char[6];
	strcpy_s(t1, 6, "haine");
	Cheltuieli c1 = Cheltuieli(5, 80, t);
	Cheltuieli c2 = Cheltuieli(10, 100, t1);

	x[0] = c1;
	Repo l1 = Repo(1, x);
	l1.addElem(c2);
	assert(l1.getSize() == 2);
	assert(l1.getAll()[1] == c2);
	cout << "test AddElem run ok" << endl;
	
}
void testDeleteElem()
{
	Cheltuieli *x = new Cheltuieli[2];
	char *t = new char[8];
	strcpy_s(t, 8, "mancare");
	char *t1 = new char[6];
	strcpy_s(t1, 6, "haine");
	Cheltuieli c1 = Cheltuieli(5, 80, t);
	Cheltuieli c2 = Cheltuieli(10, 100, t1);

	x[0] = c1;
	x[1] = c2;
	Repo l1 = Repo(2, x);
	l1.deleteElem(1);
	assert(l1.getAll()[1] != c2);
	assert(l1.getAll()[0] == c1);
	assert(l1.getSize() == 1);
	cout << "test deleteElem run ok";
}
void testUpdate()
{
	
}


