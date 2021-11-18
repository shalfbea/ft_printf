/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_to_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:08:00 by shalfbea          #+#    #+#             */
/*   Updated: 2021/11/18 20:28:08 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int build_as_type(t_list *cur, va_list args)
{
	if (cur->type == 'c')
		cur->result = char_to_str((char) va_arg(args, int), cur);
	else if (cur->type == 's')
		cur->result = string_copy(va_arg(args, char *));
	else if (cur->type == 'p')
		cur->result = ft_printf_p_arg((va_arg(args, long long)));
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
	if (cur->result == NULL)
		return (1);
	return (0);
}

static void	get_info_from_args(t_list *cur, va_list args)
{
	if (cur->width == -2)
	{
		cur->width = va_arg(args, int);
		if (cur->width < 0)
		{
			cur->width = -1 * (cur->width);
			cur->minus_flag = 1;
		}
	}
	if (cur->precision == -2)
		cur->precision = va_arg(args, int);
}

int	element_processing(t_list *cur, va_list args)
{
	get_info_from_args(cur, args);
	if (build_as_type(cur, args))
		return (1);
	if (build_precision(cur))
		return (1);
	if (build_width(cur))
		return (1);
	if (flags_for_tens(cur, args))
		return (1);
	if (hash_flag(cur))
		return (1);
	get_back_sign(cur);
	cur->length = ft_strlen(cur->result);
	if (cur->type == 'c')
	{
		if (cur->width <= 0)
			cur->width = 1;
		cur->length = cur->width;
	}
	return (0);
}

int	data_to_list(t_list **head, va_list args)
{
	t_list	*cur;

	cur = (*head)->next;
	while (cur)
	{
		if (element_processing(cur, args))
			return (1);
		cur = cur->next;
	}
	return (0);
}


