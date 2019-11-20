/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fl_hash.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 12:19:14 by ayundina      #+#    #+#                 */
/*   Updated: 2019/05/16 12:19:24 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	ft_fl_hash() function applies flag # to a given to ft_printf number
**	and converts the number into a str in "alternative form" with additional
**	'0' for octal num and '0x' or '0X' for hexadesimal num.
**
**	Param 1: t_p *p is a struct which stores all necessary flags and variables
**
**	Returns: 0 if success, -1 if an error occurred
*/

static int	ft_hash_conv_xp(t_p *p)
{
	if (*(p->format) == 'x' || *(p->format) == 'p')
	{
		ft_memrealloc(&p->ret_str, &p->tmp, &p->ret, "x");
		if (!(p->ret_str))
			return (-1);
		ft_strdel(&(p->tmp));
	}
	if (*(p->format) == 'X')
	{
		ft_memrealloc(&p->ret_str, &p->tmp, &p->ret, "X");
		if (!(p->ret_str))
			return (-1);
		ft_strdel(&(p->tmp));
	}
	return (0);
}

int			ft_fl_hash(t_p *p)
{
	int	len;

	if (((p->fl_hash && ft_strchr("oxX", *(p->format))) || *(p->format) == 'p'))
	{
		if (*(p->format) == 'o' && p->arg_str \
			&& (p->arg_str[0] == '0' && p->arg_str[1] == '\0'))
			ft_strdel(&p->arg_str);
		ft_memrealloc(&p->ret_str, &p->tmp, &p->ret, "0");
		if (!(p->ret_str))
			return (-1);
		ft_strdel(&(p->tmp));
		if (ft_hash_conv_xp(p))
			return (-1);
	}
	if (p->fl_hash && *(p->format) == 'f' && p->fl_prec == 0)
	{
		if (p->arg_str)
		{
			len = (int)ft_strlen(p->arg_str);
			ft_memrealloc(&p->arg_str, &p->tmp, &len, ".");
		}
	}
	return (0);
}
