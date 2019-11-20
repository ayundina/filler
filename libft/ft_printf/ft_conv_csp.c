/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_csp.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 12:07:35 by ayundina      #+#    #+#                 */
/*   Updated: 2019/05/16 12:07:39 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	ft_conv_c() function converts given to ft_printf character into str
**
**	Param 1: va_list ap, which gives access to variadic parameters given to
**	ft_printf
**
**	Param 2: t_p *p is a struct which stores all necessary flags and variables
**
**	Returns: 0 if success, -1 if an error occurred
*/

int	ft_conv_c(va_list ap, t_p *p)
{
	if (*(p->format) == 'c')
	{
		p->arg_str = (char *)ft_memalloc(sizeof(char) * 2);
		if (!p->arg_str)
			return (-1);
		p->arg_str[0] = va_arg(ap, int);
	}
	return (0);
}

/*
**	ft_conv_s() function duplicate given to ft_printf str into arg_str
**
**	Param 1: va_list ap, which gives access to variadic parameters given to
**	ft_printf
**
**	Param 2: t_p *p is a struct which stores all necessary flags and variables
**
**	Returns: 0 if success, -1 if an error occurred
*/

int	ft_conv_s(va_list ap, t_p *p)
{
	char	*str;

	if (*(p->format) == 's')
	{
		str = va_arg(ap, char *);
		if (str && str[0] != '\0')
		{
			p->arg_str = ft_strdup((const char *)str);
			if (!p->arg_str)
				return (-1);
		}
		if (!str)
		{
			p->arg_str = ft_strdup("(null)");
		}
	}
	return (0);
}

/*
**	ft_conv_p() function converts given to ft_printf pointer into
**	it's pointer address and stores it in arg_str
**
**	Param 1: va_list ap, which gives access to variadic parameters given to
**	ft_printf
**
**	Param 2: t_p *p is a struct which stores all necessary flags and variables
**
**	Returns: 0 if success, -1 if an error occurred
*/

int	ft_conv_p(va_list ap, t_p *p)
{
	if (*(p->format) == 'p' && !p->arg_str)
	{
		p->arg_str = ft_ulltoa_base(va_arg(ap, long long), 16, 0);
		if (!(p->arg_str))
			return (-1);
	}
	return (0);
}
