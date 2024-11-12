/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcruz-me <hcruz-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:00:34 by marvin            #+#    #+#             */
/*   Updated: 2024/11/07 17:03:50 by hcruz-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//Para los enteros sin signo. %u
unsigned int	ft_num_nosign(unsigned int num)
{
	int	i;

	i = 0;
	if (num > 9)
	{
		i = ft_num_nosign(num / 10);
		if (i == -1)
			return (-1);
		num = num % 10;
	}
	if (num <= 9)
	{
		if (ft_putchar (('0' + num)) == -1)
			return (-1);
		i++;
	}
	return (i);
}