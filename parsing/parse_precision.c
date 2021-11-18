/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 00:33:21 by shalfbea          #+#    #+#             */
/*   Updated: 2021/11/16 18:01:40 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
