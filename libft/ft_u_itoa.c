/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 13:31:11 by tlemesle          #+#    #+#             */
/*   Updated: 2021/01/08 17:08:37 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_nbrlen(unsigned int n, int_struct baseset)
{
	size_t			len;

	len = 0;
	while (n > baseset.nbr_base)
	{
		n /= baseset.nbr_base;
		len++;
	}
	len++;
	return (len);
}

static char			*ft_convert(char *str, unsigned int n, size_t len, int_struct baseset)
{
	str[len] = '\0';
	len--;
	while (n > 9)
	{
		str[len] = baseset.base[n % baseset.nbr_base];
		n /= baseset.nbr_base;
		len--;
	}
	str[len] = baseset.base[n];
	return (str);
}

static int_struct	ft_update_struct(char c, int_struct baseset)
{
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
	if (c == 'u')
	{
		baseset.base = "012456789";
		baseset.nbr_base = 10;
	}
	return(baseset);
}

char				*ft_u_itoa(unsigned int n, char c, int_struct baseset)
{
	char	*str;
	size_t	len;

	baseset = ft_update_struct(c, baseset);
	len = ft_nbrlen(n, baseset);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (0);
	str = ft_convert(str, n, len, baseset);
	return (str);
}