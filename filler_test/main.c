//
//  main.c
//  190614_1027_filler_test
//
//  Created by Anna on 14/06/2019.
//  Copyright © 2019 Codam. All rights reserved.
//

#include "fillertest.h"

/*
**	who_won_rev() function is the same as who_won(),
**	reads a file with the game output,
**	searcher for lines with the game result,
**	but stores this results in a struct in reverse:
** results of 'O' for player_two and
**	results of 'X' for player_one
**
**	Param 1: t_file *file is a struct where members keep data about output file
**
**	Param 2: t_results *res is a struct which stores results of previously launched games
**
**	Returns: 0 if success, 1 if the file is not accessible
*/

int	who_won_rev(char *file, t_results *res)
{
	FILE		*fd;
	size_t		linelen;
	size_t		linecapp;
	char		*line;
	char		*tmp;
	
	fd = fopen(file, "r");
	while (fd && (linelen = getline(&line, &linecapp, fd)) > 0)
	{
		line[linelen] = '\0';
		if ((tmp = strchr(line, '=')) != NULL)
		{
			if (tmp[3] == 'O')
				res->pl_two = atoi(tmp + 10);
			if (tmp[3] == 'X')
			{
				res->pl_one = atoi(tmp + 10);
				break;
			}
		}
	}
	fclose(fd);
	res->total_pl_one += res->pl_one;
	res->total_pl_two += res->pl_two;
	return (0);
}

/*
**	who_won() reads a file with the game output,
**	searcher for lines with the game result
**	and stores this results in a struct
**
**	Param 1: t_file *file is a struct where members keep data about output file
**
**	Param 2: t_results *res is a struct which stores results of previously launched games
**
**	Returns: 0 if success, 1 if the file is not accessible
*/


int	who_won(char *file, t_results *res)
{
	FILE		*fd;
	size_t		linelen;
	size_t		linecapp;
	char		*line;
	char		*tmp;
	
	fd = fopen(file, "r");
	if (fd < 0)
	{
		printf("No access to output file\n");
		return (1);
	}
	while (fd && (linelen = getline(&line, &linecapp, fd)) > 0)
	{
		line[linelen] = '\0';
		if ((tmp = strchr(line, '=')) != NULL)
		{
			if (tmp[3] == 'O')
				res->pl_one = atoi(tmp + 10);
			if (tmp[3] == 'X')
			{
				res->pl_two = atoi(tmp + 10);
				break;
			}
		}
	}
	fclose(fd);
	res->total_pl_one += res->pl_one;
	res->total_pl_two += res->pl_two;
	return (0);
}

/*
**	ready_file() function creates a unique file name of a file to which a game
**	will be written. Creates a file with touch command in terminal
**	and stores full path a name of the file
**
**	Param 1: char *path is a path to fillertest folder, given as a first argument
**
**	Param 2: t_file *file is a struct where members keep data about output file
**
**	Param 3: char *map is a game map
**
** Param 4 and 5: char *pl_one and char *pl_two are first and second players
**
**	Returns: 0 if success, 1 if a player name is incorrect
*/


int	ready_file(char *path, t_file *file, char *map, char *pl_one, char *pl_two)
{
	char	touch[1000];
	char	num_str[20];
	
	bzero(touch, 1000);
	file->num += 1;
	bzero(num_str, 20);
	sprintf(num_str, "%d", file->num);
//	create file with "touch"
	strcpy(touch, "touch ");
	strcpy(touch + strlen(touch), path);
	strcpy(touch + strlen(touch), "/resources/out/");
	strcpy(touch + strlen(touch), num_str);
	strcpy(touch + strlen(touch), "_");
	strcpy(touch + strlen(touch), map);
	strcpy(touch + strlen(touch), "_");
	strcpy(touch + strlen(touch), "O-");
	if (!strchr(pl_one, '.'))
	{
		printf("incorrect player_one.filler name\n");
		return (1);
	}
	strncpy(touch + strlen(touch), pl_one, strchr(pl_one, '.') - pl_one);
	strcpy(touch + strlen(touch), "_");
	strcpy(touch + strlen(touch), "X-");
	if (!strchr(pl_two, '.'))
	{
		printf("incorrect player_two.filler name\n");
		return (1);
	}
	strncpy(touch + strlen(touch), pl_two, strchr(pl_two, '.') - pl_two);
	strcpy(touch + strlen(touch), ".txt");
	system(touch);
	//file->name is a path to the file
	strcpy(file->name, touch + 6);
	return (0);
}

/*
**	ready_n_launch_command() function creates a "command" string to launch
**	game from terminal and write the game into a file
**
**	Param 1: char *path is path to fillertest folder
**
**	Param 2: char *map is a game map
**
**	Param 3-4: char *pl_one and char *pl_two are two players
**
**	Param 5: char *filename is string with a path and a name of a file for game output
**
**	Returns: none
*/

void	ready_n_launch_command(char *path, char *map, char *pl_one, char *pl_two, char *filename)
{
//	command to run
	char command[1000];
	
	strcpy(command, path);
	strcpy(command + strlen(command), "/resources/./filler_vm -f ");
	strcpy(command + strlen(command), path);
	strcpy(command + strlen(command), "/resources/maps/");
	strcpy(command + strlen(command), map);
	strcpy(command + strlen(command), " -p1 ");
	strcpy(command + strlen(command), path);
	strcpy(command + strlen(command), "/resources/players/./");
	strcpy(command + strlen(command), pl_one);
	strcpy(command + strlen(command), " -p2 ");
	strcpy(command + strlen(command), path);
	strcpy(command + strlen(command), "/resources/players/./");
	strcpy(command + strlen(command), pl_two);
    strcpy(command + strlen(command), " > ");
    strcpy(command + strlen(command), filename);
	system(command);
}

/*
**	launch_rev() function repeats the functionality launch() function,
**	but it reverces positions of the players
**	In straight position: player_one plays as O, player_two plays as X
**	In reversed position: player_one plays as X, player_two plays as O
**
**	Param 1: char *path is path to fillertest folder
**
**	Param 2: t_file *file is a struct where members keep data about output file
**
**	Param 3: char *map is a game map
**
**	Param 4: t_players *pl is a struct to store two players names
**
**	Param 5: t_results *res is a struct wich stores results of previosly launched games
**
**	Returns: none
*/

void	launch_rev(char *path, t_file *file, char *map, t_players *pl, t_results *res)
{
	int	i;
	
	i = 10;
	res->total_pl_one = 0;
	res->total_pl_two = 0;
	res->won_pl_one = 0;
	res->won_pl_two = 0;
	while (i > 0)
	{
		ready_file(path, file, map, pl->pl_two, pl->pl_one);
		ready_n_launch_command(path, map, pl->pl_two, pl->pl_one, file->name);
		who_won_rev(file->name, res);
		if (res->pl_one > res->pl_two)
		{
			printf("%d_%s:	WON:	%s	[%d]	vs	[%d]	%s\n", file->num, map, pl->pl_one, res->pl_one, res->pl_two, pl->pl_two);
			res->won_pl_one++;
		}
		else
		{
			printf("%d_%s:		%s	[%d]	vs	[%d]	%s:	WON\n",file->num, map, pl->pl_one, res->pl_one, res->pl_two, pl->pl_two);
			res->won_pl_two++;
		}
		i--;
	}
	res->fin_total_pl_one += res->total_pl_one;
	res->fin_total_pl_two += res->total_pl_two;
	res->fin_won_pl_one += res->won_pl_one;
	res->fin_won_pl_two += res->won_pl_two;
	if (res->won_pl_one > res->won_pl_two)
	{
		printf("\ntotal:		WON:	%s	[%d]-%d	vs	%d-[%d]	%s\n\n", pl->pl_one, res->total_pl_one, res->won_pl_one, res->won_pl_two, res->total_pl_two, pl->pl_two);
	}
	else
	{
		printf("\ntotal:			%s	[%d]-%d	vs	%d-[%d]	%s:	WON\n\n", pl->pl_one, res->total_pl_one, res->won_pl_one, res->won_pl_two, res->total_pl_two, pl->pl_two);
	}
}

/*
**	launch() function resets results of launched games from the last run.
**	In a while loop: creates a new file in /fillertest/resources/out,
**	to write each game into a uniquely named file, launches the game,
**	counts the result of the game, prints the results of each game
**	(each map launched i = 10 times),
**	prints the final result for i = 10 games
**
**	Param 1: char *path is a path to fillertest folder
**
**	Param 2: t_file *file is a struct where members keep data about output file
**
**	Param 3: char *map is a game map
**
**	Param 4: t_players *pl is a struct to store two players names
**
**	Param 5: t_results *res is a struct which stores results of previously launched games
**
**	Returns: 0 if success, 1 if an error occurred
*/

int	launch(char *path, t_file *file, char *map, t_players *pl, t_results *res)
{
	int	i;
	
	i = 10;
	res->total_pl_one = 0;
	res->total_pl_two = 0;
	res->won_pl_one = 0;
	res->won_pl_two = 0;
	while (i > 0)
	{
		if (ready_file(path, file, map, pl->pl_one, pl->pl_two) == 1)
			return (1);
		ready_n_launch_command(path, map, pl->pl_one, pl->pl_two, file->name);
		if (who_won(file->name, res) == 1)
			return (1);
		if (res->pl_one > res->pl_two)
		{
			printf("%d_%s:	WON:	%s	[%d]	vs	[%d]	%s\n", file->num, map, pl->pl_one, res->pl_one, res->pl_two, pl->pl_two);
			res->won_pl_one++;
		}
		else
		{
			printf("%d_%s:		%s	[%d]	vs	[%d]	%s:	WON\n",file->num, map, pl->pl_one, res->pl_one, res->pl_two, pl->pl_two);
			res->won_pl_two++;
		}
		i--;
	}
	res->fin_total_pl_one += res->total_pl_one;
	res->fin_total_pl_two += res->total_pl_two;
	res->fin_won_pl_one += res->won_pl_one;
	res->fin_won_pl_two += res->won_pl_two;
	if (res->won_pl_one > res->won_pl_two)
	{
		printf("\ntotal:		WON:	%s	[%d]-%d	vs	%d-[%d]	%s\n\n", pl->pl_one, res->total_pl_one, res->won_pl_one, res->won_pl_two, res->total_pl_two, pl->pl_two);
	}
	else
	{
		printf("\ntotal:			%s	[%d]-%d	vs	%d-[%d]	%s:	WON\n\n", pl->pl_one, res->total_pl_one, res->won_pl_one, res->won_pl_two, res->total_pl_two, pl->pl_two);
	}
	return (0);
}

/*
**	ready_player() function assignes given as argument players
**	to the members of players struct
**
**	Param 1: t_players *pl is struct containing names of two players
**
**	Param 2-3: char *pl_one and char *pl_two are two players
**
**	Returns: none
*/

void	ready_player(t_players *pl, char *pl_one, char *pl_two)
{
	pl->pl_one = pl_one;
	pl->pl_two = pl_two;
}

/*
**	ready_maps() function copies names of maps
**	(/fillertest/resources/maps) to maps struct members
**
**	Param 1: t_maps *mp is struct containing names of maps
**
**	Returns: none
*/

void	ready_maps(t_maps *mp)
{
	bzero(mp->map_one, 20);
//	strcpy(mp->map_one, "map01_X_ul_O_ll");
	strcpy(mp->map_one, "map00");
	bzero(mp->map_two, 20);
//	strcpy(mp->map_two, "map01_X_ul_O_lr");
	strcpy(mp->map_two, "map01");
	bzero(mp->map_three, 20);
//	strcpy(mp->map_three, "map01_X_ul_O_ul");
	strcpy(mp->map_three, "map02");
//	bzero(mp->map_four, 20);
//	strcpy(mp->map_four, "map01_X_ul_O_ur");
//	bzero(mp->map_five, 20);
//	strcpy(mp->map_five, "map01_X_ur_O_ll");
//	bzero(mp->map_six, 20);
//	strcpy(mp->map_six, "map01_X_ur_O_lr");
//	bzero(mp->map_seven, 20);
//	strcpy(mp->map_seven, "map01_X_ur_O_ul");
//	bzero(mp->map_eight, 20);
//	strcpy(mp->map_eight, "map01_X_ur_O_ur");
}

/*
**	clean_out() function deletes all files from /fillertest/resources/out
**
**	Param 1: char *path is path to fillertest folder
**
**	Returns: none
*/

void	clean_out(char *path)
{
	char	command[500];
	
	strcpy(command, "cd ");
	strcpy(command + strlen(command), path);
	strcpy(command + strlen(command), "/resources/out && rm -rf *");
	system(command);
}

/*
**	There are 4 structs: players, maps, file (for the output) and results
**
**	main() function deletes all the files from fillertest/resources/out,
**	assignes maps and players to its struct members,
**	launches each map in straight players position (the first player gets O, the second player gets X)
**	and then in reverse players positions (the first player gets X, the second player gets O),
**	prints final results for all launched games
**
**	Param 1: int argc is number of given parameters
**
**	Param 2: char **argv is a pointer to given parameters
**
**	Returns: 0 if success, 1 if an error occurred
*/


int main(int argc, char **argv)
{
	t_maps		mp;
	t_players	pl;
	t_file		file;
	t_results	res;
	
	file.num = 0;
	res.fin_total_pl_one = 0;
	res.fin_total_pl_two = 0;
	res.fin_won_pl_one = 0;
	res.fin_won_pl_two = 0;
//	usage message
	if (argc != 4)
	{
//		PATH/resources/./filler_vm
//		-f PATH/resources/maps/map00
//		-p1 PATH/resources/players/./ayundina.filler
//		-p2 PATH/resources/players/./lskrauci.filler > PATH/resources/out/file.txt
// 		my path: /Users/anna/Desktop/190531_1018_Filler/190614_1027_filler_test/190614_1027_filler_test
		printf("usage: %s /full/path/to/fillertest player_one.filler player_two.filler\n", argv[0]);
        return (0);
	}
	clean_out(argv[1]);
	ready_maps(&mp);
	printf("map			player_1:	O	vs	X:		player_2\n\n");
	ready_player(&pl, argv[2], argv[3]);
	if (launch(argv[1], &file, mp.map_one, &pl, &res) == 1)
		return (1);
	launch(argv[1], &file, mp.map_two, &pl, &res);
	launch(argv[1], &file, mp.map_three, &pl, &res);
//  launch(argv[1], &file, mp.map_four, &pl, &res);
//  launch(argv[1], &file, mp.map_five, &pl, &res);
//	launch(argv[1], &file, mp.map_six, &pl, &res);
//	launch(argv[1], &file, mp.map_seven, &pl, &res);
//	launch(argv[1], &file, mp.map_eight, &pl, &res);
	printf("\nmap			player_1:	X	vs	O:		player_2\n\n");
	launch_rev(argv[1], &file, mp.map_one, &pl, &res);
	launch_rev(argv[1], &file, mp.map_two, &pl, &res);
	launch_rev(argv[1], &file, mp.map_three, &pl, &res);
//  launch_rev(argv[1], &file, mp.map_four, &pl, &res);
//  launch_rev(argv[1], &file, mp.map_five, &pl, &res);
//	launch_rev(argv[1], &file, mp.map_six, &pl, &res);
//	launch_rev(argv[1], &file, mp.map_seven, &pl, &res);
//	launch_rev(argv[1], &file, mp.map_eight, &pl, &res);
	if (res.fin_won_pl_one > res.fin_won_pl_two)
	{
		printf("\nfinal:		WON:	%s	[%d]-%d	vs	%d-[%d]	%s\n", pl.pl_one, res.fin_total_pl_one, res.fin_won_pl_one, res.fin_won_pl_two, res.fin_total_pl_two, pl.pl_two);
	}
	else
	{
		printf("\nfinal:				%s	[%d]-%d	vs	%d-[%d]	%s:	WON\n", pl.pl_one, res.fin_total_pl_one, res.fin_won_pl_one, res.fin_won_pl_two, res.fin_total_pl_two, pl.pl_two);
	}
	return (0);
}
