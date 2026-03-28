#include <iostream>
#include "ReservationRequest.hpp"
using namespace std;

// ======================================================
// Classe Dia
// ======================================================
class Dia {
private:
    string nome_dia;
    bool horas_uteis[14];
    string cursos[14];

public:
    Dia(string nome_dia){
        this->nome_dia = nome_dia;

        for (int i = 0; i < 14; i++){
            // inicia com todos horários livres
            this->horas_uteis[i] = false;
            this->cursos[i] = "livre";
        }
    }

    string getDia(){
        return this->nome_dia;
    }

    void reservarHorario(int horario, string nome_curso){
        this->horas_uteis[horario-7] = true;
        this->cursos[horario-7] = nome_curso;
    }

    void cancelarHorario(int horario){
        this->horas_uteis[horario-7] = false;
        this->cursos[horario-7] = "livre";
    }

    bool getReservado(int indice){
        return horas_uteis[indice];
    }

    bool possuiReserva(){
        // Verifica se nesse dia possui alguma reserva para montar o schedule
        for(int i = 0; i < 14; i++){
            if(horas_uteis[i] == true){
                return true;
            }
        }
        return false;
    }

    string getCurso(int i){
        return this->cursos[i];
    }
};

// ======================================================
// Classe Sala
// ======================================================
class Sala {

    int capacidade;
    int numero_sala;
    Dia dias[5] = {Dia("segunda"), Dia("terca"), Dia("quarta"), Dia("quinta"), Dia("sexta")};

public:
    Sala(){}

    Sala(int capacidade, int numero){
        this->capacidade = capacidade;
        this->numero_sala = numero;
    }

    void display(){
        cout << "Sala " << this->numero_sala << endl;
        for(int i = 0; i < 5; i++){
            // Dias que não possuem reserva não são printados
            if(!this->dias[i].possuiReserva()){
                continue;
            }

            cout << this->dias[i].getDia() << endl;
            
            for(int j = 0; j < 14; j++){
                if(this->dias[i].getReservado(j)){
                }
            }
        }
    }
    
    int getCapacidade(){
        return this->capacidade;
    }

    bool estaLivre(int dia, int inicio, int fim){
        for(int i = inicio; i < fim; i++){
            if(this->dias[dia].getReservado(i)){
                return false;
            }
        }
        return true;
    }

    void reservar(int dia, int inicio, int fim, string nome_curso){
        for(int i = inicio; i < fim; i++){
            this->dias[dia].reservarHorario(i, nome_curso);
        }
    }

};

// ======================================================
// Classe sistema
// ======================================================
class ReservationSystem {

public:
    int room_count;
    int* room_capacities;
    Sala* salas;

    ReservationSystem(int room_count, int* room_capacities){
        this->room_count = room_count;
        this->room_capacities = room_capacities;

        salas = new Sala[room_count];

        for(int i = 0; i < room_count; i++){
            // Criação das salas
            salas[i] = Sala(room_capacities[i], i);
        }
    }

    ~ReservationSystem(){
        delete[] salas;
    }

    bool reserve(ReservationRequest request){
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
    bool cancel(std::string course_name);

    void printSchedule();

    // Outros métodos utilitários necessários
    // para auxiliar nas funções requisitadas
};
