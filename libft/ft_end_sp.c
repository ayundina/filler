/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_end_sp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/18 13:21:37 by ayundina      #+#    #+#                 */
/*   Updated: 2019/02/18 13:21:40 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_end_sp(char const *str)
{
	int	len;

	len = (int)ft_strlen(str);
	while ((str[len - 1] == ' ' || str[len - 1] == '\n' || \
		str[len - 1] == '\t') && len > 0)
	{
		len--;
	}
	return (len);
}
