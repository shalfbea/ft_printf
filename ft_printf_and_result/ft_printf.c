/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:38:51 by shalfbea          #+#    #+#             */
/*   Updated: 2021/11/13 16:43:26 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	if (data_to_list(&head, args))
		return (ft_lstclear(&head));
	len = make_result(&head); //Clears in it
	va_end(args);
	return (len);
}
