/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:06:52 by samin             #+#    #+#             */
/*   Updated: 2021/09/30 20:25:22 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

void	ft_bzero(void *a, size_t len)
{
	size_t			i;
	unsigned char	*tmp_a;

	i = 0;
	tmp_a = a;
	while (len > i)
	{
		tmp_a[i] = 0;
		i++;
	}
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\n'
			|| str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r'))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]) == 1)
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	if (num > 2147483647)
		return (-1);
	if (num < -2147483648)
		return (0);
	return (num * sign);
}
