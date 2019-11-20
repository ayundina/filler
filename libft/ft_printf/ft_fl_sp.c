/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fl_sp.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 12:24:10 by ayundina      #+#    #+#                 */
/*   Updated: 2019/05/16 12:24:18 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	ft_fl_sp() function applies flag ' ' to a given to ft_printf parameter.
**	Function attaches a space to returning string, if a number given
**	to ft_printf is positive.
**
**	Param 1: t_p *p is a struct which stores all necessary flags and variables
**
**	Returns: 0 if success, -1 if an error occurred
*/

int	ft_fl_sp(t_p *p)
{
	if (p->fl_sp && ft_strchr("dif", *(p->format)))
	{
		if (!p->negative)
		{
			ft_memrealloc(&p->ret_str, &p->tmp, &p->ret, " ");
			ft_strdel(&(p->tmp));
			if (!(p->ret_str))
				return (-1);
		}
	}
	return (0);
}
