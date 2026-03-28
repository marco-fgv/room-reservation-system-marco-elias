#include <iostream>
#include "ReservationSystem.hpp"
using namespace std;

int main(){
    int capacidades[3] = {100, 200, 300};

    ReservationSystem sistema(3, capacidades);

    // Capacidade não comportada
    ReservationRequest request0("AL", "sexta", 10,11,500);
    sistema.reserve(request0);

    // Deve ir para a Sala 1
    ReservationRequest request1("AEDV", "segunda", 7, 10, 20);
    sistema.reserve(request1);

    // Deve ir para a Sala 2
    ReservationRequest request2("Calculo", "segunda", 9, 12, 15);
    sistema.reserve(request2);

    // Deve ir para a Sala 1
    ReservationRequest request3("MD", "terca", 7, 10, 20);
    sistema.reserve(request3);

    // Deve ir para a Sala 1
    ReservationRequest request4("ED", "terca", 8, 10, 20);
    sistema.reserve(request4);

    // Deve ir para a Sala 3
    ReservationRequest request5("ALN", "terca", 8, 9, 20);
    sistema.reserve(request5);

    // Reserva sem disponibilidade
    sistema.reserve(request5);

    // Deve ir para a Sala 2, capacidade 200
    ReservationRequest request6("Modelagem", "sexta", 10, 11, 150);
    sistema.reserve(request6);

    sistema.printSchedule();

    // linha para visualizar melhor no terminal
    cout << "========================================" << endl;

    // remoção da matéria cálculo
    sistema.cancel("Calculo");

    // remoção da aula que não está no sistema
    sistema.cancel("Geogafia");

    sistema.printSchedule();
}