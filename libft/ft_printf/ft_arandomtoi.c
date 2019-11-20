/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_arandomtoi.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 12:06:49 by ayundina      #+#    #+#                 */
/*   Updated: 2019/05/16 12:07:06 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	ft_arandomtoi() function skips any char and zero in str,
**	before it finds a group of digits, converts digit characters
**	from str to int.
**
**	Param 1: a str with characters and group of digits to extract
**
**	Returns: integer value or 0 in case of no digits in a str
*/

int	ft_arandomtoi(const char *str)
{
	int	i;
	int	nb;
	int	sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (str[i] != '\0' && (!ft_isdigit(str[i]) || str[i] == '0'))
	{
		if (str[i] == '%')
		{
			return (0);
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb);
}
