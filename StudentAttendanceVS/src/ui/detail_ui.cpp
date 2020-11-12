//
// Created by Majda on 05/11/2020.
//

#include "detail_ui.h"
#include "address_ui.h"

DetailUI::DetailUI(StudentHandler* student_handler, Student* student) : UI(student_handler) {
	this->m_student = student;
}

UI* DetailUI::handle_keys() {

	std::string cmd;
	std::getline(std::cin, cmd);

	if (cmd == "n") this->move_next();
	else if (cmd == "p") this->move_prev();
	else if (cmd == "remove") {
		this->m_pop();
		this->m_student_handler->remove_student(this->m_student);
	}
	else if (cmd == "") {
		if (this->m_student->get_addresses()->size() <= 0) return nullptr;
		return new AddressUI(this->m_student_handler, &(*this->m_student->get_addresses())[this->m_index]);
	}
	else if (cmd == "new") {
		std::string country;
		std::string town;
		std::string street;
		std::string house;
		std::string postal_code;
		std::string description;
		std::string type;

		std::cout << "Country: ";
		std::getline(std::cin, country);

		std::cout << "Town: ";
		std::getline(std::cin, town);

		std::cout << "Street: ";
		std::getline(std::cin, street);

		std::cout << "House N.: ";
		std::getline(std::cin, house);

		std::cout << "Postal Code: ";
		std::getline(std::cin, postal_code);

		std::cout << "Description: ";
		std::getline(std::cin, description);

		std::cout << "Type: ";
		std::getline(std::cin, type);

		this->m_student->push_adress(Address(country, town, street, house, postal_code, description, ADDRESS_MAP[type]));
	}
	else {
		this->m_pop();
	}

	return nullptr;
}

void DetailUI::render() {
	this->m_clean();
	std::cout << this->m_student->first_name << " " << this->m_student->last_name << std::endl << std::endl;

	//    for (auto address: *this->m_student->get_addresses()) {
	//        std::cout << address.town << ", " << address.country << std::endl;
	//    }
	for (int i = 0; i < this->m_student->get_addresses()->size(); i++) {
		auto address = (*this->m_student->get_addresses())[i];

		if (this->m_index == i) std::cout << "[x] ";
		else std::cout << "[ ] ";

		std::cout << address.town << ", " << address.country << "..." << std::endl;
	}
}