#pragma once

#include <string>
#include <iostream>
#include <pqxx/pqxx>
#include "Table.hpp"

//gets all rows and columns in a table
pqxx::result getAll(Table table) {
	try {
		std::string query = "SELECT * FROM " + table.getTableName();
		pqxx::connection connectionObject(table.getConnectionString().c_str());
		pqxx::work worker(connectionObject);
		pqxx::result response = worker.exec(query);
		return response;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

//gets a row from a table given a id
pqxx::result getByID(Table table, long id) {
	try {
		std::string query = "SELECT * FROM " + table.getTableName() + " WHERE id = " + std::to_string(id);
		pqxx::connection connectionObject(table.getConnectionString().c_str());
		pqxx::work worker(connectionObject);
		pqxx::result response = worker.exec(query);
		return response;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

//deletes a row given id
void deleteByID(Table table, long id) {
	try {
		std::string query = "DELETE FROM " + table.getTableName() + " WHERE id = " + std::to_string(id) +";";
		pqxx::connection connectionObject(table.getConnectionString().c_str());
		pqxx::work worker(connectionObject);
		worker.exec(query);
		worker.commit();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

//gets the highest id value
long getHighestID(Table table) {
	try {
		std::string query = "SELECT id FROM " + table.getTableName() + " WHERE id = (SELECT MAX(id) FROM " + table.getTableName() + ")";
		pqxx::connection connectionObject(table.getConnectionString().c_str());
		pqxx::work worker(connectionObject);
		pqxx::result response = worker.exec(query);
		std::string id_string = (std::string)response[0][0].c_str();
		long id = std::stoi(id_string);
		return id;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

