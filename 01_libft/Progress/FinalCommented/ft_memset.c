/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:50:17 by marondon          #+#    #+#             */
/*   Updated: 2023/09/06 13:35:33 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i; // Must be 'size_t' to count as much as 'n'

	i = 0;
	while (i < n)
	{
		// Cast to 'unsigned char *' to treat memory as array
		// of bytes (unsigned chars). (char = 1 byte)
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	str1[] = "Hello World";
	char	str2[] = "Hello World";
	int	c;
	size_t	n;

	printf("Before ft_memset: %s\n", str1);
	c = 'X';
	n = 5;
	ft_memset(str1, c, n);
	printf("After  ft_memset: %s\n", str1);
	printf("Before    memset: %s\n", str2);
	memset(str2, c, n);
	printf("After     memset: %s\n", str2);
	return (0);
}
==============================================================================
- I use size_t i so I can count as much as n
- I have to cast 's' and 'c' to unsigned char because I'm receiving any value
(void) and I'm setting the maximum byte value wich is 255
(binary: 11111111)(hexadecimal: 0xFF)
*/
