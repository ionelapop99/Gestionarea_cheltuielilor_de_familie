#include "pch.h"
#include "cheltuieli.h"
#ifndef REPO_H
#define REPO_H
class Repo
{
private:
	Cheltuieli* ListC;
	int size;
public:
	Repo();
	Repo(int, Cheltuieli*);
	~Repo();
	void addElem(const Cheltuieli &);
	Cheltuieli* getAll();
	int getSize();
	void Resize();
	void deleteElem(int pos);
	void update(int pos, const Cheltuieli c);
};
#endif