/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_invalid_path_check.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 19:21:59 by ayundina      #+#    #+#                 */
/*   Updated: 2019/07/23 19:22:30 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	ft_path_invalid() function checks if a finishing coordinate of a given path
**	taken by an enemy, if so, finish coordinate is moved
**
**	Param 1: t_game *gm is a pointer to a struct, members of which hold
**	all data necessary for the game
**
**	Param 2: t_path *path is a pointer to a struct which holds start and finish
** coordinates of the path
**
**	Returns: 1 if path is invalid or enemy stepped on the path
**	and returns 0 if the path is fine
*/

void	ft_finish_invalid(t_game *gm, t_path *path)
{
	while (gm->map->map[path->finish_row * gm->map->cols + path->finish_col \
						+ path->finish_row] == gm->player->enemy)
	{
		if (gm->player->row_start_en <= (gm->map->rows - 1) / 2 \
			&& path->finish_row != 0)
			path->finish_row++;
		else if (gm->player->row_start_en > (gm->map->rows - 1) / 2 \
					&& path->finish_row != gm->map->rows - 1)
			path->finish_row--;
		else if (gm->player->col_start_en <= (gm->map->cols - 1) / 2 \
					&& path->finish_col != 0)
			path->finish_col++;
		else if (gm->player->col_start_en > (gm->map->cols - 1) / 2 \
					&& path->finish_col != gm->map->rows - 1)
			path->finish_col--;
	}
}

/*
**	ft_path_invalid() function checks if a finishing coordinate of a given path
**	taken by an enemy, if so, finish coordinate is moved
**	and given path becomes invalid. Or checks if the given path
**	is not overlaping with an enemy placed block
**
**	Param 1: t_game *gm is a pointer to a struct, members of which hold
**	all data necessary for the game
**
**	Param 2: t_path *path is a pointer to a struct which holds start and finish
** coordinates of the path
**
**	Param 3: t_set *closed_set is a pointer to a linked list, following parents
**	of which a path can be reconstructed
**
**	Returns: 1 if path is invalid or enemy stepped on the path
**	and returns 0 if the path is fine
*/

int		ft_path_invalid(t_game *gm, t_path *path, t_set *closed_set)
{
	ft_finish_invalid(gm, path);
	if (closed_set->row != path->finish_row \
		|| closed_set->col != path->finish_col)
		return (1);
	else
	{
		while (closed_set != NULL)
		{
			if (gm->map->map[closed_set->row * gm->map->cols + closed_set->col \
								+ closed_set->row] == gm->player->enemy)
				return (1);
			closed_set = closed_set->parent;
		}
	}
	return (0);
}
