#include "../include/SchoolSystem.h"
#include "../include/Schedule.h"
#include "../include/Registrar.h"
#include "../include/Course.h"
#include "../include/Section.h"
#include "../include/Staff.h"
#include "../include/Student.h"

void Registrar::initialize() {
    // Create the courses
    all_courses.push_back(new Course("Writing for College", ENG, 101, 3, "Introduction to writing for college"));
    all_courses.push_back(new Course("Intro to programming", CMPT, 101, 4, "This course introduces you to programming using PYthon"));
    all_courses.push_back(new Course("Intro to web development", CMPT, 105, 4, "This courses teaches you java script"));
    all_courses.push_back(new Course("Design of Compilers", CMPT, 428, 4, "This course teaches you about the design and implentation of compilers"));
    all_courses.push_back(new Course("International Business", BUS, 205, 3, "This course teaches you the intricacies of international business"));
    all_courses.push_back(new Course("Nuclear Pyschics", SCI, 402, 4, "Intro to nuclear physics and nuclear power"));
    // Add prereqs
    all_courses[3]->set_prerequisities({all_courses[1], all_courses[2]});
    // Create a few professors to teach these classes
    staff.push_back(new Staff("Larry J Fitzgerald", 123, "11 main street", "Associate professor of English"));
    staff.push_back(new Staff("Alan M Turing", 145, "112 9th ave", "Professor of computer science and mathematics"));
    staff.push_back(new Staff("Steve A Cohen", 487, "41 seaver way", "Professor of Business"));
    staff.push_back(new Staff("Albert G Einstein", 987, "1 main road", "Professor of physics"));
    // Schedule pointers to assign to each section
    Schedule *mon = new Schedule(Monday, 800, 915);
    Schedule *tues = new Schedule(Tueday, 1400, 1515);
    Schedule *wed = new Schedule(Wednesday, 1830, 2000);
    Schedule *mon2 = new Schedule(Monday, 830, 1045);
    Schedule *thurs = new Schedule(Thursday, 1215, 1330);
    // Now create a few sections for each course
    all_courses[0]->set_sections({new Section(all_courses[0], 155, {mon, thurs}, 123, 1234), new Section(all_courses[0], 156, {mon2, tues}, 487, 1233)});
    all_courses[1]->set_sections({new Section(all_courses[1], 110, {mon, wed}, 145, 1134)});
    all_courses[2]->set_sections({new Section(all_courses[2], 187, {mon2, thurs}, 145, 2456)});
    all_courses[3]->set_sections({new Section(all_courses[3], 286, {mon, tues, wed}, 145, 9874)});
    all_courses[4]->set_sections({new Section(all_courses[4], 356, {wed, thurs}, 487, 8456)});
    all_courses[5]->set_sections({new Section(all_courses[5], 456, {mon2, thurs}, 987, 8123)});
    // Fill the crn_sections map
    crn_section.insert(std::pair(1234, all_courses[0]->get_sections()[0]));
    crn_section.insert(std::pair(1233, all_courses[0]->get_sections()[1]));
    crn_section.insert(std::pair(1134, all_courses[1]->get_sections()[0]));
    crn_section.insert(std::pair(2456, all_courses[2]->get_sections()[0]));
    crn_section.insert(std::pair(9874, all_courses[3]->get_sections()[0]));
    crn_section.insert(std::pair(8456, all_courses[4]->get_sections()[0]));
    crn_section.insert(std::pair(8123, all_courses[5]->get_sections()[0]));
    // Now create some students
    undergrad_students.push_back(new Student("Chris J Pellerito", 200, "98 main street", {"Computer Science", "Cybersecurity"}, {"IT", "IS"}, {145}));
    staff[1]->add_advisee(200);
    undergrad_students.push_back(new Student("Student A Name", 199, "156 street lane", {"Business"}, {}, {487}));
    staff[2]->add_advisee(199);
    undergrad_students.push_back(new Student("first m last", 389, "324 main lane", {"Economic"}, {"Finance"}, {487}));
    staff[2]->add_advisee(389);
    grad_students.push_back(new Student("Grad A Student", 834, "18 Grad way", {"English"}, {}, {123}));
    staff[0]->add_advisee(834);

}