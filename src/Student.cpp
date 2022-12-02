#include "../headers/Student.h"

void Student::calculate_gpa() {
    for (auto g: all_classes) {
        GPA += g.second;
    }
}

void Student::calculate_credits() {
    for (auto c: all_classes) {
        total_credits += c.first->get_credits();
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
    return total_credits;
}

void Student::set_credits(int c) { total_credits = c; }

std::unordered_set<Section*> Student::get_current_classes() { return current_classes; }

void Student::add_current_class(Section* s) { current_classes.insert(s); }

void Student::remove_current_class(Section* s) { current_classes.erase(s); }

void Student::set_current_class(std::unordered_set<Section*> cc) { current_classes = cc; }

std::unordered_map<Section*, float> Student::get_all_classes() { return all_classes; }

void Student::add_class_to_all(std::pair<Section*, float> c) { all_classes.insert(c); }

void Student::remove_class_from_all(Section* s) { all_classes.erase(s); }

void Student::set_all_classes(std::unordered_map<Section*, float> c) { all_classes = c; }

Class_S::schedule Student::get_class_schedule() { return class_schedule; }

void Student::add_to_class_schedule(std::pair<Class_S::Day, std::pair<Class_S::classtime, Class_S::classtime>> c) { class_schedule.insert(c); }

void Student::remove_from_class_schedule(Class_S::Day d, std::pair<Class_S::classtime, Class_S::classtime> ct) {
    auto range = class_schedule.equal_range(d);
    for (auto itr = range.first; itr != range.second; itr++) {
        if (itr->first == d  && itr->second == ct)
            class_schedule.erase(itr);
    }
}

void Student::set_class_schedule(std::multimap<Class_S::Day, std::pair<Class_S::classtime, Class_S::classtime>> cs) { class_schedule = cs; }