#ifndef RESERVATIONSYSTEM_HPP
#define RESERVATIONSYSTEM_HPP

#include <string>
#include "ReservationRequest.hpp"
#include "Estrutura.hpp"

class ReservationSystem {
private:
    int room_count;
    int* room_capacities;
    Sala* salas;

public:
    ReservationSystem(int room_count, int* room_capacities);
    ~ReservationSystem();

    bool reserve(ReservationRequest request);
    bool cancel(std::string course_name);
    void printSchedule();
};

#endif