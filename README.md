# Philosophers

This project is an implementation of the dining philosophers problem using the pthreads library in C. Philosophers sit at a round table and do one of three things: eat, sleep, or think. While eating, they need two forks (one from their left and one from their right). The challenge is to avoid deadlock and make sure no philosopher starves.

## Table of Contents

- [Philosophers](#philosophers)
  - [Table of Contents](#table-of-contents)
  - [Compilation and Build](#compilation-and-build)
  - [Usage](#usage)
  - [Code Structure](#code-structure)

## Compilation and Build

The following commands can be used with the Makefile:

1. To compile and build the project:
   ```bash
   make
   ```

2. To remove all the object files:
   ```bash
   make clean
   ```

3. To remove all the object files and the binary:
   ```bash
   make fclean
   ```

4. To recompile the whole project:
   ```bash
   make re
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

   - **ft_isdigit.c**: A function to check if a character is a digit.

   - **ft_atoi.c**: An implementation of the atoi function which converts a string to an integer.

   - **free_malloc.c**: Memory management functions related to dynamic memory allocation and deallocation.

   - **init_data.c**: Initializes data structures or values required for the program.

   - **main.c**: Entry point of the program.

   - **create_threads.c**: Creates threads for parallel execution of tasks.

   - **monitoring.c**: Functions related to the oversight or management of threads or processes.

   - **time_utils.c**: Utility functions related to time.
