/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dminh <dminh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:53:52 by dminh             #+#    #+#             */
/*   Updated: 2026/01/22 02:18:07 by dminh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_check_buffer(char *buffer, char *line, size_t *len)
{
	if (buffer[0])
	{
		line = ft_set_line(line, buffer, len);
		if (!line)
			return (NULL);
		if (ft_is_nl(buffer))
			return (line);
		return (line);
	}
	return (NULL);
}

char	*ft_read_line(char *buffer, int fd, char *line, size_t	*len)
{
	ssize_t	reading;

	reading = 1;
	line = ft_check_buffer(buffer, line, len);
	if (!ft_is_nl(line))
	{
		while (!ft_is_nl(buffer) && reading > 0)
		{
			reading = read(fd, buffer, BUFFER_SIZE);
			if (reading == -1)
			{
				if (line)
					free(line);
				return (buffer[0] = '\0', NULL);
			}
			if (reading == 0)
				return (buffer[0] = '\0', line);
			buffer[reading] = '\0';
			line = ft_set_line(line, buffer, len);
			if (!line)
				return (NULL);
		}
	}
	ft_del_printed(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	size_t		len;
	static char	buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	len = 0;
	line = ft_read_line(buffer, fd, line, &len);
	if (!line)
		return (NULL);
	return (line);
}

//int	main(int ac, char **av)
//{
	//int	i;
//
	//if (ac > 1)
	//{
		//char	*tab;
		//tab =  0;
		//i = 0;
		//int	fd = open(av[1], O_RDONLY);
		//while ((tab = get_next_line(fd)) != NULL && i < 3)
		//{
			//printf("%s", tab);
			//free(tab);
			//tab = NULL;
			//i++;
		//}
		//if (tab)
			//free(tab);
		//close(fd);
	//}
	//return (0);
//}
