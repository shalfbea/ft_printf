/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 23:26:06 by shalfbea          #+#    #+#             */
/*   Updated: 2021/11/04 00:49:35 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

int	parse_after_percent(char **str, t_list *cur)
{
	parse_flags(str, cur);
	parse_width(str, cur);
	parse_precision(str, cur);
	if(parse_args(str, cur))
		return (1);
	//(*str) += 2;
	return (0);
}

int	parse_percent(char **str, t_list **cur, size_t *i, size_t *k)
{
	if (((*str)[*i]) == '%')
	{
		if (*k > 0)
		{
			if (add_part_of_string(*str, *k, cur))
				return (1);
		}
		(*str) += (*k);
		//replace with real parcer
		(*cur)->next = ft_lstnew(NULL, 0);
		parse_after_percent(str, *cur);
		*k = 0; //bad
		*i = 0;
	}
	return (0);
}

int	parser(char *str, t_list **head)
{
	size_t	i;
	size_t	k;
	t_list	*cur;

	i = 0;
	k = 0;
	*head = ft_lstnew(NULL, 's');
	if (!(*head))
		return (1);
	cur = (*head);
	while (str[i])
	{
		if (parse_percent(&str, &cur, &i, &k))
			return (1);
		else
		{
			++i;
			++k;
		}
	}
	if (k > 0)
		add_part_of_string(str, k, &cur);
	return (0);
}
