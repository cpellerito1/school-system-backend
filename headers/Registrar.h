#ifndef REGISTRAR_H
#define REGISTRAR_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

#include "Person.h"
#include "Student.h"
#include "Staff.h"
#include "Course.h"
#include "Section.h"

namespace Class_S {
    typedef int classtime;
    std::ostream& operator<<(std::ostream& out, classtime ct) {
        std::string ending = "AM";
        if (ct > 1259) {
            ct -= 1200;
            ending = "PM";
        }
        std::string s_time = std::to_string(ct);
        out << s_time.substr(0, 2) << ":" << s_time.substr(2) << ending;
        return out;
    }

    enum Day { Monday = 1, Tueday = 2, Wednesday = 3, Thursday = 4, Friday = 5 };
    std::ostream& operator<<(std::ostream& out, const Day& d) {
        std::string day;
        switch (d) {
            case 1:
                day = "Monday";
                break;
            case 2:
                day = "Tuesday";
                break;
            case 3:
                day = "Wednesday";
                break;
            case 4:
                day = "Thursday";
            case 5:
                day = "Friday";
                break;
        }
        out << day;
        return out;
    }

    typedef std::multimap<Day, std::pair<classtime, classtime>> schedule;
}

class Registrar {
    std::vector<Student*> undergrad_students;
    std::vector<Student*> grad_students;
    std::vector<Staff*> staff;
    std::vector<Course*> all_courses;
    std::unordered_map<int, Section*> crn_section;

    bool check_registration(Student&, int);

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
        std::vector<Course*> get_all_courses(void);
        void add_course(Course*);
        void remove_course(Course*);
        void set_all_courses(std::vector<Course*>);
        void print_all_courses(void);

        void start_registration(Student&);


};



#endif // REGISTRAR_H