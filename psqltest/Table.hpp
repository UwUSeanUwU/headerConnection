#pragma once

#include <string>
#include <pqxx/pqxx>

class Table
{
	private:
		std::string connectionString;
		std::string table_name;

	public:
		Table(std::string host, long port, std::string dbname, std::string user, std::string password, std::string table_name);
		std::string getConnectionString();
		std::string getTableName();
		~Table();
};

