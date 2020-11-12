//
// Created by Majda on 04/11/2020.
//

#ifndef STUDENT_REGISTRY_UI_H
#define STUDENT_REGISTRY_UI_H

#include "../handlers/student_handler.h";

class UI {
public:
	UI(StudentHandler* student_handler);

	virtual UI* handle_keys() = 0;

	virtual void render() = 0;

	bool should_pop() { return this->m_should_pop; }

protected:
	StudentHandler* m_student_handler;

	void m_pop() { this->m_should_pop = true; }
	void m_clean();

private:
	bool m_should_pop = false;
};


#endif //STUDENT_REGISTRY_UI_H
