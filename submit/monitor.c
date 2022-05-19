/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 10:23:39 by samin             #+#    #+#             */
/*   Updated: 2021/09/30 20:23:23 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	single_monitor(t_philosopher *philo)
{
	long long	monitor_time;

	while (1)
	{
		monitor_time = get_mstime();
		philo->starve_time = monitor_time - philo->eating_start_time;
		if (philo->status == 1)
		{
			philo->rule_info->eatting_done_count++;
			if (philo->rule_info->eatting_done_count
				== philo->rule_info->number_of_philosophers)
				philosopher_print(philo, "end of meal");
			return ;
		}
		if (philo->starve_time > philo->rule_info->time_to_die)
		{
			philosopher_print(philo, "died");
			philo->rule_info->death = 1;
			return ;
		}
		usleep(100);
	}
	return ;
}
