/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_header.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:43:01 by shalfbea          #+#    #+#             */
/*   Updated: 2021/11/04 00:42:58 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_HEADER_H
# define FT_PRINTF_HEADER_H

/*
* To delete
*/
# include <stdio.h>

/*
* end to delete
*/

# include <limits.h>
# include <float.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	char			*result;
	char			type;
	int				width;
	int				precision;
	int				length;
	int 			minus_flag;
	int				plus_flag;
	int				space_flag;
	int				hash_flag;
	int				zero_flag;
	struct s_list	*next;
}	t_list;

int		ft_printf(const char *str, ...);
t_list	*ft_lstnew(void *content, char type);
int		add_part_of_string(char	*str, int k, t_list **cur);
int		ft_lstclear(t_list **lst);
int		make_result(t_list **head);

//parsing.c
int	parser(char *str, t_list **head);
int	parse_percent(char **str, t_list **cur, size_t *i, size_t *k);
// parse_flags.c
void parse_flags(char **str, t_list *cur);
// parse_width.c
void	parse_width(char **str, t_list *cur);
// parse_precision.c
void	parse_precision(char **str, t_list *cur);
// parse_args.c
int	parse_args(char **str, t_list *cur);
// utils.c
int ft_is_digit(char c);
#endif
