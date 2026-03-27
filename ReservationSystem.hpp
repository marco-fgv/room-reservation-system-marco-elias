#include <iostream>
#include "ReservationRequest.hpp"
using namespace std;

class Horario {
private:
    int hora;
    bool reservado;

public:
    Horario();
    void def_hora(int h);
    void reservarHorario();
    bool getReservado();
    int getHora();
};

class Dia {
private:
    static const int horas_totais = 15;
    string nome_dia;
    
    public:
    Horario horas_uteis[horas_totais];
    Dia(string nome_dia);
    string getDia();
    
};

class Sala {

    int capacidade;
    int numero_sala;
    Dia dias[5] = {Dia("Segunda"), Dia("Terca"), Dia("Quarta"), Dia("Quinta"), Dia("Sexta")};

public:
    Sala(){}

    Sala(int capacidade, int numero);
    void display();
    int getCapacidade();
    bool estaLivre(int dia, int inicio, int fim);
    void reservar(int dia, int inicio, int fim);
};

class ReservationSystem {

private:
    int room_count;
    int* room_capacities;

    // Estruturas internas escolhidas pelos alunos
    // para armazenar e gerenciar as reservas, os horários, ...

public:

    ReservationSystem(int room_count, int* room_capacities);
    ~ReservationSystem();

    bool reserve(ReservationRequest request);
    bool cancel(std::string course_name);

    void printSchedule();

    // Outros métodos utilitários necessários
    // para auxiliar nas funções requisitadas
};