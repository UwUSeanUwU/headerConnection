#include "Table.hpp"

Table::Table(std::string host, long port, std::string dbname, std::string user, std::string password, std::string table_name) {
	connectionString = "host=" + host + " port=" + std::to_string(port) + " dbname=" 
					 + dbname + " user=" + user + " password =" + password;
	this->table_name = table_name;
}

std::string Table::getConnectionString() {
	return connectionString;
}

std::string Table::getTableName() {
	return table_name;
}

Table::~Table() {

}