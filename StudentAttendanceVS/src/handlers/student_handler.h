//
// Created by Majda on 04/11/2020.
//


#ifndef STUDENT_REGISTRY_STUDENT_HANDLER_H
#define STUDENT_REGISTRY_STUDENT_HANDLER_H

#include <vector>;
#include "../models/student.h";


class StudentHandler {
public:
	StudentHandler();

	~StudentHandler();

	std::vector<Student*> students;

	Student* create_student(std::string given_name, std::string family_name);

	void remove_student(Student* student);

	void save(std::string filename);
	void load(std::string filename);
};


#endif //STUDENT_REGISTRY_STUDENT_HANDLER_H
