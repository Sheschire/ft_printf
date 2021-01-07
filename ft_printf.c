/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 10:45:15 by tlemesle          #+#    #+#             */
/*   Updated: 2021/01/07 11:33:00 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int	ft_fill_flags(char *s, va_list *ap)
{
	t_flags flags;
	int	i;
	int count;

	count = 0;
	i = 0;
	flags = ft_init_flags();
	while (s[i] && !ft_is_convertor(s[i]))
	{
		if (s[i] == '0' && flags.minus == 0 && flags.dot == -1)
			flags.zero = 1;
		if (s[i] == '.')
			flags = ft_dot_flag(flags, s + i);
		if (ft_isdigit(s[i]) && s[i] != '0')
			flags = ft_width_flag(flags, s + i);
		if (s[i] == '.' || flags.width != 0)
			i += ft_update_index(s + i, s[i], flags);
		if (s[i] == '-')
			flags = ft_minus_flag(flags, s + i);
		if (s[i] == '*')
			flags = ft_joker_flag(flags, *ap);
		i++;
	}
	flags.convertor = s[i];
	if (s[i] && ft_is_convertor(s[i]))
		count = ft_convert(s[i], flags, *ap);
	else
		count = 0;
	return (count);
}

int	ft_putn_and_count(char *s, int n)
{
	write(1, s, n);
	return (n);
}

int	ft_build_print(char *s, va_list *ap)
{
	char	*tmp;
	int		count;

	count = 0;
	while (*s)
	{
		tmp = s;
		while (*s != '%' && *s)
			s++;
		if (*s == '%')
		{
			count += ft_putn_and_count(tmp, (s - tmp));
			count += ft_fill_flags(s + 1, ap);
			while (!ft_is_convertor(*s) && *s)
				s++;
			if (ft_is_convertor(*s))
				s++;
		}
	}
	count += ft_putn_and_count(tmp, (s - tmp));
	return (count);
}

int	ft_printf(const char *input, ...)
{
	va_list ap;
	int		count;

	va_start(ap, input);
	if (!input)
		return (0);
	count = ft_build_print((char *)input, &ap);
	va_end(ap);
	printf("\ncount = %d\n\n", count);
	return (count);
}

int main()
{
//	char 	name[] = "Theo";
	char	age = '2';
	char	qi[] = "130";
	
	int		printf_result;

	printf("\nLET'S PRINTF THIS OUT : <    Je suis %%---10.3s et j'ai %%.*c ans et %%s de QI.    >\n\n");
	printf("          /-----------------------\\\n");
	printf("          |                       |\n");
	printf("          | TEST WITH REAL PRINTF |\n");
	printf("          |                       |\n");
	printf("          \\-----------------------/\n\n");
	printf_result = printf("Je suis %10.3s et j'ai %3c ans et %s de QI.", NULL, age, qi);
	printf("\ncount = %d\n\n", printf_result);
	printf("          /---------------------\\\n");
	printf("          |                     |\n");
	printf("          | TEST WITH FT_PRINTF |\n");
	printf("          |                     |\n");
	printf("          \\---------------------/\n\n");
	ft_printf("Je suis %10.3s et j'ai %3c ans et %s de QI.", NULL, age, qi);
//	printf_result = printf("%.*i", -4, 34);
	
}