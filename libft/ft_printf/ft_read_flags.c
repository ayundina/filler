/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_flags.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 12:26:22 by ayundina      #+#    #+#                 */
/*   Updated: 2019/05/16 12:26:26 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	ft_read_flags() parses given in format flags and stores
**	it's values in a struct
**
**	Param 1: t_p *p is a struct which stores all necessary flags and variables
**
**	Returns: none
*/

static void	ft_read_more_more_flags(t_p *p)
{
	if (*(p->format) == '#' && *(p->format + 1) != '\0')
		p->fl_hash = true;
	if (*(p->format) == '-' && *(p->format + 1) != '\0' \
		&& *(p->format + 1) != '.')
	{
		p->fl_minus = ft_arandomtoi(p->format + 1);
		if (p->fl_zero)
			p->fl_zero = 0;
	}
	if (*(p->format) == '+' && *(p->format + 1) != '\0')
	{
		p->fl_plus = true;
		if (p->fl_sp)
			p->fl_sp = false;
	}
	if (*(p->format) == ' ' && *(p->format + 1) != '\0')
	{
		if (!p->fl_plus)
			p->fl_sp = true;
	}
	if (*(p->format) == '*' && *(p->format + 1) != '\0')
		p->fl_sp = true;
}

static void	ft_read_more_flags(t_p *p)
{
	if (*(p->format) == '.' && *(p->format + 1) != '\0')
	{
		if (p->fl_prec < 0)
			p->fl_prec = ft_arandomtoi(p->format + 1);
	}
	if (*(p->format) == 'h' && *(p->format + 1) != '\0' \
		&& *(p->format + 1) != 'h')
		p->fl_h = true;
	if (*(p->format) == 'h' && *(p->format + 1) != '\0' \
		&& *(p->format + 1) == 'h')
	{
		p->fl_hh = true;
		p->format++;
	}
	if (*(p->format) == 'l' && *(p->format + 1) != '\0' \
		&& *(p->format + 1) != 'l')
		p->fl_l = true;
	if (*(p->format) == 'l' && *(p->format + 1) != '\0' \
		&& *(p->format + 1) == 'l')
	{
		p->fl_ll = true;
		p->format++;
	}
	if (*(p->format) == 'L' && *(p->format + 1) != '\0')
		p->fl_capitll = true;
}

void		ft_read_flags(t_p *p)
{
	while (*(p->format) != '\0' && (ft_strchr("hlL#-+ .", *(p->format)) \
			|| ft_isdigit(*(p->format))))
	{
		if (*(p->format) == '0' && *(p->format + 1) != '\0')
		{
			if (!p->fl_zero && !p->fl_width && !p->fl_minus && p->fl_prec < 0)
				p->fl_zero = ft_arandomtoi(p->format);
		}
		if (ft_isdigit(*(p->format)))
		{
			if (!p->fl_minus && !p->fl_zero && !p->fl_width && p->fl_prec < 0)
				p->fl_width = ft_arandomtoi(p->format);
		}
		ft_read_more_flags(p);
		ft_read_more_more_flags(p);
		p->format++;
	}
	if (p->fl_prec > -1 && p->fl_zero && ft_strchr("dibouxX", *(p->format)))
	{
		p->fl_width = p->fl_zero;
		p->fl_zero = 0;
	}
}
