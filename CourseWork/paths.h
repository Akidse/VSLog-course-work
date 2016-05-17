enum path
{
	USERS,
	GROUPS
};


std::string get_path(path p)
{
	std::string path;
	switch(p)
	{
	case  USERS:
		path = "data/users/";
		break;
	case  GROUPS:
		path = "data/groups/";
		break;
	}
	return path;
}