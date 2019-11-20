/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/23 11:27:58 by ayundina      #+#    #+#                 */
/*   Updated: 2019/02/07 12:33:58 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;
	int	j;
	int	leng;

	i = 0;
	leng = (int)len;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && leng > 0)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && leng - j > 0)
		{
			if (needle[j + 1] == '\0')
				return (&((char *)haystack)[i]);
			j++;
		}
		leng--;
		i++;
	}
	return (0);
}
