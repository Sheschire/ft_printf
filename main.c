int main()
{
//	char 	name[] = "Theo";
	unsigned int age = -13;
//	unsigned int	n = -12;
	void	*p = 0;
	char	qi = '4';
//	char	age = '2';
//	unsigned int	matricule = -2655654;
	int		printf_result;

	printf("\nLET'S PRINTF THIS OUT : <    Je suis %%---10.3s et j'ai %%.*c ans et %%s de QI.    >\n\n");
	printf("          /-----------------------\\\n");
	printf("          |                       |\n");
	printf("          | TEST WITH REAL PRINTF |\n");
	printf("          |                       |\n");
	printf("          \\-----------------------/\n\n");
	printf_result = printf("Je suis %20p et j'ai %u ans et %3c de QI.", p, age, qi);
	printf("\ncount = %d\n\n", printf_result);
	printf("          /---------------------\\\n");
	printf("          |                     |\n");
	printf("          | TEST WITH FT_PRINTF |\n");
	printf("          |                     |\n");
	printf("          \\---------------------/\n\n");
	printf_result = ft_printf("Je suis %20p et j'ai %u ans et %3c de QI.", p, age, qi);
	printf("\ncount = %d\n\n", printf_result);
}