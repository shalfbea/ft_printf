/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 00:33:21 by shalfbea          #+#    #+#             */
/*   Updated: 2021/11/12 15:39:06 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

void	parse_precision(char **str, t_list *cur)
{
	int	p;

	if (**str != '.')
		return ;
	(*str)++;
	while (ft_isdigit(**str))
	{
		p = (p * 10) + (**str) - '0';
		(*str)++;
	}
	cur->precision = p;
}
