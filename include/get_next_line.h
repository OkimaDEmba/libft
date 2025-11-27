/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dminh <dminh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:53:55 by dminh             #+#    #+#             */
/*   Updated: 2025/11/26 14:18:42 by dminh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

char	*ft_is_nl(char *str);
char	*get_next_line(int fd);
char	*ft_read_line(char *res, int fd);
char	*ft_join(char *s1, char *s2);
char	*ft_set_line(char *res);
char	*ft_del_printed(char *res);
#endif
