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

std::unordered_map<Section*, float> Student::get_classes() { return classes; }

void Student::add_class(std::pair<Section*, float> c) { classes.insert(c); }

void Student::remove_class(Section* s) { classes.erase(s); }

void Student::set_classes(std::unordered_map<Section*, float> c) { classes = c; }

Class_S::schedule Student::get_class_schedule() { return class_schedule; }

void Student::add_to_class_schedule(std::pair<Class_S::Day, std::pair<Class_S::classtime, Class_S::classtime>> c) { class_schedule.insert(c); }

void Student::remove_from_class_schedule(Class_S::Day d, std::pair<Class_S::classtime, Class_S::classtime> ct) {
    for (auto itr: class_schedule) {
        if (itr.first == d  && itr.second == ct)
            class_schedule.erase(itr);
    }
}

void Student::set_class_schedule(std::multimap<Class_S::Day, std::pair<Class_S::classtime, Class_S::classtime>> cs) { class_schedule = cs; }