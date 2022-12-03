#include "../include/Staff.h"

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