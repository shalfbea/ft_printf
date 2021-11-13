/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:41:14 by shalfbea          #+#    #+#             */
/*   Updated: 2021/11/13 18:57:27 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// TO DELETE
# include <stdio.h>
// END TO DELETE

# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
// parsing.c
int	parser(char *str, va_list args);
// utils.c
size_t	ft_strlen(const char *s);

# define MINUS_FLAG 0
# define PLUS_FLAG 1
# define SPACE_FLAG 2
# define HASH_FLAG 3
# define ZERO_FLAG 4

typedef struct s_list
{
	char			type;
	int				width;
	int				precision;
	unsigned char	flags;
}	t_list;
#endif
