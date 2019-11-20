/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_move_on_path.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 18:47:54 by ayundina      #+#    #+#                 */
/*   Updated: 2019/07/23 18:47:56 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	when middle row or column is reached:
**	ft_move_ver() function checks if top or bottom row (depends on the enemy
**	starting position) is not reached. If path is present and valid, function
** checks for possible placements of a piece within the path and choose
**	for the closest placement towards the finish of the path
**
**	Param 1: t_game *gm is a struct, members of which hold
**	all data necessary for the game
**
**	Returns: 1 if piece is placed or 0 otherwise
*/

int	ft_move_ver(t_game *gm)
{
	if (ft_reached_row(gm->map, gm->player->me, gm->path_ver->finish_row) < 0)
	{
		if (ft_path_invalid(gm, gm->path_ver, gm->closed_ver_set))
		{
			ft_what_the_path(gm, gm->path_ver, &gm->closed_ver_set);
			ft_del_set(&gm->open_set);
		}
		if (!gm->closed_ver_set->finish_blocked \
			&& ft_find_best_placement(gm, gm->path_ver, gm->closed_ver_set) \
			&& ft_print_best_set(&gm->open_set, gm->piece))
		{
			ft_del_set(&gm->open_set);
			return (1);
		}
	}
	return (0);
}

/*
**	when middle row or column is reached:
**	ft_move_hor() function checks if a piece is a square sized or horizontally
**	oriented and if left or right column (depends on the enemy starting
** position) is not reached. If path is present and valid, function checks
**	for possible placements of a piece within the path and choose
**	for the closest placement towards the finish of the path
**
**	Param 1: t_game *gm is a struct, members of which hold
**	all data necessary for the game
**
**	Returns: 1 if piece is placed or 0 otherwise
*/

int	ft_move_hor(t_game *gm)
{
	if (gm->piece->cols >= gm->piece->rows \
		&& (ft_reached_col(gm->map, gm->player->me, \
							gm->path_hor->finish_col) < 0 \
			|| ft_reached_row(gm->map, gm->player->me, \
								gm->path_ver->finish_row) >= 0))
	{
		if (ft_path_invalid(gm, gm->path_hor, gm->closed_hor_set))
		{
			ft_what_the_path(gm, gm->path_hor, &gm->closed_hor_set);
			ft_del_set(&gm->open_set);
		}
		if (!gm->closed_hor_set->finish_blocked \
			&& ft_find_best_placement(gm, gm->path_hor, gm->closed_hor_set) \
			&& ft_print_best_set(&gm->open_set, gm->piece))
		{
			ft_del_set(&gm->open_set);
			return (1);
		}
	}
	return (0);
}

/*
**	ft_move_to_mid() function checks if middle row or middle column
**	are not reached and path is blocked or invalid, creates a path from
**	starting position of my player to the middle of the map.
**	If path is made, functions checks for possible placements of a piece within
**	the path and choose for the closest placement towards the finish of the path
**
**	Param 1: t_game *gm is a struct, members of which hold
**	all data necessary for the game
**
**	Returns: 1 if piece is placed or 0 otherwise
*/

int	ft_move_to_mid(t_game *gm)
{
	if (ft_reached_col(gm->map, gm->player->me, gm->path_mid->finish_col) < 0 \
		&& ft_reached_row(gm->map, gm->player->me, \
							gm->path_mid->finish_row) < 0)
	{
		if (ft_path_invalid(gm, gm->path_mid, gm->closed_mid_set))
		{
			ft_what_the_path(gm, gm->path_mid, &gm->closed_mid_set);
			ft_del_set(&gm->open_set);
		}
		if (!gm->closed_mid_set->finish_blocked \
			&& ft_find_best_placement(gm, gm->path_mid, gm->closed_mid_set) \
			&& ft_print_best_set(&gm->open_set, gm->piece))
		{
			ft_del_set(&gm->open_set);
			return (1);
		}
	}
	return (0);
}
