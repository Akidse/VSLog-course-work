class vslog
{
	static int status_log;
	static bool superuser;
	static char* superuser_name;
public:
	static char username[64];
	static char password[64];
	static int isLogged();
	static void setLogged(int status);
	static void verify();
	static void message(text message);
	static void error(text error);
	static void get_password(char &var);
	static void clear_window();
	static void user(char* action);
	static bool str_compare(const char pass1, const char pass2);
	static void users_list();
	static void delete_user();
	static bool access();
	static std::string echo(text text);
};

int vslog::isLogged()
{
	return status_log;
}

void vslog::setLogged(int status)
{
	if(str_compare(*vslog::username,*superuser_name))vslog::superuser = TRUE; else vslog::superuser = FALSE;
	status_log = status;
}

void vslog::verify()
{
	std::string path;
	char filepass[64];
	path = get_path(path::USERS) + username;
	std::ifstream fpass;
	fpass.open(path);
	setLogged(0);
	if(fpass)
	{
		fpass >> filepass;
		if(strcmp(password, filepass) == 0)
		{
			setLogged(1);
		}
		else
		{
			error(text::LOGIN_FAIL);
		}
	}
	else
	{
		error(text::LOGIN_FAIL);
	}
	fpass.close();
}
std::string vslog::echo(text text)
{
	return get_message(text);
}
void vslog::message(text message)
{
	HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hwnd, FOREGROUND_GREEN);
	std::cout << get_message(message) << std::endl;
	SetConsoleTextAttribute(hwnd, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
void vslog::error(text error)
{
	HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hwnd, FOREGROUND_INTENSITY | FOREGROUND_RED);
	std::cout << get_message(error) << std::endl;
	SetConsoleTextAttribute(hwnd, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void vslog::get_password(char &var)
{
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE); 
	DWORD mode = 0;
	GetConsoleMode(hStdin, &mode);
	SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
	std::cin >> &var;
	std::cout << std::endl;
	SetConsoleMode(hStdin, mode);
}
void vslog::clear_window()
{
	system("cls");
}

void vslog::user(char* action)
{
	std::string path, nick;
	char pass1[64],pass2[64];
	if(action == "add")
	{
		std::cout << vslog::echo(text::ENTER_NAME);
		std::cin >> nick;
		path = get_path(path::USERS) + nick;
		if(FileExists(path))
		{
			vslog::error(text::ADD_USER_EXISTED);
			return;
		}
	}
	else
	{
		path = get_path(path::USERS) + nick;
	}
	

	do
	{
		std::cout << vslog::echo(text::ENTER_PASSWORD);
		get_password(*pass1);
		std::cout << vslog::echo(text::ENTER_PASSWORD_AGAIN);
		get_password(*pass2);
		if(str_compare(*pass1,*pass2) == false)vslog::error(text::ADD_USER_ERR_PASS);
	}
	while(str_compare(*pass1,*pass2) == false);

	std::ofstream fout(path, std::ios_base::trunc);
	if(fout.is_open())
	{
		fout << pass1;
		if(action == "add") vslog::message(text::ADD_USER_SUCCESS);
		if(action == "pass") vslog::message(text::CHANGE_PASS_SUCCESS);
	}
	else
	{
		vslog::error(text::ADD_USER_FAIL);
	}
	fout.close();
}

bool vslog::str_compare(const char pass1, const char pass2)
{
	if(strcmp(&pass1, &pass2) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void vslog::users_list()
{
	WIN32_FIND_DATAW wfd;
    HANDLE const hFind = FindFirstFileW(L"data/users/*", &wfd);
    if (INVALID_HANDLE_VALUE != hFind)
    {
      do
      {
        if(!(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))std::wcout  << &wfd.cFileName[0]  << std::endl;
      } while (NULL != FindNextFileW(hFind, &wfd));
 
      FindClose(hFind);
    }
}

void vslog::delete_user()
{
	std::string path,nick;
	std::cout << vslog::echo(text::ENTER_NAME);
	std::cin >> nick;
	path = get_path(path::USERS) + nick;
	if(!FileExists(path))
	{
		vslog::error(text::USER_NOT_EXIST);
		return;
	}
	if(str_compare(*username, *nick.c_str()))
	{
		vslog::error(text::USER_CANT_DELETE_HIMSELF);
		return;
	}
	if (remove(path.c_str())==-1)
	{
		vslog::message(text::USER_DELETE_FAIL);
	}
    else
	{
        vslog::message(text::USER_DELETE_SUCCESS);
	}
}

bool vslog::access()
{
	if(superuser == TRUE)
	{
		return TRUE;
	}
	else
	{
		vslog::message(text::NOT_ALLOWED);
		return FALSE;
	}
}

int vslog::status_log = 0;
char vslog::username[64] = "";
char vslog::password[64] = "";
bool vslog::superuser = false;
char* vslog::superuser_name = "root";