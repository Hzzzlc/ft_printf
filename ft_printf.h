/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcruz-me <hcruz-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:49:44 by marvin            #+#    #+#             */
/*   Updated: 2024/11/07 10:09:29 by hcruz-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int		ft_printf(char const *str, ...);
int		ft_putchar(int c);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
#endif