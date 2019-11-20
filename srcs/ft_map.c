/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_map.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/25 11:00:59 by ayundina      #+#    #+#                 */
/*   Updated: 2019/06/25 11:01:02 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	ft_read_start_pos() function searches for starting positions of players
**
**	Param 1: t_game *gm is a struct members of which hold
**	all data necessary for the game
**
**	Param 2: char *line is a string to store lines from stdin
**
**	Returns: 0 if success, -1 if an error ocured
*/

static void	ft_read_start_pos(t_player *player, char *line)
{
	if (ft_strchr(line, player->enemy))
	{
		player->row_start_en = ft_atoi(line);
		player->col_start_en = (int)(ft_strchr(line + 4, player->enemy)
										- (line + 4));
	}
	if (ft_strchr(line, player->me))
	{
		player->row_start_me = ft_atoi(line);
		player->col_start_me = (int)(ft_strchr(line + 4, player->me)
										- (line + 4));
	}
}

/*
**	ft_alloc_area() allocates area for a map and pieces
**
**	Param 1: char **area is an area to be allocates (a map or a piece)
**
**	Param 2: char *size is a string containing a number of rows and
**	a number of collumns to indicate the size of allocation
**
**	Param 3: int *row is to keep a number of rows after allocation is done
**
**	Param 4: int *col is to keep a number of collumns after allocation is done
**
**	Returns: 0 if success, -1 if an error ocured
*/

static int	ft_alloc_area(char **area, char *size, int *row, int *col)
{
	if (*area)
		ft_strdel(area);
	*row = ft_atoi(size);
	*col = ft_atoi(size + ft_intlen(*row));
	*area = (char *)ft_memalloc(sizeof(char) * (*row * (*col + 1) + 1));
	if (!*area)
	{
		perror("ayundina error: ft_alloc_area() - malloc failed");
		return (-1);
	}
	return (0);
}

/*
**	ft_update_map() function updates the map every time before a new move:
**	it fills map string with '\0',
**	reads and copies an updated map line by line from stdin.
**	It reads starting positions of the players in the beginning of the game
**	and it allocates new area for a new piece
**
**	Param 1: t_game *gm is a struct members of which hold
**	all data necessary for the game
**
**	Param 2: char *line is a string to store lines from stdin
**
**	Returns: 0 if success, -1 if an error ocured
*/

int			ft_update_map(t_game *gm, char *line)
{
	ft_memset((void *)gm->map->map, '\0', ft_strlen(gm->map->map));
	while (get_next_line(0, &line))
	{
		if (!line)
			return (-1);
		if (*(line + 4) == '.' || *(line + 4) == 'O' || *(line + 4) == 'X')
		{
			ft_strcpy(gm->map->map + ft_strlen(gm->map->map), line + 4);
			*(gm->map->map + ft_strlen(gm->map->map)) = '\n';
			if (!gm->piece->piece)
				ft_read_start_pos(gm->player, line);
		}
		if (*line == 'P')
		{
			if (ft_alloc_area(&gm->piece->piece, line + 6, &gm->piece->rows,
								&gm->piece->cols))
				return (-1);
			ft_strdel(&line);
			break ;
		}
		ft_strdel(&line);
	}
	return (0);
}

/*
**	ft_create_map() function allocates area for a map
**	in the begginning of the game
**
**	Param 1: t_game *gm is a struct members of which hold
**	all data necessary for the game
**
**	Returns: 0 if success, -1 if an error ocured
*/

int			ft_create_map(t_map *map)
{
	char	*line;

	if (get_next_line(0, &line) == 1 && line)
	{
		if (ft_alloc_area(&map->map, line + 8, &map->rows, &map->cols))
			return (-1);
		ft_strdel(&line);
	}
	else
	{
		perror("ayundina error: ft_create_map() - map is missed");
		return (-1);
	}
	return (0);
}
