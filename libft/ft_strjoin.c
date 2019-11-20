/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/31 13:22:12 by ayundina      #+#    #+#                 */
/*   Updated: 2019/02/07 12:06:34 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*concat_str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len = (int)ft_strlen(s1) + (int)ft_strlen(s2);
	concat_str = (char *)malloc(sizeof(char) * len + 1);
	if (!concat_str)
		return (NULL);
	while (s1[i] != '\0')
	{
		concat_str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		concat_str[i + j] = s2[j];
		j++;
	}
	concat_str[i + j] = '\0';
	return (concat_str);
}
