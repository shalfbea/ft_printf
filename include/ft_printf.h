/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:43:01 by shalfbea          #+#    #+#             */
/*   Updated: 2021/11/13 16:31:43 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <float.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# include <string.h> //need it?

typedef struct s_list
{
	char				*result;
	char				type;
	int					width;
	int					precision;
	int					length;
	char				minus_flag;
	char				plus_flag;
	char				space_flag;
	char				hash_flag;
	char				zero_flag;
	struct s_list	*next;
}	t_list;

int		ft_printf(const char *str, ...);
t_list	*ft_lstnew(char type);
int		add_part_of_string(char	*str, int k, t_list **cur);
int		ft_lstclear(t_list **lst);
int		parser(char *str, t_list **head);
void	parse_flags(char **str, t_list *cur);
void	parse_width(char **str, t_list *cur);
void	parse_precision(char **str, t_list *cur);
int		parse_args(char **str, t_list *cur);
int		data_to_list(t_list **head, va_list args);
char	*char_to_str(int c);
char	*ft_printf_p_arg(long long s1);
char	*string_copy(const char *s1);
char	*ft_itoa_base(long long n, char *base_charset);
int		flags_for_tens(t_list *cur, va_list args);
int		hash_flag(t_list *cur);
int		build_precision(t_list *cur);
int		build_width(t_list *cur);
void	get_back_sign(t_list *cur);
int		add_some_amount_to_result(t_list *cur, char left_or_right,
			char space, int amount);
int		add_to_result(t_list *cur, char left_or_right, char	*to_add);
int		cut_result(t_list *cur, int new_size);
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2, size_t custom_len);
char	*ft_itoa(int n);
size_t	ft_strlcpy(char *dst, const char *src,
			size_t dstsize);
# define LEFT 0
# define RIGHT 1
#endif
