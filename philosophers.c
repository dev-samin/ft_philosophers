/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 21:24:07 by samin             #+#    #+#             */
/*   Updated: 2021/07/28 16:39:58 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		main(int argc, char **argv)
{
	t_philosophers_info philosophers_info;

	init(argc, argv, &philosophers_info);
	init_philosophers_info(&philosophers_info);
	init_philosopher(&philosophers_info);
	init_thread(&philosophers_info);

    return (0);
}
