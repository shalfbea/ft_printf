/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resulting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:44:18 by shalfbea          #+#    #+#             */
/*   Updated: 2021/11/13 16:43:26 by shalfbea         ###   ########.fr       */
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

int	make_result(t_list **head)
{
	int		len;
	char	*res;

	res = allocate_result(head, &len);
	fill_result(head, res);
	write(1, res, len);
	ft_lstclear(head);
	free(res);
	return (len);
}
