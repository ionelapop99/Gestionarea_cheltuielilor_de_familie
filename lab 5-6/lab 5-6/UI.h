#include "pch.h"
#include "Controller.h"
#include<fstream>

#ifndef UI_H
#define UI_H
class UI
{
private:
	Controller* C;
public:
	UI();
	UI(Controller* crt);
	~UI();

	///menu
	void showMenu();

	///Main Aplication
	void run();

	///Print functions
	void printList(const Controller*);

	///
	///void loadData(char *c);
};
#endif