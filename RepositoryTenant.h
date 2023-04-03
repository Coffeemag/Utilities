#pragma once
#include <string>
#include <iostream>
#include "sqlite/sqlite3.h"
#include "Tenant.h"
#include "Repository.h"

class RepositoryTenant : public Repository
{
private:
	Tenant _tenant;
public:
	RepositoryTenant();

	void storeItem(Tenant tn);
	
	void showItems() const;

	void deleteItem(int id);
	
};

