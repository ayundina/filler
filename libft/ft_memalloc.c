/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/30 08:50:31 by ayundina      #+#    #+#                 */
/*   Updated: 2019/01/30 11:47:40 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*memret;

	memret = (char *)malloc(sizeof(char) * size);
	if (!memret)
		return (NULL);
	ft_memset((void *)memret, 0, sizeof(char) * size);
	return ((void *)memret);
}
