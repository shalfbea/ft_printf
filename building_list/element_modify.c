/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_modify.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:59:55 by shalfbea          #+#    #+#             */
/*   Updated: 2021/11/24 20:24:51 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	add_some_amount_to_result(t_list *cur, char left_or_right,
		char space, int amount)
{
	char	*to_add;
	int		i;
	int		res;

	to_add = (char *) malloc(sizeof(char) * (amount + 1));
	if (!to_add)
		return (1);
	i = 0;
	while (i < amount)
		to_add[i++] = space;
	to_add[i] = '\0';
	res = add_to_result(cur, left_or_right, to_add);
	free(to_add);
	cur->length = ft_strlen(cur->result);
	return (res);
}

int	add_to_result(t_list *cur, char left_or_right, char	*to_add)
{
	char	*new_result;
	size_t	custom_len;

	custom_len = 0;
	if (cur->type == 'c')
		custom_len = 1;
	if (left_or_right)
		new_result = ft_strjoin(cur->result, to_add, custom_len);
	else
		new_result = ft_strjoin(to_add, cur->result, custom_len);
	if (!new_result)
		return (1);
	free(cur->result);
	cur->result = new_result;
	return (0);
}

int	cut_result(t_list *cur, int new_size)
{
	char	*new_result;
	int		i;

	if (ft_strlen(cur->result) < (size_t) new_size)
		return (0);
	new_result = (char *) malloc (sizeof(char) * (new_size + 1));
	if (!new_result)
		return (1);
	i = -1;
	//while (++i < new_size)
	while (++i < new_size)
		new_result[i] = (cur->result)[i];
	new_result[i] = '\0';
	free(cur->result);
	cur->result = new_result;
	return (0);
}
