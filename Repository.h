#pragma once
#include <iostream>
#include "sqlite/sqlite3.h"

class Repository
{
protected:
	static sqlite3* _db;
public:
	static void connectDB();
	static void disconnectDB();
	void showItems(){}
};
