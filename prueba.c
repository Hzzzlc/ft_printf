
#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

int suma(int count, ...)
{
    int result = 0;

    va_list(args);
    va_start(args, count);

    int i = 0;
    while(i < count)
    {
        int num = va_arg(args, int);
        result += num;
        i++;
    }
    va_end(args);
    return result;
}

int main()
{
    int result = suma(6, 1, 2, 3, 4, 5, 6);//El primer numero es la cantidad de numeros que hay despues de ese numero.
    printf("La suma es: %d\n", result);
    return 0;
}