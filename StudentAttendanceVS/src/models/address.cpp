//
// Created by Majda on 04/11/2020.
//

#include "address.h"


Address::Address(std::string country, std::string town, std::string street, std::string house,
	std::string postal_code, std::string description, AddressType type) {

	this->country = country;
	this->town = town;
	this->street = street;
	this->house = house;
	this->postal_code = postal_code;
	this->description = description;
	this->type = type;
}

Address::Address() {

}
