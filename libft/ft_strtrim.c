/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/31 14:21:03 by ayundina      #+#    #+#                 */
/*   Updated: 2019/02/01 08:26:03 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		l_offset;
	int		r_offset;
	char	*str;

	if (!s)
		return (NULL);
	l_offset = ft_beg_sp(s);
	r_offset = ft_end_sp(s);
	if (r_offset - l_offset > 0)
	{
		if (!(str = (char *)malloc(sizeof(char) * (r_offset - l_offset) + 1)))
			return (NULL);
		str = ft_strncpy(str, &s[l_offset], r_offset - l_offset);
		str[r_offset - l_offset] = '\0';
	}
	else
	{
		str = (char *)malloc(sizeof(char) * 1);
		str[0] = '\0';
	}
	return (str);
}
