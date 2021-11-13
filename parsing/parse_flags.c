/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 00:10:43 by shalfbea          #+#    #+#             */
/*   Updated: 2021/11/13 16:43:26 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_flags(char **str, t_list *cur)
{
	char	not_end;

	not_end = 1;
	while (not_end)
	{
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
		(*str)++;
	}
}
