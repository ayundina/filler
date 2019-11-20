/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_enemy_corner.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 19:08:19 by ayundina      #+#    #+#                 */
/*   Updated: 2019/07/23 19:08:21 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	ft_enemy_upper_left() function checks if given coordinates and an opponent
**	starting position are within the the same upper left quarter of the map
**	and the same time my player starting position is not in the same
** upper left quarter
**
**	Param 1: int r is a row coordinate
**
**	Param 2: int c is a column coordinate
**
**	Param 3: t_game *gm is a pointer to a struct, members of which hold
**	all data necessary for the game
**
**	Returns: 1 if given coordinates and starting enemy position are in the same
**	upper left quarter of the map and my starting position is not in the upper
**	left quarter or returns 0 otherwise
*/

static int	ft_enemy_upper_left(int r, int c, t_game *gm)
{
	if ((r >= 0 && r < (gm->map->rows - 1) / 2 \
		&& c >= 0 && c < (gm->map->cols - 1) / 2) \
		&& ((gm->player->row_start_en >= 0 \
				&& gm->player->row_start_en < (gm->map->rows - 1) / 2 \
				&& gm->player->col_start_en >= 0 \
				&& gm->player->col_start_en < (gm->map->cols - 1) / 2) \
			&& !(gm->player->row_start_me >= 0 \
					&& gm->player->row_start_me < (gm->map->rows - 1) / 2 \
					&& gm->player->col_start_me >= 0 \
					&& gm->player->col_start_me < (gm->map->cols - 1) / 2)))
	{
		return (1);
	}
	return (0);
}

/*
**	ft_enemy_upper_right() function checks if given coordinates and an opponent
**	starting position are within the the same upper right quarter of the map
**	and the same time my player starting position is not in the same
** upper right quarter
**
**	Param 1: int r is a row coordinate
**
**	Param 2: int c is a column coordinate
**
**	Param 3: t_game *gm is a pointer to a struct, members of which hold
**	all data necessary for the game
**
**	Returns: 1 if given coordinates and starting enemy position are in the same
**	upper right quarter of the map and my starting position is not in the upper
**	right quarter or returns 0 otherwise
*/

static int	ft_enemy_upper_right(int r, int c, t_game *gm)
{
	if ((r >= 0 && r < (gm->map->rows - 1) / 2 \
		&& c > (gm->map->cols - 1) / 2 && c < gm->map->cols) \
		&& ((gm->player->row_start_en >= 0 \
				&& gm->player->row_start_en < (gm->map->rows - 1) / 2 \
				&& gm->player->col_start_en > (gm->map->cols - 1) / 2 \
				&& gm->player->col_start_en < gm->map->cols) \
			&& !(gm->player->row_start_me >= 0 \
					&& gm->player->row_start_me < (gm->map->rows - 1) / 2 \
					&& gm->player->col_start_me > (gm->map->cols - 1) / 2 \
					&& gm->player->col_start_me < gm->map->cols)))
	{
		return (1);
	}
	return (0);
}

/*
**	ft_enemy_lower_right() function checks if given coordinates and an opponent
**	starting position are within the the same lower right quarter of the map
**	and the same time my player starting position is not in the same
** lower right quarter
**
**	Param 1: int r is a row coordinate
**
**	Param 2: int c is a column coordinate
**
**	Param 3: t_game *gm is a pointer to a struct, members of which hold
**	all data necessary for the game
**
**	Returns: 1 if given coordinates and starting enemy position are in the same
**	lower right quarter of the map and my starting position is not in the lower
**	right quarter or returns 0 otherwise
*/

static int	ft_enemy_lower_right(int r, int c, t_game *gm)
{
	if ((r > (gm->map->rows - 1) / 2 && r < gm->map->rows \
		&& c > (gm->map->cols - 1) / 2 && c < gm->map->cols) \
		&& ((gm->player->row_start_en > (gm->map->rows - 1) / 2 \
				&& gm->player->row_start_en < gm->map->rows \
				&& gm->player->col_start_en > (gm->map->cols - 1) / 2 \
				&& gm->player->col_start_en < gm->map->cols) \
			&& !(gm->player->row_start_me > (gm->map->rows - 1) / 2 \
					&& gm->player->row_start_me < gm->map->rows \
					&& gm->player->col_start_me > (gm->map->cols - 1) / 2 \
					&& gm->player->col_start_me < gm->map->cols)))
	{
		return (1);
	}
	return (0);
}

/*
**	ft_enemy_lower_left() function checks if given coordinates and an opponent
**	starting position are within the the same lower left quarter of the map
**	and the same time my player starting position is not in the same
** lower left quarter
**
**	Param 1: int r is a row coordinate
**
**	Param 2: int c is a column coordinate
**
**	Param 3: t_game *gm is a pointer to a struct, members of which hold
**	all data necessary for the game
**
**	Returns: 1 if given coordinates and starting enemy position are in the same
**	lower left quarter of the map and my starting position is not in the lower
**	left quarter or returns 0 otherwise
*/

static int	ft_enemy_lower_left(int r, int c, t_game *gm)
{
	if ((r > (gm->map->rows - 1) / 2 && r < gm->map->rows \
		&& c >= 0 && c < (gm->map->cols - 1) / 2) \
		&& ((gm->player->row_start_en > (gm->map->rows - 1) / 2 \
				&& gm->player->row_start_en < gm->map->rows \
				&& gm->player->col_start_en >= 0 \
				&& gm->player->col_start_en <= (gm->map->cols - 1) / 2) \
			&& !(gm->player->row_start_me > (gm->map->rows - 1) / 2 \
					&& gm->player->row_start_me < gm->map->rows \
					&& gm->player->col_start_me >= 0 \
					&& gm->player->col_start_me <= (gm->map->cols - 1) / 2)))
	{
		return (1);
	}
	return (0);
}

/*
**	ft_enemy_corner() function checks if given coordinates are within
**	the quarter of the map where an opponent started the game
**	and the same time my player starting position is not in the same
** quarter as the opponnt's
**
**	Param 1: int r is a row coordinate
**
**	Param 2: int c is a column coordinate
**
**	Param 3: t_game *gm is a pointer to a struct, members of which hold
**	all data necessary for the game
**
**	Returns: none
*/

int			ft_enemy_corner(int r, int c, t_game *gm)
{
	if (ft_enemy_upper_left(r, c, gm))
		return (1);
	if (ft_enemy_upper_right(r, c, gm))
		return (1);
	if (ft_enemy_lower_right(r, c, gm))
		return (1);
	if (ft_enemy_lower_left(r, c, gm))
		return (1);
	return (0);
}
