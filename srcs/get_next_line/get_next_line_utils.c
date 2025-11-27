/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dminh <dminh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:53:55 by dminh             #+#    #+#             */
/*   Updated: 2025/11/26 13:30:35 by dminh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

char	*ft_is_nl(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\n')
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_join(char *s1, char *s2)
{
	char	*joined;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s1)
	{
		s1 = malloc(sizeof(*s1));
		*s1 = '\0';
	}
	if (!s2)
		return (NULL);
	joined = malloc(sizeof(*joined) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!joined)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	while (s1[j])
		joined[i++] = s1[j++];
	while (s2[k])
		joined[i++] = s2[k++];
	joined[i] = '\0';
	free(s1);
	return (joined);
}

char	*ft_set_line(char *res)
{
	char	*line;
	size_t	i;

	if (res[0] == '\0')
		return (NULL);
	i = 0;
	while (res[i] && res[i] != '\n')
		i++;
	line = malloc(sizeof(*line) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (res[i] && res[i] != '\n')
	{
		line[i] = res[i];
		i++;
	}
	if (res[i] == '\n')
	{
		line[i] = res[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_del_printed(char *res)
{
	char	*next;
	size_t	i;
	size_t	j;

	i = 0;
	while (res[i] && res[i] != '\n')
		i++;
	if (res[i] == '\0')
	{
		free(res);
		return (NULL);
	}
	next = malloc(sizeof(*next) * (ft_strlen(res) - i + 1));
	if (!next)
		return (NULL);
	i++;
	j = 0;
	while (res[i])
	{
		next[j++] = res[i];
		i++;
	}
	next[j] = '\0';
	free(res);
	return (next);
}
