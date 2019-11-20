/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_getwords.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/18 13:12:15 by ayundina      #+#    #+#                 */
/*   Updated: 2019/02/18 13:12:17 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_getwords(char **ret, char const *s, char c, int words)
{
	int	next_word;
	int nw_len;

	next_word = 0;
	while (next_word < words && *s != '\0')
	{
		nw_len = 0;
		while (*s == c && *s != '\0')
		{
			s++;
		}
		if (*s != c && *s != '\0')
		{
			while (s[nw_len] != c && s[nw_len] != '\0')
			{
				nw_len++;
			}
			ret[next_word] = (char *)malloc(sizeof(char) * nw_len);
			ft_dupword(ret[next_word], s, c);
			next_word++;
			s += nw_len;
		}
	}
	ret[words] = NULL;
}
