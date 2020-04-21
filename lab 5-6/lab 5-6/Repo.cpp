#include "pch.h"
#include "Repo.h"
#include<iostream>

using namespace std;

//default constructor
Repo::Repo()
{
	this->List.reserve(10);
	//cout << "[Repo] default constructor" << endl;
}

//copy constructor
Repo::Repo(const vector<Cheltuieli>&v)
{

	for(unsigned i=0;i<v.size();i++){
		this->List.push_back(v[i]);
	}
	//cout << "[Repo] copy constructor" << endl;
	
}

//destructor
Repo::~Repo(){
	this->List.~vector();
	//cout << "[Repo] destructor" << endl;
}

//---------------------------------------------------------------
int Repo::getSize()
{
	return this->List.size();
}

vector<Cheltuieli> Repo::getByDay(int day)
{
	vector<Cheltuieli>L;
	for(unsigned i=0;i<this->List.size();i++)
	{
		if(this->List[i].getDay()==day)
		{
			L.push_back(this->List[i]);
		}
	}
	return L;
}

//---------------------------------------------------------
//delete 
void Repo::deleteElem(int pos)
{
	this->List.erase(this->List.begin() + pos);
}

//update
void Repo::update(int pos,const Cheltuieli &c)
{

	this->List[pos] = c;
	if (c.compare(List[pos])==true)
	{
		this->List[pos] = c;
	}
}

//add
void Repo::insert(const Cheltuieli &c)
{
	this->List.push_back(c);
}

///--------------------------------------------------------------------
//Operator = overloading
/*Repo& Repo:: operator=(const vector<Cheltuieli>&L)
{
	for (unsigned i = 0; i < List.size(); i++)
	{
		this->List.push_back(L[i]);
	}
	return *this;
}*/

//Operator = overloading
Repo& Repo::operator=( Repo  &L)
{

	for (unsigned i = 0; i < L.getSize(); i++)
	{
		this->List.push_back(L.getAll()[i]);
	}
	return *this;
}