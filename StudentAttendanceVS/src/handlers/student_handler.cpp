//
// Created by Majda on 04/11/2020.
//

#include "student_handler.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "../models/address.h";

Student* StudentHandler::create_student(std::string given_name, std::string family_name) {
	auto student = new Student(given_name, family_name);
	this->students.push_back(student);

	return student;
}

void StudentHandler::remove_student(Student* student) {
	this->students.erase(std::remove(this->students.begin(), this->students.end(), student), this->students.end());
	delete student;
}

StudentHandler::StudentHandler() {

}

StudentHandler::~StudentHandler() {
	for (auto student : this->students) {
		delete student;
	}
}


void StudentHandler::save(std::string filename) {
	std::ofstream f(filename);

	if (f.is_open()) {
		for (auto student : this->students) {
			f << student->first_name << " " << student->last_name << std::endl;

			for (auto address : *(student->get_addresses())) {
				f << "- country " << address.country << std::endl;
				f << "- description " << address.description << std::endl;
				f << "- house " << address.house << std::endl;
				f << "- postal_code " << address.postal_code << std::endl;
				f << "- street " << address.street << std::endl;
				f << "- town " << address.town << std::endl;
				f << std::endl;
			}
		}
	}
	else {
		std::cout << "Couldn't open save file...!";
	}


	f.close();
}

void StudentHandler::load(std::string filename) {
	std::ifstream f(filename);
	Student* student = nullptr;

	auto addr = Address();
	//Address addr;

	if (f.is_open()) {
		std::string line;
		std::string firstName;
		std::string lastName;
		std::string denom;


		while (!f.eof()) {
			std::getline(f, line);

			if (line.rfind("-", 0) == 0) {
				std::getline(f, line);
				if (student == nullptr) continue; // SKIP LINE

				auto ss = std::stringstream(line);

				std::getline(ss, denom, ' ');
				std::getline(ss, firstName, ' ');
				std::getline(ss, lastName);

				if (firstName == "country") addr.country = lastName;
				if (firstName == "town") addr.town = lastName;
				if (firstName == "house") addr.house = lastName;
				if (firstName == "postal_code") addr.postal_code = lastName;
				if (firstName == "description") addr.description = lastName;
				if (firstName == "street") addr.street = lastName;
			}
			else if (line == "") {
				if (student == nullptr) continue; // SKIP LINE

				student->push_adress(addr);
				addr = Address();
				continue;
			}
			else {
				auto ss = std::stringstream(line);

				std::getline(ss, firstName, ' ');
				std::getline(ss, lastName, ' ');
				student = this->create_student(firstName, lastName);
			}
		}
	}
	else {
		std::cout << "Couldn't open load file...!";
	}

	f.close();
}
