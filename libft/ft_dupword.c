/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dupword.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/18 13:01:03 by ayundina      #+#    #+#                 */
/*   Updated: 2019/02/18 13:01:07 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dupword(char *ret, const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
}
