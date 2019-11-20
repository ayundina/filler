/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fl_zero.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 12:25:16 by ayundina      #+#    #+#                 */
/*   Updated: 2019/05/16 12:25:20 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	ft_fl_zero() function adds zero padding to a given to ft_printf parameter.
**	Function attaches zeros to returning string, before converted argument
**	is attached
**
**	Param 1: t_p *p is a struct which stores all necessary flags and variables
**
**	Returns: 0 if success, -1 if an error occurred
*/

static int	ft_add_padding(t_p *p)
{
	char	*width;

	width = (char *)ft_memalloc(sizeof(char) * (p->fl_zero + 1));
	if (!width)
		return (-1);
	ft_memset((void *)width, '0', p->fl_zero);
	ft_memrealloc(&p->ret_str, &p->tmp, &p->ret, width);
	if (!p->ret_str)
		return (-1);
	ft_strdel(&p->tmp);
	ft_strdel(&width);
	return (0);
}

int			ft_fl_zero(t_p *p)
{
	if (p->fl_zero && p->arg_str)
	{
		if (p->fl_plus || p->negative || p->fl_sp \
			|| (p->fl_hash && *(p->format) == 'o') \
			|| (!ft_strlen(p->arg_str) && *(p->format) == 'c'))
			p->fl_zero -= 1;
		if (*(p->format) == 'p' \
			|| (p->fl_hash && ft_strchr("xX", *(p->format))))
			p->fl_zero -= 2;
		p->fl_zero -= ft_strlen(p->arg_str);
		if (p->fl_zero > 0)
		{
			if (ft_add_padding(p))
				return (-1);
		}
	}
	return (0);
}
