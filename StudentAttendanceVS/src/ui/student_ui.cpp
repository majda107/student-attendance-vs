//
// Created by Majda on 05/11/2020.
//

#include "student_ui.h";
#include "detail_ui.h";
#include <iostream>
#include <conio.h>;

StudentUI::StudentUI(StudentHandler* student_handler) : UI(student_handler) {
	this->m_index = 0;
}

UI* StudentUI::handle_keys() {
	//std::string cmd;
	//std::getline(std::cin, cmd);

	//if (cmd == "n") this->move_next();
	//else if (cmd == "p") this->move_prev();
	//else if (cmd == "exit") this->m_pop();
	//else if (cmd == "") {
	//    return new DetailUI(this->m_student_handler, this->m_student_handler->students[this->m_index]);
	//}

	char c = _getch();
	if (c == 'j') this->move_next();
	else if (c == 'k') this->move_prev();
	else if (c == 'e') this->m_pop();
	else if (c == 'n') {
		std::string given_name, family_name;

		std::cout << "Given name: ";
		std::getline(std::cin, given_name);

		std::cout << "Family name: ";
		std::getline(std::cin, family_name);

		this->m_student_handler->create_student(given_name, family_name);
	}
	else if (c == '\r') {
		if (this->m_index < this->m_student_handler->students.size()) {
			return new DetailUI(this->m_student_handler, this->m_student_handler->students[this->m_index]);
		}
	}


	return nullptr;
}

void StudentUI::render() {
	this->m_clean();
	std::cout << "[j] - DOWN, [k] - UP, [enter] - EDIT, [e] - EXIT" << std::endl;
	this->m_render_separator();
	std::cout << "Students in registry..." << std::endl << std::endl;

	// RESET INDEX
	if (this->m_index < 0 || this->m_index >= this->m_student_handler->students.size()) this->move_next();

	for (int i = 0; i < this->m_student_handler->students.size(); i++) {
		auto student = this->m_student_handler->students[i];

		if (this->m_index == i) std::cout << "[x] ";
		else std::cout << "[ ] ";

		std::cout << student->first_name << " " << student->last_name << std::endl;
	}
}