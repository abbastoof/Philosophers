/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:28:29 by atoof             #+#    #+#             */
/*   Updated: 2023/07/25 17:56:21 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static u_int64_t	get_time_micro(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000000ULL) + tv.tv_usec);
}
