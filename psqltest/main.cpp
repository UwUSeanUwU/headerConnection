#include <iostream>
#include <string>
#include "query_headers.h"
#include "UserQueries.h"

int main() {
	
	Table user("localhost", 5432, "microservice", "postgres", "123456789", "app_user");
	updateUser(user, 4, "Home", "Simp", "HSimp@gmail.com", "Male", "NULL", 1);
	/*
	insertUser(user, "Homer", "Simpson", "HSimp@gmail.com", "Male", "", 1);
	results = getByID(user, 3);
	for (size_t i = 0; i < results.size(); i++) {
		std::cout << "Id: " << results[i][0] << " firstName: " << results[i][1] << " lastName: " << results[i][2] << " Email: " << results[i][3] << std::endl;
	}
	*/
	//std::cout << getHighestID(user) << std::endl;
	pqxx::result results = getAll(user);
	for (size_t i = 0; i < results.size(); i++) {
		for (size_t j = 0; j < results[i].size(); j++) {
			std::cout << results[i][j] << "||";
		}
		std::cout << std::endl;
	}
	deleteByID(user, 4);
	results = getAll(user);
	for (size_t i = 0; i < results.size(); i++) {
		for (size_t j = 0; j < results[i].size(); j++) {
			std::cout << results[i][j] << "||";
		}
		std::cout << std::endl;
	}

}
