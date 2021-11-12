/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_to_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:08:00 by shalfbea          #+#    #+#             */
/*   Updated: 2021/11/12 17:46:54 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

static void build_as_type(t_list *cur, va_list args)
{//cspdiuxX%
	if (cur->type == 'c')
		cur->result = char_to_str((char) va_arg(args, int));
	else if (cur->type == 's')
		cur->result = ft_strdup(va_arg(args, char *));
	else if (cur->type == 'p')
		return ;
	else if (cur->type == 'd')
		cur->result = ft_itoa(va_arg(args, int));
	else if (cur->type == 'i')
		cur->result = ft_itoa(va_arg(args, int)); // Check if there is anything else than d
	else if (cur->type == 'u')
		return ;
	else if (cur->type == 'x')
		return ;
	else if (cur->type == 'X')
		return ;
	else if (cur->type == '%')
		cur->result = char_to_str('%');
}
static int	element_processing(t_list *cur, va_list args)
{
	build_as_type(cur, args);
	///...
	cur->length = ft_strlen(cur->result);
	return (0);
}

int	data_to_list(t_list **head, va_list args)
{
	t_list *cur;

	cur = (*head)->next;
	while (cur)
	{
		if (element_processing(cur, args))
			return (1);
		cur = cur->next;
	}
	return (0);
}
