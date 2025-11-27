/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dminh <dminh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 01:37:23 by dminh             #+#    #+#             */
/*   Updated: 2025/11/21 09:56:51 by dminh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memset(void *dest, int c, size_t count)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)dest;
	while (i < count)
	{
		str[i] = (unsigned int)c;
		i++;
	}
	return (dest);
}
