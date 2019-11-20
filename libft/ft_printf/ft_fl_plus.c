/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fl_plus.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 12:22:48 by ayundina      #+#    #+#                 */
/*   Updated: 2019/05/16 12:22:51 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	ft_fl_plus() function applies flag '+' to a given to ft_printf parameter.
**	Function attaches '+' to returning string if a number given to ft_printf
**	is positive. '+' is attached to returning string, before converted arg
**	is attached.
**
**	Param 1: t_p *p is a struct which stores all necessary flags and variables
**
**	Returns: 0 if success, -1 if an error occurred
*/

int	ft_fl_plus(t_p *p)
{
	if (p->fl_plus && ft_strchr("dif", *(p->format)))
	{
		if (!p->negative)
		{
			ft_memrealloc(&p->ret_str, &p->tmp, &p->ret, "+");
			ft_strdel(&(p->tmp));
			if (!(p->ret_str))
				return (-1);
		}
	}
	return (0);
}
