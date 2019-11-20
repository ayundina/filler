/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fill_gaps.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/25 11:05:26 by ayundina      #+#    #+#                 */
/*   Updated: 2019/06/25 11:05:28 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	ft_valid_position() function checks if position within found pattern
**	would be valid for a placement of a piece
**
**	Param 1: t_game *gm is a struct, members of which hold
**	all data necessary for the game
**
**	Param 2-3: int r, int c is a row and a column coordinates
**	to search for a pattern
**
**	Returns: 1 if a piece can be placed,
**	0 if a position is invalid for a placement
*/

static int	ft_valid_position(t_game *gm, int r, int c)
{
	if (ft_check_and_print(gm, r, c))
		return (1);
	if (ft_check_and_print(gm, r, c + 1))
		return (1);
	if (ft_check_and_print(gm, r + 1, c))
		return (1);
	if (ft_check_and_print(gm, r + 1, c + 1))
		return (1);
	return (0);
}

/*
**	ft_found_pattern_one() function searches for a patterns as:
**		. *
**		* .
**	where the asterics would be my character in the map
**
**	Param 1: t_game *gm is a struct, members of which hold
**	all data necessary for the game
**
**	Param 2: t_player *player is a pointer to a struct, which holds information
**	about players
**
**	Param 3-4: int r, int c is a row and a column coordinates
**	to search for a pattern
**
**	Returns: 1 if the pattern is found, 0 if the pattern is not found
*/

static int	ft_found_pattern_one(t_map *map, t_player *player, int r, int c)
{
	if (map->map[r * map->cols + c + r] == '.' \
		|| map->map[r * map->cols + c + r] == player->enemy)
	{
		if (map->map[r * map->cols + c + 1 + r] == player->me)
		{
			if (r + 1 < map->rows \
				&& (map->map[(r + 1) * map->cols + c + 1 + r + 1] == '.' \
					|| map->map[(r + 1) * map->cols + c + 1 + r + 1] \
						== player->enemy))
			{
				if (map->map[(r + 1) * map->cols + c + r + 1] == player->me)
				{
					return (1);
				}
			}
		}
	}
	return (0);
}

/*
**	ft_found_pattern_two() function searches for a patterns as:
**		* .
**		. *
**	where the asterics would be my character in the map
**
**	Param 1: t_game *gm is a struct, members of which hold
**	all data necessary for the game
**
**	Param 2-3: int r, int c is a row and a column coordinates
**	to search for a pattern
**
**	Returns: 1 if the pattern is found, 0 if the pattern is not found
*/

static int	ft_found_pattern_two(t_map *map, t_player *player, int r, int c)
{
	if (map->map[r * map->cols + c + r] == player->me)
	{
		if ((map->map[r * map->cols + c + 1 + r] == '.' \
				|| map->map[r * map->cols + c + 1 + r] == player->enemy))
		{
			if (r + 1 < map->rows \
				&& map->map[(r + 1) * map->cols + c + 1 + r + 1] == player->me)
			{
				if (map->map[(r + 1) * map->cols + c + r + 1] == '.' \
					|| map->map[(r + 1) * map->cols + c + 1 + r] \
						== player->enemy)
				{
					return (1);
				}
			}
		}
	}
	return (0);
}

/*
**	ft_fill_gaps() function searches for two patterns (.*\n*. or *.\n.*)
**	where an enemy could escape the wall and places a piece there
**
**	Param 1: t_game *gm is a struct, members of which hold
**	all data necessary for the game
**
**	Returns: 1 if a pattern is found and piece is placed,
**	0 if pattern is not found or the placement is imposible
*/

int			ft_fill_gaps(t_game *gm, int r, int c)
{
	while (gm->map->map[r * gm->map->cols + c + r] != '\0')
	{
		if (ft_found_pattern_one(gm->map, gm->player, r, c))
		{
			if (ft_valid_position(gm, r, c))
				return (1);
		}
		if (ft_found_pattern_two(gm->map, gm->player, r, c))
		{
			if (ft_valid_position(gm, r, c))
				return (1);
		}
		c++;
		if (gm->map->map[r * gm->map->cols + c + r] == '\n' \
			&& r + 1 < gm->map->rows)
		{
			r++;
			c = 0;
		}
	}
	return (0);
}
