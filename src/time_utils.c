/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:28:29 by atoof             #+#    #+#             */
/*   Updated: 2023/07/27 18:33:06 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*		time.tv_sec * 1000: 
	This converts seconds to milliseconds.
	time.tv_usec / 1000: This converts microseconds to milliseconds.
	(time.tv_sec * 1000) + (time.tv_usec / 1000):
	This adds the converted seconds and converted
	microseconds together to get the total time in milliseconds.
	Therefore, the function get_time returns time in milliseconds.*/

u_int64_t	get_time_micro(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000000ULL) + tv.tv_usec);
}

u_int64_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(t_philo *philo, u_int64_t time)
{
	u_int64_t	loop;

	loop = get_time_micro() + (time * 1000);
	while ((check_finish(philo, 0) == 0) && get_time_micro() < loop)
		usleep(500);
}
