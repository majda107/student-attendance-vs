//
// Created by Majda on 05/11/2020.
//

#include "address_ui.h"

AddressUI::AddressUI(StudentHandler* student_handler, Address* address) : UI(student_handler) {
	this->m_address = address;
}

void AddressUI::render() {
	this->m_clean();
	std::cout << this->m_address->country << std::endl;
	std::cout << this->m_address->town << ", " << this->m_address->postal_code << std::endl;
	std::cout << this->m_address->street << ", " << this->m_address->house << std::endl;
	std::cout << std::endl << this->m_address->description << std::endl;
}

UI* AddressUI::handle_keys() {
	std::string cmd;
	std::getline(std::cin, cmd);

	this->m_pop();
	return nullptr;
}