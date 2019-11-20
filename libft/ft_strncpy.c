/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 09:09:03 by ayundina      #+#    #+#                 */
/*   Updated: 2019/01/18 10:50:38 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int	i;
	int	cpylen;

	i = 0;
	cpylen = (int)len;
	while (src[i] != '\0' && i < cpylen)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < cpylen)
		dst[i++] = '\0';
	return (dst);
}
