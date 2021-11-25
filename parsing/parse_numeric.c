/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_numeric.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 00:33:21 by shalfbea          #+#    #+#             */
/*   Updated: 2021/11/25 15:03:11 by shalfbea         ###   ########.fr       */
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
	p = 0;
	while (ft_isdigit(**str))
	{
		p = (p * 10) + (**str) - '0';
		(*str)++;
	}
	cur->precision = p;
}

void	parse_width(char **str, t_list *cur)
{
	int	w;

	w = 0;
	if (**str == '*')
	{
		cur->width = -2;
		(*str)++;
		return ;
	}
	while (ft_isdigit(**str))
	{
		w = (w * 10) + (**str) - '0';
		(*str)++;
	}
	cur->width = w;
}
