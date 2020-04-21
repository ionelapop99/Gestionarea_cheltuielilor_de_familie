#include "pch.h"
#include "Repo.h"
#include "cheltuieli.h"
#include<iostream>

using namespace std;

Repo::Repo()
{
	cout << "[Repo]default constructor" << endl;
	this->ListC = new Cheltuieli[10];
	this->size = 0;
}

Repo::Repo(int s, Cheltuieli* list)
{
	cout << "[Repo]constructor with param" << endl;
	if(this->ListC!=NULL)
	{
		delete[]ListC;
	}
	this->ListC = list;
	this->size = s;
}


Repo::~Repo(){

	if(this->ListC!=NULL)
	{
		cout << "[Repo] destructor" << endl;
		delete[]this->ListC;
		this->ListC = NULL;
	}
}

void Repo::addElem(const Cheltuieli &c)
{
	if(this->size < sizeof(this->ListC))
	{
		this->ListC[size] = c;
		size++;
	}
	else
		Resize();
	
}
void Repo::Resize()
{

	Cheltuieli *newList = new Cheltuieli[2* size];
	for(int i=0;i<size;i++)
	{
		newList[i] = this->ListC[i];
	}
	this->ListC = NULL;
	this->ListC = newList;
	delete[] newList;
}
Cheltuieli* Repo::getAll()
{
	return this->ListC;
}
int Repo::getSize()
{
	return this->size;
}
void Repo::deleteElem(int pos)
{
	//this->ListC.erase(this->ListC.begin() + pos);

	//in ui anunta ca pozitiile incep de la 0
	if(pos==size-1)
	{
		Cheltuieli c = Cheltuieli(0, 0, "null");
		this->ListC[pos] = c;
	}
	for(int i=pos;i<size-1;i++)
	{
		this->ListC[i] =this->ListC[i + 1];
	}
	this->size = this->size - 1;
}

void Repo::update(int pos,const Cheltuieli c)
{
	this->ListC[pos] = c;
}







