/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dminh <dminh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:53:52 by dminh             #+#    #+#             */
/*   Updated: 2025/11/26 14:23:52 by dminh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

char	*ft_read_line(char *res, int fd)
{
	char	*buffer;
	ssize_t	reading;

	buffer = malloc(sizeof(*buffer) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	reading = 1;
	while (!ft_is_nl(res) && reading > 0)
	{
		reading = read(fd, buffer, BUFFER_SIZE);
		if (reading == -1)
		{
			free(res);
			free(buffer);
			return (NULL);
		}
		buffer[reading] = '\0';
		res = ft_join(res, buffer);
	}
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	res = ft_read_line(res, fd);
	if (!res)
		return (NULL);
	line = ft_set_line(res);
	res = ft_del_printed(res);
	return (line);
}
//
//int	main(int ac, char **av)
//{
//	if (ac > 1)
//	{
//		char    *tab;
//		int     fd = open(av[1], O_RDONLY);
//
//		while ((tab = get_next_line(fd)) != NULL)
//		{
//			printf("%s", tab);
//			free(tab);
//		}
//		close(fd);
//	}
//	return (0);
//}
