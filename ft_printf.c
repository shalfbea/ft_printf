/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:38:51 by shalfbea          #+#    #+#             */
/*   Updated: 2021/11/04 00:44:30 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

int	ft_printf(const char *str, ...)
{
	t_list	*head;
	int		len;

	len = 0;
	head = NULL;
	va_list(args);
	va_start(args, str);
	if (parser((char *)str, &head))
		return (ft_lstclear(&head));
	//make smth with head, len;
	len = make_result(&head); //Clears in it
	va_end(args);
	return (len);
}
