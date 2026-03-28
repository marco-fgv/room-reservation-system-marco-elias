#ifndef RESERVATIONSYSTEM_HPP
#define RESERVATIONSYSTEM_HPP

#include <string>
#include "ReservationRequest.hpp"

class Dia {
private:
    std::string nome_dia;
    bool horas_uteis[14];
    std::string cursos[14];

public:
    Dia();  
    Dia(std::string nome_dia);

    std::string getDia();
    void reservarHorario(int horario, std::string nome_curso);
    void cancelarHorario(int horario);
    bool getReservado(int horario);
    bool possuiReserva();
    std::string getCurso(int i);
};

class Sala {
private:
    int capacidade;
    int numero_sala;
    Dia dias[5];
    bool possuiReserva;

public:
    Sala();
    Sala(int capacidade, int numero);

    void display();
    int getCapacidade();
    bool estaLivre(int dia, int inicio, int fim);
    void reservar(int dia, int inicio, int fim, std::string nome_curso);
    bool cancelar(std::string nome_curso);
    bool SalaPossuiReserva();
};

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