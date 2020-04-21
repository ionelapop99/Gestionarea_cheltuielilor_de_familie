#include "pch.h"
#include "Repo.h"
#include "Cheltuieli.h"

#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller
{
protected:
	Repo* List;
	//obiect,nu lista
public:
	Controller();
	Controller(Repo *rCrt);
	~Controller();

	///----------------------------------------------------------------
	//print functions
	void printAll();
	void printByType(const char*c);
	void printByTypeSum(const char *c);

	//delete functions
	void deleteByDay(int);
	void deleteBetween(int, int);
	void deleteByType(const char *);

	///Getters
	int getSize();
	Cheltuieli* getAll() { return this->List->getAll(); }

	///filter functons
	vector<Cheltuieli> filterByType(const char* c);
	vector<Cheltuieli> filterByTypeSumGreater(const char* c, int sum);///>
	vector<Cheltuieli> filterByTypeSumLower(const char*c, int sum);///<
	vector<Cheltuieli> filterByTypeSumEqual(const char* c, int sum);//==

	//properties of different sublists
	int sumByType(const char *c);
	void maxDay(int &,int &);
	void sortByDay(int Sum[33],int Days[33]);
	void sortByType(const char* c,int Sum[33],int Days[33]);

	//basically function
	void add(const Cheltuieli &c);
	void update(int pos, const Cheltuieli &c);
	void deleteE(int pos);
};
#endif