// CourseWork.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <time.h>
#include <windows.h>
#include <io.h>
#include "functions.h"
#include "paths.h"
#include "messages.h"
#include "vslog.h"
#include "dater.h"
#include "journal.h"
#include "menu.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	while(vslog::isLogged() == 0)
	{
		cout << "Enter username: ";
		cin >> vslog::username;
		cout << "Enter password: ";
		vslog::get_password(*vslog::password);
		vslog::verify();
	}
	vslog::clear_window();
	vslog::message(text::START_PAGE);
	menu::initialize();
	system("pause");
	return 0;
}

