//
// Created by Majda on 04/11/2020.
//

#ifndef STUDENT_REGISTRY_ADDRESS_H
#define STUDENT_REGISTRY_ADDRESS_H

#include <string>;
#include <map>

enum AddressType { Residence, Correspondence, Representative };
static std::map<std::string, AddressType> ADDRESS_MAP = {
	{"residence", AddressType::Residence},
	{"correspondence", AddressType::Correspondence},
	{"representative", AddressType::Representative}
};

class Address {
public:
	Address(std::string country, std::string town, std::string street, std::string house,
		std::string postal_code, std::string description, AddressType type);

	Address();

	std::string country;
	std::string town;
	std::string street;
	std::string house;
	std::string postal_code;
	std::string description;
	AddressType type;
};


#endif //STUDENT_REGISTRY_ADDRESS_H
