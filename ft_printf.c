/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:38:51 by shalfbea          #+#    #+#             */
/*   Updated: 2021/11/19 17:39:23 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*allocate_result(t_list **head, int *len)
{
	t_list	*cur;
	char	*res;

	cur = (*head)->next;
	*len = 0;
	while (cur)
	{
		(*len) += cur->length;
		cur = cur->next;
	}
	res = (char *)malloc(sizeof(char) * ((*len) + 1));
	if (!res)
		return (NULL);
	return (res);
}

static void	fill_result(t_list **head, char *res)
{
	t_list	*cur;
	size_t	i;
	int		k;

	cur = (*head)->next;
	i = 0;
	while (cur)
	{
		k = 0;
		while (k < (cur->length))
			res[i++] = (cur->result)[k++];
		cur = cur->next;
	}
	res[i] = '\0';
}

static int	make_result(t_list **head)
{
	int		len;
	char	*res;

	res = allocate_result(head, &len);
	if (!res)
		return (ft_lstclear(head));
	fill_result(head, res);
	write(1, res, len);
	ft_lstclear(head);
	free(res);
	return (len);
}

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
	if (data_to_list(&head, args))
		return (ft_lstclear(&head));
	len = make_result(&head);
	va_end(args);
	return (len);
}
