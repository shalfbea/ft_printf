/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:40:35 by shalfbea          #+#    #+#             */
/*   Updated: 2021/11/25 15:19:28 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*
static int test(char *s, void *data)
{
	printf(s, data);
	printf("\n");
	ft_printf(s, data);
	return (0);
}
*/
int	main(void)
{
	char	*s;

	s = "";
	ft_printf("%##x", 42);
}
