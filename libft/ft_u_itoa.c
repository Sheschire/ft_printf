/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 13:31:11 by tlemesle          #+#    #+#             */
/*   Updated: 2021/01/19 17:02:31 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_nbrlen(unsigned long long n, int_struct baseset, char c)
{
	size_t			len;

	len = 0;
	while (n > baseset.nbr_base - 1)
	{
		n /= baseset.nbr_base;
		len++;
	}
	len++;
	if (c == 'p')
		len+= 2;
	return (len);
}

static char			*ft_convert(char *str, unsigned long long n, size_t len, int_struct baseset, char c)
{
	str[len] = '\0';
	len--;
	while (n > baseset.nbr_base - 1)
	{
		str[len] = baseset.base[n % baseset.nbr_base];
		n /= baseset.nbr_base;
		len--;
	}
	str[len] = baseset.base[n];
	if (c == 'p')
	{
		str[len - 1] = 'x';
		str[len - 2] = '0';
	}
	return (str);
	printf("str = %s\n", str);
}

static int_struct	ft_update_struct(char c)
{
	int_struct	baseset;
	if (c == 'x' || c == 'p')
	{
		baseset.base = "0123456789abcdef";
		baseset.nbr_base = 16;
	}
	if (c == 'X')
	{
		baseset.base = "0123456789ABCDEF";
		baseset.nbr_base = 16;
	}
	if (c == 'u' || c == 'd' || c == 'i')
	{
		baseset.base = "0123456789";
		baseset.nbr_base = 10;
	}
	return(baseset);
}

char				*ft_u_itoa(unsigned long long n, char c)
{
	char		*str;
	size_t		len;
	int_struct	baseset;

	baseset = ft_update_struct(c);
	len = ft_nbrlen(n, baseset, c);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (0);
	str = ft_convert(str, n, len, baseset, c);
	return (str);
}