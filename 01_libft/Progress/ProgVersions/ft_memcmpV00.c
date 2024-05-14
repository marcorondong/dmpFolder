/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:39:54 by marondon          #+#    #+#             */
/*   Updated: 2023/09/08 11:11:26 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	const unsigned char	*s1byte;
	const unsigned char	*s2byte;

	s1byte = (const unsigned char *)s1;
	s2byte = (const unsigned char *)s2;
	i = 0;
	while (s1byte[i] != '\0' || s2byte[i] != '\0' && i != n)
	{
		if (s1byte[i] != s2byte[i])
			return (s1byte[i] - s2byte[i]);
		i++;
	}
	return (0);
}