/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 10:23:32 by samin             #+#    #+#             */
/*   Updated: 2021/07/28 14:46:13 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philosopher_action(t_philosopher *philo)
{
	philo->public_time = get_mstime();

	if (philo->philo_num % 2 == 0)
	{
		while (get_mstime() - philo->eating_start_time < philo->rule_info->time_to_eat)
		{}
	}
	while (philo->eating_count < philo->rule_info->number_of_times_each_philosopher_must_eat ||
	philo->rule_info->number_of_times_each_philosopher_must_eat == 0) 
	{
		if (philo->rule_info->death == 1)
			break;
		philosopher_eat(philo);
		if (philo->rule_info->death == 1)
			break;
		philosopher_sleep(philo);
		if (philo->rule_info->death == 1)
			break;
		philosopher_think(philo);
	}
	if (philo->rule_info->death != 1)
	{
		philo->status = 1;
		philo->rule_info->eatting_done_count++;
	}
	return ((void*)0);
}

void	philosopher_eat(t_philosopher *philo)
{
	if (philo->philo_num % 2 == 1)
	{
		take_fork(philo, philo->left_fork);
		take_fork(philo, philo->right_fork);
	}
	else
	{
		usleep(100);
		take_fork(philo, philo->right_fork);
		usleep(100);
		take_fork(philo, philo->left_fork);
	}
	philo->eating_start_time = get_mstime();
	philosopher_print(philo, "is eating");
	philo->eating_count++;
	while (get_mstime() - philo->eating_start_time < philo->rule_info->time_to_eat) {}
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	philosopher_sleep(t_philosopher *philo)
{
	long long sleeping_time = get_mstime();
	philosopher_print(philo, "is sleeping");
	while (get_mstime() - sleeping_time < philo->rule_info->time_to_sleep) { }
}

void	philosopher_think(t_philosopher *philo)
{
	// usleep(50);

	philosopher_print(philo, "is thinking");
}

void	take_fork(t_philosopher *philo, pthread_mutex_t *fork)
{

	pthread_mutex_lock(fork);
	philosopher_print(philo, "has taken a fork");
}

void	philosopher_print(t_philosopher *philo, char *str)
{
	if (philo->rule_info->death == 1)
		return ;
    pthread_mutex_lock(philo->mutex_print);
	printf("starve_time = %lld\n", philo->starve_time);
	printf("%lldms\t %d %s %d\n\n",(get_mstime() - (philo->public_time)), philo->philo_num, str, philo->eating_count);
	pthread_mutex_unlock(philo->mutex_print);
}
