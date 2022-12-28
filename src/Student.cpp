#include "../include/Student.h"

Student::Student(std::string name, id_t student_id, std::string addr, std::vector<std::string> student_majors, std::vector<std::string> student_minors,
    std::vector<id_t> advisors) {
        // Body
        const char delim = ' ';
        const size_t first = name.find_first_of(delim);
        this->first_name = name.substr(0, first);
        // first is the index of the first space, so the middle initial should be first+1
        this->middle_i = name[first+1];
        this->last_name = name.substr(name.find_last_of(delim));
        this->cwid = student_id;
        this->address = addr;
        // Set data memebrs in body to make code cleaner and more readable
        this->major = student_majors;
        this->minor = student_minors;
        this->advisor = advisors;
    }

void Student::calculate_gpa() {
    for (auto g: all_classes) {
        GPA += g.second.second;
    }
    GPA /= all_classes.size();
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

uint8_t Student::get_credits() {
    calculate_credits();
    return total_credits;
}

void Student::set_credits(uint8_t c) { total_credits = c; }

std::unordered_set<section_id_t> Student::get_current_classes() { return current_classes; }
void Student::add_current_class(section_id_t s) { current_classes.insert(s); }

void Student::remove_current_class(section_id_t s) { current_classes.erase(s); }

void Student::set_current_class(std::unordered_set<section_id_t> cc) { current_classes = cc; }

std::unordered_map<Course*, std::pair<section_id_t, float>> Student::get_all_classes() { return all_classes; }

void Student::add_class_to_all(std::pair<Course*, std::pair<section_id_t, float>> c) { all_classes.insert(c); }

void Student::remove_class_from_all(Course* s) { all_classes.erase(s); }

void Student::set_all_classes(std::unordered_map<Course*, std::pair<section_id_t, float>> c) { all_classes = c; }

std::vector<Schedule*> Student::get_class_schedule() { return class_schedule; }

void Student::add_to_class_schedule(Schedule* c) { class_schedule.push_back(c); }

void Student::remove_from_class_schedule(Schedule* c) {class_schedule.erase(std::find(class_schedule.begin(), class_schedule.end(), c)); }

void Student::set_class_schedule(std::vector<Schedule*> cs) { class_schedule = cs; }

std::vector<id_t> Student::get_advisor() { return advisor; }

void Student::add_advisor(id_t a) { advisor.push_back(a); }

void Student::remove_advisor(id_t a) { advisor.erase(std::find(advisor.begin(), advisor.end(), a)); }

void Student::set_advisor(std::vector<id_t> a) { advisor = a; }

void Student::print_registration_info() {
    std::cout << "Name: " << first_name << " " << middle_i << " " << last_name << std::endl;
    std::cout << "Majors: ";
    for (auto m: major) {
        std::cout << m;
        if (m != *major.end()--)
            std::cout << ", ";
        else
            std::cout << std::endl;
    }
    std::cout << "Minors: ";
    for (auto m: minor) {
        std::cout << m;
        if (m != *minor.end()--)
            std::cout << ", ";
        else
            std::cout << std::endl;
    }
    std::cout << "credits: " << get_credits() << std::endl;
    std::cout << "GPA: " << get_gpa() << std::endl;
}
