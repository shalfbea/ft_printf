/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:46:39 by shalfbea          #+#    #+#             */
/*   Updated: 2021/11/19 17:49:55 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	size;

	size = ft_strlen(s1) + 1;
	s2 = (char *)malloc(sizeof(char) * size);
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s1, size);
	return (s2);
}

/*
** Allocates (with malloc(3)) and returns a new
** string, which is the result of the concatenation
** of ’s1’ and ’s2’.
*/
char	*ft_strjoin(char const *s1, char const *s2, size_t custom_len)
{
	char	*res;
	size_t	i;
	size_t	k;
	size_t	len;

	if ((!s1) || (!s2))
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (ft_strlen(s1) == 0 || ft_strlen(s2) == 0)
		len += 1;
	res = (char *) malloc(sizeof(char) * len);
	if (!res)
		return (NULL);
	i = 0;
	k = 0;
	while (s1[i] || i < custom_len)
		res[k++] = s1[i++];
	i = 0;
	while (s2[i] || i < custom_len)
		res[k++] = s2[i++];
	res[k] = '\0';
	return (res);
}

/*
** DESCRIPTION
**  The ft_strlcpy() function copy and concatenate strings with the same
** 	input parameters and output result as snprintf(3).
**
**  ft_strlcpy() take the full size of the destination buffer and guarantee
** 	NUL-termination if there is room.  Note that room for
**  the NUL should be included in dstsize.
**
**  ft_strlcpy() copies up to dstsize - 1 characters from the string src
**  to dst, NUL-terminating the result if dstsize is not 0.
**
**  If the src and dst strings overlap, the behavior is undefined.
**
** RETURN VALUES
**  the ft_strlcpy() function return the total length of the string they
**  tried to create.  For strlcpy() that means the length of src.
**
**  If the return value is >= dstsize, the output string has been
**  truncated. It is the caller's responsibility to handle this.
**
*/
size_t	ft_strlcpy(char *dst, const char *src,
					size_t dstsize)
{
	size_t	size_src;
	size_t	i;

	size_src = ft_strlen(src);
	if (dstsize <= 0)
		return (size_src);
	i = 0;
	while (i < size_src && i < dstsize - 1)
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
	return (size_src);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*
** DESCRIPTION
**  The ft_strncmp() function lexicographically compare the
**  null-terminated strings s1 and s2.
**
**  The ft_strncmp() function compares not more than n characters.
**  Because ft_strncmp() is designed for comparing strings rather
**  than binary data, characters that appear after a
**  `\0' character are not compared.
**
** RETURN VALUES
**  The ft_strncmp() functions return an integer greater than,
**  equal to, or less than 0, according as the string s1 is
**  greater than, equal to, or less than the string s2.
**  The comparison is done using unsigned characters,
**  so that `\200' is greater than `\0'.
*/
/*
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((i < n) && (s1[i] == s2[i]) && s1[i] && s2[i])
		++i;
	if (i == n)
		return ((int) 0);
	return ((unsigned char)s1[i] - s2[i]);
}
*/
