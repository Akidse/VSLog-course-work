class Dater
{
	static int currentDate, currentYear, currentDay;
public:
	static std::string today();
	static void display_today();
	static int set_date(std::string date);
	static int days_in_month(int m, int y);
	static int count_days(int year, int month, int day);
};
int Dater::days_in_month(int m, int y)
	{
		int leap = (1 - (y % 4 + 2) % (y % 4 + 1)) * ((y % 100 + 2) % (y % 100 + 1)) + (1 - (y % 400 + 2) % (y % 400 + 1));
		return 28 + ((m + (m / 8)) % 2) + 2 % m + ((1 + leap) / m) + (1/m) - (leap/m);
	}
std::string Dater::today()
{
	std::string date, year, month, day;
	time_t t;
	tm *tk;
	
	time(&t);
	tk=localtime(&t);
	year = std::to_string(1900+tk->tm_year);
	month = std::to_string(1+tk->tm_mon);
	day = std::to_string(tk->tm_mday);
	date = year +"."+ month +"."+ day;
	return date;
}
void Dater::display_today()
{
	std::cout << Dater::today() << std::endl;
}
int Dater::count_days(int year, int month, int day)
{
   int count = 0;
   for(int i = 1; i < month; i++)
   {
	   count+= days_in_month(i, year);
   }
   count+=day;
   return count;
}
int Dater::set_date(std::string date)
{
	float value = 0;
	std::string year = "0", month = "0", day = "0";
	int k = 0, i_year = 0, i_month = 0;
	for(int i = 0; i < date.length(); i++)
	{
		if(date[i] == '.')
		{
			if(k == 0)
			{
				i_year = i;
				cut_str(date, year, 0, i_year-1);
				k++;
			}
			else if(k == 1)
			{
				i_month = i;
				cut_str(date, month, i_year+1, i_month-1);
				cut_str(date, day, i_month+1, date.length());
				k++;
			}
		}
	}
	if(std::stoi(year) <= 0 || std::stoi(month) <= 0 || std::stoi(day) <= 0)return 0;
	if(std::stoi(year) < 1970 || std::stoi(month) > 12  || std::stoi(day) > 31)return 0;
	currentYear = std::stoi(year);
	currentDay = count_days(std::stoi(year), std::stoi(month), std::stoi(day)); 
	value = currentYear*1000 + currentDay;
	currentDate = value;
	return value;
}

int Dater::currentDate = 0, Dater::currentYear = 0, Dater::currentDay = 0;