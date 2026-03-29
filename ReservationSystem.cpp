#include <iostream>
#include "ReservationRequest.hpp"
#include "ReservationSystem.hpp"
#include "Estrutura.hpp"
using namespace std;

// ======================================================
// Classe sistema
// ======================================================
ReservationSystem::ReservationSystem(int room_count, int* room_capacities){
    this->room_count = room_count;
    this->room_capacities = room_capacities;

    salas = new Sala[room_count];

    for(int i = 0; i < room_count; i++){
        // Criação das salas
        salas[i] = Sala(room_capacities[i], i);
    }
}

ReservationSystem::~ReservationSystem(){
    delete[] salas;
}

bool ReservationSystem::reserve(ReservationRequest request){
    string nome_curso = request.getCourseName();
    int inicio = request.getStartHour();
    int fim = request.getEndHour();
    int dia = request.getWeekdayIndex();
    
    // verificação se o fim da aula é posterior ao início e está no intervalo correto
    if(fim <= inicio || fim > 21 || inicio < 7){
        return false;
    }

    // Percorre, no pior dos casos, todas as salas
    for(int i = 0; i < this->room_count; i++){
        // verificação da capacidade
        if(request.getStudentCount() > salas[i].getCapacidade()){
            continue;
        }
        // verificação se no horario solicitado a sala está livre
        if(salas[i].estaLivre(dia, inicio, fim)){
            salas[i].reservar(dia, inicio, fim, nome_curso);
            return true;
        }
    }
    return false;
}

bool ReservationSystem::cancel(string course_name){
    bool foiCancelado = false;

    // Percorre todas as salas e chama o método que procura se há a ocorrencia dessa aula
    for(int i = 0; i < room_count; i++){
        if(salas[i].cancelar(course_name)){
            foiCancelado = true;
        }
    }

    return foiCancelado;
}

void ReservationSystem::printSchedule(){
    for(int i = 0; i < this->room_count; i++){
        if(!this->salas[i].SalaPossuiReserva()){
            continue;
        }
        this->salas[i].display();
        cout << endl;
    }
}