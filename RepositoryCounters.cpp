#include "RepositoryCounters.h"

RepositoryCounters::RepositoryCounters()
{
		sqlite3_stmt* stmt = nullptr;
		std::string str = "CREATE TABLE IF NOT EXISTS counters ("
			" id INTEGER PRIMARY KEY, "
			" name TEXT,"
			" value REAL NOT NULL,"
			" water INTEGER DEFAULT 0, room_Id INTEGER,"
			" FOREIGN KEY (room_Id) REFERENCES rooms (id) ON DELETE RESTRICT DEFERRABLE INITIALLY DEFERRED)";
		const char* pzTail{};
		sqlite3_prepare_v2(_db, str.c_str(), -1, &stmt, &pzTail);
		auto rs = sqlite3_step(stmt);
		if (rs != SQLITE_DONE) { std::cout << "Counter Tabel : There is an Error" << rs; }
		else { std::cout << "Table Counters is OK\n"; }
		sqlite3_finalize(stmt);
}
