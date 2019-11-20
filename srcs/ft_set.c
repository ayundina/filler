/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_set.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/25 11:01:43 by ayundina      #+#    #+#                 */
/*   Updated: 2019/06/25 11:01:46 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	ft_del_set() function deletes all the nodes of a linked list and sets
**	it's pointer to NULL
**
**	Param 1: t_set **set is a linked list to delete
**
**	Returns: none
*/

void	ft_del_set(t_set **set)
{
	t_set	*tmp_set;

	while (*set != NULL)
	{
		tmp_set = *set;
		*set = (*set)->next;
		ft_memset((void *)tmp_set, '\0', sizeof(t_set));
		free(tmp_set);
		tmp_set = NULL;
	}
}

/*
**	ft_is_in_set() function searches if a node with given row and column
**	coordinates is present in a linked list
**
**	Param 1: int row is a row coordinate
**
**	Param 2: int col is a column coordinate
**
**	Param 3: t_set *set is a linked list to search within
**
**	Returns: if a node is found ft_is_in_set() function returns
**	g_value (int) of the node. Otherwise it returns 0.
*/

int		ft_is_in_set(int row, int col, t_set *set)
{
	while (set != NULL)
	{
		if (row == set->row && col == set->col)
			return (set->g);
		set = set->next;
	}
	return (0);
}

/*
**	ft_create_module() function creates a new node, sets given row and column
**	coordinates and a parent to a new node
**
**	Param 1: int row is a row coordinate
**
**	Param 2: int col is a column coordinate
**
**	Param 3: t_set *parent is a parent node for a node to be created
**
**	Returns: a new t_set node
*/

t_set	*ft_create_module(int row, int col, t_set *parent)
{
	t_set	*set;

	set = (t_set *)ft_memalloc(sizeof(t_set));
	set->row = row;
	set->col = col;
	set->parent = parent;
	set->next = NULL;
	return (set);
}

/*
**	ft_pop() function traverce through a linked list to find a node with given
**	row and column coordinates and delete it from the set
**
**	Param 1: int row is a row coordinate
**
**	Param 2: int col is a column coordinate
**
**	Param 3: t_set **set is a linked list
**
**	Returns: none
*/

void	ft_pop(int row, int col, t_set **set)
{
	t_set	*tmp_set;
	t_set	*tmp_module;

	tmp_set = *set;
	tmp_module = *set;
	if (tmp_set->row == row && tmp_set->col == col)
	{
		*set = tmp_set->next;
		free(tmp_set);
		tmp_set = NULL;
		return ;
	}
	while (tmp_set != NULL && !(tmp_set->row == row && tmp_set->col == col))
	{
		tmp_module = tmp_set;
		tmp_set = tmp_set->next;
	}
	tmp_module->next = tmp_set->next;
	free(tmp_set);
	tmp_set = NULL;
}

/*
**	ft_push() function creates and attaches a new node to the beggining
**	of a linked list and copies values to a new node from the given node
**
**	Param 1: t_set *module is a node, which values needs to be added
**	to the linked list
**
**	Param 2: t_set **set is a linked list where new node needs to be added
**
**	Returns: none
*/

void	ft_push(t_set *module, t_set **set)
{
	t_set	*tmp_set;

	tmp_set = *set;
	*set = ft_create_module(module->row, module->col, module->parent);
	(*set)->f = module->f;
	(*set)->g = module->g;
	(*set)->h = module->h;
	(*set)->next = tmp_set;
}
