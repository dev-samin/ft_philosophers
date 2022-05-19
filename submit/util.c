/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 22:24:58 by samin             #+#    #+#             */
/*   Updated: 2021/09/30 20:14:56 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	get_mstime(void)
{
	struct timeval	tv;
	long long		ms_time;

	gettimeofday(&tv, NULL);
	ms_time = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	return (ms_time);
}

void	check_str_num(int argc, char **str_num)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (str_num[i][j] != '\0')
		{
			if (ft_isdigit(str_num[i][j]) == 0)
			{
				printf("it's not a number\n");
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void	philosopher_print(t_philosopher *philo, char *str)
{
	pthread_mutex_lock(philo->mutex_print);
	if (philo->rule_info->death == 1)
	{
		pthread_mutex_unlock(philo->mutex_print);
		return ;
	}
	printf("%lldms %d %s\n",
		(get_mstime() - (philo->public_time)), philo->philo_num, str);
	pthread_mutex_unlock(philo->mutex_print);
}

int	handle_one_philosopher(t_philosopher *philo)
{
	if (philo->left_fork == philo->right_fork)
	{
		take_fork(philo, philo->left_fork);
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	return (0);
}
