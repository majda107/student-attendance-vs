//
// Created by Majda on 04/11/2020.
//

#include "ui_handler.h"

//#include <curses.h>
// conio.h in case of windows

#include "../models/student.h";

UIHandler::UIHandler() {


	this->student_handler = new StudentHandler();

	//this->student_handler->create_student("Majda", "Brdkos");
	//this->student_handler->create_student("Brystof", "Bahumensky");
	//this->student_handler->create_student("Bebe", "Bervenka");

	this->m_ui_stack.push(new StudentUI(this->student_handler));

	//    this->m_index = 0;
	//    this->m_selected = nullptr;
}

UIHandler::~UIHandler() {
	delete this->student_handler;
}

void UIHandler::process() {
	auto ui = this->m_ui_stack.top();
	ui->render();

	auto newUI = ui->handle_keys();

	if (ui->should_pop()) {
		// POP
		delete ui;
		this->m_ui_stack.pop();

		if (this->m_ui_stack.size() <= 0) this->m_exit = true;

	}
	else if (newUI != nullptr) {
		this->m_ui_stack.push(newUI);
	}

}

//void UIHandler::render() {
//    std::cout << "\x1B[2J\x1B[H";
//    std::cout << "Students in registry..." << std::endl << std::endl;
//
//    if (this->m_selected == nullptr) {
//        for (int i = 0; i < this->student_handler.students.size(); i++) {
//            auto student = this->student_handler.students[i];
//
//            if (this->m_index == i) std::cout << "[x] ";
//            else std::cout << "[ ] ";
//
//            std::cout << student.first_name << " " << student.last_name << std::endl;
//        }
//    } else {
//        std::cout << this->m_selected->first_name << " " << this->m_selected->last_name << std::endl;
//    }
//
////    for (auto student: this->student_handler.students) {
////        std::cout << "[ ] " << student.first_name << " " << student.last_name << std::endl;
////    }
//}
//
//void UIHandler::select() {
////    std::cout << "SELECTING" << std::endl;
//    this->m_selected = &this->student_handler.students[this->m_index];
//}
//
//void UIHandler::deselect() {
//    this->m_selected = nullptr;
//}
//
//void UIHandler::handle_keys() {
//    std::string cmd;
//    std::getline(std::cin, cmd);
//
//    if (cmd == "exit") this->m_exit = true;
//    else if (cmd == "") this->select();
//    else if (cmd == "n") this->move_next();
//    else if (cmd == "p") this->move_prev();
//    else if (cmd == "b") this->deselect();
//
////    auto pressed = (char) getch();
////    std::cout << pressed << std::endl;
//}