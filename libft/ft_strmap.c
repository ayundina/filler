/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/30 16:12:21 by ayundina      #+#    #+#                 */
/*   Updated: 2019/02/07 12:04:51 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*news;

	i = 0;
	if (!s)
		return (NULL);
	news = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!news)
		return (NULL);
	while (s[i] != '\0')
	{
		news[i] = f(s[i]);
		i++;
	}
	news[i] = '\0';
	return (news);
}
