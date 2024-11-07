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
//Funcion principal del proyecto.

int ft_printf(char const *str, ...)
{
	int format = 0;
	va_list(arguments);
	va_start(arguments, format);
}
//Teniendo en cuenta que var sirve para poder leer varios argumentos cuando se le envia al programa. es decir por ejemplo
//							ft_printf("hola %d", 255);
//con var va pasado paso a paso cada letra del hola y luego cuando lee el % lo que hace es leer la siguiente y depende de la letra hace una o otra cosa. 
// Luego hay que gestionar lo que hay despues de las comillas, es decir la coma y la variable a la que se llama que sera la que se imprima que es llamada en las comillas con el porcentaje y la letra.