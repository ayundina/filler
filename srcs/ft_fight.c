/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fight.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/25 11:01:43 by ayundina      #+#    #+#                 */
/*   Updated: 2019/06/25 11:01:46 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	ft_reverse_set() reverces the order of a linked list
**
**	Param 1: t_set **head is a pointer to a first node in a linked list
**
**	Returns: none
*/

void		ft_reverse_set(t_set **head)
{
	t_set	*current;
	t_set	*prev;

	if (*head != NULL)
	{
		prev = *head;
		current = (*head)->next;
		*head = (*head)->next;
		prev->next = NULL;
		while (*head != NULL)
		{
			*head = (*head)->next;
			current->next = prev;
			prev = current;
			current = *head;
		}
		*head = prev;
	}
}

/*
**	ft_make_move() sets key points to path structs (mid, horizontal, vertical),
**	searches for starting position to place pieces towards middle,
**	places pieces towards middle. When middle is reached,
**	searches for starting positions to place pieces towards left or right side -
**	horizontally and towards top or bottom side - vertically.
**	Places pieces horizontally and vertically until two sides are reached.
**	This way the enemy will be locked in a corner.
**	When sides are reached, pieces can be placed next to enemy pieces,
**	in a corner enemy began the game or just first valid cell
**
**	Param 1: t_game *gm is a struct members of which hold
**	all data necessary for the game
**
**	Returns: 1 if a move is made, 0 if a move is impossible
*/

static int	ft_make_move(t_game *gm)
{
	ft_key_path_points(gm);
	ft_starting_mid_set(gm);
	if (ft_move_to_mid(gm))
		return (1);
	ft_starting_hor_ver_set(gm);
	if (!gm->closed_hor_set->finish_blocked && ft_move_hor(gm))
		return (1);
	if (!gm->closed_ver_set->finish_blocked && ft_move_ver(gm))
		return (1);
	if (!gm->closed_hor_set->finish_blocked && ft_move_hor(gm))
		return (1);
	if (ft_next_to_enemy(gm))
		return (1);
	if (ft_enemy_corner_placement(gm))
		return (1);
	if (ft_random_placement(gm))
		return (1);
	return (0);
}

/*
**	ft_fight_loop() function is executing while it get input from stdin.
**	It gets and saves updated map after each move,
**	gets and saves new piece, checks if there possible gaps in previous moves,
**	through wich the opponent can escape.
**	If no gaps to fill, it makes a move.
**
**	Param 1: t_game *gm is a struct members of which hold
**	all data necessary for the game
**
**	Returns: 0 when game is finished, -1 if an error ocured
*/

int			ft_fight_loop(t_game *gm)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (!line)
			return (-1);
		if (ft_update_map(gm, NULL))
		{
			perror("ayundina error: ft_update_map() - unable to read the map");
			return (-1);
		}
		if (ft_get_piece(gm->piece))
		{
			perror("ayundina error: ft_get_piece() - reading issue");
			return (-1);
		}
		if (!ft_fill_gaps(gm, 0, 0))
		{
			if (!ft_make_move(gm))
				ft_printf("0 0\n");
		}
		ft_strdel(&line);
	}
	return (0);
}
