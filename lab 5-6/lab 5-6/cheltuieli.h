#include "pch.h"
#include<iostream>

using namespace std;
#ifndef CHELTUIELI_H
#define CHELTUIELI_H
class Cheltuieli
{
private:
	int day;
	int sum;
	char* type;
public:
	//-------------------------------------------------------------
	//Constructors& Destructor
	Cheltuieli();
	Cheltuieli(int,int,char*);
	Cheltuieli(const Cheltuieli &);
	~Cheltuieli();

	//--------------------------------------------------------------
	//Getters
	char* getType();
	int getSum();
	int getDay();

	//--------------------------------------------------------------
	//Setters
	void setType(char*);
	void setSum(int);
	void setDay(int);

	//--------------------------------------------------------------
	//Operators
	Cheltuieli& operator=(const Cheltuieli &);
	bool operator==(const Cheltuieli&)const;
	bool operator!=(const Cheltuieli&)const;

	//----------------------------------------------------------------
	bool compare(const Cheltuieli &Otherc)const;

	//---------------------------------------------------------------
	friend ostream& operator<<(ostream &os, const Cheltuieli &obj);
};
#endif