class Journal
{
	static std::string currentGroup;
public:
	static void set_group();
	static std::string get_group();
	static void set_group(std::string group);
	static void create_group();
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
	
}

std::string Journal::currentGroup = "0";