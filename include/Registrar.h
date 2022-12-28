#ifndef REGISTRAR_H
#define REGISTRAR_H

#include "SchoolSystem.h"

#include "Student.h"
#include "Staff.h"
#include "Course.h"
#include "Section.h"

// Forward Declarations
class Student;
class Staff;
class Course;
class Section;

class Registrar {
    const int CREDIT_LIMIT = 16;

    std::vector<Student*> undergrad_students;
    std::vector<Student*> grad_students;
    std::vector<Staff*> staff;
    // Classes
    std::vector<Course*> all_courses;
    std::unordered_map<int, Section*> crn_section;

    bool check_registration(Student&, int);

    public:
        Registrar();
        Registrar(std::vector<Student*>, std::vector<Student*>, std::vector<Staff*>, std::vector<Course*>, std::unordered_map<int, Section*>);
        void initialize(void);

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
        std::vector<Course*> get_all_courses(void);
        void add_course(Course*);
        void remove_course(Course*);
        void set_all_courses(std::vector<Course*>);
        void print_all_courses(void);
        std::unordered_map<int, Section*> get_crn_sections(void);
        void add_crn_section(std::pair<int, Section*>);
        void remove_crn_section(int);
        void set_crn_section(std::unordered_map<int, Section*>);
        void start_registration(Student&);
        std::vector<Student*>::const_iterator find_student(Student&);

};



#endif // REGISTRAR_H