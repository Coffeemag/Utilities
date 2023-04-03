#include "View.h"

void View::prompt(std::string str)
{
		std::cout << str << "\n";
}

std::string View::getString() const
{
	std::string str;
	std::cin.ignore();
	std::getline(std::cin, str);
	return str;
}

int View::getInt() const
{
	int in;
	std::cin >> in;
	return in;
}

double View::getDouble() const
{
	double num;
	std::cin >> num;
	return num;
}
