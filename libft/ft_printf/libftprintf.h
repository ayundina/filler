/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 12:28:17 by ayundina      #+#    #+#                 */
/*   Updated: 2019/05/29 13:37:46 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdbool.h>
# include "../libft.h"

typedef struct		s_p
{
	int				ret;
	int				fl_prec;
	bool			fl_hh;
	bool			fl_h;
	bool			fl_ll;
	bool			fl_l;
	bool			fl_capitll;
	bool			fl_hash;
	int				fl_zero;
	int				fl_width;
	int				fl_minus;
	bool			fl_plus;
	bool			fl_sp;
	bool			negative;
	char			*tmp;
	char			*width;
	char			*arg_str;
	char			*ret_str;
	char			*format;
}					t_p;

int					ft_printf(const char *format, ...);
int					ft_dprintf(int fd, const char *format, ...);
char				*ft_memrealloc(char **str, char **strtmp, int *strlen,
					char *add);

/*
**		Functions to read flags
*/

void				ft_read_flags(t_p *p);

/*
**		Functions to upply flags and convertion types
*/

int					ft_upply_options(va_list ap, t_p *p, int i);

int					ft_fl_hh(va_list ap, t_p *p);
int					ft_fl_h(va_list ap, t_p *p);
int					ft_fl_l(va_list ap, t_p *p);
int					ft_fl_ll(va_list ap, t_p *p);
int					ft_fl_capitll(va_list ap, t_p *p);

int					ft_conv_c(va_list ap, t_p *p);
int					ft_conv_s(va_list ap, t_p *p);
int					ft_conv_p(va_list ap, t_p *p);
int					ft_conv_di(va_list ap, t_p *p);
int					ft_conv_boux(va_list ap, t_p *p);
int					ft_conv_f(va_list ap, t_p *p);
int					ft_conv_none(t_p *p);
int					ft_fl_prec(t_p *p);
int					ft_fl_width(t_p *p);
int					ft_negative_num(t_p *p);
int					ft_fl_hash(t_p *p);

int					ft_fl_plus(t_p *p);
int					ft_fl_sp(t_p *p);
int					ft_fl_minus(t_p *p);
int					ft_fl_zero(t_p *p);

int					ft_combine_options(t_p *p);

/*
**		Converting functions
*/

char				*ft_ulltoa_base(unsigned long long value, int base,
		int uppercase);
int					ft_num_len_base(unsigned long long value, int base);
char				*ft_dtoa(long double num, int precision);
int					ft_arandomtoi(const char *str);

#endif
