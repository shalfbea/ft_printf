/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   building.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:11:11 by shalfbea          #+#    #+#             */
/*   Updated: 2021/12/02 16:16:23 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flags_for_tens(t_list *cur, va_list args)
{
	(void) args;
	if ((cur->type != 'd') && (cur->type != 'i') && (cur->type != 'u'))
		return (0);
	if (cur->plus_flag && ((cur->result)[0] != '-'))
		return (add_to_result(cur, LEFT, "+"));
	else if (cur->space_flag && ((cur->result)[0] != '-'))
		return (add_to_result(cur, LEFT, " "));
	return (0);
}

int	hash_flag(t_list *cur)
{
	if (cur->hash_flag == 0 || cur->type == 'c' || cur->type == 's')
		return (0);
	if ((cur->type != 'x') && (cur->type != 'X'))
		return (0);
	if (cur->zero_flag && cur->result[0] == '0')
	{
		if (cur->result[1] == '0')
		{
			(cur->result)[1] = cur->type;
			return (0);
		}
		else
		{
			cur->result[0] = cur->type;
			return (add_to_result(cur, LEFT, "0"));
		}
	}
	if (cur->type == 'x')
		return (add_to_result(cur, LEFT, "0x"));
	if (cur->type == 'X')
		return (add_to_result(cur, LEFT, "0X"));
	return (0);
}

int	build_precision(t_list *cur)
{
	int		missing_size;

	if ((cur->type == '%' && cur->zero_flag == 0) || cur->precision < 0)
		return (0);
	if (cur->type == 's')
		return (cut_result(cur, cur->precision));
	if ((ft_strlen(cur->result) == 1) && (cur->result[0]) == '0'
		&& cur->precision == 0)
	{
		free(cur->result);
		cur->result = ft_strdup("");
	}
	if (cur->type == 'd' || cur->type == 'i' || cur->type == 'u'
		|| cur->type == 'x' || cur->type == 'X' || cur->type == '%')
	{
		missing_size = (cur->precision) - ft_strlen(cur->result);
		if (((cur->result)[0] == '-') && (cur->zero_flag == 0))
			missing_size++;
		if (cur->zero_flag && (cur->plus_flag || cur->space_flag))
			missing_size -= 1;
		if (missing_size > 0)
			return (add_some_amount_to_result(cur, LEFT, '0', missing_size));
	}
	return (0);
}

void	get_back_sign(t_list *cur)
{
	char	*s;
	char	*head;

	if (cur->type == 'c' || cur->type == 's' || cur->type == '%')
		return ;
	if (cur->width <= 0 && cur->precision <= 0)
		return ;
	s = cur->result;
	head = s;
	while (*s == '0')
		++s;
	if (*s == '-' && (s != head))
	{
		*s = '0';
		*head = '-';
	}
}

int	build_width(t_list *cur)
{
	int		missing_size;
	char	space_char;

	if (cur->width <= 0)
		return (0);
	space_char = ' ';
	if (cur->zero_flag)
		return (0);
	if (cur->type == 'c')
		missing_size = (cur->width) - 1;
	else
		missing_size = (cur->width) - ft_strlen(cur->result);
	if (missing_size > 0)
		return (add_some_amount_to_result(cur, (cur->minus_flag),
				space_char, missing_size));
	return (0);
}
