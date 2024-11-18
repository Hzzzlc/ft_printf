#include <stdio.h>
#include "ft_printf.h"

int main(void) {
    int len1, len2;


    len1 = ft_printf("Char: %c\n", 'A');
    len2 = printf("Char: %c\n", 'A');
    ft_printf("Length ft_printf: %d, Length printf: %d\n\n", len1, len2);

    len1 = ft_printf("String: %s\n", "Hola, mundo");
    len2 = printf("String: %s\n", "Hola, mundo");
    ft_printf("Length ft_printf: %d, Length printf: %d\n\n", len1, len2);

    len1 = ft_printf("Integer: %d\n", 1234);
    len2 = printf("Integer: %d\n", 1234);
    ft_printf("Length ft_printf: %d, Length printf: %d\n\n", len1, len2);

    len1 = ft_printf("Negative integer: %d\n", -5678);
    len2 = printf("Negative integer: %d\n", -5678);
    ft_printf("Length ft_printf: %d, Length printf: %d\n\n", len1, len2);

    int x = 42;
    len1 = ft_printf("Pointer: %p\n", (void *)&x);
    len2 = printf("Pointer: %p\n", (void *)&x);
    ft_printf("Length ft_printf: %d, Length printf: %d\n\n", len1, len2);

    // Test del símbolo de porcentaje
    len1 = ft_printf("Percent sign: %%\n");
    len2 = printf("Percent sign: %%\n");
    ft_printf("Length ft_printf: %d, Length printf: %d\n\n", len1, len2);

    return 0;
}
