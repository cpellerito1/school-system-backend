#include "Person.h"

std::string Person::get_first_name() { return first_name; }

void Person::set_first_name(std::string fn) { first_name = fn; }

std::string Person::get_last_name() { return last_name; }

void Person::set_last_name(std::string ln) { last_name = ln; }

char Person::get_middle_i() { return middle_i; }

void Person::set_middle_i(char initial) { middle_i = initial; }

std::string Person::get_name() { return first_name + " " + std::string(1, middle_i) + " " + last_name; }

void Person::set_name(std::string fn, std::string ln, char initial) {
    first_name = fn;
    last_name = ln;
    middle_i = initial;
}

long Person::get_id() { return id; }

void Person::set_id(long n_id) { id = n_id; }

std::string Person::get_address() { return address; }

void Person::set_address(std::string new_address) { address = new_address; }

bool Person::operator==(const Person &rhs) const { return this->id == rhs.id; }

std::ostream& operator<<(std::ostream &out, const Person &p) {
    out << p.first_name << " " << std::string(1, p.middle_i) << " " << p.last_name;
    return out;
}
