#include "../include/Course.h"

Course::Course(std::string class_name, Department dept, int cid, u_int8_t c, std::string descr): 
    name(class_name), department(dept), course_id(cid), credits(c), description(descr) {}

Course::Course(std::string class_name, Department dept, int cid, u_int8_t c, std::string descr, std::vector<Course*> prereqs, std::vector<Section*> secs): 
    name(class_name), department(dept), credits(c), course_id(cid), description(descr), prerequisites(prereqs), sections(secs) {}

std::string Course::get_name() { return name; }

void Course::set_name(std::string n) { name = n; }

course_id_t Course::get_course_id() const { return course_id; }

void Course::set_course_id(course_id_t id) { course_id = id; }

Department Course::get_department() { return department; }

void Course::set_department(Department dept) { department = dept; }

u_int8_t Course::get_credits() { return credits; }

void Course::set_credits(u_int8_t c) { credits = c; }

std::string Course::get_desciption() { return description; }

void Course::set_description(std::string desc) { description = desc; }

void Course::print_description() {
    std::ostream& out = std::cout;
    int count = 0;
    for (auto c: description) {
        if (++count >= 64 && c == ' ') {
            out << '\n';
            count = 0;
        } else
            out << c;
    }
}

std::vector<Course*> Course::get_prerequisites() { return prerequisites; }

void Course::set_prerequisities(std::vector<Course*> prereq) { prerequisites = prereq; }

std::vector<Section*> Course::get_sections() { return sections; }

void Course::add_section(Section* s) { sections.push_back(s); }

void Course::remove_section(Section* s) { sections.erase(std::find(sections.begin(), sections.end(), s)); } 

void Course::set_sections(std::vector<Section*> new_sections) { sections = new_sections; }

bool Course::operator==(const Course& rhs) const { return this->course_id == rhs.course_id; }

std::ostream& operator<<(std::ostream& out, const Course& rhs) {
    out << rhs.department << rhs.course_id << " - " << rhs.name << "\n" << rhs.description;
    return out;
}

std::ostream& operator<<(std::ostream& out, const Department& rhs) {
    switch (rhs) {
        case 0:
            out << "ENG";
            break;
        case 1:
            out << "CMPT";
            break;
        case 2:
            out << "BUS";
            break;
        case 3:
            out << "COMM";
            break;
        case 4:
            out << "SCI";
            break;
    }
    return out;
}