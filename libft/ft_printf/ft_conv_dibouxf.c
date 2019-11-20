/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_dibouxf.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 12:09:00 by ayundina      #+#    #+#                 */
/*   Updated: 2019/05/16 12:09:04 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	ft_negative_num() adds '-' caracter to return string if a number received
**	by ft_printf is a negative number
**
**	Param 1: t_p *p is a struct which stores all necessary flags and variables
**
**	Returns: 0 if success, -1 if an error occurred
*/

int	ft_negative_num(t_p *p)
{
	if (p->negative && p->fl_width <= 0)
	{
		ft_memrealloc(&p->ret_str, &p->tmp, &p->ret, "-");
		if (!p->ret_str)
			return (-1);
		ft_strdel(&(p->tmp));
	}
	return (0);
}

/*
**	ft_conv_di() converts int variable, given as a parameter to ft_printf
**	into str
**
**	Param 1: va_list ap, which gives access
**	to variadic parameters given to ft_printf
**
**	Param 2: t_p *p is a struct which stores all necessary flags and variables
**
**	Returns: 0 if success, -1 if an error occurred
*/

int	ft_conv_di(va_list ap, t_p *p)
{
	int		i;
	long	l;

	if ((*(p->format) == 'd' || *(p->format) == 'i') && !p->arg_str)
	{
		i = va_arg(ap, int);
		l = i;
		if (i < 0)
		{
			p->negative = true;
			l *= -1;
		}
		p->arg_str = ft_ulltoa_base(l, 10, 0);
		if (!(p->arg_str))
			return (-1);
	}
	return (0);
}

/*
**	ft_conv_boux() converts int variable, given as a parameter to ft_printf
**	into binary or octal or unsigned or hexadesimal and stores it in a str
**
**	Param 1: va_list ap, which gives access
**	to variadic parameters given to ft_printf
**
**	Param 2: t_p *p is a struct which stores all necessary flags and variables
**
**	Returns: 0 if success, -1 if an error occurred
*/

/*
**	if (ui == 0 && ft_strchr("xX", *(p->format))) // this is inconsisten,
**	it makes %.0o = 0 and %.0x = (nothing)
*/

int	ft_conv_boux(va_list ap, t_p *p)
{
	int				base;
	unsigned int	ui;

	base = 10;
	if (ft_strchr("bouxX", *(p->format)) && !p->arg_str && *(p->format) != '\0')
	{
		ui = va_arg(ap, unsigned int);
		if (ui == 0 && ft_strchr("xX", *(p->format)))
			p->fl_hash = false;
		if (*(p->format) == 'b')
			base = 2;
		if (*(p->format) == 'o')
			base = 8;
		if (*(p->format) == 'u')
			base = 10;
		if (*(p->format) == 'x' || *(p->format) == 'X')
			base = 16;
		if (!(p->arg_str) && *(p->format) != 'X')
			p->arg_str = ft_ulltoa_base(ui, base, 0);
		if (!(p->arg_str) && *(p->format) == 'X')
			p->arg_str = ft_ulltoa_base(ui, base, 1);
		if (!(p->arg_str))
			return (-1);
	}
	return (0);
}

/*
**	ft_conv_f() function converts float variable, given as a parameter to
**	ft_printf into an arg_str
**
**	Param 1: va_list ap, which gives access
**	to variadic parameters given to ft_printf
**
**	Param 2: t_p *p is a struct which stores all necessary flags and variables
**
**	Returns: 0 if success, -1 if an error occurred
*/

int	ft_conv_f(va_list ap, t_p *p)
{
	double	f;

	if (*(p->format) == 'f' && !p->arg_str)
	{
		if (!(p->arg_str))
		{
			f = va_arg(ap, double);
			if (f < 0)
			{
				p->negative = true;
				f *= -1;
			}
			if (p->fl_prec == -1)
				p->fl_prec = 6;
			p->arg_str = ft_dtoa(f, p->fl_prec);
		}
		if (!(p->arg_str))
			return (-1);
	}
	return (0);
}
