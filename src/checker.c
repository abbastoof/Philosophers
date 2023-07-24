/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:40:17 by atoof             #+#    #+#             */
/*   Updated: 2023/07/24 16:47:06 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <stdlib.h>

int	check_positive_num(int argc, char **argv)
{
	int		indx;
	int		num;
	char	**args;

	args = {"philo_num",
		"time_to_die",
		"time_to_eat",
		"time_sleep",
		"meal_num"};
	indx = 0;
	while (indx < argc)
	{
		num = atoi(argv[indx]);
		if (num < 0)
		{
			printf("Number of \
					%s is negative.Please enter a positive number.\n ", \
					args[indx]);
			return (-1);
		}
		indx++;
	}
	return (1);
}

int	checker(int argc, char **argv)
{
	(void)argv;
	if (argc < 5 || argc > 6)
	{
		printf("Invalid args\n");
		printf("./philo philo_num time_to_die time_to_eat \
				time_sleep (optional) meal_num \n");
		return (-1);
	}
	check_positive_num(argc, argv);
	return (0);
}
