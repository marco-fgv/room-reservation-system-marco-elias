#include <iostream>
#include "ReservationSystem.hpp"
using namespace std;

int main(){
    int capacidades[3] = {100, 200, 300};
    Dia dias[5] = {Dia("Segunda"), Dia("Terça"), Dia("Quarta"), Dia("Quinta"), Dia("Sexta")};

    ReservationSystem sistema(3, capacidades);

    ReservationRequest request("AL", "Segunda", 7, 9, 10);

    sistema.reserve(request);
}