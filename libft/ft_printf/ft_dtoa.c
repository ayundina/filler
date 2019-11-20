/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dtoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 12:09:29 by ayundina      #+#    #+#                 */
/*   Updated: 2019/05/16 12:09:32 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	ft_dtoa() function converts a number with a floating point into a str
**
**	Param 1: a number with floating point
**
**	Param 2: precision value to round the number
**
**	Returns: str if success, NULL if an error occurred
*/

static void	convert_double_to_str(char *ret, long double num, int precision)
{
	int		i;
	int		int_part;
	char	*tmp;

	int_part = (int)num;
	tmp = ft_ulltoa_base(int_part, 10, 0);
	ft_strcpy(ret, tmp);
	ft_strdel(&tmp);
	i = ft_num_len_base(int_part, 10);
	num -= int_part;
	if (precision > 0)
	{
		ret[i] = '.';
	}
	while (precision > 0)
	{
		i++;
		num *= 10;
		int_part = (int)num;
		num -= int_part;
		ret[i] = int_part + '0';
		precision--;
	}
}

static void	determine_round_dec(long double *round_dec, int precision)
{
	while (precision > 0)
	{
		*round_dec /= 10;
		precision--;
	}
}

static void	round_dtoa(long double *num, int precision)
{
	int			int_part;
	long double	num_tmp;
	long double	round_dec;

	num_tmp = *num;
	int_part = (int)num_tmp;
	round_dec = 1;
	determine_round_dec(&round_dec, precision);
	num_tmp -= int_part;
	while (precision > 0)
	{
		num_tmp *= 10;
		precision--;
	}
	int_part = (int)num_tmp;
	num_tmp -= int_part;
	if (num_tmp > 0.5)
	{
		*num += round_dec;
	}
}

static char	*malloc_dtoa(char *ret, long double num, int *precision)
{
	int	point;
	int	double_len;

	point = 0;
	if (*precision > 0)
	{
		point = 1;
	}
	double_len = ft_num_len_base((int)num, 10) + point + *precision;
	ret = (char *)malloc(sizeof(char) * (double_len + 1));
	if (!ret)
		return (NULL);
	ft_memset(ret, '\0', double_len + 1);
	return (ret);
}

char		*ft_dtoa(long double num, int precision)
{
	char	*ret;

	ret = NULL;
	ret = malloc_dtoa(ret, num, &precision);
	if (!ret)
		return (NULL);
	round_dtoa(&num, precision);
	convert_double_to_str(ret, num, precision);
	return (ret);
}
