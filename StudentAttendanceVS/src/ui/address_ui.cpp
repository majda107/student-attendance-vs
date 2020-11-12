//
// Created by Majda on 05/11/2020.
//

#include "address_ui.h"
#include <conio.h>

AddressUI::AddressUI(StudentHandler* student_handler, Student* student, Address* address) : UI(student_handler) {
	this->m_address = address;
	this->m_student = student;
}

void AddressUI::render() {
	this->m_clean();
	std::cout << "[Type] " << ADDRESS_STRING_MAP[this->m_address->type] << std::endl;
	std::cout << "[Country] " << this->m_address->country << std::endl;
	std::cout << "[Town, Code] " << this->m_address->town << ", " << this->m_address->postal_code << std::endl;
	std::cout << "[Street, House] " << this->m_address->street << ", " << this->m_address->house << std::endl;
	std::cout << std::endl << "[Description] " << this->m_address->description << std::endl;
}

UI* AddressUI::handle_keys() {
	char c = _getch();

	if (c == 'd') {
		//auto addresses = this->m_student->get_addresses();
		this->m_student->remove_address(*this->m_address);
	}

	this->m_pop();
	return nullptr;
}