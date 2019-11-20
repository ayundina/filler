/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/31 10:27:00 by ayundina      #+#    #+#                 */
/*   Updated: 2019/02/07 12:07:09 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		news[i] = f(i, s[i]);
		i++;
	}
	news[i] = '\0';
	return (news);
}
