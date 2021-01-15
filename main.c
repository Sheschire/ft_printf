#include "ft_printf.h"

int main()
{/*
	char			c = 'w';
	char			str[] = "Theo";
	int				i = 24;
	unsigned int	matricule = -125;
	unsigned int 	n = 321;
	void			*p = &n;*/
	int				printf_result;

	printf("\nLET'S PRINTF THIS OUT : <    Je suis %%---10.3s et j'ai %%.*c ans et %%s de QI.    >\n\n");
	printf("          /-----------------------\\\n");
	printf("          |                       |\n");
	printf("          | TEST WITH REAL PRINTF |\n");
	printf("          |                       |\n");
	printf("          \\-----------------------/\n\n");
	printf_result = printf("%05%");
	printf("\ncount = %d\n\n", printf_result);
	printf("          /---------------------\\\n");
	printf("          |                     |\n");
	printf("          | TEST WITH FT_PRINTF |\n");
	printf("          |                     |\n");
	printf("          \\---------------------/\n\n");
	printf_result = ft_printf("%05%");
	printf("\ncount = %d\n\n", printf_result);
}