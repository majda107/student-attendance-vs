//
// Created by Majda on 05/11/2020.
//

#ifndef STUDENT_REGISTRY_DETAIL_UI_H
#define STUDENT_REGISTRY_DETAIL_UI_H

#include "ui.h";

class DetailUI : public UI {
public:
    DetailUI(StudentHandler *student_handler, Student *student);

    virtual UI *handle_keys();

    virtual void render();


    // FOR PAGITATION
    void move_next() {
        if (++this->m_index >= this->m_student->get_addresses()->size()) this->m_index = 0;
    }

    void move_prev() {
        if (--this->m_index < 0) this->m_index = this->m_student->get_addresses()->size() - 1;
    }
    // FOR PAGITATION

private:
    Student *m_student;
    int m_index = 0;
};


#endif //STUDENT_REGISTRY_DETAIL_UI_H
