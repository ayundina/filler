/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fl_precision.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 12:23:23 by ayundina      #+#    #+#                 */
/*   Updated: 2019/05/16 12:23:27 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	ft_fl_prec() function applies flag precision to a given
**	to ft_printf parameter
**
**	Param 1: t_p *p is a struct which stores all necessary flags and variables
**
**	Returns: 0 if success, -1 if an error occurred
*/

/*
**	if (p->fl_prec == 0 && p->arg_str && ft_strchr("pdibouxX", *(p->format)))
**	if prec is zero, print none for all ??what if it's float??
*/

static int	ft_add_padding(t_p *p)
{
	char	*width;

	if (ft_strchr("pdiouxX", *(p->format)))
	{
		p->fl_prec -= ft_strlen(p->arg_str);
		width = (char *)ft_memalloc(sizeof(char) * (p->fl_prec + 1));
		if (!width)
			return (-1);
		ft_memset((void *)width, '0', p->fl_prec);
		ft_memrealloc(&width, &p->tmp, &p->fl_prec, p->arg_str);
		ft_strdel(&p->arg_str);
		p->arg_str = width;
		if (!p->arg_str)
			return (-1);
		ft_strdel(&p->tmp);
	}
	return (0);
}

int			ft_fl_prec(t_p *p)
{
	if (p->fl_prec >= 0 && *(p->format) != 'f' && p->arg_str)
	{
		if (*(p->format) == 's' && (int)ft_strlen(p->arg_str) > p->fl_prec)
		{
			(p->arg_str)[p->fl_prec] = '\0';
		}
		if (*(p->format) == 'o' && p->fl_hash)
			p->fl_prec -= 1;
		if (ft_strlen(p->arg_str) < (size_t)p->fl_prec)
		{
			if (ft_add_padding(p))
				return (-1);
		}
	}
	if (p->fl_prec == 0 && p->arg_str && ft_strchr("pdibouxX", *(p->format)))
	{
		if ((p->arg_str[0] == '0' && p->arg_str[1] == '\0'))
		{
			ft_strdel(&p->arg_str);
		}
	}
	return (0);
}
