//
// Created by Majda on 04/11/2020.
//

#include "student.h"
#include <iostream>

Student::Student(std::string first_name, std::string last_name) {
	this->first_name = first_name;
	this->last_name = last_name;

	this->m_adresses = new std::vector<Address>();
}

Student::~Student() {
	delete this->m_adresses;
}


void Student::push_adress(Address address) {
	this->m_adresses->push_back(address);
}

void Student::remove_address(Address address) {
	this->m_adresses->erase(std::remove(this->m_adresses->begin(), this->m_adresses->end(), address), this->m_adresses->end());
	//this->students.erase(std::remove(this->students.begin(), this->students.end(), student), this->students.end());
	//delete student;
}