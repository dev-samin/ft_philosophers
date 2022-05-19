/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:25:44 by samin             #+#    #+#             */
/*   Updated: 2021/07/28 11:06:41 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/time.h>
#include <readline/history.h>
#include <readline/readline.h>

long long get_mstime()
{
	struct timeval tv;
	long long ms_time;
	
	gettimeofday(&tv, NULL);
	ms_time = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000; 
	return(ms_time);
}

int main()
{
	struct timeval tv;
	long long start_time = get_mstime();
	while(1)
	{
		long long time_in_mill = get_mstime();
		printf("%lld\n", time_in_mill - start_time);
	}
	return (0);
}