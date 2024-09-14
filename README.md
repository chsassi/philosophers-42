# Philosophers (42 School)

🇬🇧🇺🇸

Philosophers project is part of the 42 curriculum and aims to deepen knowledge of concurrency, multithreading, and process synchronization. 
Inspired by the classic "Dining Philosophers Problem," the task is to simulate a situation where several philosophers alternate between thinking, eating, and sleeping, but must share a limited number of forks (resources) for eating. The challenge is to manage this situation without causing a deadlock, while ensuring that all philosophers get a chance to eat.

Through this project, you will learn about:
- Threads and mutexes
- Synchronization techniques
- Avoiding deadlocks
- Resource allocation

🇮🇹

Il progetto Philosophers fa parte del curriculum della Scuola 42 e ha lo scopo di approfondire la conoscenza della concorrenza, del multithreading e della sincronizzazione dei processi. 
Ispirato al classico "Problema dei Filosofi a Cena," il compito è simulare una situazione in cui diversi filosofi alternano momenti di riflessione, mangiare e dormire, ma devono condividere un numero limitato di forchette (risorse) per mangiare. La sfida consiste nel gestire questa situazione senza causare un deadlock, garantendo allo stesso tempo che tutti i filosofi abbiano l'opportunità di mangiare.

Attraverso questo progetto, imparerai:
- Thread e mutex
- Tecniche di sincronizzazione
- Come evitare deadlock
- Allocazione delle risorse


Evaluation: 100/100

### Compilation:
```bash
make

Execution:

bash

./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

    number_of_philosophers: The number of philosophers and forks.
    time_to_die: Time (in milliseconds) until a philosopher dies if they don’t start eating.
    time_to_eat: Time (in milliseconds) a philosopher takes to eat.
    time_to_sleep: Time (in milliseconds) a philosopher spends sleeping.
    [number_of_times_each_philosopher_must_eat]: Optional, the number of times each philosopher must eat before the simulation ends.
