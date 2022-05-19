/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 10:24:15 by samin             #+#    #+#             */
/*   Updated: 2021/07/28 16:30:53 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print(pthread_mutex_t	*mutex_print, char *str)
{
    pthread_mutex_lock(mutex_print);
	printf("%s", str);
    pthread_mutex_unlock(mutex_print);
}
