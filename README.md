#  Room Reservation System

**Trabalho de Elias Vieira Moraes e Marco Túlio Pereira Silva**

---

##  Descrição do Projeto

Neste trabalho, foi implementado um sistema simples para gerenciamento da alocação de disciplinas em salas de aula ao longo de uma semana.

Um usuário solicita a reserva de uma sala informando um **dia da semana** e um **intervalo de horário** para ministrar uma disciplina. O sistema então **verifica automaticamente** se existe alguma sala disponível naquele período.

- Caso existam salas disponíveis que comportem a disciplina, uma reserva é criada automaticamente  
- Caso contrário, o sistema informa a indisponibilidade de salas naquele horário  

Cada reserva corresponde a:
- Uma única disciplina  
- Um único dia da semana  
- Um intervalo contínuo de tempo  

---

##  Instruções de Compilação

### Pré-requisitos
- Compilador com suporte a **C++17 ou superior**

### Comando de compilação

```bash
g++ main.cpp ReservationSystem.cpp ReservationRequest.cpp -o reservation_system
```

## Instruções de Execução

### Windows
```bash
.\reservation_system.exe
```

### Linux
```bash
./reservation_system
```

## Organização dos Dados

A estrutura interna do sistema segue a seguinte hierarquia:

```txt
ReservationSystem
    └── Sala
            └── Dia
                    └── horarios
