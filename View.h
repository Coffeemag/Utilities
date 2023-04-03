#pragma once
#include <string>
#include <iostream>

class Repository;

class View
{
private:
	Repository* _repo = nullptr;
public:
	View(){}
	void prompt(std::string str);
	
	std::string getString() const;

	int getInt() const;
	
	double getDouble() const;
	
	~View(){}
};

