/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 16:25:45 by ayundina      #+#    #+#                 */
/*   Updated: 2019/02/08 11:16:13 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;

	temp = NULL;
	while (*s != '\0')
	{
		if (*s == c)
		{
			temp = (char *)s;
		}
		s++;
	}
	if (*s == c)
	{
		temp = (char *)s;
	}
	return (temp);
}
