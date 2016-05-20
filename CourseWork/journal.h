class Journal
{
	static std::string currentGroup;
public:
	static void set_group();
	static std::string get_group();
	static void set_group(std::string group);
	static void create_group();
	static void list_groups();
};

std::string Journal::get_group()
{
	if(currentGroup != "0")
	{
		return currentGroup;
	}
	else
	{
		return "0";
	}
}
void Journal::set_group()
{
	std::string group;
	std::cout << "Enter group name:";
	std::cin >> group;
	if(!FileExists(get_path(path::GROUPS)+group))
	{
		vslog::error(text::GROUP_NOT_FOUND);
	}
	else
	{
		currentGroup = group;
	}
}
void Journal::set_group(std::string group)
{
	if(!FileExists(get_path(path::GROUPS)+group))
	{
		vslog::error(text::GROUP_NOT_FOUND);
	}
	else
	{
		currentGroup = group;
	}
}
void Journal::create_group()
{
	//if (CreateDirectory("c:\\new",NULL))
	std::string group;
	std::cout << "Enter group name:";
	std::cin >> group;	
	group = get_path(path::GROUPS) + group;
	std::wstring stemp = std::wstring(group.begin(), group.end());
    LPCWSTR sw = stemp.c_str();
	if (CreateDirectory(sw,NULL))
	{
		vslog::message(text::GROUP_CREATED_SUCCESS);
		std::ofstream ofs(group+"/students");
        ofs.close();
	}
	else
	{
		vslog::error(text::GROUP_CANT_CREATE);
	}
}
void Journal::list_groups()
{
	list(get_path(path::GROUPS)+"*", 1);
}

std::string Journal::currentGroup = "0";