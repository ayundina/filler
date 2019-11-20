/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_upply_options.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 12:27:42 by ayundina      #+#    #+#                 */
/*   Updated: 2019/05/16 12:27:46 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	ft_upply_options() function traverce the functions,
**	which applies given flags
**
**	Param 1: va_list ap, which gives access
**	to variadic parameters given to ft_printf
**
**	Param 2: t_p *p is a struct which stores all necessary flags and variables
**
**	Returns: 0 if success, -1 if an error occurred
*/

static int	ft_modify_options(t_p *p, int i)
{
	int	(*modify[9])(t_p *);

	modify[0] = ft_conv_none;
	modify[1] = ft_fl_prec;
	modify[2] = ft_fl_width;
	modify[3] = ft_negative_num;
	modify[4] = ft_fl_hash;
	modify[5] = ft_fl_plus;
	modify[6] = ft_fl_sp;
	modify[7] = ft_fl_minus;
	modify[8] = ft_fl_zero;
	while (i < 9)
	{
		if ((*modify[i])(p))
			return (-1);
		i++;
	}
	return (0);
}

int			ft_upply_options(va_list ap, t_p *p, int i)
{
	int	(*convert[11])(va_list, t_p *);

	convert[0] = ft_fl_hh;
	convert[1] = ft_fl_h;
	convert[2] = ft_fl_l;
	convert[3] = ft_fl_ll;
	convert[4] = ft_fl_capitll;
	convert[5] = ft_conv_c;
	convert[6] = ft_conv_s;
	convert[7] = ft_conv_p;
	convert[8] = ft_conv_di;
	convert[9] = ft_conv_boux;
	convert[10] = ft_conv_f;
	while (i < 11)
	{
		if ((*convert[i])(ap, p))
			return (-1);
		i++;
	}
	ft_modify_options(p, 0);
	return (0);
}

static void	ft_set_defaul_flags(t_p *p)
{
	p->fl_prec = -1;
	p->fl_width = 0;
	p->fl_hh = false;
	p->fl_h = false;
	p->fl_ll = false;
	p->fl_l = false;
	p->fl_capitll = false;
	p->fl_hash = false;
	p->fl_zero = 0;
	p->fl_minus = 0;
	p->fl_plus = false;
	p->fl_sp = false;
	p->negative = false;
	p->tmp = NULL;
	p->width = NULL;
	p->arg_str = NULL;
}

static int	ft_add_extra_space(t_p *p)
{
	int	ret_len;

	ret_len = p->ret;
	ft_memrealloc(&p->ret_str, &p->tmp, &ret_len, p->format);
	if (!p->ret_str)
		return (-1);
	ft_strdel(&p->tmp);
	return (0);
}

/*
**	ft_combine_options() adds arg_str (given to ft_printf arg, converted to str)
**	to ret_str (str to be printed, eventually)
**
**	Param 1: t_p *p is a struct which stores all necessary flags and variables
**
**	Returns: 0 if success, -1 if an error occurred
*/

int			ft_combine_options(t_p *p)
{
	if (*(p->format) == 'c')
	{
		p->ret_str[p->ret] = p->arg_str[0];
		p->ret += 1;
		if (p->fl_minus)
		{
			ft_memrealloc(&p->ret_str, &p->tmp, &p->ret, p->arg_str + 1);
			if (!(p->ret_str))
				return (-1);
			ft_strdel(&p->tmp);
		}
		ft_strdel(&p->arg_str);
	}
	if (p->arg_str)
	{
		ft_memrealloc(&p->ret_str, &p->tmp, &p->ret, p->arg_str);
		if (!(p->ret_str))
			return (-1);
		ft_strdel(&p->tmp);
		ft_strdel(&p->arg_str);
	}
	ft_add_extra_space(p);
	ft_set_defaul_flags(p);
	return (0);
}
