/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:19:32 by atoof             #+#    #+#             */
/*   Updated: 2023/07/27 13:10:28 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_gen_data	gen_data;

	(void)argv;
	if (checker(argc, argv) == -1)
		return (-1);
	if (init_data(argc, argv, &gen_data) == -1)
		return (-1);
	create_threads(&gen_data);
	monitoring(&gen_data);
	return (0);
}
