/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:37:04 by shalfbea          #+#    #+#             */
/*   Updated: 2021/11/19 18:15:56 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*char_to_str(int c)
{
	char	*res;

	res = (char *) malloc(sizeof(char ) * 2);
	if (!res)
		return (NULL);
	res[0] = (char) c;
	res[1] = '\0';
	return (res);
}

char	*string_copy(const char *s1)
{
	if (s1)
		return (ft_strdup(s1));
	return (ft_strdup("(null)"));
}

char	*ft_printf_p_arg(long long s1)
{
	char	*s2;
	char	*res;

	if (s1 == LONG_MIN)
		return (ft_strdup("0x8000000000000000"));
	else if (s1 == LONG_MAX)
		return (ft_strdup("0x7fffffffffffffff"));
	else if (s1 == (long long) ULONG_MAX)
		return (ft_strdup("0xffffffffffffffff"));
	//else if (s1 == -ULONG_MAX)
	//	return (ft_strdup("0x1"));
	s2 = ft_itoa_base(s1, "0123456789abcdef");
	if (!s2)
		return (NULL);
	res = ft_strjoin("0x", s2, 0);
	free(s2);
	return (res);
}
