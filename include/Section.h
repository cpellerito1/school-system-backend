#ifndef SECTION_H
#define SECTION_H

#include "SchoolSystem.h"

#include "Course.h"
#include "Staff.h"
#include "Schedule.h"

//using namespace school_types;

typedef int section_id_t;

class Section {
    Course* course;
    section_id_t s_id;
    std::vector<Schedule*> class_schedule;
    id_t instructor;
    std::vector<id_t> roster;
    int crn;

    public:
        Section(Course*, section_id_t, std::vector<Schedule*>, id_t, int);
        Section(Course*, section_id_t, std::vector<Schedule*>, id_t, std::vector<id_t>, int);

        Course* get_course(void);
        void set_course(Course*);
        section_id_t get_section_id(void) const;
        void set_section_id(section_id_t);
        std::vector<Schedule*> get_class_schedule(void);
        void set_class_schedule(std::vector<Schedule*>);
        void print_schedule(void);
        id_t get_instructor(void);
        void set_instructor(id_t);
        std::vector<id_t> get_roster(void);
        void add_student(id_t);
        void remove_student(id_t);
        void set_roster(std::vector<id_t>);
        int get_crn(void);
        void set_crn(int);

        bool operator==(const Section&);
        friend std::ostream& operator<<(std::ostream&, const Section&);

};

#endif // SECTION_H
