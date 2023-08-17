# Philosophers

This project is an implementation of the dining philosophers problem using the pthreads library in C. Philosophers sit at a round table and do one of three things: eat, sleep, or think. While eating, they need two forks (one from their left and one from their right). The challenge is to avoid deadlock and make sure no philosopher starves.

## Table of Contents

- [Philosophers](#philosophers)
  - [Table of Contents](#table-of-contents)
  - [Compilation](#compilation)
  - [Usage](#usage)
  - [Code Structure](#code-structure)

## Compilation

To compile, you'll need to have the `pthread` library installed on your system. Use the following command:

```bash
gcc -Wall -Wextra -Werror -pthread *.c -o philo
```

## Usage

After compilation, run the program as follows:

```bash
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [optional: number_of_times_each_philosopher_must_eat]
```

- `number_of_philosophers`: Number of philosophers and also the number of forks.
- `time_to_die`: Time in milliseconds a philosopher waits after eating before dying of starvation.
- `time_to_eat`: Time in milliseconds it takes a philosopher to eat.
- `time_to_sleep`: Time in milliseconds a philosopher sleeps.
- `number_of_times_each_philosopher_must_eat`: (Optional) If all philosophers eat at least this many times, the simulation will stop.

## Code Structure

- **philo.h**: Header file containing required includes, defines, and data structure definitions.
  
- **checker.c**: Validates the arguments provided to the program.
  
- **actions.c**: Contains functions to perform philosopher's activities like eating, sleeping, and thinking.

- **memory.c**: Contains functions to allocate and deallocate memory, initialize and destroy mutexes.
  
- **utils.c**: Utility functions including integer to ASCII conversion and digit checking.
  
- **init.c**: Initializes the program's data structures.
  
- **main.c**: Entry point of the program, setting up threads for each philosopher.
  
- **monitor.c**: Monitors the philosophers to check if they're alive or if they've eaten the required number of times.

- **time.c**: Contains time-related utility functions.
