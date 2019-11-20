/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_move_random.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 18:52:25 by ayundina      #+#    #+#                 */
/*   Updated: 2019/07/23 18:52:28 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	ft_next_to_enemy() function traverses through the row and columns and
**	if a coordinate has an enemy block as neighbour, this coordinate is checked
**	for the possible placement
**
**	Param 1: t_game *gm is a struct, members of which hold
**	all data necessary for the game
**
**	Returns: 1 if piece is placed or 0 otherwise
*/

int	ft_next_to_enemy(t_game *gm)
{
	int	r;
	int	c;

	r = 0;
	c = 0;
	while (r < gm->map->rows)
	{
		while (c < gm->map->cols)
		{
			if ((gm->map->map[r * gm->map->cols + c + r] == '.' \
					|| gm->map->map[r * gm->map->cols + c + r] \
						== gm->player->me) \
				&& ft_neighbour_is_a_char(gm->player->enemy, gm->map, r, c))
			{
				if (ft_check_and_print(gm, r, c))
					return (1);
			}
			c++;
		}
		c = 0;
		r++;
	}
	return (0);
}

/*
**	ft_random_placement() function traverses through the rows and columns
**	of the map and checkes each coordinaye for a possible placement of a piece
**
**	Param 1: t_game *gm is a struct, members of which hold
**	all data necessary for the game
**
**	Returns: 1 if piece is placed or 0 otherwise
*/

int	ft_random_placement(t_game *gm)
{
	int	r;
	int	c;

	r = 0;
	c = 0;
	while (r < gm->map->rows)
	{
		while (c < gm->map->cols)
		{
			if (ft_check_and_print(gm, r, c))
				return (1);
			c++;
		}
		c = 0;
		r++;
	}
	return (0);
}

/*
**	ft_enemy_corner_placement() function traverses through the rows and columns
**	of the map and if a coordinate is in a quarter where enemy started
**	it's checked for a possible placement of a piece
**
**	Param 1: t_game *gm is a struct, members of which hold
**	all data necessary for the game
**
**	Returns: 1 if piece is placed or 0 otherwise
*/

int	ft_enemy_corner_placement(t_game *gm)
{
	int	r;
	int	c;

	r = 0;
	c = 0;
	while (r < gm->map->rows)
	{
		while (c < gm->map->cols)
		{
			if (ft_enemy_corner(r, c, gm))
			{
				if (ft_check_and_print(gm, r, c))
					return (1);
			}
			c++;
		}
		c = 0;
		r++;
	}
	return (0);
}
