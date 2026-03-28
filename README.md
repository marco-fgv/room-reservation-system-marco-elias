# room-reservation-system-marco-elias
Trabalho de Elias Vieira Moraes e Marco Tulio Pereira Silva 

### Descrição do Projeto:

Neste trabalho, foi implementado um sistema simples para gerenciamento a alocação de disciplinas em salas de aula durante uma semana. 

Um usuário solicita a reserva de uma sala para ministrar uma disciplina em um determinado dia da semana e intervalo de horário. O sistema então verificar automaticamente se existe alguma sala disponível naquele período.

Caso existam salas disponíveis que comportem a disciplina, uma reserva é automaticamente criada. Caso contrário, o sistema informa sobre a indisponibilidade de salas naquele horário.

Cada reserva corresponde a uma única disciplina em um único dia da semana, ocupando um intervalo contínuo de tempo.

### Instruções de Compilação:

- **Pré-Requisitos:**
  - C++17 ou superior

- **Compilação:**
'''
g++ main.cpp ReservationSystem.cpp ReservationRequest.cpp -o reservation_system
'''

### Instruções de Execução:
- **Execução**
'''
.\reservation_system.exe
'''

### Organização dos Dados:

'''
ReservationSystem
    └── Sala
            └── Dia
                    └── horarios
'''
