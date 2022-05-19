/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 10:23:32 by samin             #+#    #+#             */
/*   Updated: 2021/09/30 20:13:13 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philosopher_action(t_philosopher *philo)
{
	if (handle_one_philosopher(philo) == 1)
		return (0);
	if (philo->philo_num % 2 == 0)
	{
		while (get_mstime()
			- philo->eating_start_time < philo->rule_info->time_to_eat)
			usleep(500);
	}
	while (philo->eating_count < philo->rule_info->must_eat
		|| philo->rule_info->must_eat == 0)
	{
		if (philo->rule_info->death == 1)
			break ;
		philosopher_eat(philo);
		if (philo->rule_info->death == 1)
			break ;
		philosopher_sleep(philo);
		if (philo->rule_info->death == 1)
			break ;
		philosopher_think(philo);
	}
	if (philo->rule_info->death != 1)
		philo->status = 1;
	return (0);
}

void	philosopher_eat(t_philosopher *philo)
{
	take_fork(philo, philo->left_fork);
	take_fork(philo, philo->right_fork);
	philo->eating_start_time = get_mstime();
	philosopher_print(philo, "is eating");
	philo->eating_count++;
	while (get_mstime()
		- philo->eating_start_time < philo->rule_info->time_to_eat)
		usleep(500);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	philosopher_sleep(t_philosopher *philo)
{
	long long	sleeping_time;

	sleeping_time = get_mstime();
	philosopher_print(philo, "is sleeping");
	while (get_mstime() - sleeping_time < philo->rule_info->time_to_sleep)
		usleep(500);
}

void	philosopher_think(t_philosopher *philo)
{
	philosopher_print(philo, "is thinking");
}

void	take_fork(t_philosopher *philo, pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
	philosopher_print(philo, "has taken a fork");
}
