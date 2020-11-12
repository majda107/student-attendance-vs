//
// Created by Majda on 05/11/2020.
//

#ifndef STUDENT_REGISTRY_STUDENT_UI_H
#define STUDENT_REGISTRY_STUDENT_UI_H

#include "ui.h";
#include <iostream>

class StudentUI : public UI {

public:
    StudentUI(StudentHandler *student_handler);

    virtual UI *handle_keys();

    virtual void render();


    // FOR PAGITATION
    void move_next() {
        if (++this->m_index >= this->m_student_handler->students.size()) this->m_index = 0;
    }

    void move_prev() {
        if (--this->m_index < 0) this->m_index = this->m_student_handler->students.size() - 1;
    }
    // FOR PAGITATION

private:
    int m_index;
};


#endif //STUDENT_REGISTRY_STUDENT_UI_H
