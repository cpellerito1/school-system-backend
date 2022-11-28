#include "../headers/Course.h"

int Course::get_id() { return class_id; }

void Course::set_id(int id) { class_id = id; }

char Course::get_department() { return department; }

void Course::set_department(char dept) { department = dept; }

u_int8_t Course::get_credits() { return credits; }

void Course::set_credits(u_int8_t c) { credits = c; }

std::string Course::get_desciption() { return description; }

void Course::set_description(std::string desc) { description = desc; }

std::vector<Course*> Course::get_prerequisites() { return prerequisites; }

void Course::set_prerequisities(std::vector<Course*> prereq) { prerequisites = prereq; }

std::vector<Section*> Course::get_classes() { return classes; }

void Course::set_classes(std::vector<Section*> new_classes) { classes = new_classes; }

bool Course::operator==(const Course& rhs) const { return this->class_id == rhs.class_id; }

std::ostream& operator<<(std::ostream& out, const Course& c) {
    out << c.name << c.department;
    return out;
}