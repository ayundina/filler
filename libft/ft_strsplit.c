/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/01 08:27:01 by ayundina      #+#    #+#                 */
/*   Updated: 2019/02/04 13:06:39 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		words;
	char	**ret;

	if (!s)
		return (NULL);
	words = ft_countwords(s, c);
	ret = (char **)malloc(sizeof(char*) * (words + 1));
	if (!ret)
		return (NULL);
	ft_getwords(ret, s, c, words);
	return (ret);
}
