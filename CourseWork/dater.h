class Dater
{
public:
	static std::string today();
	static void display_today();

};

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