#include "../include/Staff.h"

Staff::Staff(std::string name, id_t staff_id, std::string addr, std::string staff_title): title(staff_title) {
    const char delim = ' ';
    const size_t first = name.find_first_of(delim);
    this->first_name = name.substr(0, first);
    // first is the index of the first space, so the middle initial should be first+1
    this->middle_i = name[first+1];
    this->last_name = name.substr(name.find_last_of(delim));
    this->cwid = staff_id;
    this->address = addr;
}

Staff::Staff(std::string name, id_t staff_id, std::string addr, std::string staff_title, std::vector<section_id_t> staff_classes,
    std::vector<section_id_t> staff_class_history, std::vector<id_t> staff_advisees) {
        // Body
        const char delim = ' ';
        const size_t first = name.find_first_of(delim);
        this->first_name = name.substr(0, first);
        // first is the index of the first space, so the middle initial should be first+1
        this->middle_i = name[first+1];
        this->last_name = name.substr(name.find_last_of(delim));
        this->cwid = staff_id;
        this->address = addr;
        // Initilize data mmembers in body of class to make the code cleaner and more readable
        this->title = staff_title;
        this->classes = staff_classes;
        this->class_history = staff_class_history;
        this->advisee = staff_advisees;
}

std::string Staff::get_title() { return title; }

void Staff::set_title(std::string t) { title = t; }

std::vector<section_id_t> Staff::get_classes() { return classes; }

void Staff::add_class(section_id_t c) { classes.push_back(c); }

void Staff::set_classes(std::vector<section_id_t> c) { classes = c; }

std::vector<section_id_t> Staff::get_class_history() { return class_history; }

void Staff::add_class_to_history(section_id_t c) { class_history.push_back(c); }

void Staff::set_class_history(std::vector<section_id_t> ch) { class_history = ch; }

std::vector<id_t> Staff::get_advisee() { return advisee; }

void Staff::add_advisee(id_t s) { advisee.push_back(s); }

void Staff::set_advisee(std::vector<id_t> a) { advisee = a; }