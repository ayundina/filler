/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/23 16:24:31 by ayundina      #+#    #+#                 */
/*   Updated: 2019/01/24 16:13:05 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	sizecpy;

	i = 0;
	j = 0;
	sizecpy = size;
	while (size != 0 && dest[i] != '\0')
	{
		size--;
		i++;
	}
	if (size == 0)
		return (sizecpy + ft_strlen(src));
	while (src[j] != '\0' && size > 1)
	{
		dest[i + j] = src[j];
		j++;
		size--;
	}
	dest[i + j] = '\0';
	return (i + ft_strlen(src));
}
