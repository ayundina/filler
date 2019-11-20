/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fl_hh.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 12:19:59 by ayundina      #+#    #+#                 */
/*   Updated: 2019/05/16 12:20:06 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	ft_fl_hh() function applies flag hh to a given to ft_printf int number
**	and converts the number into a str.
**
**	Param 1: va_list ap, which gives access
**	to variadic parameters given to ft_printf
**
**	Param 2: t_p *p is a struct which stores all necessary flags and variables
**
**	Returns: 0 if success, -1 if an error occurred
*/

static int	ft_fl_hh_conv_oux(va_list ap, t_p *p)
{
	unsigned char	uc;

	uc = (unsigned char)va_arg(ap, int);
	if (*(p->format) == 'o')
		p->arg_str = ft_ulltoa_base(uc, 8, 0);
	if (*(p->format) == 'u')
		p->arg_str = ft_ulltoa_base(uc, 10, 0);
	if (*(p->format) == 'x')
		p->arg_str = ft_ulltoa_base(uc, 16, 0);
	if (*(p->format) == 'X')
		p->arg_str = ft_ulltoa_base(uc, 16, 1);
	if (!(p->arg_str))
		return (-1);
	return (0);
}

int			ft_fl_hh(va_list ap, t_p *p)
{
	int		i;
	char	c;

	if (p->fl_hh && ft_strchr("di", *(p->format)) && !p->arg_str)
	{
		c = (char)va_arg(ap, int);
		i = c;
		if (i < 0)
		{
			p->negative = true;
			i *= -1;
		}
		p->arg_str = ft_ulltoa_base(i, 10, 0);
		if (!p->arg_str)
			return (-1);
	}
	if (p->fl_hh && ft_strchr("ouxX", *(p->format)))
	{
		if (ft_fl_hh_conv_oux(ap, p))
			return (-1);
	}
	return (0);
}
