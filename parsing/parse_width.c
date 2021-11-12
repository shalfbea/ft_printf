/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 00:28:00 by shalfbea          #+#    #+#             */
/*   Updated: 2021/11/12 15:37:33 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

void	parse_width(char **str, t_list *cur)
{
	int	w;

	w = 0;
	while (ft_isdigit(**str))
	{
		w = (w * 10) + (**str) - '0';
		(*str)++;
	}
	cur->width = w;
}
