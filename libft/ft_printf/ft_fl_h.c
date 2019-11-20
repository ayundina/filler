/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fl_h.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 12:11:01 by ayundina      #+#    #+#                 */
/*   Updated: 2019/05/16 12:11:05 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	ft_fl_h() function applies flag h to a given to ft_printf int number
**	and converts the number into a str.
**
**	Param 1: va_list ap, which gives access
**	to variadic parameters given to ft_printf
**
**	Param 2: t_p *p is a struct which stores all necessary flags and variables
**
**	Returns: 0 if success, -1 if an error occurred
*/

static int	ft_fl_h_conv_oux(va_list ap, t_p *p)
{
	unsigned short	us;

	us = (unsigned short)va_arg(ap, int);
	if (*(p->format) == 'o')
		p->arg_str = ft_ulltoa_base(us, 8, 0);
	if (*(p->format) == 'u')
		p->arg_str = ft_ulltoa_base(us, 10, 0);
	if (*(p->format) == 'x')
		p->arg_str = ft_ulltoa_base(us, 16, 0);
	if (*(p->format) == 'X')
		p->arg_str = ft_ulltoa_base(us, 16, 1);
	if (!(p->arg_str))
		return (-1);
	return (0);
}

int			ft_fl_h(va_list ap, t_p *p)
{
	int		i;
	short	s;

	if (p->fl_h && ft_strchr("di", *(p->format)) && !p->arg_str)
	{
		s = (short)va_arg(ap, int);
		i = s;
		if (i < 0)
		{
			p->negative = true;
			i *= -1;
		}
		p->arg_str = ft_ulltoa_base(i, 10, 0);
		if (!p->arg_str)
			return (-1);
	}
	else if (p->fl_h && ft_strchr("ouxX", *(p->format)) && !p->arg_str)
	{
		if (ft_fl_h_conv_oux(ap, p))
			return (-1);
	}
	return (0);
}
