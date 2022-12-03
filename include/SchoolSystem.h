#ifndef SCHOOL_SYSTEM_H
#define SCHOOL_SYSTEM_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>

typedef int course_id_t;
typedef int section_id_t;

namespace Class_S {
    typedef int classtime;
    std::ostream& operator<<(std::ostream& out, classtime ct) {
        std::string ending = "AM";
        if (ct > 1259) {
            ct -= 1200;
            ending = "PM";
        }
        std::string s_time = std::to_string(ct);
        out << s_time.substr(0, 2) << ":" << s_time.substr(2) << ending;
        return out;
    }

    enum Day { Monday = 1, Tueday = 2, Wednesday = 3, Thursday = 4, Friday = 5 };
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

    typedef std::multimap<Day, std::pair<classtime, classtime>> schedule;
}

#endif // School_System_H
