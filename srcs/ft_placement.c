/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_placement.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 18:56:21 by ayundina      #+#    #+#                 */
/*   Updated: 2019/07/23 18:56:24 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	ft_within_check_area() function checks if current point in row or column
**	is within the area around a path block, which is going to be checked
**	for a possible placement of a piece
**
**	Param 1: int current is a row or column number
**
**	Param 2: int path_point is a row or column path coordinate
**	(row number of path_point is given to check row number of current point and
**	column number of path_point is given to check column number
**	of current point)
**
**	Param 3: int map_max is an amount of rows or columns in the map
**	(number of rows of the map is given to check row number of current point and
**	number of columns of the map is given to check column number
**	of current point)
**
**	Returns: 1 if a current row or current column is within the checking area
** or 0 otherwise
*/

static int	ft_within_check_area(int current, int path_point, int map_max)
{
	if (current <= path_point + map_max / 12 \
		&& current < map_max)
	{
		return (1);
	}
	return (0);
}

/*
**	ft_path_is_on() function checks if a node frome closed_set linked list
**	is not NULL and the path coordinate (in closed set) is not overlaped
**	with any previously placed block of a piece
**
**	Param 1: t_set *closed_set is a pointer to a linked list, following parents
**	of which a path can be reconstructed
**
**	Param 2: t_map *map is a pointer to a struct members of which hold
**	information about the map
**
**	Param 3: t_player *player is a pointer to a struct, which holds information
**	about players
**
**	Returns: 1 if a closed_set node is fine to work with or 0 otherwise
*/

static int	ft_path_is_on(t_set *closed_set, t_map *map, t_player *player)
{
	if (closed_set != NULL \
		&& map->map[closed_set->row * map->cols + closed_set->col \
					+ closed_set->row] != player->me)
	{
		return (1);
	}
	return (0);
}

/*
**	ft_find_best_placement() function traverses through the path
**	from finish to start. For each block of the path a square area is taken
**	around the path block to check for a possible placement of a piece.
**	If a coordinate is valid for a placement of a piece it's saved in a linked
**	list and evaluated for how close it is to the finish and to the path.
**
**	Param 1: t_game *gm is a struct, members of which hold
**	all data necessary for the game
**
**	Param 2: t_path *path is a pointer to a struct which holds start and finish
** coordinates of the path
**
**	Param 3: t_set *closed_set is a pointer to a linked list, following parents
**	of which a path can be reconstructed
**
**	Returns: 1
*/

int			ft_find_best_placement(t_game *gm, t_path *path, t_set *closed_set)
{
	int		tmp_r;
	int		tmp_c;
	t_set	*tmp_set;

	while (ft_path_is_on(closed_set, gm->map, gm->player))
	{
		ft_row_col_to_start(&tmp_r, &tmp_c, closed_set, gm->map);
		while (ft_within_check_area(tmp_r, closed_set->row, gm->map->rows))
		{
			while (ft_within_check_area(tmp_c, closed_set->col, gm->map->cols))
			{
				if (ft_valid_move(gm, tmp_r, tmp_c, 0) \
					&& !ft_is_in_set(tmp_r, tmp_c, gm->open_set))
				{
					tmp_set = ft_create_module(tmp_r, tmp_c, closed_set);
					ft_evaluate_push_pop(tmp_set, path, &gm->open_set);
				}
				tmp_c++;
			}
			ft_row_col_to_start(NULL, &tmp_c, closed_set, gm->map);
			tmp_r++;
		}
		closed_set = closed_set->parent;
	}
	return (1);
}
