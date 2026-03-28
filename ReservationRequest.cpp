#include <iostream>
#include "ReservationRequest.hpp"
using namespace std;

ReservationRequest::ReservationRequest(string course_name, string weekday, int start_hour, int end_hour, int student_count){
    this->course_name = course_name;
    this->weekday = weekday;
    this->weekdayIndex = toIndex(weekday);
    this->start_hour = start_hour;
    this->end_hour = end_hour;
    this->student_count = student_count;
}

ReservationRequest::~ReservationRequest(){}

int ReservationRequest::getStartHour(){
    return this->start_hour;
}
int ReservationRequest::getEndHour(){
    return this->end_hour;
}
string ReservationRequest::getCourseName(){
    return this->course_name;
}
string ReservationRequest::getWeekday(){
    return this->weekday;
}
int ReservationRequest::getStudentCount(){
    return student_count;
}
int ReservationRequest::toIndex(string dia){
    // Função que auxlia a busca
    if(dia == "segunda"){
        return 0;
    }
    if(dia == "terca"){
        return 1;
    }
    if(dia == "quarta"){
        return 2;
    }
    if(dia == "quinta"){
        return 3;
    }
    if(dia == "sexta"){
        return 4;
    }
    // return -1 para evitar warming
    return -1;
}

int ReservationRequest::getWeekdayIndex(){
    return this->weekdayIndex;
}
