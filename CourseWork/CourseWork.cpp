// CourseWork.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <windows.h>
#include <io.h>
#include <iomanip> 
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
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, 50, r.top, 1750, 700, TRUE);
    //system("mode con cols=210");
	setlocale(LC_ALL, "Ukrainian");
	while(vslog::isLogged() == 0)
	{
		cout << vslog::echo(text::ENTER_NAME);
		cin >> vslog::username;
		cout << vslog::echo(text::ENTER_PASSWORD);
		vslog::get_password(*vslog::password);
		vslog::verify();
	}
	vslog::clear_window();
	vslog::message(text::START_PAGE);
	menu::initialize();
	system("pause");
	return 0;
}

