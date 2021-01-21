#include "ft_printf.h"

int main()
{
    int count;

    count = 0;
    printf("avec printf :\n");
    count = printf("%*.*d", 1, 4, -135);
    printf("\ncount = %d\n\n", count);
    printf("avec ft_printf :\n");
    count = ft_printf("%*.*d", 1, 4, -135);
    printf("\ncount = %d\n", count);
}