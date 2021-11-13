/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:40:35 by shalfbea          #+#    #+#             */
/*   Updated: 2021/11/13 19:41:40 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	//ft_printf("kek%slol%c%%%%", "dik", 'a');
	char *s;// = "k";

	s = "k";
	printf("%p",(void *) s);
	ft_printf("my %p\n", (void *) s);
}
