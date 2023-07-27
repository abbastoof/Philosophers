/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:11:12 by atoof             #+#    #+#             */
/*   Updated: 2023/07/27 17:42:44 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_finish(t_philo *philo, int exit_flag)
{
	pthread_mutex_lock(&philo->data->finish_mutex);
	if (exit_flag || philo->data->must_exit)
	{
		if (exit_flag)
			philo->data->must_exit = 1;
		pthread_mutex_unlock(&philo->data->finish_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->finish_mutex);
	return (0);
}

static int	lifetime_philo(t_philo philo)
{
	pthread_mutex_lock(&philo.data->eating);
	if ((get_time_micro() / 1000) - \
		philo.last_meal >= philo.data->death_time)
	{
		printf("%lld %d died\n", (get_time_micro() / 1000) \
				- philo.data->start_time, philo.id);
		check_finish(&philo, 1);
		if (philo.data->philo_num == 1)
			pthread_mutex_unlock(&philo.data->fork[0]);
		pthread_mutex_unlock(&philo.data->eating);
		return (1);
	}
	if (philo.data->meal_num > 0 && philo.meal_count >= philo.data->meal_num)
	{
		philo.data->max_eat += 1;
		if (philo.data->max_eat >= philo.data->philo_num)
		{
			check_finish(philo.data->philo_info, 1);
			pthread_mutex_unlock(&philo.data->eating);
			return (1);
		}
	}
	pthread_mutex_unlock(&philo.data->eating);
	return (0);
}

int	monitoring(t_gen_data *data)
{
	int	indx;
	int	flag;

	flag = 1;
	while (flag)
	{
		indx = 0;
		data->max_eat = 0;
		while (indx < data->philo_num)
		{
			if (lifetime_philo(data->philo_info[indx]))
			{
				flag = 0;
				break ;
			}
			indx++;
		}
		usleep(500);
	}
	free_malloc(data);
	return (0);
}
