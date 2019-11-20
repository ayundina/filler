/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_neighbours.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 19:18:48 by ayundina      #+#    #+#                 */
/*   Updated: 2019/07/23 19:19:13 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	ft_neighbour_is_a_char() function checks if a coordinate taken by a certain
**	character (enemy character for example, 'X' or 'O')
**
**	Param 1: char a_char is a char to search for in a given coordinate
**
**	Param 2: t_map *map is a pointer to a struct members of which hold
**	information about the map
**
**	Param 3: int r is a row coordinate
**
**	Param 4: int c is a column coordinate
**
**	Returns: 1 if the given coordinate of the map filled with a given character
** or 0 otherwise
*/

int			ft_neighbour_is_a_char(char a_char, t_map *map, int r, int c)
{
	if ((r - 1 >= 0 && map->map[(r - 1) * map->cols + c + r - 1] == a_char) \
		|| (r - 1 >= 0 && c + 1 < map->cols \
			&& map->map[(r - 1) * map->cols + c + r] == a_char) \
		|| (c + 1 < map->cols \
			&& map->map[r * map->cols + c + 1 + r] == a_char) \
		|| (r + 1 < map->rows && c + 1 < map->cols \
			&& map->map[(r + 1) * map->cols + c + 1 + r + 1] == a_char) \
		|| (r + 1 < map->rows \
			&& map->map[(r + 1) * map->cols + c + r + 1] == a_char) \
		|| (r + 1 < map->rows && c - 1 >= 0 \
			&& map->map[(r + 1) * map->cols + c + r] == a_char) \
		|| (c - 1 >= 0 \
			&& map->map[r * map->cols + c - 1 + r] == a_char) \
		|| (r - 1 >= 0 && c - 1 >= 0 \
			&& map->map[(r - 1) * map->cols + c - 1 + r - 1] == a_char))
	{
		return (1);
	}
	return (0);
}

/*
**	ft_next_neighbour() function switches coordinates
**	to the coordinates of next neigbour of current coordinates
**
**	Param 1: t_set *current is a pointer to a node, which holds coordinates
**	of current path position and neighbours of which have to be found
**
**	Param 2: int *r is a pointer to a row coordinate
**
**	Param 3: int *c is a pointer to a column coordinate
**
**	Param 4: int i is an iteration index.
**	Increasing the index in a calling function leads to the next neighbour
**
**	Returns: 1 if the is a next neighbour (maximum 8 neighbours
**	can be discovered) or 0 if all the neighbours were discovered
*/

static int	ft_next_neighbour(t_set *current, int *r, int *c, int i)
{
	while (i < 8)
	{
		if (i == 0 || i == 4)
			*c = current->col;
		if (i == 1 || i == 2 || i == 3)
			*c = current->col + 1;
		if (i == 5 || i == 6 || i == 7)
			*c = current->col - 1;
		if (i == 7 || i == 0 || i == 1)
			*r = current->row - 1;
		if (i == 6 || i == 2)
			*r = current->row;
		if (i == 3 || i == 4 || i == 5)
			*r = current->row + 1;
		return (1);
	}
	return (0);
}

/*
**	ft_valid_neighbour() function checks if a neighbour coordinate
**	is within the map. The valid coordinate can be taken by me or empty,
**	it's not cutting through the enemy placements but goes around and
**	it's not in a linked list with discovered paths (closed_set)
**
**	Param 1: t_game *gm is a pointer to a struct, members of which hold
**	all data necessary for the game
**
**	Param 2: t_set *cl_set is a pointer to a linked list
**	following parents of which will reconstruct a path
**	from current coordinate to a start coordinate and following next of which
**	will reveal all the coordinates of possible paths so far
**
**	Param 3: int r is a row coordinate of a neighbour to be checked
**
**	Param 4: int c is a column coordinate of a neighbour to be checked
**
**	Returns: 1 if a neighbour is valid or 0 otherwise
*/

static int	ft_valid_neighbour(t_game *gm, t_set *closed_set, int r, int c)
{
	if (r >= 0 && r < gm->map->rows && c >= 0 && c < gm->map->cols \
		&& (gm->map->map[r * gm->map->cols + c + r] == gm->player->me \
			|| gm->map->map[r * gm->map->cols + c + r] == '.') \
		&& !ft_found_pattern_three(gm->map, gm->player, r, c) \
		&& !ft_found_pattern_four(gm->map, gm->player, r, c) \
		&& !ft_is_in_set(r, c, closed_set) && !ft_enemy_corner(r, c, gm))
	{
		return (1);
	}
	return (0);
}

/*
**	ft_find_neighbours() function searches for all the valid neighbours
**	(neighbour coordinates) of a given current coordinate.
** When a valid neighbour is found, a new node with its coordinates is created,
**	and evaluated. If this coordinate wasn't discovered before it's added to
**	an open_set. The open_set holds possible coordinates for building a path
**
**	Param 1: t_game *gm is a pointer to a struct, members of which hold
**	all data necessary for the game
**
**	Param 2: t_set *cur is a pointer to a node which contains coordinates and
**	whos neighbours have to be discovered
**
**	Param 3: t_path *path is a pointer to a struct which holds start and finish
** coordinates of the path
**
**	Param 4: t_set *cl_set is a pointer to a linked list
**	following parents of which will reconstruct a path
**	from current coordinate to a start coordinate
**
**	Returns: none
*/

void		ft_find_neighbours(t_game *gm, t_set *cur, t_path *path,
								t_set *cl_set)
{
	int		i;
	int		r;
	int		c;
	t_set	*tmp_set;

	i = 0;
	r = cur->row;
	c = cur->col;
	while (ft_next_neighbour(cur, &r, &c, i))
	{
		if (ft_valid_neighbour(gm, cl_set, r, c))
		{
			tmp_set = ft_create_module(r, c, cur);
			ft_evaluate_set(tmp_set, path, cl_set);
			if (tmp_set->g < ft_is_in_set(r, c, gm->open_set))
				ft_pop(r, c, &gm->open_set);
			if (!ft_is_in_set(r, c, gm->open_set))
				ft_push(tmp_set, &gm->open_set);
			ft_del_set(&tmp_set);
		}
		i++;
	}
}
