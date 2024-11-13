/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcruz-me <hcruz-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:57:53 by marvin            #+#    #+#             */
/*   Updated: 2024/11/13 14:32:00 by hcruz-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Funcion de imprimira las strings. %s
void	ft_putstr(char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
	{
		write(1, &s[count], 1);
		count++;
	}
}