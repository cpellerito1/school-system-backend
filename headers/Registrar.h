#ifndef REGISTRAR_H
#define REGISTRAR_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include "Person.h"
#include "Student.h"
#include "Staff.h"
#include "Course.h"
#include "Section.h"

class Registrar {
    std::vector<Student*> undergrad_students;
    std::vector<Student*> grad_students;
    std::vector<Staff*> staff;


    public:
        std::vector<Student*> get_undergrad_students(void);
        void add_undergrad_student(Student*);
        void remove_undergrad_student(Student*);
        void set_undergrad_students(std::vector<Student*>);
        std::vector<Student*> get_grad_students(void);
        void add_grad_student(Student*);
        void remove_grad_student(Student*);
        void set_grad_students(std::vector<Student*>);
        std::vector<Staff*> get_staff(void);
        void add_staff(Staff*);
        void remove_staff(Staff*);
        void set_staff(std::vector<Staff*>);

        void start_registration(Student&);
        

};



#endif // REGISTRAR_H