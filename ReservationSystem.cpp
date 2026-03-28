#include <iostream>
#include "ReservationRequest.hpp"
#include "ReservationSystem.hpp"

using namespace std;

// ======================================================
// Classe Dia
// ======================================================
Dia::Dia(){}
Dia::Dia(string nome_dia){
    this->nome_dia = nome_dia;

    for (int i = 0; i < 14; i++){
        // inicia com todos horários livres
        this->horas_uteis[i] = false;
        this->cursos[i] = "livre";
    }
}

string Dia::getDia(){
    return this->nome_dia;
}

void Dia::reservarHorario(int horario, string nome_curso){
    this->horas_uteis[horario-7] = true;
    this->cursos[horario-7] = nome_curso;
}

void Dia::cancelarHorario(int horario){
    this->horas_uteis[horario-7] = false;
    this->cursos[horario-7] = "livre";
}

bool Dia::getReservado(int horario){
    return horas_uteis[horario-7];
}

bool Dia::possuiReserva(){
    // Verifica se nesse dia possui alguma reserva para montar o schedule
    for(int i = 0; i < 14; i++){
        if(horas_uteis[i]){
            return true;
        }
    }
    return false;
}

string Dia::getCurso(int i){
    return this->cursos[i];
}

// ======================================================
// Classe Sala
// ======================================================
Sala::Sala(){}

Sala::Sala(int capacidade, int numero){
    this->capacidade = capacidade;
    this->numero_sala = numero+1;
    dias[0] = Dia("segunda");
    dias[1] = Dia("terca");
    dias[2] = Dia("quarta");
    dias[3] = Dia("quinta");
    dias[4] = Dia("sexta");
}

void Sala::display(){
    cout << "Sala " << this->numero_sala << endl;
    for(int i = 0; i < 5; i++){
        // Dias que não possuem reserva não são printados
        if(!this->dias[i].possuiReserva()){
            continue;
        }
        
        // Printa o dia da semana que possui alguma reserva
        cout << this->dias[i].getDia() << endl;
        
        int j = 0;
        while (j < 14){
            // 'for' segmentado para ver quando começa e termina uma aula
            if(!this->dias[i].getReservado(j+7)){
                j++;
                continue;
            }
            string curso = this->dias[i].getCurso(j);
            
            // inicio da aula
            int inicio = j;
            
            // verifica ate onde vai a aula
            int k = j;
            while(k < 14 && this->dias[i].getCurso(k) == curso){
                k++;
            }
            // fim da aula
            int fim = k;

            cout << inicio + 7 << "h~" << fim + 7 << "h: " << curso << endl;
            
            // pula as posições ja visitadas
            j = k;
        }            
    }
}

int Sala::getCapacidade(){
    return this->capacidade;
}

bool Sala::estaLivre(int dia, int inicio, int fim){
    // Verifica se há conflito
    for(int i = inicio; i < fim; i++){
        if(this->dias[dia].getReservado(i)){
            return false;
        }
    }
    return true;
}

void Sala::reservar(int dia, int inicio, int fim, string nome_curso){
    for(int i = inicio; i < fim; i++){
        this->dias[dia].reservarHorario(i, nome_curso);
    }
}

bool Sala::cancelar(string nome_curso){
    bool cancelado = false;
    for(int i = 0; i < 5; i++){

        for(int j = 0; j < 14; j++){

            if(this->dias[i].getCurso(j) == nome_curso){
                this->dias[i].cancelarHorario(j+7);
                cancelado = true;
            }
        }
    }
    return cancelado;
}

bool Sala::SalaPossuiReserva(){
    for(int i = 0; i < 5; i++){
        if(this->dias[i].possuiReserva()){
            return true;
        }
    }
    return false;
}

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
    
    // verificação se o fim da aula é posterior ao início
    if(fim <= inicio){
        return false;
    }

    for(int i = 0; i < this->room_count; i++){
        if(request.getStudentCount() > salas[i].getCapacidade()){
            continue;
        }
        if(salas[i].estaLivre(dia, inicio, fim)){
            salas[i].reservar(dia, inicio, fim, nome_curso);
            return true;
        }
    }
    return false;
}

bool ReservationSystem::cancel(string course_name){
    bool foiCancelado = false;

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

