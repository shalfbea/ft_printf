/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:37:04 by shalfbea          #+#    #+#             */
/*   Updated: 2021/11/13 17:41:46 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*char_to_str(int c, t_list *cur)
{
	char	*res;

	res = (char *) malloc(sizeof(char ) * 1);
	if (!res)
		return (NULL);
	res[0] = (char) c;
	cur->length = 1;
	return (res);
}

char	*string_copy(const char *s1)
{
	if (s1)
		return (ft_strdup(s1));
	return ft_strdup("(null)");
}
