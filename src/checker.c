/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:40:17 by atoof             #+#    #+#             */
/*   Updated: 2023/07/25 14:16:34 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <stdlib.h>

static int	check_positive_num(int argc, char **argv)
{
	int	indx;
	int	num;

	indx = 1;
	while (indx < argc)
	{
		num = ft_atoi(argv[indx]);
		if (num <= 0)
		{
			printf("Error: Argument at index %d must" \
					" be a positive integer > 0\n", indx);
			return (-1);
		}
		indx++;
	}
	return (1);
}

static int	is_digit_argv(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '+' || argv[i][j] == '-')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				printf("Argument %d: Please enter only digits.\n", i);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	checker(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("Invalid args\n");
		printf("./philo philo_num time_to_die time_to_eat" \
				" time_sleep (optional) meal_num \n");
		return (-1);
	}
	if (is_digit_argv(argc, argv) == -1)
		return (-1);
	if (check_positive_num(argc, argv) == -1)
		return (-1);
	return (0);
}
