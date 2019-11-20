/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fl_ll.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 12:21:25 by ayundina      #+#    #+#                 */
/*   Updated: 2019/05/16 12:21:30 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	ft_fl_ll() function applies flag ll to a given to ft_printf int number
**	and converts the number into a str.
**
**	Param 1: va_list ap, which gives access
**	to variadic parameters given to ft_printf
**
**	Param 2: t_p *p is a struct which stores all necessary flags and variables
**
**	Returns: 0 if success, -1 if an error occurred
*/

static int	ft_fl_ll_conv_f(va_list ap, t_p *p)
{
	double	d;

	d = va_arg(ap, double);
	if (d < 0)
	{
		p->negative = true;
		d *= -1;
	}
	if (!p->fl_prec)
		p->fl_prec = 6;
	p->arg_str = ft_dtoa(d, p->fl_prec);
	if (!(p->arg_str))
		return (-1);
	return (0);
}

static int	ft_fl_ll_conv_oux(va_list ap, t_p *p)
{
	unsigned long long	ull;

	ull = va_arg(ap, unsigned long long);
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

int			ft_fl_ll(va_list ap, t_p *p)
{
	long long	ll;

	if (p->fl_ll && ft_strchr("di", *(p->format)) && !p->arg_str)
	{
		ll = va_arg(ap, long long);
		if (ll < 0)
		{
			p->negative = true;
			ll *= -1;
		}
		p->arg_str = ft_ulltoa_base(ll, 10, 0);
		if (!(p->arg_str))
			return (-1);
	}
	else if (p->fl_ll && ft_strchr("ouxX", *(p->format)) && !p->arg_str)
	{
		if (ft_fl_ll_conv_oux(ap, p))
			return (-1);
	}
	else if (p->fl_ll && *(p->format) == 'f' && !p->arg_str)
	{
		if (ft_fl_ll_conv_f(ap, p))
			return (-1);
	}
	return (0);
}
