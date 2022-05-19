/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moniter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 10:23:39 by samin             #+#    #+#             */
/*   Updated: 2021/07/09 17:00:44 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	moniter(t_philosophers_info *philosophers_info, t_rule_info rule_info)
{
	int i = -1;
	long long tmp_time;
	
	usleep(10);
	while (1)
	{
		i = -1;
		while (++i < rule_info.number_of_philosophers)
		{
			if ((philosophers_info->philosopher[i].starve_time) >= rule_info.time_to_die)
			{
				printf("[tmp time = %lld] [eating_start_time = %lld] [starve_time = %lld]\n",  tmp_time,
						philosophers_info->philosopher[i].eating_start_time,
						philosophers_info->philosopher[i].starve_time);
				philosopher_print(&philosophers_info->philosopher[i], "died");
				int j = -1;
				return ;
			}
			if (philosophers_info->philosopher[i].status == 1)
			{
				int j = -1;
				// int status;
				
				while (++j < rule_info.number_of_philosophers)
				{
					printf("/%d = %d/ \n",j, philosophers_info->philosopher[i].status);
					// pthread_join(philosophers_info->threads[j], (void **)&status);
				}
				pthread_mutex_lock(&philosophers_info->mutex_print);
				printf("\n`%d 다먹음\n", philosophers_info->philosopher[i].philo_num);
				pthread_mutex_unlock(&philosophers_info->mutex_print);
				return ;
			}
			tmp_time = get_mstime();
			philosophers_info->philosopher[i].starve_time = 
				tmp_time - philosophers_info->philosopher[i].eating_start_time;
		}
	}
}
