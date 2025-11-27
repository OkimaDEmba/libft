/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dminh <dminh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 23:56:10 by dminh             #+#    #+#             */
/*   Updated: 2025/11/18 18:17:44 by dminh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str != (unsigned char)c)
	{
		if (!*str++)
			return (NULL);
	}
	return ((char *)str);
}
