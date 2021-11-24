/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags_and_args.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 00:37:40 by shalfbea          #+#    #+#             */
/*   Updated: 2021/11/19 17:34:20 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	acceptable_args(char c)
{
	if (c == 'c' || c == 's' || c == 'p')
		return (1);
	if (c == 'd' || c == 'i' || c == 'u')
		return (1);
	if (c == 'x' || c == 'X' || c == '%')
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

void	parse_flags(char **str, t_list *cur)
{
	char	not_end;

	not_end = 1;
	while (not_end)
	{
		(*str)++;
		if (**str == '-')
			cur->minus_flag = 1;
		else if (**str == '+')
			cur->plus_flag = 1;
		else if (**str == ' ')
			cur->space_flag = 1;
		else if (**str == '#')
			cur->hash_flag = 1;
		else if (**str == '0')
			cur->zero_flag = 1;
		else
			not_end = 0;
	}
}
