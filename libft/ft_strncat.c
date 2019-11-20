/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/23 15:52:13 by ayundina      #+#    #+#                 */
/*   Updated: 2019/01/23 16:24:00 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int	i;
	int	j;
	int len;

	i = 0;
	j = 0;
	len = (int)n;
	while (s1[i] != '\0')
	{
		i++;
	}
	while (s2[j] != '\0' && len > 0)
	{
		s1[i] = s2[j];
		i++;
		j++;
		len--;
	}
	s1[i] = '\0';
	return (s1);
}
