/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:24:30 by atoof             #+#    #+#             */
/*   Updated: 2023/07/25 18:04:07 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	mutex_init(t_gen_data *gen_data)
{
	int	indx;

	indx = 0;
	while (++indx <= gen_data->philo_num)
	{
		if (pthread_mutex_init(&(gen_data->fork[indx]), NULL) != 0)
		{
			printf("init mutex error\n");
			return (-1);
		}
	}
	if (pthread_mutex_init(&(gen_data->print), NULL) != 0)
	{
		printf("init mutex error\n");
		return (-1);
	}
	if (pthread_mutex_init(&(gen_data->eating), NULL) != 0)
	{
		printf("init mutex error\n");
		return (-1);
	}
	return (0);
}

static int	malloc_gen_data(t_gen_data *gen_data)
{
	gen_data->thread = malloc(sizeof(pthread_t) * gen_data->philo_num);
	if (!gen_data->thread)
	{
		printf("malloc\n");
		return (-2);
	}
	gen_data->fork = malloc(sizeof(pthread_mutex_t) * gen_data->philo_num);
	if (!gen_data->fork)
	{
		printf("malloc\n");
		return (-2);
	}
	gen_data->philo_info = malloc(sizeof(t_philo) * gen_data->philo_num);
	if (!gen_data->philo_info)
	{
		printf("malloc\n");
		return (-2);
	}
	return (0);
}

int	init_data(int argc, char **argv, t_gen_data *gen_data)
{
	gen_data->philo_num = ft_atoi(argv[1]);
	if (gen_data->philo_num > 200)
	{
		printf("Philo number should be <= 200\n");
		return (-1);
	}
	gen_data->death_time = ft_atoi(argv[2]);
	gen_data->eat_time = ft_atoi(argv[3]);
	gen_data->sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
		gen_data->meal_num = ft_atoi(argv[5]);
	else
		gen_data->meal_num = -1;
	if (malloc_gen_data(gen_data) == -2)
		return (-2);
	if (mutex_init(gen_data) == -1)
		free_malloc(gen_data);
	return (0);
}
