/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 00:33:21 by shalfbea          #+#    #+#             */
/*   Updated: 2021/11/19 15:46:00 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isdigit(int c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	return (0);
}

void	parse_precision(char **str, t_list *cur)
{
	int	p;

	if (**str != '.')
		return ;
	(*str)++;
	if (**str == '*')
	{
		cur->precision = -2;
		(*str)++;
		return ;
	}
	while (ft_isdigit(**str))
	{
		p = (p * 10) + (**str) - '0';
		(*str)++;
	}
	cur->precision = p;
}
