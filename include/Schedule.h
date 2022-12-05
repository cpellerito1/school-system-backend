#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "SchoolSystem.h"

enum Day { Monday = 1, Tueday = 2, Wednesday = 3, Thursday = 4, Friday = 5 };
std::ostream& operator<<(std::ostream&, const Day&);

typedef int classtime;

class Schedule {
    Day day_of_week;
    classtime start_time;
    classtime end_time;

    public:
        Day get_day(void);
        void set_day(Day);
        classtime get_start_time(void);
        void set_start_time(classtime);
        classtime get_end_time(void);
        void set_end_time(classtime);

        friend std::ostream& operator<<(std::ostream&, const classtime&);
};

#endif // SCHEDULE_H
