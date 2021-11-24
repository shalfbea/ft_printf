/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:17:29 by shalfbea          #+#    #+#             */
/*   Updated: 2021/11/19 18:08:00 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Allocates (with malloc(3)) and returns a new
** element. The variable ’content’ is initialized
** with the value of the parameter ’content’. The
** variable ’next’ is initialized to NULL.
*/
t_list	*ft_lstnew(void *content, char type)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	list->precision = -1;
	list->result = NULL;
	list->length = 0;
	list->type = type;
	list->width = -1;
	list->minus_flag = 0;
	list->plus_flag = 0;
	list->space_flag = 0;
	list->hash_flag = 0;
	list->zero_flag = 0;
	return (list);
}

int	add_part_of_string(char	*str, int k, t_list **cur)
{
	char	*tmp;
	int		i;

	(*cur)->next = ft_lstnew(NULL, 0);
	*cur = (*cur)->next;
	if (!cur)
		return (1);
	i = 0;
	tmp = (char *)malloc(sizeof(char) * (k + 1));
	if (!tmp)
		return (1);
	while (i < k)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	(*cur)->result = tmp;
	(*cur)->length = k;
	(*cur)->type = '.';
	return (0);
}

static void	free_elem(t_list **list)
{
	t_list	*elem;

	elem = *list;
	if (elem == NULL)
		return ;
	if (elem->type == 's')
		free(elem->content);
	free(elem->result);
	free(elem);
	*list = NULL;
}

int	ft_lstclear(t_list **lst)
{
	t_list	*cur_elem;
	t_list	*next_elem;
	char	check;

	check = 1;
	if (*lst == NULL)
		return (0);
	cur_elem = *lst;
	next_elem = *lst;
	while (check)
	{
		if (cur_elem->next)
			next_elem = cur_elem->next;
		else
			check = 0;
		free_elem(&cur_elem);
		cur_elem = next_elem;
	}
	*lst = NULL;
	return (0);
}


