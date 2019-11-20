/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 10:17:48 by ayundina      #+#    #+#                 */
/*   Updated: 2019/02/07 10:55:26 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == 0)
		write(fd, "0", 1);
	else if (n < 0)
	{
		if (n == -2147483648)
			write(fd, "-2147483648", 11);
		if (n > -2147483648)
		{
			n *= -1;
			write(fd, "-", 1);
		}
	}
	if (n > 0)
	{
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
		}
		c = n % 10 + '0';
		write(fd, &c, 1);
	}
}
