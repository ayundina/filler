/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/24 11:16:42 by ayundina      #+#    #+#                 */
/*   Updated: 2019/04/24 11:16:46 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	ft_memrealloc() function creates new 'str' by attaching 'add'.
**	It takes length of current 'str' (== strlen) + length of 'add'
**	to malloc a fresh 'str'
**	Then, it copies the content of current 'str', saved in tmp
**	Next, it copies content of 'add'.
**	ft_memrealloc() keeps track of new 'strlen' by adding length
**	of 'add' string
**
**	Param 1: char **str is a str to reallocate
**
**	Param 2: char **strtmp to keep the original value of 'str'
**
**	Param 3: int *strlen is original lenght of 'str'
**
**	Param 4: char *add is a string to be concatenated to 'str'
**
**	Returns: new, longer 'str'
*/

char		*ft_memrealloc(char **str, char **strtmp, int *strlen, char *add)
{
	size_t	add_size;
	size_t	total_size;

	add_size = ft_strlen(add);
	total_size = *strlen + add_size + 2;
	*strtmp = *str;
	*str = (char *)ft_memalloc(sizeof(char) * total_size);
	if (!*str)
		return (NULL);
	ft_memcpy((void *)*str, (const void *)*strtmp, (size_t)*strlen);
	ft_memcpy((void *)(*str + *strlen), (const void *)add, add_size);
	*strlen += add_size;
	return (*str);
}

/*
**	ft_read_format() function copies characters from formatted str
**	unless the '%' char is found. After '%' function checks if any flags
**	are present. Next it calls for ft_upply_options() function, where given
**	options and arguments are converted to a string for output.
**
**	Param 1: va_list ap, to access variable arguments in called functions
**
**	Param 2: t_p *p is a struct which stores all necessary flags and variables
**
**	Returns: 0 if success, -1 if an error occurred
*/

static int	ft_read_format(va_list ap, t_p *p)
{
	while (*(p->format) != '\0')
	{
		if (*(p->format) == '%' && *(p->format + 1) == '\0')
			break ;
		if (*(p->format) == '%' && *(p->format + 1) != '\0')
		{
			p->format++;
			if (ft_strchr("hlL#-+ .", *(p->format)) \
				|| ft_isdigit(*(p->format)))
				ft_read_flags(p);
			if (*(p->format) == '\0')
				break ;
			if (ft_upply_options(ap, p, 0))
				return (-1);
			if (ft_combine_options(p))
				return (-1);
			p->ret -= 1;
		}
		else
			p->ret_str[p->ret] = *(p->format);
		p->ret++;
		p->format++;
	}
	return (0);
}

static int	ft_set_default_struct(const char *format, t_p *p)
{
	p->ret = 0;
	p->fl_prec = -1;
	p->fl_width = 0;
	p->fl_hh = false;
	p->fl_h = false;
	p->fl_ll = false;
	p->fl_l = false;
	p->fl_capitll = false;
	p->fl_hash = false;
	p->fl_zero = 0;
	p->fl_minus = 0;
	p->fl_plus = false;
	p->fl_sp = false;
	p->negative = false;
	p->tmp = NULL;
	p->width = NULL;
	p->arg_str = NULL;
	p->ret_str = (char *)ft_memalloc(sizeof(char) * (ft_strlen(format)) + 1);
	if (!p->ret_str)
		return (-1);
	p->format = (char *)format;
	return (0);
}

/*
**	ft_printf() function initializes struct 'p' and sets it's values to default
**	After the format is parsed and ret_str is ready it can be printed in stdout
**
**	Param 1: formatted string that specifies how subsequent arguments
**	are converted for output.
**
**	Param 2: variable arguments, to supply the farmatted string
**
**	Returns: the number of characters printed
**	(not including the trailing `\0' used to end output to strings)
*/

int			ft_printf(const char *format, ...)
{
	t_p		p;
	va_list	ap;

	if (ft_set_default_struct(format, &p))
		return (-1);
	va_start(ap, format);
	if (ft_read_format(ap, &p))
		return (-1);
	va_end(ap);
	write(1, p.ret_str, p.ret);
	ft_strdel(&p.ret_str);
	return (p.ret);
}

/*
**	ft_printf() function initializes struct 'p' and sets it's values to default
**	After the format is parsed and ret_str is ready it can be printed into given
**	file descriptor
**
**	Param 1: formatted string that specifies how subsequent arguments
**	are converted for output.
**
**	Param 2: variable arguments, to supply the farmatted string
**
**	Returns: the number of characters printed
**	(not including the trailing `\0' used to end output to strings)
*/

int			ft_dprintf(int fd, const char *format, ...)
{
	t_p		p;
	va_list	ap;

	if (ft_set_default_struct(format, &p))
		return (-1);
	va_start(ap, format);
	if (ft_read_format(ap, &p))
		return (-1);
	va_end(ap);
	write(fd, p.ret_str, p.ret);
	ft_strdel(&p.ret_str);
	return (p.ret);
}
