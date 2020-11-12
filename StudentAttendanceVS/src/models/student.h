//
// Created by Majda on 04/11/2020.
//

#include <string>;
#include <vector>;
#include "address.h";

#ifndef STUDENT_REGISTRY_STUDENT_H
#define STUDENT_REGISTRY_STUDENT_H


class Student {
public:
    Student(std::string first_name, std::string last_name);

    ~Student();

    std::string first_name;
    std::string last_name;

    // METHODS
    void push_adress(Address address);

    // GETTERS SETTERS
    std::vector<Address> *get_addresses() {
        return this->m_adresses;
    }

private:
    std::vector<Address> *m_adresses;
};


#endif //STUDENT_REGISTRY_STUDENT_H
