#pragma once
#include <string>
#include <iostream>
#include "sqlite/sqlite3.h"
#include "Repository.h"

class RepositoryRooms : public Repository
{
private:

public:
	RepositoryRooms();
	
	~RepositoryRooms(){}
};

