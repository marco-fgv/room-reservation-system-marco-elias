#include <iostream>
#include "ReservationRequest.hpp"
using namespace std;
class Sala {

    int capacidade;
    int numero_sala;
    Dia dias[5];

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

};

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
};

class Dia {
private:
    static const int horas_totais = 15;
    Horario horas_uteis[horas_totais];
    string nome_dia;
    
public:
    Dia(){}
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
        for(int i = 0; i < this->room_count; i++){
        }
    }
    bool cancel(std::string course_name);

    void printSchedule();

    // Outros métodos utilitários necessários
    // para auxiliar nas funções requisitadas
};

int main(){
    int capacidades[3] = {100, 200, 300};
    Dia dias[5] = {Dia("Segunda"), Dia("Terça"), Dia("Quarta"), Dia("Quinta"), Dia("Sexta")};

    ReservationSystem sistema(3, capacidades);

    ReservationRequest request("AL", "Segunda", 7, 9, 10);
}