//
// Created by Majda on 04/11/2020.
//

#include "ui.h"
#include <stdio.h>;
#include <iostream>;

UI::UI(StudentHandler* student_handler) {
	this->m_student_handler = student_handler;
}

void UI::m_clean()
{
	std::cout << "\x1B[2J\x1B[H";
}
