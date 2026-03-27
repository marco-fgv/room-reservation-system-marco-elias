#include <iostream>
using namespace std;

class Sala {

    int capacidade;
    string numero_sala;

public:

    Sala(int capacidade, string numero){
        this->capacidade = capacidade;
        this->numero_sala = numero;
    }

    void display(){
        cout << "Sala" << this->numero_sala << endl;
        cout << "Capacidade:" << this->numero_sala << endl;
    }
    
    int getCapacidade(){
        return this->capacidade;
    }
};
