#pragma once

#include <string>
#include <iostream>
#include <pqxx/pqxx>
#include "queries.h"
#include "Table.hpp"

void insertUser(Table table, std::string first_name, std::string last_name, std::string email, std::string gender, std::string picture, int user_status) {
	try{
	
		long id = getHighestID(table) + 1;
		
		std::string query = "INSERT INTO " + table.getTableName() + "(id, first_name, last_name, email, gender, picture, user_status, created_at, updated_at) VALUES (" 
						  + std::to_string(id) + ", '" + first_name + "', '" + last_name + "', '" + email + "', '" + gender + "', '" + picture + "', " 
						  + std::to_string(user_status) + ", current_timestamp, current_timestamp);";
		pqxx::connection connectionObject(table.getConnectionString().c_str());
		pqxx::work worker(connectionObject);
		worker.exec(query);
		worker.commit();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void updateUser(Table table, long id, std::string first_name, std::string last_name, std::string email, std::string gender, std::string picture, int user_status) {
	
	try {
		std::string query = "UPDATE " + table.getTableName() + " SET first_name = '" + first_name + "', last_name = '" + last_name + "', email = '" + email 
			+ "', gender = '"+ gender + "', picture = '" + picture + "', user_status = " + std::to_string(user_status) 
			+ ", updated_at = current_timestamp WHERE id = " + std::to_string(id) + ";";
		pqxx::connection connectionObject(table.getConnectionString());
		pqxx::work worker(connectionObject);
		worker.exec(query);
		worker.commit();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
