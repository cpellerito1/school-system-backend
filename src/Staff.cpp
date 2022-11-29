#include "../headers/Staff.h"

std::string Staff::get_title() { return title; }

void Staff::set_title(std::string t) { title = t; }

std::vector<Section*> Staff::get_classes() { return classes; }

void Staff::add_class(Section* c) { classes.push_back(c); }

void Staff::set_classes(std::vector<Section*>& c) { classes = c; }

std::vector<Section*> Staff::get_class_history() { return class_history; }

void Staff::add_class_to_history(Section* c) { class_history.push_back(c); }

void Staff::set_class_history(std::vector<Section*>& ch) { class_history = ch; }

std::vector<Student*> Staff::get_advisee() { return advisee; }

void Staff::add_advisee(Student* s) { advisee.push_back(s); }

void Staff::set_advisee(std::vector<Student*>& a) { advisee = a; }