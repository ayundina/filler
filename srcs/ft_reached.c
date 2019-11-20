/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_reached.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/25 11:03:45 by ayundina      #+#    #+#                 */
/*   Updated: 2019/06/25 11:03:48 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	ft_reached_col() function checks if the placed blocks
**	already reached a certain column of the map
**
**	Param 1: t_game *gm is a struct members of which hold
**	all data necessary for the game
**
**	Param 2: t_player *player is a pointer to a struct, which holds information
**	about players
**
**	Param 3: int r is a row of the map to check if a block is present
**	in this column
**
**	Returns: if my block is found in a given column the row number of the found
**	block is returnd. 0 if no my block are found in a given column
*/

int	ft_reached_row(t_map *map, char player, int r)
{
	int c;

	c = map->cols - 1;
	while (c > 0)
	{
		if (map->map[r * map->cols + c + r] == player)
			return (c);
		c--;
	}
	return (-1);
}

/*
**	ft_reached_col() function checks if the placed blocks
**	already reached a certain column of the map
**
**	Param 1: t_game *gm is a struct members of which hold
**	all data necessary for the game
**
**	Param 2: t_player *player is a pointer to a struct, which holds information
**	about players
**
**	Param 3: int c is a column of the map to check if a block is present
**	in this column
**
**	Returns: if my block is found in a given column the row number of the found
**	block is returnd. 0 if no my block are found in a given column
*/

int	ft_reached_col(t_map *map, char player, int c)
{
	int	r;

	r = map->rows - 1;
	while (r > 0)
	{
		if (map->map[r * map->cols + r + c] == player)
			return (r);
		r--;
	}
	return (-1);
}
