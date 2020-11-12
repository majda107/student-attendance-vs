//
// Created by Majda on 04/11/2020.
//

#ifndef STUDENT_REGISTRY_UI_HANDLER_H
#define STUDENT_REGISTRY_UI_HANDLER_H

#include "student_handler.h";
#include "../ui/ui.h";
#include "../ui/student_ui.h";
#include <iostream>;
#include <stack>;

class UIHandler {
public:
    UIHandler();

    ~UIHandler();

    void process();


    bool should_exit() { return this->m_exit; }

    StudentHandler *student_handler;

private:
//    UI *m_ui;
    std::stack<UI *> m_ui_stack;
    bool m_exit;



//    Student *m_selected;
//    int m_index;
};


#endif //STUDENT_REGISTRY_UI_HANDLER_H
