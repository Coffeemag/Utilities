#pragma once
#include <string>

class Room;

class Tenant
{
private:
	std::string _name{"Owner"};
public:
	Tenant (){}
	Tenant(std::string name) : _name(name){}
	std::string getName() { return _name; }
};

