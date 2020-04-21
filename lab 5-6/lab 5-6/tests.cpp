#include "pch.h"
#include<iostream>
#include<cassert>
#include "cheltuieli.h"
#include "tests.h"
#include "Repo.h"
#include "Controller.h"

using namespace std;
//-----------------------------------------------------------------
//tests Cheltuieli
void testCheltuieli()
{
	Cheltuieli c1 = Cheltuieli();//empty cheltuieli
	assert(c1.getType() == NULL);
	assert(c1.getDay() == 0);
	assert(c1.getSum() == 0);

	char t[] = "mancare";
	Cheltuieli c2 = Cheltuieli(5, 80, t);// cheltuiala cu informatii
	assert(c2.getDay() == 5);
	assert(c2.getSum() == 80);
	assert(strcmp(c2.getType(), t) == 0);

	Cheltuieli c3 = Cheltuieli(c2);///c3= a copy of c2
	assert(strcmp(c3.getType(),t) == 0);
	assert(c3.getDay() == 5);
	assert(c3.getSum() == 80);

	assert(c2==c3);
	c2.setDay(10);
	assert(c2.getDay() == 10);

	assert(c2!=c3);

	c2.setSum(100);
	assert(c2.getSum() == 100);
	cout << "test from Cheltuieli run ok" << endl;
	return;
}

//----------------------------------------------------------------------
//Tests Repo
void testRepo_AddElem_GetAll()
{
	char t[8] = "mancare";
	char t1[6] = "haine";

	Cheltuieli c1 = Cheltuieli(5, 80, t);
	Cheltuieli c2 = Cheltuieli(10, 100, t1);
	
	Repo l1=Repo();
	l1.insert(c1);
	l1.insert(c2);
	l1.insert(c2);
	assert(l1.getAll()[0] == c1);
	assert(l1.getAll()[1] == c2);
	assert(l1.getSize() == 3);
	assert(l1.getAll()[2] == c2);
	cout << "test Repo insert & getAll run ok" << endl;
}

void testDeleteElem()
{
	char t[8] = "mancare";
	char t1[6] = "haine";
	char t2[10] = "transport";

	Cheltuieli c1 = Cheltuieli(5, 80, t);
	Cheltuieli c2 = Cheltuieli(10, 100, t1);
	Cheltuieli c3 = Cheltuieli(20, 101, t2);
	
	Repo l1=Repo();
	l1.insert(c1);
	l1.insert(c3);
	l1.insert(c2);
	l1.deleteElem(1);
	assert(l1.getSize() == 2);
	assert(l1.getAll()[0] == c1);
	assert(l1.getAll()[1] == c2);
	cout << "test deleteElem run ok";
}

void testUpdate()
{
	char t[8] = "mancare";
	char t1[6] = "haine";
	char t2[10] = "transport";

	Cheltuieli c1 = Cheltuieli(5, 80, t);
	Cheltuieli c2 = Cheltuieli(10, 100, t1);
	Cheltuieli c3 = Cheltuieli(20, 101, t2);

	Repo l1 = Repo();
	l1.insert(c1);
	l1.insert(c2);
	l1.insert(c3);

	Cheltuieli u1 = Cheltuieli(6, 80, t);
	l1.update(0, u1);
	l1.getAll()[0] == u1;

	Cheltuieli u2 = Cheltuieli(10, 103, t1);
	l1.update(1, u2);
	l1.getAll()[1] == u2;

	char t4[7] = "chirie";
	Cheltuieli u3 = Cheltuieli(20, 101,t4);
	l1.update(2, u3);
	l1.getAll()[2] == u3;

	cout << "all update test run ok" << endl;
}
//---------------------------------------------------------------------
//Delete Tests + GetALL tests + GetSize tests
void test_deleteByDay()
{
	char t[8] = "mancare";
	char t1[6] = "haine";
	char t2[10] = "transport";

	Cheltuieli c1 = Cheltuieli(5, 80, t);
	Cheltuieli c2 = Cheltuieli(5, 100, t1);
	Cheltuieli c3 = Cheltuieli(20, 101, t2);

	Repo* l1 = new Repo();
	l1->insert(c1);
	l1->insert(c2);
	l1->insert(c3);
	
	Controller list = Controller(l1);

	//list.printAll();
	list.deleteByDay(5);
	//list.printAll();
	assert(list.getSize()== 1);
	assert(list.getAll()[0] == c3);
	cout << "all test from deleteByDay run ok" << endl;
}

void test_deleteBetween()
{
	char t[8] = "mancare";
	char t1[6] = "haine";
	char t2[10] = "transport";

	Cheltuieli c1 = Cheltuieli(5, 80, t);
	Cheltuieli c2 = Cheltuieli(9, 100, t1);
	Cheltuieli c3 = Cheltuieli(20, 101, t2);
	Cheltuieli c4 = Cheltuieli(25, 105, t2);

	Repo* l1 =new Repo();
	l1->insert(c1);
	l1->insert(c2);
	l1->insert(c3);
	l1->insert(c4);

	Controller list = Controller(l1);

	list.deleteBetween(5, 20);
	assert(list.getSize() == 1);
	assert(list.getAll()[0] == c4);
	cout << "all test from DeleteBetween run ok" << endl;
}

void test_deleteByType()
{
	char t[8] = "mancare";
	char t1[6] = "haine";
	char t2[10] = "transport";

	Cheltuieli c1 = Cheltuieli(5, 80, t);
	Cheltuieli c2 = Cheltuieli(9, 100, t1);
	Cheltuieli c3 = Cheltuieli(20, 101, t2);
	Cheltuieli c4 = Cheltuieli(25, 105, t2);

	Repo* l1 = new Repo();
	l1->insert(c1);
	l1->insert(c2);
	l1->insert(c3);
	l1->insert(c4);

	Controller list = Controller(l1);

	list.deleteByType(t2);
	assert(list.getSize() == 2);
	assert(list.getAll()[0] == c1);
	assert(list.getAll()[1] == c2);
	cout << "test from deleteByType run ok" << endl;
}

//---------------------------------------------------------------
//
void Tests_sumByType()
{
	Controller c = Controller();
	char t0[10] = "mancare";
	char t1[10] = "haine";
	char t2[10] = "curatenie";
	char t3[10] = "transport";
	char t4[10] = "party";

	Cheltuieli x = Cheltuieli(1, 25, t0);
	Cheltuieli x1 = Cheltuieli(1, 60, t2);
	Cheltuieli x2 = Cheltuieli(2, 80, t1);
	Cheltuieli x3 = Cheltuieli(3, 25, t2);
	Cheltuieli x4 = Cheltuieli(4, 36, t3);
	Cheltuieli x5 = Cheltuieli(10, 100, t4);
	Cheltuieli x6 = Cheltuieli(1, 30, t2);

	c.add(x);
	c.add(x1);
	c.add(x2);
	c.add(x3);
	c.add(x4);
	c.add(x5);
	c.add(x6);


	int s=c.sumByType(t2);
	assert(s == 115);
	s = c.sumByType(t4);
	assert(s == 100);
	cout << "all tests sumByType run ok" << endl;
}

void Tests_maxDay()
{
	Controller c = Controller();
	char t0[10] = "mancare";
	char t1[10] = "haine";
	char t2[10] = "curatenie";
	char t3[10] = "transport";
	char t4[10] = "party";

	Cheltuieli x = Cheltuieli(1, 25, t0);
	Cheltuieli x1 = Cheltuieli(1, 60, t2);
	Cheltuieli x2 = Cheltuieli(2, 80, t1);
	Cheltuieli x3 = Cheltuieli(3, 25, t2);
	Cheltuieli x4 = Cheltuieli(4, 36, t3);
	Cheltuieli x5 = Cheltuieli(10, 100, t4);
	Cheltuieli x6 = Cheltuieli(1, 30, t2);

	c.add(x);
	c.add(x1);
	c.add(x2);
	c.add(x3);
	c.add(x4);
	c.add(x5);
	c.add(x6);

	int sMax, d;
	
	c.maxDay(sMax, d);
	assert(sMax==115 && d==1);
	cout << "all tests from MaxDay run ok" << endl;
}


//--------------------------------------------------------------
void basicallyFunctionTests_Controller()
{
	Controller c = Controller();
	char y[20] = "mancare";
	Cheltuieli x = Cheltuieli(2, 30, y);
	c.add(x);

	assert(c.getAll()[0] == x);

	Cheltuieli x1 = Cheltuieli(2, 80, y);
	c.update(0, x1);
	assert(c.getAll()[0] == x1);

	c.deleteE(0);
	assert(c.getSize() == 0);
	cout << "all Basically function tests from controller run ok" << endl;
}

