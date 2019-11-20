/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_dibouxf.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 12:09:00 by ayundina      #+#    #+#                 */
/*   Updated: 2019/05/29 13:24:01 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	ft_conv_none() is executed, when given convertion specifier is illegal.
**	Function copies the convertion char as an argument into arg_str
**
**	Param 2: t_p *p is a struct which stores all necessary flags and variables
**
**	Returns: 0 if success, -1 if an error occurred
*/

int	ft_conv_none(t_p *p)
{
	int	i;

	i = 0;
	if (!p->arg_str && !ft_strchr("cspdibouxXf", *(p->format)) \
		&& *(p->format) != '\0')
	{
		p->arg_str = (char *)ft_memalloc(sizeof(char) * 2);
		if (!p->arg_str)
			return (-1);
		p->arg_str[0] = *(p->format);
	}
	return (0);
}
