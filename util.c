/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 22:24:58 by samin             #+#    #+#             */
/*   Updated: 2021/07/09 15:20:31 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long get_mstime()
{
	struct timeval tv;
	long long ms_time;
	
	gettimeofday(&tv, NULL);
	ms_time = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000; 
	return(ms_time);
}
