/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 10:45:15 by tlemesle          #+#    #+#             */
/*   Updated: 2020/12/14 10:37:10 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "./libft/libft.h"

t_flags	ft_init_flags(t_flags flags)
{
	flags.width = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.dot = -1;
	flags.joker = 0;
	return (flags);
}

t_flags	ft_fill_flags(char *s, va_list *ap)
{
	t_flags flags;
	int	i;

	i = 0;
	ft_init_flags(flags);
	printf("s = %s\n", s);
	while (s[i] && !ft_is_convertor(s[i]))
	{
		if (s[i] == '0' && flags.minus == 0 && flags.dot == -1)
			*flags.zero = 1;
		if (s[i] == '.')
			*flags = ft_dot_flag(flags, s + i);
		if (ft_isdigit(s[i]) && s[i] != '0')
			*flags = ft_width_flag(flags, s);
		if (s[i] == '.' || (ft_isdigit(s[i]) && s[i] != '0'))
			i += ft_update_index(s + i, s[i], flags);
		if (s[i] == '-')
			*flags = ft_minus_flag(flags, s + i);
//		if (s[i] == '*')
//			*flags = ft_joker_flag(flags);
		i++;
	}
	
//	if (s[i])
//		ft_convert(s[i]);
	return (flags);
}

int	ft_putn_and_count(char *str, int n)
{
	int i;

	i = 0;
	while (str && n--)
	{
		write(1, str++, 1);
		i++;
	}
	return (i);
}

int	ft_printf(const char *input, ...)
{
	va_list ap;
	char	*tmp;
	int		count;
	char	*s;

	va_start(ap, input);
	tmp = s;
	count = 0;
	s = ft_strdup(input);
	if (!s)
		return (NULL);
	while (s)
	{
		while (*s != '%' && *s)
			s++;
		if (*s == '%')
		{
			count += ft_putn_and_count(tmp, (s - tmp));
			ft_fill_flags(s + 1, &ap);
		}
	}
	free(s);
	va_end(ap);
}

int main()
{
	char name[] = "Theo";
	int	age = 24;
	
	ft_fill_flags("Je suis %-10.3s et j'ai %015d ans.", name, age);
}