/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: igbraude <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 14:38:47 by igbraude     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/12 15:30:07 by igbraude    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static	int			ft_read_buff(const int fd, char **line)
{
	char	*tmp;
	char	*stock_buff;
	int		ret;

	ret = 1;
	if (!(stock_buff = ft_strnew(BUFF_SIZE)))
		return (-1);
	while (!(ft_strchr(*line, '\n')) && ret > 0)
	{
		ret = read(fd, stock_buff, BUFF_SIZE);
		stock_buff[ret] = '\0';
		tmp = *line;
		if (!(*line = ft_strjoin(tmp, stock_buff)))
			return (-1);
		ft_strdel(&tmp);
	}
	ft_strdel(&stock_buff);
	return (ret);
}

static	int			get_stock_line(int fd, char **stock_line, char **line)
{
	char	*tmp;
	char	*tmp2;

	if (!(tmp = ft_strdup(*line)))
		return (0);
	if (!(tmp2 = ft_strdup(ft_strchr(*line, '\n'))))
		return (0);
	ft_strdel(&stock_line[fd]);
	if (!(stock_line[fd] = ft_strdup(tmp2 + 1)))
		return (0);
	ft_strdel(&tmp2);
	ft_strdel(&*line);
	if (!(*line = ft_strsub(tmp, 0, ft_strlen_endl(tmp))))
		return (0);
	ft_strdel(&tmp);
	return (1);
}

static	int			line_in_stock_line(int fd, char **line, char **stock_line)
{
	char *tmp;
	char *tmp2;

	if (!(*line = ft_strdup(stock_line[fd])))
		return (0);
	if (ft_strchr(stock_line[fd], '\n'))
	{
		if (!(get_stock_line(fd, stock_line, line)))
			return (0);
		return (1);
	}
	if (!(tmp = ft_strdup(*line)))
		return (0);
	if (!(tmp2 = ft_strdup(ft_strchr(*line, '\0'))))
		return (0);
	ft_strdel(&stock_line[fd]);
	if (tmp2[0] != '\0' && !(stock_line[fd] = ft_strdup(tmp2 + 1)))
		return (0);
	ft_strdel(&tmp2);
	ft_strdel(&*line);
	if (!(*line = ft_strsub(tmp, 0, ft_strlen_endl(tmp))))
		return (0);
	ft_strdel(&tmp);
	return (2);
}

int					get_next_line(const int fd, char **line)
{
	static char		*stock_line[256];
	int				ret;
	int				check_line;

	ret = 0;
	check_line = 0;
	if ((fd < 0 || BUFF_SIZE <= 0 || line == NULL))
		return (-1);
	if (stock_line[fd])
	{
		if (!(check_line = line_in_stock_line(fd, &*line, stock_line)))
			return (-1);
		else if (check_line == 1)
			return (1);
	}
	else if (!(*line = ft_strnew(0)) && (!(stock_line[fd]) &&
				!(stock_line[fd] = ft_strnew(0))))
		return (-1);
	if ((ret = ft_read_buff(fd, line)) == -1)
		return (-1);
	if (ft_strchr(*line, '\n') && !(get_stock_line(fd, stock_line, &*line)))
		return (-1);
	if ((check_line = 2 && *line[0] == '\0' && ret == 0))
		return (0);
	return (1);
}
