﻿struct student_visit
{
	int date;
	int mark;
};
class Journal
{
	static std::string currentGroup;
public:
	static student_visit* visits;
	static int number_visits;
	static void set_group();
	static std::string get_group();
	static void set_group(std::string group);
	static void create_group();
	static void list_groups();
	static void list_students();
	static void add_student();
	static void display(int year, int month);
	static int found_student_line();
	static void write_down();
	static bool set_data(int num, int year, int month);
	static std::string get_mark(int num, int date);
	static void set_date();
	static void set_export_date();
	static void export_file(int year, int month);
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
	std::cout << vslog::echo(text::ENTER_GROUP_NAME);
	getline(std::cin, group);
	//std::cin >> group;
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
	std::cout << vslog::echo(text::ENTER_GROUP_NAME);
	getline(std::cin, group);
	//std::cin >> group;	
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
void Journal::add_student()
{
	if(get_group() == "0")
	{
		vslog::error(text::GROUP_NOT_CHOSEN);
		return;
	}
	std::string name;
	std::cout << vslog::echo(text::ENTER_STUDENT_NAME);
	int num = count_line_file(get_path(path::GROUPS)+currentGroup+"/students");
	getline(std::cin,name);
	std::ofstream fout(get_path(path::GROUPS)+currentGroup+"/students",std::ios_base::app);
	fout << name << "\n";
	fout.close();
}
void Journal::list_students()
{
	if(get_group() == "0")
	{
		vslog::error(text::GROUP_NOT_CHOSEN);
		return;
	}
	std::string line;
	std::ifstream myfile(get_path(path::GROUPS)+currentGroup+"/students");
	int lines = 0;
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			
			getline (myfile,line);
			if(line.length() != 0)
			{
			lines++;
			std::cout << lines << ") " << line << std::endl;
			}
		}
		if(lines == 0)vslog::error(text::STUDENTS_EMPTY);
		myfile.close();
	}
	else vslog::error(text::STUDENTS_FILE_NOT_FOUND);
}

void Journal::display(int year, int month)
{
	if(get_group() == "0")
	{
		vslog::error(text::GROUP_NOT_CHOSEN);
		return;
	}
	std::cout << vslog::echo(text::JOURNAL_NAMES) << std::setw(12) << "|";
	for(int i = 1; i < 10; i++)std::cout << std::setw(1) << i << "|";
	for(int i = 10; i <= Dater::days_in_month(year, month); i++)std::cout << std::setw(2) << i << "|";
	std::cout << std::endl;
	int count_students = count_line_file(get_path(path::GROUPS)+currentGroup+"/students");
	std::string studentname;
	std::ifstream myfile(get_path(path::GROUPS)+currentGroup+"/students");
	int count = 0, tab = 2;
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			count++;
			if(count > 9)tab = 3;
			getline (myfile,studentname);
			if(studentname.length() != 0)
			{
			std::cout <<count << " " << studentname << std::setw(20-studentname.length() - tab) << "|";
			set_data(count, year, month);
			for(int i = 1; i < 10; i++)
			{
				std::cout << std::setw(1) << get_mark(count, Dater::set_date(std::to_string(year)+"."+std::to_string(month)+"."+std::to_string(i))) << "|";
			}
			for(int i = 10; i <= Dater::days_in_month(year, month); i++)
		    {
					std::cout << std::setw(2) << get_mark(count, Dater::set_date(std::to_string(year)+"."+std::to_string(month)+"."+std::to_string(i))) << "|";
			}
			std::cout << std::endl;
			//delete visits;
			}
		}
		myfile.close();
	}

}
void Journal::export_file(int year, int month)
{
	if(get_group() == "0")
	{
		vslog::error(text::GROUP_NOT_CHOSEN);
		return;
	}
	std::ofstream html("vslog.html",std::ios_base::trunc);
	html << "<html><head><meta charset='windows-1251'><link rel='stylesheet' type='text/css' href='./html/style.css'><title>VSLOG</title></head><body>";
	html << "<div class='title'>" << currentGroup << " - " << year <<"."<< month <<"</div><table><tr>";
	html << "<th>" << vslog::echo(text::JOURNAL_NAMES) << "</th>";
	for(int i = 1; i <= Dater::days_in_month(year, month); i++)html << "<th>" << i << "</th>";
	html << "</tr><tr>";
	int count_students = count_line_file(get_path(path::GROUPS)+currentGroup+"/students");
	std::string studentname;
	std::ifstream myfile(get_path(path::GROUPS)+currentGroup+"/students");
	
	int count = 0, tab = 2;
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			count++;
			if(count > 9)tab = 3;
			getline (myfile,studentname);
			if(studentname.length() != 0)
			{
			html <<"<td>" << count << " " << studentname << "</td>";
			set_data(count, year, month);
			for(int i = 1; i < 10; i++)
			{
				html << "<td>" << get_mark(count, Dater::set_date(std::to_string(year)+"."+std::to_string(month)+"."+std::to_string(i))) << "</td>";
			}
			for(int i = 10; i <= Dater::days_in_month(year, month); i++)
		    {
					html << "<td>" << get_mark(count, Dater::set_date(std::to_string(year)+"."+std::to_string(month)+"."+std::to_string(i))) << "</td>";
			}
			html << "</tr>";
			}
		}
		myfile.close();
		
	}
	html << "</table></body></html>";
	html.close();
	ShellExecute( NULL,L"open",L"vslog.html",NULL,NULL,SW_SHOW);
}
std::string Journal::get_mark(int num, int date)
{
		for(int i = 0; i < number_visits; i++)
		{
			if(visits[i].date == date)
			{
				if(visits[i].mark == 0)
				{
					return "н";
				}
				else
				{
					return std::to_string(visits[i].mark);
				}
			}
		}
		return " ";
}
bool Journal::set_data(int num, int year, int month)
{
	int from = Dater::set_date(std::to_string(year)+"."+std::to_string(month)+".1");
	int till = Dater::set_date(std::to_string(year)+"."+std::to_string(month)+"."+std::to_string(Dater::days_in_month(year, month)));
	int k = 0, i_year = 0, i_month = 0;
	std::string line, temp_id = "", temp_date = "", temp_mark = "";
	visits = new student_visit[0];
	std::ifstream myfile(get_path(path::GROUPS)+currentGroup+"/"+std::to_string(year));
	int i = 0, j = 0;
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			getline(myfile,line);
			for(int k = 0; k < line.length(); k++)
			{
				if(line[k] == ' ')
				{
					if(j == 0)
					{
						i_year = k;
						cut_str(line, temp_id, 0, k);
						j++;
					}
					else if(j == 1)
					{
						i_month = k;
						cut_str(line, temp_date, i_year+1, i_month-1);
						j++;
					}
				}
			}
			if(j == 2 && temp_id != "" && temp_date != "")
			{
				if(std::stoi(temp_id) == num && std::stoi(temp_date) >= from && std::stoi(temp_date) <= till)i++;

			}
			temp_id = "", temp_date = "";
			j = 0;
		}
		myfile.close();
	}
	if(i > 0)
	{

		visits = new student_visit[i];
		std::ifstream myfile(get_path(path::GROUPS)+currentGroup+"/"+std::to_string(year));
		int s = 0;
		j = 0;
		bool allow = false;
		temp_mark = "";
		if (myfile.is_open())
		{
			while (!myfile.eof())
			{
				getline(myfile,line);
				for(int k = 0; k < line.length(); k++)
				{
					if(line[k] == ' ')
					{
						if(j == 0)
						{
							i_year = k;
							cut_str(line, temp_id, 0, k);
							j++;
						}
						else if(j == 1)
						{
							i_month = k;
							cut_str(line, temp_date, i_year+1, i_month-1);
							cut_str(line, temp_mark, i_month, line.length());
							j++;
						}
					}
				}
				if(j == 2 && temp_id != "" && temp_date != "" && temp_mark != "")
				{
					if(std::stoi(temp_id) == num && std::stoi(temp_date) >= from && std::stoi(temp_date) <= till)
					{
						visits[s].date = std::stoi(temp_date);
						visits[s].mark = std::stoi(temp_mark);
						s++;
					}
				}
				temp_id = "", temp_date = "", temp_mark = "";
				j = 0;
			}
			myfile.close();
		}
		number_visits = s;
		return true;
	}
	else
	{
		return false;
	}
}
void Journal::set_export_date()
{
    if(get_group() == "0")
	{
		vslog::error(text::GROUP_NOT_CHOSEN);
		return;
	}
	std::string year_str, month_str;
	int year, month;
	std::cout << vslog::echo(text::ENTER_YEAR);
	getline(std::cin, year_str);
	year = stoi(year_str);
	//std::cin >> year;
	if(year < 1970 || year > 2100)
	{
		vslog::error(text::BAD_YEAR);
			return;
	}
	std::cout << vslog::echo(text::ENTER_MONTH);
	getline(std::cin, month_str);
	month = stoi(month_str);
	//std::cin >> month;	
	if(month < 1 || month > 12)
	{
		vslog::error(text::BAD_MONTH);
		return;
	}
	export_file(year, month);
}
void Journal::set_date()
{
    if(get_group() == "0")
	{
		vslog::error(text::GROUP_NOT_CHOSEN);
		return;
	}
	std::string year_str, month_str;
	int year, month;
	std::cout << vslog::echo(text::ENTER_YEAR);
	getline(std::cin, year_str);
	year = stoi(year_str);
	//std::cin >> year;
	if(year < 1970 || year > 2100)
	{
		vslog::error(text::BAD_YEAR);
			return;
	}
	std::cout << vslog::echo(text::ENTER_MONTH);
	getline(std::cin, month_str);
	month = stoi(month_str);
	//std::cin >> month;	
	if(month < 1 || month > 12)
	{
		vslog::error(text::BAD_MONTH);
		return;
	}
	display(year, month);
}
int Journal::found_student_line()
{
	std::string name;
	std::cout << vslog::echo(text::ENTER_STUDENT_NAME);
	getline(std::cin, name);
	std::string line;
	std::ifstream myfile(get_path(path::GROUPS)+currentGroup+"/students");
	int i = 0;
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			i++;
			getline(myfile,line);
			if(name == line)return i;
		}
		myfile.close();
	}

	return 0;
}

void Journal::write_down()
{
    if(get_group() == "0")
	{
		vslog::error(text::GROUP_NOT_CHOSEN);
		return;
	}
	std::string date, mark_str;
	int mark, cur_date, student_num;
	std::cout << vslog::echo(text::WRITE_DOWN) << std::endl;
	student_num = found_student_line();
	if(student_num == 0)
	{
		    vslog::error(text::STUDENT_NOT_FOUND);
			return;
	}
	std::cout << vslog::echo(text::ENTER_DATE);
	getline(std::cin, date);
	//std::cin >> date;
	cur_date = Dater::set_date(date);
	if(cur_date == 0)
	{
		vslog::error(text::BAD_DATE);
		return;
	}
	std::cout << vslog::echo(text::ENTER_MARK);
	getline(std::cin, mark_str);
	//std::cin >> mark;
	mark = stoi(mark_str);
	if(mark > 5 || mark < 0)
	{
	    vslog::error(text::BAD_MARK);
		return;
	}
	std::ofstream fout(get_path(path::GROUPS)+currentGroup+"/"+std::to_string(Dater::currentYear),std::ios_base::app);
	fout << std::to_string(student_num)+" "+std::to_string(cur_date)+" "+std::to_string(mark)+"\n";
	fout.close();
}

student_visit* Journal::visits = new student_visit[0];
std::string Journal::currentGroup = "0";
int Journal::number_visits = 0;