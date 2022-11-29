#include "../headers/Section.h"

int Section::get_section_id() { return section_id; }

void Section::set_section_id(int sid) { section_id = sid; }

Staff* Section::get_instructor() { return instructor; }

void Section::get_instructor(Staff* inst) { instructor = inst; }

std::vector<Student*> Section::get_roster() { return roster; }

void Section::add_student(Student* new_student) { roster.push_back(new_student); }

void Section::remove_student(int index) { roster.erase(roster.begin() + index-1); }

void Section::remove_student(Student* s) { roster.erase(std::find(roster.begin(), roster.end(), s)); }

void Section::set_roster(std::vector<Student*> rstr) { roster = rstr; }

bool Section::operator==(const Section& rhs) { return this->section_id == rhs.section_id && this->get_course_id() == rhs.get_course_id();}