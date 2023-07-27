/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:02:20 by atoof             #+#    #+#             */
/*   Updated: 2023/07/27 16:37:10 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_gen_data(t_gen_data *gen_data)
{
	if (gen_data->thread != NULL)
	{
		free(gen_data->thread);
		gen_data->thread = NULL;
	}
	if (gen_data->fork != NULL)
	{
		free(gen_data->fork);
		gen_data->fork = NULL;
	}
	if (gen_data->philo_info != NULL)
	{
		free(gen_data->philo_info);
		gen_data->philo_info = NULL;
	}
	// free(gen_data);
}

static void	join(t_gen_data *gen_data)
{
	int	indx;

	indx = -1;
	while (++indx < gen_data->philo_num)
		pthread_join(gen_data->thread[indx], NULL);
}

static void	destroy_mutexes(t_gen_data *gen_data)
{
	int	indx;

	indx = -1;
	while (++indx <= gen_data->philo_num)
		pthread_mutex_destroy(&(gen_data->fork[indx]));
	pthread_mutex_destroy(&(gen_data->print));
	pthread_mutex_destroy(&(gen_data->eating));
	pthread_mutex_destroy(&(gen_data->finish_mutex));
}

void	free_malloc(t_gen_data *gen_data)
{
	if (gen_data->philo_num == 1)
		pthread_mutex_unlock(&gen_data->fork[0]);
	if (gen_data != NULL)
	{
		join(gen_data);
		destroy_mutexes(gen_data);
		free_gen_data(gen_data);
	}
}
