/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:28:01 by atoof             #+#    #+#             */
/*   Updated: 2023/07/26 18:13:17 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# define ERROR -1
# define TRUE 1
# define FALSE 0

typedef struct s_gen_data
{
	int					philo_num;
	u_int64_t			death_time;
	u_int64_t			eat_time;
	u_int64_t			sleep_time;
	int					meal_num;
	u_int64_t			start_time;
	pthread_t			*thread;
	pthread_mutex_t		*fork;
	pthread_mutex_t		print;
	pthread_mutex_t		eating;
	struct s_philo		*philo_info;
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
int						ft_isdigit(int c);
int						init_data(int argc, char **argv, t_gen_data *gen_data);
int						create_threads(t_gen_data *philo);
void					free_malloc(t_gen_data *gen_data);
u_int64_t				get_time_micro(void);
void					ft_usleep(u_int64_t time);

#endif