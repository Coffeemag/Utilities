#include <iostream>
#include <string>
#include "Repository.h"
#include "RepositoryTenant.h"
#include "RepositoryCounters.h"
#include "RepositoryRooms.h"
#include "ControllerTenant.h"

int main()
{
    std::cout << "Hello World!\n";
    Repository::connectDB();
    ControllerTenant * contr = new ControllerTenant;
    contr->interact();
    
    Repository::disconnectDB();
    delete contr;
}

