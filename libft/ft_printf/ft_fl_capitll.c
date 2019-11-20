/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fl_capitl.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 12:10:08 by ayundina      #+#    #+#                 */
/*   Updated: 2019/05/16 12:10:14 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	ft_fl_capitll() function applies flag L to a given to ft_printf
**	floating number and converts the number into a str. Flag L casts floating
**	point number as loong double
**
**	Param 1: va_list ap, which gives access
**	to variadic parameters given to ft_printf
**
**	Param 2: t_p *p is a struct which stores all necessary flags and variables
**
**	Returns: 0 if success, -1 if an error occurred
*/

int	ft_fl_capitll(va_list ap, t_p *p)
{
	long double	ld;

	if (p->fl_capitll && *(p->format) == 'f' && !p->arg_str)
	{
		ld = va_arg(ap, long double);
		if (ld < 0)
		{
			p->negative = true;
			ld *= -1;
		}
		if (p->fl_prec == -1)
			p->fl_prec = 6;
		p->arg_str = ft_dtoa(ld, p->fl_prec);
		if (!(p->arg_str))
			return (-1);
	}
	return (0);
}
