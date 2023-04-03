#pragma once
#include "RepositoryTenant.h"
#include "ViewTenant.h"

class ControllerTenant
{
private:
	RepositoryTenant * repo = nullptr;
	ViewTenant * viewt = nullptr;

public:
	ControllerTenant(){}
	void interact();
	~ControllerTenant(){}
};

