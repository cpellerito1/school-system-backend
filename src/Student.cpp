#include "../headers/Student.h"

void Student::calculate_gpa() {
    for (auto g: classes) {
        GPA += g.second;
    }
}

void Student::calculate_credits() {
    for (auto c: classes) {
        current_credits += c.first->get_credits();
    }
}

std::vector<std::string> Student::get_major() { return major; }

void Student::set_major(std::vector<std::string> m) { major = m; }

void Student::add_major(std::string m) { major.push_back(m); }

void Student::remove_major(int index) { major.erase(major.begin() + index - 1); }

void Student::remove_major(std::string m) { major.erase(std::find(major.begin(), major.end(), m)); }

std::vector<std::string> Student::get_minor() { return major; }

void Student::set_minor(std::vector<std::string> mi) { minor = mi; }

void Student::remove_minor(int index) { minor.erase(minor.begin() + index - 1); }

void Student::remove_minor(std::string m) { minor.erase(std::find(minor.begin(), minor.end(), m)); }

void Student::add_minor(std::string mi) { minor.push_back(mi); }

float Student::get_gpa() {
    calculate_gpa();
    return GPA;
}

void Student::set_gpa(float g) { GPA = g; }

int Student::get_credits() {
    calculate_credits();
    return current_credits;
}

void Student::set_credits(int c) { current_credits = c; }