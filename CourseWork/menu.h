class menu
{
public:
	static void initialize();
	static std::string get_userline();
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

std::string menu::get_userline()
{
	std::string userline = "vslog@";
	userline = userline + vslog::username;
	if(Journal::get_group() != "0")userline = userline + "~" + Journal::get_group();
	std::cout << userline << ": ";
	return userline;
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
	else if(menu::current_query == "-today")
	{
		Dater::display_today();
	}
	else if(menu::current_query == "-groupslist")
	{
		Journal::list_groups();
	}
	else if(menu::current_query == "-studentslist")
	{
		Journal::list_students();
	}
	else if(menu::current_query == "-addgroup")
	{
		Journal::create_group();
	}
	else if(menu::current_query == "-setgroup")
	{
		Journal::set_group();
	}
	else if(menu::current_query == "-addstudent")
	{
		Journal::add_student();
	}
	else if(menu::current_query == "-writedown")
	{
		Journal::write_down();
	}
	else if(menu::current_query == "-display")
	{
		Journal::set_date();
	}
	else if(menu::current_query == "-debug")
	{
		Journal::set_group("lool");
		Journal::display(2016,5);
	}
	else
	{
		vslog::error(text::WRONG_COMMAND);
	}
}

std::string menu::current_query = "";