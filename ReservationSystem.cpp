#include <iostream>
#include "ReservationRequest.hpp"
using namespace std;

class Horario {
private:
    int hora;
    bool reservado;

public:
    Horario(){
        hora = 0;
    };

    void def_hora(int h){
        hora = h;
    }

    void reservarHorario(){
        this->reservado = true;
    }
    bool getReservado(){
        return this->reservado;
    }
    int getHora(){
        return this->hora;
    }
};

class Dia {
private:
    static const int horas_totais = 15;
    string nome_dia;
    
    public:
    Horario horas_uteis[horas_totais];
    Dia(string nome_dia){
        this->nome_dia = nome_dia;
        for (int i = 0; i < horas_totais; i++) {
            horas_uteis[i].def_hora(7 + i);
        }
    };
    string getDia(){
        return this->nome_dia;
    }
};

class Sala {

    int capacidade;
    int numero_sala;
    Dia dias[5] = {Dia("Segunda"), Dia("Terca"), Dia("Quarta"), Dia("Quinta"), Dia("Sexta")};

public:
    Sala(){}

    Sala(int capacidade, int numero){
        this->capacidade = capacidade;
        this->numero_sala = numero;
    }

    void display(){
        cout << "Sala " << this->numero_sala << endl;
        cout << "Capacidade: " << this->capacidade << endl;
    }
    
    int getCapacidade(){
        return this->capacidade;
    }

    bool estaLivre(int dia, int inicio, int fim){
        for(int i = inicio; i < fim; i++){
            if(this->dias[dia].horas_uteis[i-7].getReservado()){
                return false;
            }
            else{
                return true;
            }
        }
    }

    void reservar(int dia, int inicio, int fim){
        for(int i = inicio; i < fim; i++){
            this->dias[dia].horas_uteis[i-7].reservarHorario();
        }
    }

};

class ReservationSystem {

public:
    int room_count;
    int* room_capacities;
    Sala* salas;

    // Estruturas internas escolhidas pelos alunos
    // para armazenar e gerenciar as reservas, os horários, ...


    ReservationSystem(int room_count, int* room_capacities){
        this->room_count = room_count;
        this->room_capacities = room_capacities;

        salas = new Sala[room_count];

        for(int i = 0; i < room_count; i++){
            salas[i] = Sala(room_capacities[i], i);
        }
    }

    ~ReservationSystem(){
        delete[] salas;
    }

    bool reserve(ReservationRequest request){
        // verificação se o fim da aula é posterior ao início
        int inicio = request.getStartHour();
        int fim = request.getEndHour();
        int dia = request.getWeekdayIndex();

        if(fim <= inicio){
            return false;
        }

        for(int i = 0; i < this->room_count; i++){
            if(request.getStudentCount() > salas[i].getCapacidade()){
                continue;
            }
            if(salas[i].estaLivre(dia, inicio, fim)){
                salas[i].reservar(dia, inicio, fim);
            }
        }
    }
    bool cancel(std::string course_name);

    void printSchedule();

    // Outros métodos utilitários necessários
    // para auxiliar nas funções requisitadas
};