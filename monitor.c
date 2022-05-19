/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moniter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 10:23:39 by samin             #+#    #+#             */
/*   Updated: 2021/07/11 11:54:27 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	single_monitor(t_philosopher *philo)
{
	long long monitor_time;
	
	while (1)
	{
		monitor_time = get_mstime();
		philo->starve_time = monitor_time - philo->eating_start_time;
		if (philo->rule_info->eatting_done_count == philo->rule_info->number_of_philosophers)
		{
			philosopher_print(philo, "다먹음");
			break ;
		}
		if ((philo->starve_time) > philo->rule_info->time_to_die) // 죽었을때.
		{
			philosopher_print(philo, "died");
			philo->rule_info->death = 1;
			return ;
		}
		if (philo->status == 1) 
			return ;
		usleep(100);
	}
	return ;
}
