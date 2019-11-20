/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/25 14:24:48 by ayundina      #+#    #+#                 */
/*   Updated: 2019/01/25 14:36:46 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int				i;
	int				len;
	unsigned char	*str;

	i = 0;
	len = (int)n;
	str = (unsigned char *)s;
	while (i < len)
	{
		str[i] = '\0';
		i++;
	}
}
