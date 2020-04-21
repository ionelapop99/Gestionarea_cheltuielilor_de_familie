#include "pch.h"
#include "cheltuieli.h"

//--------------------------------------------------------------
//Default Constructor
Cheltuieli::Cheltuieli()
{
	//cout << "[Cheltuieli]default constructor" << endl;
	 this->type= NULL;
	 this->sum= 0;
	 this->day = 0;
}

//Constructor with parametters
 Cheltuieli::Cheltuieli(int d, int s, char* type)
{
	 //cout << "[Cheltuieli]contructor with parameters"<<endl;
	 this->type = new char[strlen(type) + 1];
	 strcpy_s(this->type, strlen(type) + 1, type);
	 this->day = d;
	 this->sum = s;
}

//Copy constructor
Cheltuieli::Cheltuieli(const Cheltuieli &c)
{
	//cout << "[Cheltuieli]copy constructor" << endl;

	this->type = new char[strlen(c.type) + 1];
	strcpy_s(this->type, strlen(c.type) + 1, c.type);
	this->sum = c.sum;
	this->day = c.day;
}

//-------------------------------------------------------------
//Destructor
Cheltuieli::~Cheltuieli()
{
	
	if(this->type != NULL)
	{
		//cout << "[Cheltuieli]destructor "<<type << endl;
		delete []this->type;
		this->type = NULL;
	}
}
//---------------------------------------------------------------
//Operator = overloading
Cheltuieli& Cheltuieli::operator=(const Cheltuieli &c)
{
	if(this!=&c)
	{
		this->setType(c.type);
		this->setDay(c.day);
		this->setSum(c.sum);
	}
	return *this;
}

//Operator == overloading
bool Cheltuieli::operator==(const Cheltuieli &c)const
{
	return (strcmp(this->type, c.type) == 0) && (this->day == c.day && this->sum == c.sum);
}

//Operator != overloading
bool Cheltuieli::operator!=(const Cheltuieli &c)const
{
	return (strcmp(this->type, c.type) != 0) || (this->day != c.day || this->sum != c.sum);
}

//-------------------------------------------------------------------------
//cout operator overloading
ostream& operator<<(ostream &os, const Cheltuieli &obj) {
	os << obj.day << "\t |" << obj.sum << "\t\t |" << obj.type;
	return os;
}
//-------------------------------------------------------------------------------
//compare
bool Cheltuieli::compare(const Cheltuieli &Other)const
{
	if ((this->day == Other.day) || (this->sum == Other.sum || this->type == Other.type))
	{
		return true;
	}
	return false;
}

//---------------------------------------------------------------------------------
//Getters
int Cheltuieli::getDay()
{
	return this->day;
}
int Cheltuieli::getSum()
{
	return this->sum;
}
char* Cheltuieli::getType()
{
	return this->type;
}

//-----------------------------------------------------------------------------------
//setters
void Cheltuieli::setType(char *t)
{
	if (this->type)
	{
		delete[] this->type;
	}
	this->type = new char[strlen(t) + 1];
	strcpy_s(this->type, strlen(t) + 1, t);
}
void Cheltuieli::setDay(int d)
{
	this->day = d;
}
void Cheltuieli::setSum(int s)
{
	this->sum = s;
}


//------------------------------------------------------------------------------








