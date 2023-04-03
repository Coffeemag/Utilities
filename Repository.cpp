#include "Repository.h"

sqlite3* Repository::_db = nullptr;

void Repository::connectDB()
{
		sqlite3_initialize();
		auto rs1 = sqlite3_open_v2("utilities.db", &_db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);
		if (rs1 != SQLITE_OK) std::cout << "ERROR OF OPEN DB" << rs1 << "\n";
		else std::cout << "Data Base is OK\n";
}

void Repository::disconnectDB()
{
		sqlite3_close_v2(_db);
		sqlite3_shutdown();
}
