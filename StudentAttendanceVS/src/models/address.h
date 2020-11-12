//
// Created by Majda on 04/11/2020.
//

#ifndef STUDENT_REGISTRY_ADDRESS_H
#define STUDENT_REGISTRY_ADDRESS_H

#include <string>;


class Address {
public:
	Address(std::string country, std::string town, std::string street, std::string house,
		std::string postal_code, std::string description);

	Address();

	std::string country;
	std::string town;
	std::string street;
	std::string house;
	std::string postal_code;
	std::string description;
};


#endif //STUDENT_REGISTRY_ADDRESS_H
