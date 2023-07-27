/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:18:33 by atoof             #+#    #+#             */
/*   Updated: 2023/07/27 18:29:27 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_msg(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->data->print);
	if (check_finish(philo, 0))
	{
		pthread_mutex_unlock(&philo->data->print);
		return ;
	}
	printf("%llu %d %s\n", (get_time_micro() / 1000) - philo->data->start_time, \
			philo->id, msg);
	pthread_mutex_unlock(&philo->data->print);
	usleep(100);
}

void	action(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork[philo->id - 1]);
	print_msg(philo, "has taken a fork");
	pthread_mutex_lock(&philo->data->fork[philo->id % philo->data->philo_num]);
	print_msg(philo, "has taken a fork");
	print_msg(philo, "is eating");
	pthread_mutex_lock(&philo->data->eating);
	philo->meal_count += 1;
	philo->last_meal = get_time_micro() / 1000;
	pthread_mutex_unlock(&philo->data->eating);
	ft_usleep(philo, philo->data->eat_time);
	pthread_mutex_unlock(&philo->data->fork[philo->id \
			% philo->data->philo_num]);
	pthread_mutex_unlock(&philo->data->fork[philo->id - 1]);
	print_msg(philo, "is sleeping");
	ft_usleep(philo, philo->data->sleep_time);
	print_msg(philo, "is thinking");
}

void	*philo_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	print_msg(philo, "is thinking");
	if (philo->id % 2 == 0)
		ft_usleep(philo, philo->data->eat_time);
	while (1)
	{
		if (check_finish(philo, 0))
			return (NULL);
		action(philo);
	}
	return (NULL);
}

int	create_threads(t_gen_data *data)
{
	int	indx;

	indx = 0;
	data->start_time = get_time_micro() / 1000;
	while (indx < data->philo_num)
	{
		data->philo_info[indx].last_meal = data->start_time;
		if (pthread_create(&data->thread[indx], NULL, &philo_routine,
				&data->philo_info[indx]) != 0)
			return (-1);
		indx++;
	}
	return (0);
}
