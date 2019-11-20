/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_starting.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 18:36:46 by ayundina      #+#    #+#                 */
/*   Updated: 2019/07/23 18:36:53 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	ft_last_node() function traverses diven linked list till the last node
**	and returns it
**
**	Param 1: t_set *set is a linked list
**
**	Returns: last node of a given linked list
*/

t_set	*ft_last_node(t_set *set)
{
	while (set->next != NULL)
		set = set->next;
	return (set);
}

/*
**	ft_row_col_to_start() gives starting coordinates (row and column) to iterate
**	and check possible piece placements near a path block
**
**	Param 1: int *row is a pointer to a row coordinate to be assigned
**
**	Param 2: int *col is a pointer to a column coordinate to be assigned
**
**	Param 3: t_set *closed_set is a node of path linked list containing
**	coordinates of a path block. Following parents of closed set a path
**	can be reconstracted
**
**	Param 4: t_map *map is a pointer to a struct members of which hold
**	information about the map
**
**	Returns: none
*/

void	ft_row_col_to_start(int *row, int *col, t_set *closed_set, t_map *map)
{
	if (row != NULL)
	{
		*row = closed_set->row - map->rows / 12;
		if (*row < 0)
			*row = 0;
	}
	if (col != NULL)
	{
		*col = closed_set->col - map->cols / 12;
		if (*col < 0)
			*col = 0;
	}
}

/*
**	when pieces are placed following the path
**	to the middle and middle of the map is reached:
**	ft_find_starting_point() function checks where placed pieces overlap with
**	the path to the middle and assigns the closest to the middle overlap
**	as starting coordinates for making horizontal and vertical path
**
**	Param 1: t_game *gm is a struct, members of which hold
**	all data necessary for the game
**
**	Param 2: int *row is a pointer to a row coordinate to be assigned
**
**	Param 3: int *col is a pointer to a column coordinate to be assigned
**
**	Returns: none
*/

void	ft_find_starting_point(t_game *gm, int *row, int *col)
{
	t_set	*tmp_set;

	tmp_set = gm->closed_mid_set;
	while (tmp_set != NULL)
	{
		if (gm->map->map[tmp_set->row * gm->map->cols + tmp_set->col \
							+ tmp_set->row] == gm->player->me)
		{
			*row = tmp_set->row;
			*col = tmp_set->col;
			return ;
		}
		tmp_set = tmp_set->parent;
	}
}

/*
**	when pieces are placed following the path
**	to the middle and middle of the map is reached:
**	ft_starting_hor_ver_set() function assigns starting coordinates
**	for horizontal and vertical pathes,
**	creates first nodes vertical and horizontal closed sets
** and evaluate them (calculates f, g and h values, as in A* algorithm)
**
**	Param 1: t_game *gm is a struct, members of which hold
**	all data necessary for the game
**
**	Returns: none
*/

void	ft_starting_hor_ver_set(t_game *gm)
{
	if (!gm->closed_hor_set)
	{
		ft_find_starting_point(gm, &gm->path_hor->start_row,
								&gm->path_hor->start_col);
		ft_find_starting_point(gm, &gm->path_ver->start_row,
								&gm->path_ver->start_col);
		gm->closed_hor_set = ft_create_module(gm->path_hor->start_row,
												gm->path_hor->start_col, NULL);
		ft_evaluate_set(gm->closed_hor_set, gm->path_hor, NULL);
		gm->closed_ver_set = ft_create_module(gm->path_ver->start_row,
												gm->path_ver->start_col, NULL);
		ft_evaluate_set(gm->closed_ver_set, gm->path_ver, NULL);
	}
}

/*
**	when the game starts:
**	ft_starting_mid_set() function creates first node of closed set
**	(as in A* algorithm) assigning it starting coordinates of my player
**	and evaluate it (calculates f, g and h values, as in A* algorithm)
**
**	Param 1: t_game *gm is a struct, members of which hold
**	all data necessary for the game
**
**	Returns: none
*/

void	ft_starting_mid_set(t_game *gm)
{
	if (!gm->closed_mid_set)
	{
		gm->closed_mid_set = (t_set *)ft_memalloc(sizeof(t_set));
		gm->closed_mid_set->row = gm->player->row_start_me;
		gm->closed_mid_set->col = gm->player->col_start_me;
		ft_evaluate_set(gm->closed_mid_set, gm->path_mid, NULL);
	}
}
