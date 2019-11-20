/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_evaluate.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 18:59:23 by ayundina      #+#    #+#                 */
/*   Updated: 2019/07/23 18:59:27 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	ft_evaluate_set() function takes coordinates from the given node
**	of a set and calculates how close this coordinate to finish (h_value)
**	and how close this coordinate to its start (g_value).
**	Values h and g are heuristic and calculated as manhattan distance
**
**	Param 1: t_set *set is a pointer to a node of a linked list, which holds
** checked path steps from start to finish (or from start to current)
**
**	Param 2: t_path *path is a pointer to a struct which holds start and finish
** coordinates of the path
**
**	Param 3: t_set *parent is a coordinate which is a previous step of the path.
**	A coordinate which we currently evaluating came from this parent coordinate
**
**	Returns: none
*/

void	ft_evaluate_set(t_set *set, t_path *path, t_set *parent)
{
	int	distance_row;
	int	distance_col;

	distance_row = set->row - path->finish_row;
	if (distance_row < 0)
		distance_row *= -1;
	distance_col = set->col - path->finish_col;
	if (distance_col < 0)
		distance_col *= -1;
	set->h = (distance_row + distance_col);
	distance_row = set->row - path->start_row;
	if (distance_row < 0)
		distance_row *= -1;
	distance_col = set->col - path->start_col;
	if (distance_col < 0)
		distance_col *= -1;
	if (parent != NULL)
		set->g = distance_row + distance_col + parent->g;
	else
		set->g = 1;
	set->f = set->g + set->h;
}

/*
**	ft_evaluate_push_pop() function evaluetes a found placement of a piece,
**	pushes coordinates and its values from temporary node
**	to an open_set linked list and deletes temporary node
**
**	Param 1: t_set *tmp_set is a temporary node to keep the placement
**	coordinates and coordinate's values
**
**	Param 2: t_path *path is a pointer to a struct which holds start and finish
** coordinates of the path
**
**	Param 3: t_set **open_set is a pointer to a pointer to a linked list
**	to hold possible placement coordinates and its values of a piece
**	for a current move within a current path
**
**	Returns: none
*/

void	ft_evaluate_push_pop(t_set *tmp_set, t_path *path, t_set **open_set)
{
	ft_evaluate_placement(tmp_set, path);
	ft_push(tmp_set, open_set);
	ft_pop((*open_set)->row, (*open_set)->col, &tmp_set);
}

/*
**	ft_evaluate_placement() function takes coordinates from the given node
**	of a set and calculates how close this coordinate to finish (h_value)
**	and how close this coordinate to its parent (g_value).
**	A parent of the placement coordinate is a path block around which,
**	the placement of a piece was checked and is possible.
**	Values h and g are heuristic and calculated as manhattan distance
**
**	Param 1: t_set *set is a pointer to a node of a set, where placement
**	coordinates of a piece are saved
**
**	Param 2: t_path *path is a pointer to a struct which holds start and finish
** coordinates of the path
**
**	Returns: none
*/

void	ft_evaluate_placement(t_set *set, t_path *path)
{
	int	distance_row;
	int	distance_col;

	distance_row = set->row - path->finish_row;
	if (distance_row < 0)
		distance_row *= -1;
	distance_col = set->col - path->finish_col;
	if (distance_col < 0)
		distance_col *= -1;
	set->h = distance_row + distance_col;
	distance_row = set->row - set->parent->row;
	if (distance_row < 0)
		distance_row *= -1;
	distance_col = set->col - set->parent->col;
	if (distance_col < 0)
		distance_col *= -1;
	set->g = distance_row + distance_col;
	set->f = set->g + set->h;
}
