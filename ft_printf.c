/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcruz-me <hcruz-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:40:53 by marvin            #+#    #+#             */
/*   Updated: 2024/11/07 17:18:10 by hcruz-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//Funcion de los tipos de variables :
static int variables(char c, va_list args)
{
	if ( c == 'X')
		return (ft_hexa_max(va_arg(args, int)));
	if ( c == 'x')
		return (ft_hexa_min(va_arg(args, int)));
	if ( c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if ( c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if ( c == 'u')
		return (ft_unsigned_int(va_arg(args, unsigned int)));
	if ( c == 'p')
		return (ft_pointer(va_arg(args, void *)));
	if ( c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	return (0);
}
//Funcion que recorrera la string para imprimirla.
static int print_s(char *s, va_list args, int i)
{
	int j;

	j = 0;
	while(s[j])
	{
		//Si el caracter es %
		if (s[j] == '%')
		{
			//Llama a la funcion que es la que decidira la accion que hara dependiendo del caracter que pasara despues del %.
			i += print_percent(s[j + 1], args);
			if	(i == -1)
				return (-1);
			j++;
		}
		else
		{
			//Imprimimos el caracter %
			if (write (1, &s[j], 1) != 1)
				return (-1);
			i++;
		}
		j++;
	}
	//Cantidad de caracteres impresos.
	return (i);
}
//Funcion que maneja dependiendo de que caracter hay despues del porcentaje como un tipo de variable o imprime el % literalmente.
static int print_percent(char c, va_list args)
{
	int i;

	i = 0;
	if (c != '%')
	{
		i = variables(c, args);
		if (i == -1)
			return (-1);
		return (i);
	}
	else
	{
		if (write (1, &c, 1) != 1)
			return (-1);
		return (1);
	}
}
//Funcion principal del proyecto.
int ft_printf(char const *s, ...)
{
	//Declcaración de las variables :
	va_list	args;
	int		i;
	//Inicializamos i a 0
	i = 0;
	//Inicializamos args para acceder a los argumentos.
	va_start(args, s);
	i = print_s(s, args, i);
	va_end(args);
	return (i);
}


//Teniendo en cuenta que var sirve para poder leer varios argumentos cuando se le envia al programa. es decir por ejemplo
//							ft_printf("hola %d", 255);
//con var va pasado paso a paso cada letra del hola y luego cuando lee el % lo que hace es leer la siguiente y depende de la letra hace una o otra cosa. 
// Luego hay que gestionar lo que hay despues de las comillas, es decir la coma y la variable a la que se llama que sera la que se imprima que es llamada en las comillas con el porcentaje y la letra.