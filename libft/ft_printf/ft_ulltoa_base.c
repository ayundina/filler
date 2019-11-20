/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ulltoa_base.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: exam <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/02 15:06:35 by exam          #+#    #+#                 */
/*   Updated: 2019/05/30 13:12:01 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	ft_ulltoa_base() function converts unsigned long long value into str
**
**	Param 1: a decimal number to convert into a str
**
**	Param 2: a base to use for convertion
**
**	Param 3: specifies with 1, if to use uppercase letters in convertion.
**	Specify 0, for lowercase
**
**	Returns: a str if success, NULL if memory allocation failed
*/

static void	ft_convert_num(char *str, int n_len, unsigned long long value,
		int base)
{
	int	tmp;

	while (value != 0)
	{
		n_len--;
		tmp = value % base;
		if (tmp >= 10)
			str[n_len] = tmp - 10 + 'a';
		else
			str[n_len] = tmp + '0';
		value /= base;
	}
}

int			ft_num_len_base(unsigned long long value, int base)
{
	int	len;

	len = 0;
	if (value == 0)
		len = 1;
	while (value != 0)
	{
		value /= base;
		len++;
	}
	return (len);
}

static void	ft_make_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
}

char		*ft_ulltoa_base(unsigned long long value, int base, int uppercase)
{
	int		n_len;
	char	*str;

	n_len = ft_num_len_base(value, base);
	str = (char *)malloc(sizeof(char) * (n_len + 1));
	if (!str)
		return (NULL);
	str[n_len] = '\0';
	ft_convert_num(str, n_len, value, base);
	if (value == 0)
		str[0] = '0';
	if (uppercase)
		ft_make_uppercase(str);
	return (str);
}
