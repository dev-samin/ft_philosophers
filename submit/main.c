/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 21:24:07 by samin             #+#    #+#             */
/*   Updated: 2021/09/30 19:51:37 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philosophers_info	philosophers_info;

	if (argc < 5 || argc > 6)
		exit(0);
	check_str_num(argc, argv);
	init(argc, argv, &philosophers_info);
	init_philosophers_info(&philosophers_info);
	init_philosopher(&philosophers_info);
	init_thread(&philosophers_info);
	return (0);
}
