/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fl_width.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 12:24:47 by ayundina      #+#    #+#                 */
/*   Updated: 2019/05/16 12:24:51 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	ft_fl_width() function applies a given width to a given to ft_printf
**	parameter, by adding necessary spaces before the argument
**
**	Param 1: t_p *p is a struct which stores all necessary flags and variables
**
**	Returns: 0 if success, -1 if an error occurred
*/

/*
**	p->fl_width = 0; Do I need it?
*/

static int	ft_add_padding(t_p *p)
{
	char	*width;

	width = (char *)ft_memalloc(sizeof(char) * (p->fl_width + 1));
	if (!width)
		return (-1);
	ft_memset((void *)width, ' ', p->fl_width);
	ft_memrealloc(&p->ret_str, &p->tmp, &p->ret, width);
	if (!p->ret_str)
		return (-1);
	ft_strdel(&p->tmp);
	ft_strdel(&width);
	p->fl_width = 0;
	return (0);
}

int			ft_fl_width(t_p *p)
{
	if (p->fl_width > 0)
	{
		if (p->fl_plus || p->fl_sp || p->negative || \
			(p->fl_hash && (*(p->format) == 'o' || *(p->format) == 'f')) || \
			(p->arg_str && (p->arg_str)[0] == '\0' && *(p->format) != 's'))
		{
			p->fl_width -= 1;
		}
		if (*(p->format) == 'p' || \
			(p->fl_hash && ft_strchr("xX", *(p->format))))
		{
			p->fl_width -= 2;
		}
		if (p->arg_str)
			p->fl_width -= ft_strlen(p->arg_str);
		if (p->fl_width > 0)
		{
			if (ft_add_padding(p))
				return (-1);
		}
	}
	return (0);
}
