#include "ControllerTenant.h"

void ControllerTenant::interact()
{
	int cl = 1;
	while (cl == 1){
		repo->showItems();
		viewt->prompt("Choose the action: 1 - Add New Tenant 2 - Delete Tenant 3 - Change Data 4 - Exit. Enter Number\n");
		switch(auto ch = viewt->getInt(); ch)
		{
		case 1: 
		{
			viewt->prompt("Let us Add new Tenants in List\n");
			viewt->prompt("Write down Name of New Tenant\n");
			repo->storeItem(viewt->getTenant());
		}; break;
		case 2: 
		{
			viewt->prompt("Enter id item to delete\n");
			repo->deleteItem(viewt->getInt());
		}; break;
		case 3: {viewt->prompt("Do you want to Change Neme of Tenant?");
			viewt->prompt("Enter id this Item");
			auto ids = viewt->getInt();
			repo->updateItem(ids, viewt->getTenant());
		}; break;
		
		case 4:cl = 0; break;
		
		default: std::cout << "You have entered incorrect number";
		}
	}
}
