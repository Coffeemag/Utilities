#include "ViewTenant.h"

Tenant const ViewTenant::getTenant()
{
		prompt("Enter Tenant's Name");
		auto name = getString();
		Tenant tnt( name );
		return tnt;
}
