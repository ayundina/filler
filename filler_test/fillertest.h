//
//  fillertest.h
//  190614_1027_filler_test
//
//  Created by Anna on 14/06/2019.
//  Copyright © 2019 Codam. All rights reserved.
//

#ifndef fillertest_h
#define fillertest_h

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>//open file
# include <sys/types.h>//read fd
# include <sys/uio.h>//read fd
# include <unistd.h>//read fd

typedef struct	s_results
{
	int			pl_one;
	int			pl_two;
	int			total_pl_one;
	int			total_pl_two;
	int			fin_total_pl_one;
	int			fin_total_pl_two;
	int			won_pl_one;
	int			won_pl_two;
	int			fin_won_pl_one;
	int			fin_won_pl_two;
}				t_results;

typedef struct	s_file
{
	char		name[1000];
	int			num;
}				t_file;

typedef struct	s_players
{
	char		*pl_one;
	char		*pl_two;
}				t_players;

typedef struct	s_maps
{
	char		map_one[20];
	char		map_two[20];
	char		map_three[20];
	char		map_four[20];
	char		map_five[20];
	char		map_six[20];
	char		map_seven[20];
	char		map_eight[20];
}				t_maps;

#endif /* fillertest_h */
