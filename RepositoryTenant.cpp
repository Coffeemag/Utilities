#include "RepositoryTenant.h"
#include "Repository.h"

RepositoryTenant::RepositoryTenant()
{
		sqlite3_stmt* stmt = nullptr;
		std::string str = "CREATE TABLE IF NOT EXISTS tenants (id INTEGER PRIMARY KEY, name TEXT NOT NULL)";
		const char* pzTail{};
		auto res = sqlite3_prepare_v2(_db, str.c_str(), -1, &stmt, &pzTail);
		if (res != SQLITE_OK) std::cout << "Error in PREPARE\t" << res << "\n";
		auto rs = sqlite3_step(stmt);
		if (rs != SQLITE_DONE) { std::cout << "Tenants Table : There is an Error" << rs; }
		else std::cout << "Table Tenant is OK\n";
		sqlite3_finalize(stmt);
}

void RepositoryTenant::storeItem(Tenant tn)
{
		sqlite3_stmt* stmt = nullptr;
		std::string nam = tn.getName();
		const char* name = nam.c_str();
		std::string str = "INSERT INTO tenants (name) VALUES (?1)";
		sqlite3_prepare_v2(_db, str.c_str(), -1, &stmt, NULL);
		sqlite3_bind_text(stmt, 1, name, -1, SQLITE_TRANSIENT);
		auto rs = sqlite3_step(stmt);
		if (rs != SQLITE_DONE) std::cout << "Error Store Item\t" << rs;
		else { std::cout << "Item has stored\n"; }
		sqlite3_finalize(stmt);
}

void RepositoryTenant::showItems() const
{
		sqlite3_stmt* stmt = nullptr;
		std::string str = "SELECT * FROM tenants";
		auto res = sqlite3_prepare_v2(_db, str.c_str(), -1, &stmt, 0);
		res = sqlite3_step(stmt);
		if (res == SQLITE_DONE) 
		{
			std::cout << "Table tenants is OK, but Empty yet\n";
			return;
		}
		else if (res != SQLITE_ROW) 
		{ 
			std::cout << "Error in Tenant"<< res;
			sqlite3_finalize(stmt);
			return;
		}
		do 
		{
			std::printf("%5i %20s \n", sqlite3_column_int(stmt, 0), sqlite3_column_text(stmt, 1));
		}
		while (sqlite3_step(stmt) == SQLITE_ROW);

		 
		sqlite3_finalize(stmt);
}

void RepositoryTenant::deleteItem(int idd)
{
		sqlite3_stmt* stmt = nullptr;
		std::string str = "DELETE FROM tenants WHERE id = ?";
		sqlite3_prepare_v2(_db, str.c_str(), -1, &stmt, 0);
		sqlite3_bind_int(stmt, 1, idd);
		auto rs = sqlite3_step(stmt);
		if (rs != SQLITE_DONE) std::cout << "There is an Error\t" << rs<<"\n";
		else std::cout << "Item has deleted\n";
		sqlite3_finalize(stmt);
}
