/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 00:37:40 by shalfbea          #+#    #+#             */
/*   Updated: 2021/11/13 16:43:26 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int acceptable_args(char c)
{
	if (c == 'c' ||c == 's' || c == 'p')
		return (1);
	if (c == 'd' ||c == 'i' || c == 'u')
		return (1);
	if (c == 'x' ||c == 'X' || c == '%')
		return (1);
	return (0);
}

int	parse_args(char **str, t_list *cur)
{
	if (!acceptable_args(**str))
		return (1);
	cur->type = **str;
	(*str)++;
	return (0);
}
