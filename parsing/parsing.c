/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 23:26:06 by shalfbea          #+#    #+#             */
/*   Updated: 2021/11/25 15:02:42 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
int	parse_after_percent(char **str, t_list *cur)
{
	parse_flags(str, cur);
	parse_width(str, cur);
	parse_precision(str, cur);
	if (parse_args(str, cur))
		return (1);
	return (0);
}
*/

int	parse_percent(char **str, t_list **cur, int *i)
{
	if (((*str)[*i]) == '%')
	{
		if (*i > 0)
		{
			if (add_part_of_string(*str, *i, cur))
				return (1);
		}
		(*str) += (*i);
		(*cur)->next = ft_lstnew(0);
		(*cur) = (*cur)->next;
		parse_flags(str, *cur);
		parse_width(str, *cur);
		parse_precision(str, *cur);
		if (parse_args(str, *cur))
			return (1);
		*i = -1;
	}
	return (0);
}

int	parser(char *str, t_list **head)
{
	int		i;
	t_list	*cur;

	i = 0;
	*head = ft_lstnew('s');
	if (!(*head))
		return (1);
	cur = (*head);
	while (str[i])
	{
		if (parse_percent(&str, &cur, &i))
			return (1);
		++i;
	}
	if (i > 0)
	{
		if (add_part_of_string(str, i, &cur))
			return (1);
	}
	return (0);
}
