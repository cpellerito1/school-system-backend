#include "../include/Schedule.h"

std::ostream& operator<<(std::ostream& out, const Day& d) {
    std::string day;
        switch (d) {
            case 1:
                day = "Monday";
                break;
            case 2:
                day = "Tuesday";
                break;
            case 3:
                day = "Wednesday";
                break;
            case 4:
                day = "Thursday";
            case 5:
                day = "Friday";
                break;
        }
        out << day;
        return out;
}

Schedule::Schedule(Day d, classtime start, classtime end): day_of_week(d), start_time(start), end_time(end) {}

Day Schedule::get_day() const { return day_of_week; }

void Schedule::set_day(Day d) { day_of_week = d; }

classtime Schedule::get_start_time() const { return start_time; }

void Schedule::set_start_time(classtime t) { start_time = t; }

classtime Schedule::get_end_time() const { return end_time; }

void Schedule::set_end_time(classtime t) { end_time = t; }

bool Schedule::operator==(const Schedule& rhs) {
    return this->day_of_week == rhs.get_day() && this->start_time == rhs.get_start_time() && this->end_time == rhs.get_end_time();
}

std::ostream& operator<<(std::ostream& out, const classtime& class_time) {
    std::string ending = "AM";
    classtime ct = class_time;
    if (ct > 1259) {
        ct -= 1200;
        ending = "PM";
    }
    std::string s_time = std::to_string(ct);
    out << s_time.substr(0, 2) << ":" << s_time.substr(2) << ending;
    return out;
}