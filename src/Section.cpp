#include "../include/Section.h"

course_id_t Section::get_course_id() const { return course; }

void Section::set_course_id(course_id_t cid) { course = cid; }

section_id_t Section::get_section_id() { return s_id; }

void Section::set_section_id(section_id_t id) {
    // Section id should be a combination of the course id and the section id to keep them unique
    // The first 3 digits should be the course id and the next 3 should be the section id
    const std::string temp(std::to_string(course) + std::to_string(id));
    id = std::atoi(temp.c_str());
 }

Class_S::schedule Section::get_class_schedule() { return class_schedue; }

void Section::set_class_schedule(Class_S::schedule cs) { class_schedue = cs; }

void Section::print_schedule() {
    for (auto s: class_schedue)
        std::cout << "Day: " << s.first << " Time: " << s.second.first << "-" << s.second.second << '\n';
}

id_t Section::get_instructor() { return instructor; }

void Section::set_instructor(id_t inst) { instructor = inst; }

std::vector<id_t> Section::get_roster() { return roster; }

void Section::add_student(id_t new_student) { roster.push_back(new_student); }

void Section::remove_student(id_t s) { roster.erase(std::find(roster.begin(), roster.end(), s)); }

void Section::set_roster(std::vector<id_t> rstr) { roster = rstr; }

int Section::get_crn() { return crn; }

void Section::set_crn(int t_crn) { crn = t_crn; }

bool Section::operator==(const Section& rhs) { return this->s_id == rhs.s_id && this->course == rhs.get_course_id();}