#ifndef SECTION_H
#define SECTION_H

#include "Registrar.h"

class Section : public Course {
    int section_id;
    // Schedule
    Staff* instructor;
    std::vector<Student*> roster;

    public:
        int get_section_id(void);
        void set_section_id(int);
        Staff* get_instructor(void);
        void get_instructor(Staff*);
        std::vector<Student*> get_roster(void);
        void add_student(Student*);
        void remove_student(int);
        void remove_student(Student*);
        void set_roster(std::vector<Student*>);

        bool operator==(const Section&);
        friend std::ostream& operator<<(std::ostream&, const Section&);

};

#endif // SECTION_H
