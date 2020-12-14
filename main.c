/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 11:46:37 by tlemesle          #+#    #+#             */
/*   Updated: 2020/12/11 16:27:16 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "./libft/libft.h"

int main()
{
	char name[] = "Theo";
	int age = -24;
	//ft_printf("Je suis %10.3s et j'ai %3-d ans.", name, age);
	printf("Je suis %-10.3s et j'ai %015d ans.", name, age);
}