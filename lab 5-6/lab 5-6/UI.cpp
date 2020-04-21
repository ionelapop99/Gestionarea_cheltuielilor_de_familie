#include "pch.h"
#include "UI.h"
#include<iostream>
#include "cheltuieli.h"

using namespace std;

//default constructor
UI::UI()
{
	//cout << "[UI] default constructor" << endl;
	this->C = new Controller();
}


//constructor with param
UI::UI(Controller* crt)
{
	//cout << "[UI] constructor with parameters" << endl;
	this->C = crt;
}

//destructor
UI::~UI()
{
	//cout << "[UI] destructor" << endl;
	this->C = NULL;
}

//----------------------------------------------------------------------
//Menu
void UI::showMenu()
{
	cout << "Meniu:" << endl;
	cout << "1.Adauga Cheltuiala noua\n";
	cout << "2.Modifica o Cheltuiala\n";
	cout << "3.Sterge o Cheltuiala\n";
	cout << endl;
	cout << "4.Elimina Cheltuielile din ziua X\n";
	cout << "5.Elimina Cheltuielile din data X pana in data Y\n";
	cout << "6.Elimina toate Cheltuielile din categoria X\n";
	cout << endl;
	cout << "7.Afiseaza toate Cheltuielile din luna curenta\n";
	cout << "8.Afiseaza toate Cheltuielile din categoria X\n";
	cout << "9.Afiseaza Cheltuielile din categoria X > decat suma Y\n";
	cout << "10.Afiseaza Cheltuielile din categoria X < decat suma Y\n";
	cout << "11.Afiseaza Cheltuielile din categoria X = cu suma Y\n";
	cout << endl;
	cout << "12.Suma tututror Cheltuielilor din categoria X\n";
	cout << "13.Afisarea zile cu cele mai mari Cheltuieli\n";
	cout << "14.Afisarea sumelor cheltuite zilnic in ordine descrescatoare\n";///sortByDay
	cout << "15.Afisarea sumelor cheltuite zilnic pentru categoria X in ordine crescatoare\n";//sortByType
	cout << endl;
	cout << "16.Filtreaza dupa categoria X\n";
	cout << "17.Filtreaza dupa categoria X > decat suma Y\n";
	cout << "18.Filtreaza dupa categoria X < decat suma Y\n";
	cout << "19.Filtreaza dupa categoria X = cu suma Y\n";
	//cout << endl;
	//cout << "20. Anuleaza ultima actiune\n";//undo
}

//------------------------------------------------------------------------------
void UI::printList(const Controller *c)
{
	cout << "Day" << "\t |" << "Sum" << "\t |" << "Type" << endl;
	for(unsigned i=0;i<C->getSize();i++)
	{
		cout << this->C->getAll()[i] << endl;
	}
}

/*//------------------------------------------------------------------------------
void UI::loadData(char *c)
{
	fstream f;
	f.open(c);

	do
	{
		int day, sum;
		char t[100];
		f >> day;
		f >> sum;
		f >> t;
		Cheltuieli x = Cheltuieli(day, sum, t);
		this->C->add(x);

	} while (f.eof!=0);
	
	f.close();
}*/


//-----------------------------------------------------------------------------
void UI::run()
{
	/*char location[] = "date.in";
	loadData(location);*/

	char t0[10]="mancare";
	char t1[10] = "haine";
	char t2[10] = "curatenie";
	char t3[10] = "transport";
	char t4[10] = "party";

	Cheltuieli x = Cheltuieli(1, 25,t0);
	Cheltuieli x1 = Cheltuieli(1, 60, t2);
	Cheltuieli x2 = Cheltuieli(2, 80, t1);
	Cheltuieli x3 = Cheltuieli(3, 25, t2);
	Cheltuieli x4 = Cheltuieli(4, 36, t3);
	Cheltuieli x5 = Cheltuieli(10, 100, t4);
	Cheltuieli x6 = Cheltuieli(1, 30, t2);
	this->C->add(x);
	this->C->add(x1);
	this->C->add(x2);
	this->C->add(x3);
	this->C->add(x4);
	this->C->add(x5);
	this->C->add(x6);



	cout << "Cheltuieli de Familie" << endl;
	cout << endl;
	showMenu();
	cout << endl;

	cout << "Introduceti optiunea dorita:";
	int op;
	cin >> op;


	while(op>=1 && op<=20)
	{
		int sum, day,pos;
		char t[100];

		switch (op)
		{
		case(1)://adauga o cheltuiala la lista
		{
			printList(this->C);///list e goala
			cout << endl;

			cout << "Adauga o cheltuiala noua in lista" << endl;
			cout << "Introdu ziua:"; cin >> day;
			cout << "Introdu suma:"; cin >> sum;
			cout << "Introdu tipul:"; cin >> t;
			cout << endl;

			Cheltuieli c = Cheltuieli(day, sum, t);
			this->C->add(c);
			cout << "Ati adaugat o cheltuiala" << endl;

			printList(this->C);
			cout << endl;
			break;
		}
		case(2)://modifica o cheltuiala
		{
			cout << "Modifica o cheltuiala existenta" << endl;
			printList(this->C);

			cout << endl << "Introdu pozitia Cheltuielii pe care vrei sa o modifici:"; cin >> pos;
			cout << "Introdu noua Cheltuiala:" << endl;
			cout << "Introdu ziua:"; cin >> day;
			cout << "Introdu suma:"; cin >> sum;
			cout << "Introdu tipul:"; cin >> t;

			Cheltuieli c = Cheltuieli(day, sum, t);
			this->C->update(pos - 1, c);

			cout << "Cheltuiala de pe pozitia " << pos << " a fost modificata" << endl;
			printList(this->C);
			cout << endl;
			break;
		}
		case(3)://sterge o cheltuiala
		{
			cout << "Sterge o cheltuiala existenta" << endl;
			printList(this->C);

			cout << endl << "Introdu pozitia Cheltuielii pe care vrei sa o stergi:"; cin >> pos;
			this->C->deleteE(pos);

			cout << "Cheltuiala de pe pozitia " << pos << " a fost stearsa" << endl;
			printList(this->C);
			cout << endl;
			break;
		}
		case(4)://elimina cheltuielile din ziua X
		{
			printList(this->C);
			cout << endl << "Elimina cheltuielile din ziua X" << endl;
			cout << "Introdu ziua dorita:"; cin >> day;

			this->C->deleteByDay(day);
			cout << "Cheltuielile din ziua " << day << " au fost eliminate" << endl;
			printList(this->C);
			cout << endl;
			break;
		}
		case(5)://elimina Cheltuielile din data x pana in data y
			printList(this->C);

			cout << "Elimina Cheltuielile din data X pana in data Y" << endl;
			int startd, stopd;
			cout << "Introdu ziua de inceput:"; cin >> startd;
			cout << "Introdu ziua finala:"; cin >> stopd;

			this->C->deleteBetween(startd, stopd);
			printList(this->C);
			cout << endl;
			break;
		case(6)://elimina Cheltuielile din categoria X
		{
			printList(this->C);
			cout << "Elimina Cheltuielile din categoria X" << endl;
			char z[100];
			cout << "Introdu categoria dorita:"; cin >> z;

			this->C->deleteByType(z);

			cout << "Cheltuielile din categoria " << z << " au fost eliminate" << endl;
			printList(this->C);
			cout << endl;
			break;
		}
		case(7):
		{
			cout << "Lista curenta:" << endl;
			printList(this->C);
			break;
		}
		case(8):
		{
			cout << "Afiseaza toate cheltuielile din categoria X\n";
			printList(this->C);
			char z[100];
			cout << endl << "Introdu categoria dorita:"; cin >> z;

			vector<Cheltuieli>v;
			v = this->C->filterByType(z);

			cout << "Day" << "\t |" << "Sum" << "\t |" << "Type" << endl;
			for (unsigned i = 0; i < v.size(); i++)
			{
				cout << v[i] << endl;
			}

			break;
		}
		case(9):
		{
			cout << "Afiseaza cheltuielile din categoria X > decat suma Y" << endl;
			printList(this->C);
			char z[100];
			cout << endl << "Introdu categoria dorita:"; cin >> z;
			cout << "Introdu suma dorita:"; cin >> sum;

			vector<Cheltuieli>v;
			v = this->C->filterByTypeSumGreater(z, sum);

			cout << "Day" << "\t |" << "Sum" << "\t |" << "Type" << endl;
			for (unsigned i = 0; i < v.size(); i++)
			{
				cout << v[i] << endl;
			}

			break;
		}
		case(10):
		{
			cout << "Afiseaza cheltuielile din categoria X < decat suma Y" << endl;
			printList(this->C);
			char z[100];
			cout << endl << "Introdu categoria dorita:"; cin >> z;
			cout << "Introdu suma dorita:"; cin >> sum;

			vector<Cheltuieli>v;
			v = this->C->filterByTypeSumLower(z, sum);

			cout << "Day" << "\t |" << "Sum" << "\t |" << "Type" << endl;
			for (unsigned i = 0; i < v.size(); i++)
			{
				cout << v[i] << endl;
			}

			break;
		}
		case(11):
		{
			cout << "Afiseaza cheltuielile din categoria X = cu suma Y" << endl;
			printList(this->C);
			char z[100];
			cout << endl << "Introdu categoria dorita:"; cin >> z;
			cout << "Introdu suma dorita:"; cin >> sum;

			vector<Cheltuieli>v;
			v = this->C->filterByTypeSumEqual(z, sum);

			cout << "Day" << "\t |" << "Sum" << "\t |" << "Type" << endl;
			for (unsigned i = 0; i < v.size(); i++)
			{
				cout << v[i] << endl;
			}

			break;
		}
		case(12):
		{
			cout << "Suma tuturor cheltuielilor din categoria X" << endl;
			printList(this->C);
			char z[100];
			cout << endl << "Introdu categoria dorita:"; cin >> z;

			int r;
			r = this->C->sumByType(z);
			cout << "Suma tuturor cheltuielilor din categoria " << z << " este:" << r << endl;
			break;
		}
		case(13):
		{
			cout << "Afisarea zilei cu cele mai mari cheltuieli" << endl;
			//printList(this->C);
			int sMax, d;
			this->C->maxDay(sMax, d);
			cout << "Ziua cu cele mai mari cheltuielie este ziua " << d << " a lunii" << endl;
			cout << "In acesta zi a-ti cheltuit " << sMax << endl;
			break;
		}
		case(14):
		{
			cout << "Afisarea sumelor cheltuite zilnic in ordine descrescatoare\n";///sortByDay
			//vector<vector<Cheltuieli>> V;
			int Sum[33], Days[33];
			this->C->sortByDay( Sum, Days);
			cout << "Ziua" << "\t |" << "Suma" << endl;
			for (unsigned i = 1; i <= 31; i++)
			{
				if (Sum[i] != 0)
				{
					cout << Days[i] << "\t |" << Sum[i] << endl;
				}
			}
			break;
		}
		case(15):
		{
			cout << "Afisarea sumelor cheltuite zilnic pentru categoria X in ordine crescatoare\n";//sortByType
			printList(this->C); cout << endl;
			int Sum[33], Days[33];
			char z[30];
			cout << "Introdu categoria dorita:"; cin >> z;
			this->C->sortByType(z, Sum, Days);
			cout << "Ziua" << "\t |" << "Suma" << endl;
			for (unsigned i = 1; i <= 31; i++)
			{
				if (Sum[i] != 0)
				{
					cout << Days[i] << "\t |" << Sum[i] << endl;
				}
			}
			break;
		}
		case(16):
		{	cout << "Filtreaza dupa categoria X\n";
			printList(this->C);
			char z[100];
			cout << endl << "Introdu categoria dorita:"; cin >> z;

			vector<Cheltuieli>v;
			v = this->C->filterByType(z);

			cout << "Day" << "\t |" << "Sum" << "\t |" << "Type" << endl;
			for (unsigned i = 0; i < v.size(); i++)
			{
				cout << v[i] << endl;
			}

			break;
		}
		case(17):
		{
			cout << "Filtreaza dupa categoria X > decat suma Y\n";
			printList(this->C);
			char z[100];
			cout << endl << "Introdu categoria dorita:"; cin >> z;
			cout << "Introdu suma dorita:"; cin >> sum;

			vector<Cheltuieli>v;
			v = this->C->filterByTypeSumGreater(z, sum);

			cout << "Day" << "\t |" << "Sum" << "\t |" << "Type" << endl;
			for (unsigned i = 0; i < v.size(); i++)
			{
				cout << v[i] << endl;
			}

			break;
		}
		case(18):
		{
			cout << "Filtreaza dupa categoria X < decat suma Y\n";
			printList(this->C);
			char z[100];
			cout << endl << "Introdu categoria dorita:"; cin >> z;
			cout << "Introdu suma dorita:"; cin >> sum;

			vector<Cheltuieli>v;
			v = this->C->filterByTypeSumLower(z, sum);

			cout << "Day" << "\t |" << "Sum" << "\t |" << "Type" << endl;
			for (unsigned i = 0; i < v.size(); i++)
			{
				cout << v[i] << endl;
			}

			break;
		}
		case(19):
		{
			cout << "Filtreaza dupa categoria X = cu suma Y\n";
			printList(this->C);
			char z[100];
			cout << endl << "Introdu categoria dorita:"; cin >> z;
			cout << "Introdu suma dorita:"; cin >> sum;

			vector<Cheltuieli>v;
			v = this->C->filterByTypeSumEqual(z, sum);

			cout << "Day" << "\t |" << "Sum" << "\t |" << "Type" << endl;
			for (unsigned i = 0; i < v.size(); i++)
			{
				cout << v[i] << endl;
			}

			break;
		}
		}
		cout << "Introduceti optiunea dorita:";
		cin >> op;
	}
	cout << "Bye bye!" << endl;
	return;
}


