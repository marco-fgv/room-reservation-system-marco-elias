#include <iostream>

class ReservationRequest {

private:
    std::string course_name;
    std::string weekday;
    int start_hour;
    int end_hour;
    int student_count;
    int weekdayIndex;

public:

    ReservationRequest(std::string course_name, std::string weekday, int start_hour, int end_hour, int student_count);
    ~ReservationRequest();

    int getStartHour();
    int getEndHour();
    std::string getCourseName();
    std::string getWeekday();
    int getStudentCount();
    int toIndex(string dia);
    int getWeekdayIndex();
};