#include "pch.h"
#include "cheltuieli.h"
#include<vector>
#ifndef REPO_H
#define REPO_H
class Repo
{
private:
	vector<Cheltuieli>List;
public:
	Repo();
	Repo(const vector<Cheltuieli>&v);
	~Repo();

	//-------------------------------------------------------
	//Getterss
	Cheltuieli* getAll() { return &this->List[0]; }
	int getSize();
	vector<Cheltuieli>getByDay(int day);
	//vector<Cheltuieli>getByType(const char *c);

	//---------------------------------------------------------
	//other functions
	
	void update(int pos, const Cheltuieli &c);
	void insert(const Cheltuieli &c);
	//void addElem()
	
	//delete functions
	void deleteElem(int pos);
	

	//operator= overloading
	//Repo& operator= (const vector<Cheltuieli>&L);
	Repo& operator=(Repo &L);
};
#endif