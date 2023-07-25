/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:19:32 by atoof             #+#    #+#             */
/*   Updated: 2023/07/25 17:56:53 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *data)
{
	(void)data;
	printf("test from threads\n");
	sleep(1);
	printf("Ending thread\n");
	return (NULL);
}

static int	create_thread(void)
{
	
	return (0);
}

int	main(int argc, char **argv)
{
	t_gen_data	gen_data;

	(void)argv;
	if (checker(argc, argv) == -1)
		return (-1);
	if (init_data(argc, argv, &gen_data) == -1)
		return (-1);
	create_thread(&gen_data);
	return (0);
}
