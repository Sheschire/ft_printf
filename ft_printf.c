/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 10:45:15 by tlemesle          #+#    #+#             */
/*   Updated: 2021/01/04 11:52:29 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

t_flags	ft_init_flags()
{
	t_flags flags;
	
	flags.width = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.dot = -1;
	flags.joker = 0;
	return (flags);
}

int	ft_fill_flags(char *s, va_list *ap)
{
	t_flags flags;
	int	i;
	int count;

	count = 0;
	i = 0;
	flags = ft_init_flags();
/*	printf("[START FILL FLAGS] = %s\n", s);
	printf("\n--------- [CHAR LOOP ANALYSIS] --------\n");*/
	while (s[i] && !ft_is_convertor(s[i]))
	{
//		printf("%c\n", s[i]);
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
//		if (s[i] == '*')
//			flags = ft_joker_flag(flags, &ap);
		i++;
	}
	flags.convertor = s[i];
/*	printf("--------- [END LOOP ANALYSIS] ---------\n\n");
	printf("[CHAR AFTER LOOP] = %c\n\n", s[i]);
	printf("---------[STRUCT CHECK]---------\n");
	printf("flags.width = %d\n", flags.width);
	printf("flags.minus = %d\n", flags.minus);
	printf("flags.zero = %d\n", flags.zero);
	printf("flags.dot = %d\n", flags.dot);
	printf("flags.convertor = %c\n", flags.convertor);
	printf("---------[END STRUCT CHECK]---------\n\n");
	printf("s after loop = %s\n", s);
*/	
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
	while (s)
	{
		tmp = s;
		while (*s != '%' && *s)
			s++;
		if (*s == '%')
		{
			count += ft_putn_and_count(tmp, (s - tmp));
			count += ft_fill_flags(s + 1, ap);
			while (!ft_is_convertor(*s) && s)
				s++;
			if (ft_is_convertor(*s))
				s++;
//			printf("\n\nS EST ICI ----->%c<--------\n\n", *s);
		}
		if (!s)
			count += ft_putn_and_count(tmp, (s - tmp));
	}
	free(s);
	return (count);
}

int	ft_printf(const char *input, ...)
{
	va_list ap;
	int		count;
	char	*s;

	va_start(ap, input);
	if (!input)
		return (0);
	s = ft_strdup(input);
	count = ft_build_print(s, &ap);
	va_end(ap);
	return (count);
}

int main()
{
	char 	name[] = "Theo";
	char	age[] = "24";
	
	ft_printf("Je suis %-10.3s et j'ai %s ans.", name, age);
}