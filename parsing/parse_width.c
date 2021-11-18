/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 00:28:00 by shalfbea          #+#    #+#             */
/*   Updated: 2021/11/18 18:30:56 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
