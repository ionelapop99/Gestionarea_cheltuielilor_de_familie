// lab 5-6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "tests.h"

#include "UI.h"


using namespace std;

int main()
{
	//--------------------------------------------------------
	//Called tests
	testCheltuieli();
	cout << "A" << endl;
	testRepo_AddElem_GetAll();
	cout << "B" << endl;
	testDeleteElem();
	cout <<endl<< "C" << endl;
	testUpdate();
	cout << "D" << endl;
	test_deleteByDay();
	cout << "E" << endl;
	test_deleteBetween();
	cout << "F" << endl;
	test_deleteByType();
	cout << "G" << endl;
	basicallyFunctionTests_Controller();
	cout << "H" << endl;
	Tests_sumByType();
	cout << "I" << endl;
	Tests_maxDay();
	cout << "J" << endl;
	cout << endl;

	//----------------------------------------------
	
	UI* ui = new UI();
	ui->run();
	return 0;
}