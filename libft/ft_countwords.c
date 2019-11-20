/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_countwords.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/18 13:16:00 by ayundina      #+#    #+#                 */
/*   Updated: 2019/02/18 13:16:03 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countwords(char const *s, char c)
{
	int	words;

	words = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
		{
			s++;
		}
		if (*s != c && *s != '\0')
		{
			words++;
			s++;
		}
		while (*s != c && *s != '\0')
		{
			s++;
		}
	}
	return (words);
}
