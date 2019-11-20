/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/12 14:25:03 by ayundina      #+#    #+#                 */
/*   Updated: 2019/02/12 14:25:06 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		len;
	char	*ret;

	len = ft_intlen(n);
	ret = (char *)malloc(sizeof(char) * len + 1);
	if (!ret)
		return (NULL);
	if (n < 0)
	{
		ft_getnum(ret, n, len);
		if (n == -2147483648)
			ret[len - 1] = '8';
		ret[0] = '-';
		return (ret);
	}
	if (n >= 0)
	{
		ft_getnum(ret, n, len);
		return (ret);
	}
	return (0);
}
