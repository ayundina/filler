/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_path.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/25 11:01:43 by ayundina      #+#    #+#                 */
/*   Updated: 2019/06/25 11:01:46 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	ft_found_pattern_three() function looks for a pattern:
**		. *
**		* .
** It is necessary to avoid building path through this made by enemy pattern,
**	so enemy will be fully surrounded by block and not just cutted
**
**	Param 1: t_map *map is a struct members of which hold
**	information about the map
**
**	Param 2: t_player *player is a pointer to a struct, which holds information
**	about players
**
**	Param 3: int r is a row coordinate
**
**	Param 4: int c is a column coordinate
**
**	Returns: 1 if within given coordinates a pattern is found,
**	otherwise returns 0
*/

int		ft_found_pattern_three(t_map *map, t_player *player, int r, int c)
{
	if (map->map[r * map->cols + c + r] == '.' \
		|| map->map[r * map->cols + c + r] == player->me)
	{
		if (c + 1 < map->cols && map->map[r * map->cols + c + 1 + r] \
			== player->enemy)
		{
			if (r + 1 < map->rows \
				&& (map->map[(r + 1) * map->cols + c + 1 + r + 1] == '.' \
					|| map->map[(r + 1) * map->cols + c + 1 + r + 1] \
						== player->me))
			{
				if (map->map[(r + 1) * map->cols + c + r + 1] == player->enemy)
				{
					return (1);
				}
			}
		}
	}
	return (0);
}

/*
**	ft_found_pattern_four() function looks for a pattern:
**		* .
**		. *
** It is necessary to avoid building path through this made by enemy pattern,
**	so enemy will be fully surrounded by block and not just cutted.
**
**	Param 1: t_map *map is a struct members of which hold
**	information about the map
**
**	Param 2: t_player *player is a pointer to a struct, which holds information
**	about players
**
**	Param 3: int r is a row coordinate
**
**	Param 4: int c is a column coordinate
**
**	Returns: 1 if within given coordinates a pattern is found,
**	otherwise returns 0
*/

int		ft_found_pattern_four(t_map *map, t_player *player, int r, int c)
{
	if (map->map[r * map->cols + c + r] == '.' \
		|| map->map[r * map->cols + c + r] == player->me)
	{
		if (c - 1 >= 0 && map->map[r * map->cols + c - 1 + r] \
			== player->enemy)
		{
			if (r + 1 < map->rows && c - 1 >= 0 \
				&& (map->map[(r + 1) * map->cols + c - 1 + r + 1] == '.' \
					|| map->map[(r + 1) * map->cols + c - 1 + r + 1] \
						== player->me))
			{
				if (map->map[(r + 1) * map->cols + c + r + 1] == player->enemy)
				{
					return (1);
				}
			}
		}
	}
	return (0);
}

/*
**	ft_is_closest() function checks if a given node of a given linked list
**	has the lowest f_value within all the nodes of the given linked list
**
**	Param 1: t_set *set_node is a node of a given linked list
**
**	Param 2: t_set *set is a linked list
**
**	Returns: 1 a node has lovest f_value within the linked list, otherwise 0
*/

int		ft_is_closest(t_set *set_node, t_set *set)
{
	t_set	*tmp_set;
	int		closest_f;

	tmp_set = set;
	closest_f = set_node->f;
	while (tmp_set != NULL)
	{
		if (closest_f > tmp_set->f)
			closest_f = tmp_set->f;
		tmp_set = tmp_set->next;
	}
	if (set_node->f <= closest_f)
		return (1);
	return (0);
}

/*
**	ft_what_the_path() builds a path from coordinates which are given in the
**	last node of closed set to finish coordinates which are saved in path struct
**
**	Param 1: t_game *gm is a struct, members of which hold
**	all data necessary for the game
**
**	Param 2: t_path *path is a node that has start and finish coordinates
**	of the path
**
**	Param 3: t_set **closed_set is a linked list folowing parents of wich,
**	the path can be reconstruct
**
**	Returns: 1 if a path is built, 0 if path is not existing
*/

int		ft_what_the_path(t_game *gm, t_path *path, t_set **closed_set)
{
	t_set	*tmp_set;

	ft_push(ft_last_node(*closed_set), &gm->open_set);
	tmp_set = gm->open_set;
	ft_del_set(closed_set);
	while (tmp_set != NULL)
	{
		if (ft_is_closest(tmp_set, gm->open_set))
		{
			ft_push(tmp_set, closed_set);
			tmp_set = *closed_set;
			ft_pop(tmp_set->row, tmp_set->col, &gm->open_set);
			if (tmp_set->row == path->finish_row \
				&& tmp_set->col == path->finish_col)
				return (1);
			ft_find_neighbours(gm, tmp_set, path, *closed_set);
			tmp_set = gm->open_set;
		}
		else
			tmp_set = tmp_set->next;
	}
	(*closed_set)->finish_blocked = true;
	return (0);
}

/*
**	ft_key_path_points() allocates memory for path structs and assign start
**	and finish coordinates to path_mid (path from player starting position to
**	the middle of the map) and finish coordinates to path_hor and path_ver.
**
**	Param 1: t_game *gm is a struct, members of which hold
**	all data necessary for the game
**
**	Returns: none
*/

void	ft_key_path_points(t_game *gm)
{
	if (!gm->path_mid)
	{
		gm->path_mid = (t_path *)ft_memalloc(sizeof(t_path));
		gm->path_hor = (t_path *)ft_memalloc(sizeof(t_path));
		gm->path_ver = (t_path *)ft_memalloc(sizeof(t_path));
		gm->path_mid->start_row = gm->player->row_start_me;
		gm->path_mid->start_col = gm->player->col_start_me;
		gm->path_mid->finish_row = (gm->map->rows - 1) / 2;
		gm->path_mid->finish_col = (gm->map->cols - 1) / 2;
		gm->path_hor->finish_row = (gm->map->rows - 1) / 2;
		if (gm->player->col_start_en <= (gm->map->cols - 1) / 2)
			gm->path_hor->finish_col = 0;
		if (gm->player->col_start_en > (gm->map->cols - 1) / 2)
			gm->path_hor->finish_col = gm->map->cols - 1;
		gm->path_ver->finish_col = (gm->map->cols - 1) / 2;
		if (gm->player->row_start_en <= (gm->map->rows - 1) / 2)
			gm->path_ver->finish_row = 0;
		if (gm->player->row_start_en > (gm->map->rows - 1) / 2)
			gm->path_ver->finish_row = gm->map->rows - 1;
	}
}
