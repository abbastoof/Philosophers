/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:19:32 by atoof             #+#    #+#             */
/*   Updated: 2023/07/24 15:57:14 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
		Here's a breakdown of the function parameters:
		pthread_t *restrict thread:
		This is a pointer to a pthread_t variable
		where the function will store the identifier of
		the newly created thread.
		The identifier serves as a handle that can be used
		to manipulate or join the thread later.

		const pthread_attr_t *restrict attr: 
		This parameter is used to specify the attributes
		of the thread being created.
		It's a pointer to a pthread_attr_t structure
		that contains various attributes
		related to the thread, such as its stack size,
		scheduling policy, etc.
		If you pass NULL as the argument,
		the thread will be created with the default attributes.

		void *(*start_routine)(void *):
		This is a pointer to the function that will be executed
		by the newly created thread.
		The function should have a return type of void* and take
		a single void* argument.
		It is common to use this argument to pass data or a structure
		to the thread function.

		void *restrict arg:
		This is the argument that will be passed to the start_routine function
		when the new thread starts executing.
		It can be a pointer to any data you want to pass
		to the thread function,
		and you can cast it appropriately within the start_routine
		function to use the data.

		When you call pthread_create,
			it creates a new thread that will begin executing
		the function specified by start_routine with the
		provided argument arg.
		The new thread runs independently alongside the main thread
		and any other threads in the program,
		allowing for concurrent execution.
*/

// int	pthread_create(pthread_t *restrict thread,
// 		const pthread_attr_t *restrict attr, void *(*start_routine)(void *),
// 		void *restrict arg);

int	main(int argc, char **argv)
{
	(void)argv;
	if (checker(argc, argv) == -1)
		printf("Please enter positive number\n");
	return (0);
}
