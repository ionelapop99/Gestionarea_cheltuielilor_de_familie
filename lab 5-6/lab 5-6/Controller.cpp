#include "pch.h"
#include "Repo.h"
#include "Controller.h"
#include <algorithm>

//controller default constructor
Controller::Controller()
{
	///cout << "[Controller] default constructor" << endl;
	this->List = new Repo();
}

//constructor with param
Controller::Controller(Repo* rCrt)
{
	//cout << "[Controller]Constructor with param" << endl;
	this->List = rCrt;
}

//controller destructor
Controller::~Controller()
{
	//cout << "[Controller] Destructor" << endl;
	this->List = NULL;
}

//deleteByDay
void Controller::deleteByDay(int d)
{
	for (unsigned i = 0; i < this->List->getSize(); i++)
	{
		if (this->List->getAll()[i].getDay() == d)
		{
			this->List->deleteElem(i);
			i--;
		}
	}
}

//deleteBetween
void Controller::deleteBetween(int startd, int stopd)
{
	for (unsigned i = 0; i < this->List->getSize(); i++)
	{
		if (this->List->getAll()[i].getDay() >= startd && this->List->getAll()[i].getDay() <= stopd)
		{
			this->List->deleteElem(i);
			i--;
		}
	}
}

//deleteByType
void Controller::deleteByType(const char*c)
{
	for (unsigned i = 0; i < List->getSize(); i++)
	{
		if (strcmp(this->List->getAll()[i].getType(), c) == 0)
		{
			this->List->deleteElem(i);
			i--;
		}
	}
}
/*
//-----------------------------------------------------------
//print list
void Controller::printAll()
{
	cout << "Day" << "\t |" << "Sum" << "\t |" << "Type" << endl;
	for(unsigned i=0;i<this->List->getSize();i++)
	{
		cout << this->List->getAll()[i]<<endl;
	}
}

//print by type
void Controller::printByType(const char *c)
{
	cout << "Day" << "\t |" << "Sum" << "\t |" << "Type" << endl;
	for(unsigned i=0;i<this->List->getSize();i++)
	{
		if (strcmp(this->List->getAll()[i].getType(), c) == 0)
		{
			cout << this->List->getAll()[i] << endl;
		}
	}
}

 //print by type & sum*
void Controller::printByTypeSum(const char *c)
{
	cout << "Day" << "\t |" << "Sum" << "\t |" << "Type" << endl;
	for (unsigned i = 0; i < this->List->getSize(); i++)
	{
		if (strcmp(this->List->getAll()[i].getType(), c) == 0)
		{
			cout << this->List->getAll()[i] << endl;
		}
	}
}
*/

///------------------------------------------------------------------
//Getters

int Controller::getSize()
{
	return this->List->getSize();
}

//----------------------------------------------------------------------
//filter functons

vector<Cheltuieli> Controller::filterByType(const char* c)
{
	vector<Cheltuieli>L;
	for(unsigned i=0;i<this->List->getSize();i++)
	{
		if (strcmp(this->List->getAll()[i].getType(), c) == 0)
		{
			L.push_back(this->List->getAll()[i]);
		}

	}
	return L;
}

vector<Cheltuieli> Controller::filterByTypeSumEqual(const char* c, int s)
{
	vector<Cheltuieli>L;
	for (unsigned i = 0; i < this->List->getSize(); i++)
	{
		if (strcmp(this->List->getAll()[i].getType(), c) == 0 && this->List->getAll()[i].getSum()==s)
		{
			L.push_back(this->List->getAll()[i]);
		}

	}
	return L;
}

vector<Cheltuieli> Controller::filterByTypeSumGreater(const char* c, int s)
{
	vector<Cheltuieli>L;
	for (unsigned i = 0; i < this->List->getSize(); i++)
	{
		if (strcmp(this->List->getAll()[i].getType(), c) == 0 && this->List->getAll()[i].getSum() > s)
		{
			L.push_back(this->List->getAll()[i]);
		}

	}
	return L;
}

vector<Cheltuieli> Controller::filterByTypeSumLower(const char* c, int s)
{
	vector<Cheltuieli>L;
	for (unsigned i = 0; i < this->List->getSize(); i++)
	{
		if (strcmp(this->List->getAll()[i].getType(), c) == 0 && this->List->getAll()[i].getSum() <s)
		{
			L.push_back(this->List->getAll()[i]);
		}

	}
	return L;
}

///------------------------------------------------------------------------------------------------
//properties of different sublists

//Max Day-the day with the highest expenses
void Controller::maxDay(int &sMax,int &d)
{
	sMax = 0;
	d = 0;
	
	for (unsigned i = 1;i<=31; i++)
	{
		vector<Cheltuieli>L = this->List->getByDay(i);
		int s = 0;
		for(unsigned j=0;j<L.size();j++)
		{
			s += L[j].getSum();
		}
		if(s>sMax)
		{
			sMax = s;
			d = i;
		}
	}
}

///Sum By Type-sum for a given type
int Controller::sumByType(const char* c)
{
	int s = 0;
	for(unsigned i=0;i<this->List->getSize();i++)
	{
		if(strcmp(this->List->getAll()[i].getType(), c) == 0)
		{
			s += this->List->getAll()[i].getSum();
		}
	}
	return s;
}

//Sort By Day-daily decreasing amounts
void Controller::sortByDay(int Sum[33],int Days[33])
{
	for (unsigned i = 1; i <= 31; i++)
	{
		Days[i] = i;
		vector<Cheltuieli>L = this->List->getByDay(i);
		//V[i] = L;
		int s = 0;
		for (unsigned j = 0; j < L.size(); j++)
		{
			s += L[j].getSum();
		}
		Sum[i] = s;
	}
	for(unsigned i=1;i<31;i++)
	{
		for(unsigned j=i+1;j<=31;j++)
		{
			//vector<Cheltuieli> auxC;
			int aux;
			if(Sum[i]<Sum[j])
			{
				aux = Sum[i];
				Sum[i] = Sum[j];
				Sum[j] = aux;

				aux = Days[i];
				Days[i] = Days[j];
				Days[j] = aux;

				/*auxC = V[i];
				V[i] = V[j];
				V[j] = auxC;*/
			}
		}
	}
}

///Sort by Type-the amounts spent daily for a given type,upgraded
void Controller::sortByType(const char* c,int Sum[33],int Days[33])
{
	//vector<vector<Cheltuieli>>V;

	for (unsigned i = 1; i <= 31; i++)
	{
		vector<Cheltuieli>L = this->List->getByDay(i);
		//V[i] = L;
		int s = 0;
		for (unsigned j = 0; j < L.size(); j++)
		{
			if(strcmp(L[j].getType(),c)==0)
			{
				s += L[j].getSum();
			}
		}
		Sum[i] = s;
		Days[i] = i;
	}

	for (unsigned i = 1; i < 31; i++)
	{
		for (unsigned j = i + 1; j <= 31; j++)
		{
			//vector<Cheltuieli> auxC;
			int aux;
			if (Sum[i] > Sum[j])
			{
				aux = Sum[i];
				Sum[i] = Sum[j];
				Sum[j] = aux;

				aux = Days[i];
				Days[i] = Days[j];
				Days[j] = aux;

				/*auxC = V[i];
				V[i] = V[j];
				V[j] = auxC;*/
			}
		}
	}
}

//------------------------------------------------------------------------------
//add element
void Controller::add(const Cheltuieli& c)
{
	this->List->insert(c);
}

//update
void Controller::update(int pos, const Cheltuieli& c)
{
	this->List->update(pos, c);
}

//delete
void Controller::deleteE(int pos)
{
	this->List->deleteElem(pos);
}












