/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_getnum.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/18 12:48:57 by ayundina      #+#    #+#                 */
/*   Updated: 2019/02/18 12:48:59 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_getnum(char *ret, int n, int len)
{
	ret[len] = '\0';
	if (n == 0)
	{
		len--;
		ret[len] = '0';
	}
	while (n != 0)
	{
		len--;
		if (n < 0)
			n *= -1;
		ret[len] = n % 10 + '0';
		n /= 10;
	}
}
