/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/25 11:00:39 by ayundina      #+#    #+#                 */
/*   Updated: 2019/06/25 11:00:42 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	Filler is a game between two players, where players are pursuing a goal
**	to place more of given pieces on a given map then it's opponent.
**	In order to win ayundina.filler (this player) tries to lock an enemy in his
**	quarter and have three quarters of the map to place it's pieces.
**	For that ayundina.filler places pieces towards the middle of the map, then
**	forks horizontally and vertically to close the enemy.
**
**	In order to move certain directions I chose to use A* algorithm to build
**	a path and place a piece near that path and prefarably closest to
**	the path finish.
*/

static void	ft_free_everything(t_game *gm)
{
	ft_strdel(&gm->map->map);
	ft_strdel(&gm->piece->piece);
	free(gm->map);
	free(gm->piece);
	free(gm->player);
	gm->map = NULL;
	gm->piece = NULL;
	gm->player = NULL;
	ft_del_set(&gm->closed_mid_set);
	ft_del_set(&gm->closed_hor_set);
	ft_del_set(&gm->closed_ver_set);
	ft_memset((void *)gm->path_mid, '\0', sizeof(t_path));
	ft_memset((void *)gm->path_hor, '\0', sizeof(t_path));
	ft_memset((void *)gm->path_ver, '\0', sizeof(t_path));
	free(gm->path_mid);
	free(gm->path_hor);
	free(gm->path_ver);
	gm->path_mid = NULL;
	gm->path_hor = NULL;
	gm->path_ver = NULL;
}

/*
**	ft_get_player() reads from stdin a player number, given by filler_vm
**	player one (p1) is represented by 'O',
**	player two (p2) is represented by 'X'
**
**	Param 1: t_game *gm is a struct members of which hold
**	all data necessary for the game
**
**	Returns: 0 if success, -1 if an error occurred
*/

static int	ft_get_player(t_player *player)
{
	char *line;

	line = NULL;
	if (get_next_line(0, &line) == 1 && line)
	{
		if (ft_strstr(line, "p1"))
		{
			player->enemy = 'X';
			player->me = 'O';
		}
		if (ft_strstr(line, "p2"))
		{
			player->enemy = 'O';
			player->me = 'X';
		}
		ft_strdel(&line);
	}
	else
	{
		perror("ayundina error: ft_get_player - missed player ID");
		return (-1);
	}
	return (0);
}

/*
**	main() function allocates memory for structs: map, piece and player
**	set values to NULL
**	gets player ('O' or 'X'),
**	allocates memory area for a map,
**	launches the fight function
**	and frees allocated areas at the end
**
**	Returns: 0 if success, -1 if an error occurred
*/

int			main(void)
{
	t_game	gm;

	gm.map = (t_map *)ft_memalloc(sizeof(t_map));
	gm.piece = (t_piece *)ft_memalloc(sizeof(t_piece));
	gm.player = (t_player *)ft_memalloc(sizeof(t_player));
	gm.open_set = NULL;
	gm.closed_mid_set = NULL;
	gm.closed_hor_set = NULL;
	gm.closed_ver_set = NULL;
	gm.path_mid = NULL;
	if (ft_get_player(gm.player))
		return (-1);
	if (ft_create_map(gm.map))
		return (-1);
	if (ft_fight_loop(&gm))
		return (-1);
	ft_free_everything(&gm);
	return (0);
}
