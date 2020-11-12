//
// Created by Majda on 05/11/2020.
//

#ifndef STUDENT_REGISTRY_ADDRESS_UI_H
#define STUDENT_REGISTRY_ADDRESS_UI_H

#include "ui.h";
#include <iostream>;
#include "../handlers/student_handler.h";
#include "../models/address.h";


class AddressUI : public UI {
public:
	AddressUI(StudentHandler* student_handler, Student* student, Address* address);

	virtual void render();

	virtual UI* handle_keys();

private:
	Address* m_address;
	Student* m_student;
};


#endif //STUDENT_REGISTRY_ADDRESS_UI_H
