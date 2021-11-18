/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:40:35 by shalfbea          #+#    #+#             */
/*   Updated: 2021/11/18 20:47:17 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
static int test(char *s, void *data)
{
	printf(s, data);
	printf("\n");
	ft_printf(s, data);
	return (0);
}
*/
int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	//test("%#u", (void *) 5000000000000000);
	//ft_printf("kek%slol%c%%%%", "dik", 'a');
	//void *s;// = "k";
	printf("%.2s", " ");
	//printf("%-3c", '0');
	//ft_printf(" %-1c %-2c %-3c ", '0', 0, '1');
	//ft_printf("%-2c", '0');
	//ft_printf("%3d\n", 5);
	//test("%p", ULONG_MAX);
	//printf("%p", ULONG_MAX);
}
