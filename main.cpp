#include <iostream>
#include "ReservationSystem.hpp"
using namespace std;

int main(){
    int capacidades[3] = {100, 200, 300};

    ReservationSystem sistema(3, capacidades);

    ReservationRequest request("AL", "Segunda", 7, 9, 10);

    sistema.reserve(request);
}