/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:53:20 by marvin            #+#    #+#             */
/*   Updated: 2024/11/18 17:53:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return 0;
}

int ft_putnbr(int n) {
    int count = 0;
    char digit;
    if (n == -2147483648) {
        count += write(1, "-2147483648", 11);
        return count;
    }
    if (n < 0) {
        count += write(1, "-", 1);
        n = -n;
    }
    if (n >= 10) {
        count += ft_putnbr(n / 10);
    }
    digit = '0' + (n % 10);
    count += write(1, &digit, 1);
    return count;
}

int ft_putstr(char *str) {
    int len = 0;
    if (!str) {
        return write(1, "(null)", 6);
    }
    while (str[len]) {
        write(1, &str[len], 1);
        len++;
    }
    return len;
}

int ft_hexa(void *ptr) {
    unsigned long addr = (unsigned long)ptr;
    char *hex = "0123456789abcdef";
    char buffer[16];
    int i = 0, count = 0;

    if (!ptr) {
        return write(1, "(nil)", 5);
    }
    count += write(1, "0x", 2);
    while (addr > 0) {
        buffer[i++] = hex[addr % 16];
        addr /= 16;
    }
    while (--i >= 0) {
        count += write(1, &buffer[i], 1);
    }
    return count;
}