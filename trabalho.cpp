#include <iostream>
using namespace std;

class Horario {
public:
    int hora;
    bool reservado;

    Horario(){
        hora = 0;
        reservado = false;
    };

    void def_hora(int h){
        hora = h;
    }
};

class Dia {
private:
    static const int horas_totais = 15;
    Horario horas_uteis[horas_totais];
    
public:
    string nome_dia;

    Dia(){
        for (int i = 0; i < horas_totais; i++) {
            horas_uteis[i].def_hora(7 + i);
        }
    };

};