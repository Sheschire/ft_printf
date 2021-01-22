#include "ft_printf.h"

int main()
{
    int count;
    int n = 7346;
    void    *p = &n;

    printf("Avec vrai printf\n");
    count = ft_printf("%-10.3s%-5.5d%1p%03.u%%%2c%10s%-*.*s%0*.*X\n", "allo", -256, p, 25, 'g', NULL, -6, 5, NULL, 10, -5, 25687);
    printf("count = %d\n", count);
    printf("Avec ft_printf\n");
    count = printf("%-10.3s%-5.5d%1p%03.u%%%2c%10s%-*.*s%0*.*X\n", "allo", -256, p, 25, 'g', NULL, -6, 5, NULL, 10, -5, 25687);
    printf("count = %d\n", count);
}