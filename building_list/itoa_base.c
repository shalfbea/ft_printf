/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:21:55 by shalfbea          #+#    #+#             */
/*   Updated: 2021/11/15 16:48:21 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_itoa_base_malloc(long long *n, long long *tens, int base)
{
	long long 		tmp;
	long long 		len;
	char			*res;
	char			put_minus;

	put_minus = 0;
	len = 2;
	*tens = 1;
	if (*n < 0)
	{
		len++;
		*n *= -1;
		put_minus = 1;
	}
	tmp = *n;
	while (tmp > (base - 1))
	{
		tmp /= base;
		len++;
		(*tens) *= base;
	}
	res = (char *)malloc(sizeof(char) * (len));
	if (put_minus && res)
		*res = '-';
	return (res);
}

char	*ft_itoa_base(long long n, char *base_charset)
{
	long long 		tens;
	char			*res;
	char			*ret_res;
	int				base;

	base = strlen(base_charset);
	res = NULL;
	res = ft_itoa_base_malloc(&n, &tens, base);
	if (!res)
		return (NULL);
	ret_res = res;
	if (*res == '-')
		res++;
	while (tens > 0)
	{
		*res = base_charset[(n / tens)];
		n %= tens;
		tens /= base;
		res++;
	}
	*res = '\0';
	return (ret_res);
}
