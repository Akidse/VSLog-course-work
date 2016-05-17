class menu
{
public:
	static void initialize();
	static char get_userline();
	static void parse_query();
	static std::string current_query;
};

void menu::initialize()
{
	while(true)
	{
      menu::get_userline();
	  //getline(std::cin, menu::current_query);
	  std::cin >> menu::current_query;
	  std::cin.get();
	  menu::parse_query();
	}
}

char menu::get_userline()
{
	char userline[86] = "vslog@";
	strcat(userline, vslog::username);
	std::cout << userline << ": ";
	return *userline;
}
void menu::parse_query()
{
	if(menu::current_query == "-help")
	{
		vslog::message(text::HELP);
	}
	else if(menu::current_query == "-clear")
	{
		vslog::clear_window();
	}
	else if(menu::current_query == "-adduser")
	{
		if(vslog::access())vslog::user("add");
	}
	else if(menu::current_query == "-pass")
	{
		vslog::user("pass");
	}
	else if(menu::current_query == "-users")
	{
		vslog::users_list();
	}
	else if(menu::current_query == "-userdel")
	{
		if(vslog::access())vslog::delete_user();
	}
	else
	{
		vslog::error(text::WRONG_COMMAND);
	}
}

std::string menu::current_query = "";