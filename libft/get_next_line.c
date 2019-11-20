/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/18 16:52:30 by ayundina      #+#    #+#                 */
/*   Updated: 2019/03/06 15:58:28 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** is_newline() function locates first occurrence of '\n' in leftover string
*/

int		is_newline(char *txt)
{
	int	len;

	len = 0;
	if (!txt)
		return (-1);
	while (txt[len] != '\0')
	{
		if (txt[len] == '\n')
		{
			return (len);
		}
		len++;
	}
	return (-1);
}

/*
** free_str() function frees a leftover string, allocate space for 1 char
** and sets '\0'. It does reallocation to avoid segfault if g_n_l will try
** to access the same str.
*/

void	free_str(t_l **left, int fd)
{
	if ((*left)->s[fd])
	{
		free((*left)->s[fd]);
		(*left)->s[fd] = ft_memalloc(sizeof(char) * 1);
		(*left)->nl[fd] = -1;
	}
}

/*
** check_leftover() function allocates new leftover when g_n_l is called
** for the first time, with that, function allocates 1 char for each str
** in leftover->string array and sets it to '\0'.
**
** Second if statement does the copy of buf into the string,
** corresponding to the specified file descriptor.
*/

t_l		*check_leftover(t_l **left, char *buf, int fd)
{
	int		i;

	i = 0;
	if (!(*left))
	{
		*left = (t_l *)malloc(sizeof(t_l));
		if (!*left)
			*left = NULL;
		while (i < 1042)
		{
			(*left)->nl[i] = -1;
			(*left)->s[i] = ft_memalloc(sizeof(char) * 1);
			i++;
		}
	}
	if (*left)
	{
		(*left)->tmp = (*left)->s[fd];
		(*left)->s[fd] = ft_strjoin((*left)->s[fd], buf);
		free((*left)->tmp);
		(*left)->nl[fd] = is_newline((*left)->s[fd]);
	}
	return (*left);
}

/*
** get_line() function copies new line found in fd into **line.
** First if statement works when '\n' is present in leftover,
** second if statement works when no '\n' is present and file is read (EOF),
** the last statement covers fully read file and when there is nothing
** more to return.
*/

int		get_line(t_l **left, char **line, int fd, int ret)
{
	if (*left)
	{
		if (ret > 0 && (*left)->nl[fd] >= 0)
		{
			*line = ft_strsub((*left)->s[fd], 0, (*left)->nl[fd]);
			(*left)->tmp = (*left)->s[fd];
			(*left)->s[fd] = ft_strsub((*left)->s[fd], \
				(unsigned int)((*left)->nl[fd]) + 1, \
				ft_strlen(((*left)->s[fd]) + (((*left)->nl[fd]) + 1)));
			free((*left)->tmp);
			(*left)->nl[fd] = is_newline((*left)->s[fd]);
			return (1);
		}
		if (ret == 0 && (*left)->s[fd] && ft_strlen((*left)->s[fd]) > 0)
		{
			*line = ft_strsub((*left)->s[fd], 0, ft_strlen((*left)->s[fd]));
			free_str(left, fd);
			return (1);
		}
		else
			return (0);
	}
	else
		return (-1);
}

/*
** get_next_line() function reads from file descriptor.
** Returns -1 if an error has occurred, 0 if the file is read,
** and 1 if one line is read.
*/

int		get_next_line(const int fd, char **line)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	static t_l	*left;

	ret = 1;
	if (fd < 0 || line == NULL)
		return (-1);
	while (!left || left->nl[fd] < 0)
	{
		ret = (int)read(fd, buf, BUFF_SIZE);
		if (ret < 0)
			return (-1);
		buf[ret] = '\0';
		if (ret == 0)
		{
			break ;
		}
		left = check_leftover(&left, buf, fd);
		if (!left)
			return (-1);
	}
	return (get_line(&left, line, fd, ret));
}
