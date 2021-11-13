/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:40:41 by shalfbea          #+#    #+#             */
/*   Updated: 2021/11/13 19:12:37 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parse_percent(char **str, int *i, va_list args)
{
	int	outputed;

	outputed = *i;
	if (((*str)[*i]) == '%')
	{
		if (*i > 0)
			write(1, &str, *i);
		(*str) += (*i);
		outputed += parse_after_percent(str, *cur);
		*i = -1;
	}
	return (outputed);
}

int	parser(char *str, va_list args)
{
	int	i;
	int total;

	i = 0;
	total = 0;
	while (str[i])
	{
		total += parse_percent(&str, &i, args));
		if (i == -2)
			return (total);
		++i;
	}
	if (i > 0)
		total+=write(1, &str, i);
	return (total);
}
