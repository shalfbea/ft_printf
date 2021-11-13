/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_to_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:08:00 by shalfbea          #+#    #+#             */
/*   Updated: 2021/11/13 19:40:14 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void build_as_type(t_list *cur, va_list args)
{//cspdiuxX%
	if (cur->type == 'c')
		cur->result = char_to_str((char) va_arg(args, int), cur);
	else if (cur->type == 's')
		cur->result = string_copy(va_arg(args, char *));
	else if (cur->type == 'p')
		cur->result = ft_itoa_base((va_arg(args, long long)), "0123456789abcdef");
	else if (cur->type == 'd')
		cur->result = ft_itoa(va_arg(args, int));
	else if (cur->type == 'i')
		cur->result = ft_itoa(va_arg(args, int)); // Check if there is anything else than d
	else if (cur->type == 'u')
		cur->result = ft_itoa_base((va_arg(args, unsigned int)), "0123456789");
	else if (cur->type == 'x')
		cur->result = ft_itoa_base((va_arg(args, unsigned int)), "0123456789abcdef");
	else if (cur->type == 'X')
		cur->result = ft_itoa_base((va_arg(args, unsigned int)), "0123456789ABCDEF");
	else if (cur->type == '%')
		cur->result = char_to_str('%', cur);
}
static int	element_processing(t_list *cur, va_list args)
{
	build_as_type(cur, args);
	///...
	cur->length = ft_strlen(cur->result);
	//fix later :
	if(cur->type == 'c')
		cur->length = 1;
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
