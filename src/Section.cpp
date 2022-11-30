#include "../headers/Section.h"

int Section::get_section_id() { return section_id; }

void Section::set_section_id(int sid) { section_id = sid; }

Class_S::schedule Section::get_class_schedule() { return class_schedue; }

void Section::set_class_schedule(Class_S::schedule cs) { class_schedue = cs; }

void Section::print_schedule() {
    for (auto s: class_schedue)
        std::cout << "Day: " << s.first << " Time: " << s.second.first << "-" << s.second.second << '\n';
}

Staff* Section::get_instructor() { return instructor; }

void Section::get_instructor(Staff* inst) { instructor = inst; }

std::vector<Student*> Section::get_roster() { return roster; }

void Section::add_student(Student* new_student) { roster.push_back(new_student); }

void Section::remove_student(int index) { roster.erase(roster.begin() + index-1); }

void Section::remove_student(Student* s) { roster.erase(std::find(roster.begin(), roster.end(), s)); }

void Section::set_roster(std::vector<Student*> rstr) { roster = rstr; }

int Section::get_crn() { return crn; }

void Section::set_crn(int t_crn) { crn = t_crn; }

bool Section::operator==(const Section& rhs) { return this->section_id == rhs.section_id && this->get_course_id() == rhs.get_course_id();}