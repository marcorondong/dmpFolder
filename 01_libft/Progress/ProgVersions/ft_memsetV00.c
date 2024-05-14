/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:50:17 by marondon          #+#    #+#             */
/*   Updated: 2023/09/06 13:11:59 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		s[i] = c;
		i++;
	}
	return (s);
}
/*- Is not (i<n-1) because Im using an array. Initial element is s[0]
and last is [n-1]
- I use size_t i so I can count as much as n
- I have to cast s and c to unsigned char because I'm receiving any value (void)
and I'm setting the maximum byte value wich is 255
(binary: 11111111)(hexadecimal: 0xFF)*/
