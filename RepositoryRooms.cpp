#include "RepositoryRooms.h"

RepositoryRooms::RepositoryRooms()
{
		sqlite3_stmt* stmt = nullptr;
		std::string str = "CREATE TABLE IF NOT EXISTS rooms ("
			"id INTEGER PRIMARY KEY, "
			"name TEXT NOT NULL,"
			"square REAL NOT NULL, tenantId INTEGER,"
			" FOREIGN KEY (tenantId) REFERENCES tenants (id) ON DELETE RESTRICT DEFERRABLE INITIALLY DEFERRED)";
		const char* pzTail{};
		sqlite3_prepare_v2(_db, str.c_str(), -1, &stmt, &pzTail);
		auto rs = sqlite3_step(stmt);
		if (rs != SQLITE_DONE) { std::cout << "Rooms Table : There is an Error"; }
		else std::cout << "Table Rooms is OK\n";
		sqlite3_finalize(stmt);
}
