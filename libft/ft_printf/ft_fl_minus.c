/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fl_minus.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 12:22:08 by ayundina      #+#    #+#                 */
/*   Updated: 2019/05/16 12:22:20 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	ft_fl_minus() function applies flag '-' to a given to ft_printf parameter
**	and adds necessary padding to the arg_str on the right.
**
**	Param 1: t_p *p is a struct which stores all necessary flags and variables
**
**	Returns: 0 if success, -1 if an error occurred
*/

static int	ft_add_padding(t_p *p)
{
	int		len;
	char	*width;

	width = (char *)ft_memalloc(sizeof(char) * (p->fl_minus + 1));
	if (!width)
		return (-1);
	ft_memset((void *)width, ' ', p->fl_minus);
	if (!p->arg_str)
	{
		p->arg_str = (char *)ft_memalloc(sizeof(char) * 2);
		if (!p->arg_str)
			return (-1);
	}
	if (*(p->format) != 'c')
		len = (int)ft_strlen(p->arg_str);
	if (*(p->format) == 'c')
		len = 1;
	ft_memrealloc(&p->arg_str, &p->tmp, &len, width);
	if (!p->arg_str)
		return (-1);
	ft_strdel(&p->tmp);
	ft_strdel(&width);
	return (0);
}

int			ft_fl_minus(t_p *p)
{
	if (p->fl_minus)
	{
		if (p->fl_plus || p->negative || (p->fl_hash && *(p->format) == 'o') \
			|| (p->arg_str && !ft_strlen(p->arg_str) && *(p->format) == 'c'))
		{
			p->fl_minus -= 1;
		}
		if (*(p->format) == 'p' \
			|| (p->fl_hash && ft_strchr("xX", *(p->format))))
		{
			p->fl_minus -= 2;
		}
		if (p->arg_str)
			p->fl_minus -= ft_strlen(p->arg_str);
		if (p->fl_minus > 0)
		{
			if (ft_add_padding(p))
				return (-1);
		}
	}
	return (0);
}
