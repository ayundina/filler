/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/14 15:19:16 by ayundina      #+#    #+#                 */
/*   Updated: 2019/02/14 15:19:22 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp_next;

	while (*alst != NULL)
	{
		tmp_next = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = tmp_next;
	}
}
