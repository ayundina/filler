/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_n_print.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/25 11:04:44 by ayundina      #+#    #+#                 */
/*   Updated: 2019/06/25 11:04:47 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	ft_print_best_set() function searches within t_set **set for a closest
**	coordinates towards the finish point where piece placement is valid
**	and prints these coordinates
**
**	Param 1: t_set **set is a linked list with valid placements of a piece
**
**	Param 2: t_piece *piece is a struct which holds information about left
**	and top offset of a piece. Allows to print correct coordinates
**
**	Returns: 1 if the set has placements and a placement coordinates
**	are printed, otherwise returns 0
*/

int			ft_print_best_set(t_set **set, t_piece *piece)
{
	t_set	*tmp_set;

	ft_reverse_set(set);
	tmp_set = *set;
	while (tmp_set != NULL)
	{
		if (ft_is_closest(tmp_set, *set))
		{
			ft_printf("%d %d\n", tmp_set->row - piece->row_offset,
						tmp_set->col - piece->col_offset);
			return (1);
		}
		tmp_set = tmp_set->next;
	}
	return (0);
}

/*
**	ft_valid_block_position() function checks if a placement
**	of a block of a current piece is fitting well within a map block
**
**	Param 1: int overlap is a number of overlaps of blocks of
**	current piece with blocks of pieces placed in the map
**
**	Param 2: char piece_block is a block of the piece to be checked
**
**	Param 3: char map_block is block of the map to check
**	if the block of the piece can fit
**
**	Param 4: char enemy is a character denoting to the enemy
**
**	Returns: 1 if the placement of the block is valid, 0 if the placement
**	of the block is invalid
*/

static int	ft_valid_block_position(int overlap, char piece_block,
									char map_block, char enemy)
{
	if (overlap > 1 || (overlap == 0 && piece_block + 1 == '\0') \
		|| (piece_block == '*' && (map_block == enemy || map_block == '\n' \
		|| map_block == '\0')))
		return (0);
	return (1);
}

/*
**	ft_check_overlap() function checks if a piece block overlap a previously
**	placed by my player block on the map
**
**	Param 1: t_game *gm is a struct, members of which hold
**	all data necessary for the game
**
**	Param 2: int i is an index of a piece string
**
**	Param 3: int r is a row coordinare on the map
**
**	Param 4: int c is a column coordinate on the map
**
**	Returns: 1 if a piece block has an overlap or 0 otherwise
*/

static int	ft_check_overlap(t_game *gm, int i, int r, int c)
{
	if (gm->piece->piece[i] == '*' \
		&& gm->map->map[r * gm->map->cols + c + r] == gm->player->me)
		return (1);
	return (0);
}

/*
**	ft_valid_move() function checks if a placement has only one overlap
**	of a block of current piece with a block of a piece placed previously
**	and if each block of the piece will fit to the given map
**
**	Param 1: t_game *gm is a struct, members of which hold
**	all data necessary for the game
**
**	Param 2: int r is a row number of the placement
**
**	Param 3: int c is a col number of the placement
**
**	Param 4: int i is an index variable to traverce through the piece
**
**	Returns: 1 if the placement is valid, 0 if the placement is invalid
*/

int			ft_valid_move(t_game *gm, int r, int c, int i)
{
	int	overlap;
	int	tmp_c;

	overlap = 0;
	tmp_c = c;
	while (gm->piece->piece[i] != '\0')
	{
		overlap += ft_check_overlap(gm, i, r, c);
		if (!ft_valid_block_position(overlap, gm->piece->piece[i],
					gm->map->map[r * gm->map->cols + c + r], gm->player->enemy))
			return (0);
		if (gm->piece->piece[i + 1] == '\n' && gm->piece->piece[i + 2] != '\0')
		{
			if (r + 1 >= gm->map->rows)
				return (0);
			r++;
			c = tmp_c - 1;
			i++;
		}
		c++;
		i++;
	}
	if (overlap == 0)
		return (0);
	return (1);
}

/*
**	ft_check_and_print() function checks if a placement is valid and
**	prints coordinates of the plasement in stdout
**
**	Param 1: t_game *gm is a struct, members of which hold
**	all data necessary for the game
**
**	Param 2: int row_start is a row number of the placement
**
**	Param 3: int col_start is a col number of the placement
**
**	Returns: 1 if the placement is successful, 0 if the placement is false
*/

int			ft_check_and_print(t_game *gm, int row_start, int col_start)
{
	if (ft_valid_move(gm, row_start, col_start, 0))
	{
		ft_printf("%d %d\n", row_start - gm->piece->row_offset,
					col_start - gm->piece->col_offset);
		return (1);
	}
	return (0);
}
