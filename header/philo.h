/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:28:01 by atoof             #+#    #+#             */
/*   Updated: 2023/07/24 16:27:13 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_gen_data
{
	u_int64_t			start_time;
	u_int64_t			death_time;
	u_int64_t			eat_time;
	u_int64_t			sleep_time;
	int					philo_num;
	int					meal_num;
	pthread_t			*thread;
	pthread_mutex_t		*fork;
	struct s_philo		*philo;
}						t_gen_data;

typedef struct s_philo
{
	u_int64_t			last_meal;
	int					meal_count;
	int					id;
	struct s_gen_data	*data;
}						t_philo;

int						checker(int argc, char **argv);
int						ft_atoi(const char *str);


#endif