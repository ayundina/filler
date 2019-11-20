/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fl_l.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 12:20:56 by ayundina      #+#    #+#                 */
/*   Updated: 2019/05/16 12:21:01 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	ft_fl_l() function applies flag l to a given to ft_printf int number
**	and converts the number into a str.
**
**	Param 1: va_list ap, which gives access
**	to variadic parameters given to ft_printf
**
**	Param 2: t_p *p is a struct which stores all necessary flags and variables
**
**	Returns: 0 if success, -1 if an error occurred
*/

static int	ft_fl_l_conv_oux(va_list ap, t_p *p)
{
	unsigned long	ull;

	ull = va_arg(ap, unsigned long);
	if (*(p->format) == 'o')
		p->arg_str = ft_ulltoa_base(ull, 8, 0);
	if (*(p->format) == 'u')
		p->arg_str = ft_ulltoa_base(ull, 10, 0);
	if (*(p->format) == 'x')
		p->arg_str = ft_ulltoa_base(ull, 16, 0);
	if (*(p->format) == 'X')
		p->arg_str = ft_ulltoa_base(ull, 16, 1);
	if (!(p->arg_str))
		return (-1);
	return (0);
}

int			ft_fl_l(va_list ap, t_p *p)
{
	long	l;

	if (p->fl_l && ft_strchr("di", *(p->format)) && !p->arg_str)
	{
		l = va_arg(ap, long);
		if (l < 0)
		{
			p->negative = true;
			l *= -1;
		}
		p->arg_str = ft_ulltoa_base(l, 10, 0);
		if (!(p->arg_str))
			return (-1);
	}
	else if (p->fl_l && ft_strchr("ouxX", *(p->format)) && !p->arg_str)
	{
		if (ft_fl_l_conv_oux(ap, p))
			return (-1);
	}
	return (0);
}
